#! /usr/bin/env python

import sys
import time
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(
    host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='task_queue', durable=True)

print '[*] Waiting for message. To exit press CTRL+C'

def callback(ch, method, properties, body):
    """"""
    print "[x] Received %r" % (body,)
    sys.stdout.write('[x] Processing')
    for i in range(body.count('.')):
        time.sleep(1)
        sys.stdout.write('.')
        sys.stdout.flush()
    print ""
    print "[x] Done"
    ch.basic_ack(delivery_tag=method.delivery_tag)


channel.basic_qos(prefetch_count=1)
channel.basic_consume(callback, queue='task_queue')

channel.start_consuming()
