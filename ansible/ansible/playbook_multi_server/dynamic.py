#!/usr/bin/env python3.6
import subprocess
import paramiko
import os

cmd = "vagrant ssh-config vagrant2"

# p = subprocess.Popen(cmd.split(), stdout=subprocess.PIPE)

textlist = os.popen(cmd).readlines()
for line in textlist:
    line = line.replace('\n', '')
    print(line)

config = paramiko.SSHConfig()
config.parse(textlist)
print(config.lookup("vagrant2"))