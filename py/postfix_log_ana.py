#! /usr/bin/env python
import re

LOGFILE = '/home/maomao/downloads/sentlog'


def simple_parse(line):
    """parse postfix log"""
    time = re.findall('^\w+\s\d+\s\d+:\d+:\d+', line)[0]
    to = re.findall('<(.*)>', line)[0]
    relay = re.findall('relay=(.*)\[', line)[0]
    delay = float(re.findall('delay=(\d*\.?\d*)', line)[0])
    return (time, to, relay, delay)


if __name__ == '__main__':

    # download logfile

    # grep log with 'status=sent'

    # parse log 
    send_time = []
    send_to = []
    send_relay = []
    send_delay = []

    with open(LOGFILE, 'r') as f:
        for line in f:
            time, to, relay, delay = simple_parse(line)
            send_time.append(time)
            send_to.append(to)
            send_relay.append(relay)
            send_delay.append(delay)
    print send_time[0:4], len(send_time)
    print send_to[0:4], len(send_to)
    print send_relay[0:4], len(send_relay)
    print send_delay[0:4], len(send_delay)

    # analysis log
