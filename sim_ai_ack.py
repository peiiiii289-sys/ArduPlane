#!/usr/bin/env python3
import time
import sys
from pymavlink import mavutil

# 連接 SITL (使用 SERIAL1 或 SERIAL2 的 TCP 端口)
# 標準 SITL: 5760=Serial0 (Console), 5762=Serial1, 5763=Serial2
connection_string = 'tcp:127.0.0.1:5762'

print(f"Connecting to {connection_string}...")
master = mavutil.mavlink_connection(connection_string)
# 關鍵修改：將模擬腳本的 System ID 設為 1 (與飛控相同)，代表它是同一台無人機上的 Companion Computer
master.mav.srcSystem = 1
master.mav.srcComponent = 211

# 等待心跳包
print("Waiting for heartbeat...")
master.wait_heartbeat()
print("Heartbeat received!")

# 監聽迴圈
print("Sending Heartbeat and Listening for COMMAND_LONG (31020)...")
last_heartbeat = 0

while True:
    # 每秒發送一次 Heartbeat 確保連線活躍
    if time.time() - last_heartbeat > 1.0:
        master.mav.heartbeat_send(
            mavutil.mavlink.MAV_TYPE_ONBOARD_CONTROLLER,
            mavutil.mavlink.MAV_AUTOPILOT_INVALID,
            0, 0, 0
        )
        last_heartbeat = time.time()
        # print("Heartbeat sent") # Optional debug

    # 非阻塞接收
    msg = master.recv_match(type='COMMAND_LONG', blocking=False)
    
    if msg is None:
        time.sleep(0.01)
        continue

    # Debug: print received command for verification
    print(f"Received COMMAND_LONG: {msg.command}")

    if msg.command == 31020: # MAV_CMD_START_AI_LANDING
        print(f"Match! START Command (31020) received from SysID {msg.get_srcSystem()}")
        
        # 發送 ACK
        ack = mavutil.mavlink.MAVLink_command_ack_message(
            31020, # command
            mavutil.mavlink.MAV_RESULT_ACCEPTED, # result
            255, # progress
            0, # result_param2
            msg.get_srcSystem(), # target_system
            msg.get_srcComponent() # target_component
        )
        
        # 強制設定發送者 ID 為 211 + 發送
        master.mav.srcComponent = 211
        master.mav.send(ack)
        
        print(f"ACK Sent! (Target: {msg.get_srcSystem()}/{msg.get_srcComponent()})")

    elif msg.command == 31021: # MAV_CMD_STOP_AI_LANDING
        print("Received STOP Command (31021)")
        ack = mavutil.mavlink.MAVLink_command_ack_message(
            31021,
            mavutil.mavlink.MAV_RESULT_ACCEPTED,
            255, 0,
            msg.get_srcSystem(),
            msg.get_srcComponent()
        )
        master.mav.srcComponent = 211
        master.mav.send(ack)
        print("ACK Sent!")

    elif msg.command == 31021: # MAV_CMD_STOP_AI_LANDING
        print("Received STOP Command (31021)")
        master.mav.srcComponent = 211
        master.mav.command_ack_send(
            31021,
            mavutil.mavlink.MAV_RESULT_ACCEPTED,
            255, 0,
            msg.get_srcSystem(),
            msg.get_srcComponent()
        )
        print("ACK Sent!")
