#!/usr/bin/env python3

import time
import sys
import argparse
from pymavlink import mavutil

import flightstack

def main():
    parser = argparse.ArgumentParser(description='Send AI_LANDING_CORRECTION messages')
    parser.add_argument('--connection', type=str, default='tcp:127.0.0.1:5762', help='MAVLink connection string')
    parser.add_argument('--flags', type=int, default=1, help='Flags value (1=Valid, 0=Invalid)')
    parser.add_argument('--dist', type=float, default=100.0, help='Distance in meters')
    parser.add_argument('--rate', type=float, default=10.0, help='Rate in Hz')
    args = parser.parse_args()

    # Connect to SITL
    print(f"Connecting to {args.connection}...")
    master = mavutil.mavlink_connection(args.connection, source_system=1, source_component=211)
    master.wait_heartbeat()
    print("Heartbeat received!")
    
    print(f"Sending AI_LANDING_CORRECTION with flags={args.flags} at {args.rate}Hz")
    
    last_send_time = 0
    
    try:
        while True:
            # Check for incoming STATUSTEXT or echoed AI_LANDING_CORRECTION messages
            msg = master.recv_match(type=['STATUSTEXT', 'AI_LANDING_CORRECTION'], blocking=False)
            if msg:
                if msg.get_type() == 'STATUSTEXT':
                    print(f"STATUSTEXT: {msg.text}")
                elif msg.get_type() == 'AI_LANDING_CORRECTION':
                    print(f"ECHO: Received AI_LANDING_CORRECTION flags={msg.flags}")

            # Send message at target rate
            now = time.time()
            if now - last_send_time >= (1.0 / args.rate):
                last_send_time = now
                
                # Construct message
                # Timestamp: ms since boot (simulated wrap or offset)
                timestamp = int((now * 1000) % 4294967295)
                
                # Example Data
                angle_x = 0.1 # Pitch err (rad)
                angle_y = 0.05 # Yaw err (rad)
                distance = args.dist
                
                # Create message object using generated class
                # Params: time_boot_ms, roll_err, pitch_err, yaw_err, distance, confidence, frame, flags
                msg_obj = flightstack.MAVLink_ai_landing_correction_message(
                    timestamp,     # time_boot_ms
                    0.0,           # roll_err
                    angle_x,       # pitch_err
                    angle_y,       # yaw_err
                    distance,      # distance
                    0.9,           # confidence
                    0,             # frame (CAMERA)
                    args.flags     # flags
                )
                
                # Send using the mav instance from master
                master.mav.send(msg_obj)
            
            # Short sleep to prevent busy loop, but fast enough to process msgs
            time.sleep(0.01)
            
    except KeyboardInterrupt:
        print("Stopping.")

if __name__ == '__main__':
    main()
