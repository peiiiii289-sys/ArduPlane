#!/bin/bash
# Start ArduPlane in background
# Use speedup to boot faster, but not too fast for python script sync
./build/sitl/bin/arduplane --model plane --speedup 10 > sitl_output.txt 2>&1 &
SITL_PID=$!
echo "Started ArduPlane (PID $SITL_PID)"

# Wait for SITL to init
sleep 15

# Run test script
echo "Running test script..."
# Run for 20 seconds
timeout 20s python3 -u Tools/scripts/test_ailanding.py > test_output.txt 2>&1

# Kill SITL
kill $SITL_PID
echo "Test finished. Output:"
cat test_output.txt
