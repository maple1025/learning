#! /usr/bin/env python

import sys
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(
    host='localhost'))
channel = connection.channel()

# add durable to ensure queue will not lost in rabbitmq
channel.queue_declare(queue='task_queue', durable=True)

message = ' '.join(sys.argv[1:]) or "Hello World!"
channel.basic_publish(exchange='',
                      routing_key='task_queue',
                      body=message,
                      properties=pika.BasicProperties(
                          delivery_mode = 2, # make message presistent
                          ))

print "[x] Sent %r" % (message,)
connection.close()
