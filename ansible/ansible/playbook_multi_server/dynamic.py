#!/usr/bin/env python3.6
import argparse
import json
import sys
import paramiko
import os

# p = subprocess.Popen(cmd.split(), stdout=subprocess.PIPE)

def parse_args():
    parser = argparse.ArgumentParser(description="Vagrant inventory script")
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--list', action='store_true')
    group.add_argument('--host')
    return parser.parse_args()

def list_running_hosts():
    cmd = "vagrant status --machine-readable"
    status = os.popen(cmd).readlines()
    hosts = []
    for line in status:
        line = line.rstrip('\n')
        host_status = line.split(',')
        if host_status[2] == 'state' and host_status[3] == 'running':
            hosts.append(host_status[1])
    return hosts

def get_host_details(host):
    cmd = "vagrant ssh-config {}".format(host)

    textlist = os.popen(cmd).readlines()
    #for line in textlist:
        #line = line.replace('\n', '')
        #print(line)
    
    config = paramiko.SSHConfig()
    config.parse(textlist)
    c = config.lookup(host)
    
    return {'ansible_ssh_host': c['hostname'],
            'ansible_ssh_port': c['port'],
            'ansible_ssh_user': c['user'],
            'ansible_ssh_private_key_file': c['identityfile'][0]}

def main():
    args = parse_args()
    
    if args.list:
        hosts = list_running_hosts()
        json.dump({'vagrant': hosts}, sys.stdout)
    else:
        details = get_host_details(args.host)
        json.dump(details, sys.stdout)

if __name__ == '__main__':
    main()