#!/usr/bin/env python3

import sys
import os
import time
import math

# Add current directory to path so we can import flightstack.py
sys.path.insert(0, os.path.dirname(os.path.realpath(__file__)))

# os.environ['MAVLINK_DIALECT'] = 'flightstack' # Removed to avoid XML load error

from pymavlink import mavutil
import flightstack

def main():
    connection_string = 'tcp:127.0.0.1:5760'
    print(f"Connecting to {connection_string}")
    
    # Create the connection (default dialect for receiving STATUSTEXT)
    master = mavutil.mavlink_connection(connection_string, source_system=255)
    
    # Create a MAVLink instance for packing our custom message
    # We use file=None because we will manually write the buffer to master
    custom_mav = flightstack.MAVLink(None)
    custom_mav.srcSystem = 1  # Assuming from same system
    custom_mav.srcComponent = 211 # Uni-Co AI Computer ID

    
    print("Waiting for heartbeat...")
    master.wait_heartbeat()
    print("Heartbeat received!")

    print("Sending AI_LANDING_CORRECTION messages...")
    
    frame_count = 0
    start_time = time.time()

    while True:
        # Check for incoming STATUSTEXT messages
        while True:
            msg = master.recv_match(type='STATUSTEXT', blocking=False)
            if not msg:
                break
        # Simulate some changing data
        t = time.time() - start_time
        roll_err = 0.1 * math.sin(t)
        pitch_err = 0.05 * math.cos(t)
        distance = 20.0 - (t * 0.5) # Approaching
        if distance < 0: distance = 0
        
        # Send Correction Message
        # Note: We must ensure the message ID matches what ArduPilot expects (52100)
        msg_corr = flightstack.MAVLink_ai_landing_correction_message(
            time_boot_ms=int(t * 1000),
            roll_err=roll_err,
            pitch_err=pitch_err,
            yaw_err=0.0,
            distance=distance,
            confidence=0.98,
            frame=0,
            flags=0
        )
        
        # We pack it using our custom_mav instance and write via mavutil connection
        buf = msg_corr.pack(custom_mav)
        master.write(buf)
        
        # Send Status Message occasionally (every 1 second)
        if frame_count % 10 == 0:
             msg_status = flightstack.MAVLink_ai_landing_status_message(
                 time_boot_ms=int(t * 1000),
                 visual_confidence=0.95,
                 target_lost=0,
                 reproj_error=0.5,
                 covariance=0.1
             )
             buf = msg_status.pack(custom_mav)
             master.write(buf)
             print("Sent AI_LANDING_STATUS")
        
        # Send Test Trigger for Start Command (target_lost=255)
        if frame_count == 50:
             print("Sending TEST TRIGGER for Start Command...")
             msg_status = flightstack.MAVLink_ai_landing_status_message(
                 time_boot_ms=int(t * 1000),
                 visual_confidence=0.0,
                 target_lost=255, # Magic value to trigger start command
                 reproj_error=0.0,
                 covariance=0.0
             )
             master.write(msg_status.pack(custom_mav))

        # Check for COMMAND_LONG (and STATUSTEXT)
        while True:
            msg = master.recv_msg()
            if not msg:
                break
            
            if msg.get_type() == 'STATUSTEXT':
                print(f"Received STATUSTEXT: {msg.text}")
                if "AI Landing Corr" in msg.text:
                    if not verified_corr:
                        print("SUCCESS: Verified AI Landing Correction logic!")
                        verified_corr = True
                if "AI Landing Status" in msg.text:
                     if not verified_status:
                        print("SUCCESS: Verified AI Landing Status logic!")
                        verified_status = True
                if "Command Accepted" in msg.text:
                    print("SUCCESS: Verified AI Landing Command ACK logic!")
                    verified_ack = True

            if msg.get_type() == 'COMMAND_LONG':
                print(f"Received COMMAND_LONG: {msg.command}")
                if msg.command == 31020: # MAV_CMD_START_AI_LANDING
                    print("Received START_AI_LANDING command! Sending ACK...")
                    # Send ACK
                    msg_ack = master.mav.command_ack_encode(
                        31020, # command
                        0, # MAV_RESULT_ACCEPTED
                        0, # progress
                        0, # result_param2
                        msg.target_system,
                        msg.target_component
                    )
                    # NOTE: pymavlink might need correct addressing. 
                    # We are Component 211.
                    # master.mav.srcComponent = 211 (Already set)
                    master.write(msg_ack.pack(master.mav))
                    print("Sent COMMAND_ACK for START_AI_LANDING")

        # print(f"Sent: Dist={distance:.1f}m Roll={roll_err:.2f} Pitch={pitch_err:.2f}")
        
        time.sleep(0.1) # 10Hz
        frame_count += 1

    if verified_corr and verified_status and verified_ack:
        pass

if __name__ == "__main__":
    main()
