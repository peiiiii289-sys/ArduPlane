import sys
import time
import argparse
from pymavlink import mavutil
import flightstack # Generated module

def main():
    parser = argparse.ArgumentParser(description='Manual Test for AI Landing')
    parser.add_argument('--connection', type=str, default='tcp:127.0.0.1:5762', help='MAVLink connection string')
    args = parser.parse_args()

    print(f"Connecting to {args.connection}...")
    master = mavutil.mavlink_connection(args.connection, source_system=1, source_component=211)
    master.wait_heartbeat()
    print("Heartbeat received! Ready for commands.")
    print("-------------------------------------------------")
    print(" [a]  Send COMMAND_ACK (31020) - Story 1.2")
    print(" [c0] Send INVALID Correction (Flags=0) - Story 1.3")
    print(" [c1] Send VALID Correction   (Flags=3) - Story 1.3")
    print(" [q]  Quit")
    print("-------------------------------------------------")

    try:
        while True:
            cmd = input("Command (a/c0/c1/q): ").strip().lower()
            
            if cmd == 'q':
                break
                
            elif cmd == 'a':
                print(" -> Sending COMMAND_ACK for CMD 31020...")
                # MAV_CMD_DO_AI_LANDING = 31020
                master.mav.command_ack_send(
                    31020, # command
                    0,     # MAV_RESULT_ACCEPTED
                    255,   # progress
                    0,     # param2
                    1,     # target_system
                    0      # target_component
                )
                
            elif cmd.startswith('c'):
                flags = 0
                if cmd == 'c1':
                    flags = 3
                
                print(f" -> Sending AI_LANDING_CORRECTION (Flags={flags})...")
                timestamp = int((time.time() * 1000) % 4294967295)
                
                # Using generated flightstack class
                msg = flightstack.MAVLink_ai_landing_correction_message(
                    timestamp,
                    0.0,   # roll_err
                    0.1,   # pitch_err (rad)
                    0.05,  # yaw_err (rad)
                    10.0,  # distance (m)
                    0.9,   # confidence
                    0,     # frame
                    flags
                )
                master.mav.send(msg)
                
            elif cmd == 's':
                 print(" -> Sending AI_LANDING_STATUS (Lost=0, Conf=0.95)...")
                 timestamp = int((time.time() * 1000) % 4294967295)
                 # MAVLink_ai_landing_status_message(time_boot_ms, visual_confidence, target_lost, reproj_error, covariance)
                 msg = flightstack.MAVLink_ai_landing_status_message(
                     timestamp,
                     0.95,  # visual_confidence
                     0,     # target_lost (0=Tracking)
                     1.5,   # reproj_error
                     0.1    # covariance
                 )
                 master.mav.send(msg)

            else:
                print("Unknown command.")
                
            # Briefly check for any feedback
            # We fetch raw messages to avoid dialect name-lookup issues
            msg = master.recv_msg()
            while msg:
                msg_type = msg.get_type()
                msg_id = msg.get_msgId()
                
                # Debug: Print any COMMAND (to see if we get 31020)
                if msg_id == 76: # COMMAND_LONG
                    if msg.command == 31020:
                        print(f" [RECV] COMMAND 31020 received! (Drone requesting AI Start)")

                if msg_type == 'STATUSTEXT':
                     print(f" [AP] {msg.text}")
                
                # Check for ID 52100 (AI_LANDING_CORRECTION) even if name lookup fails
                elif msg_id == 52100:
                     print(f" [ECHO] AI_LANDING_CORRECTION (ID 52100) Received! Flags={getattr(msg, 'flags', '?')}")

                # Check for ID 52102 (AI_LANDING_STATUS)
                elif msg_id == 52102:
                     print(f" [ECHO] AI_LANDING_STATUS (ID 52102) Received! Lost={getattr(msg, 'target_lost', '?')}")
                
                 # Fallback name check
                elif msg_type == 'AI_LANDING_CORRECTION':
                     print(f" [ECHO] AI_LANDING_CORRECTION Received! Flags={msg.flags}")
                
                msg = master.recv_msg()

    except KeyboardInterrupt:
        print("\nStopping.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == '__main__':
    main()
