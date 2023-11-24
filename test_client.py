from subprocess import run, PIPE
import time

for i in range(10):
    run(f"mosquitto_pub -d -t testTopic -m 'Hello World {i}'", shell=True)
    time.sleep(1)
