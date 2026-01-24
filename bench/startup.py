#!/usr/bin/env python3
# Measures time to first render and full start-to-close cycle

import subprocess, time, os, pty, select

master, slave = pty.openpty()
start = time.perf_counter()
p = subprocess.Popen(['./e', 'demo.txt'], stdin=slave, stdout=slave, stderr=slave)

# Wait for first render
select.select([master], [], [], 1)
os.read(master, 10000)
render_time = time.perf_counter() - start

# Send C-q (quit)
os.write(master, b'\x11')

# Wait for exit
p.wait()
total_time = time.perf_counter() - start

os.close(master)
os.close(slave)

print(f"Time to first render: {render_time*1000:.2f}ms")
print(f"Time to close:        {total_time*1000:.2f}ms")
