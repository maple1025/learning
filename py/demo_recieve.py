#! /usr/bin/env python
import pika
import sys

from pika.adapters import BlockingConnection

pika.log.setup(color=True)


def handle_delivery(channel, method_frame, header_frame, body):
    # Receive the data in 3 frames from RabbitMQ
    pika.log.info("Basic.Deliver %s delivery-tag %i: %s",
                  header_frame.content_type,
                  method_frame.delivery_tag,
                  body)
    channel.basic_ack(delivery_tag=method_frame.delivery_tag)

if __name__ == '__main__':
    # Connect to RabbitMQ
    host = (len(sys.argv) > 1) and sys.argv[1] or '127.0.0.1'
    credentials = pika.PlainCredentials('guest', 'guest')
    parameters = pika.ConnectionParameters(credentials=credentials, host=host)
    connection = BlockingConnection(parameters)
    print "connected to mq"
    
    # Open the channel
    channel = connection.channel()
    channel.exchange_declare(exchange='sendcloud', type='direct')
    channel.queue_bind(exchange='sendcloud', queue='email_queue')
    print ' [*] Waiting for logs. To exit press CTRL+C'

    def callback(ch, method, properties, body):
        print " [x] %r" % (body,)

    channel.basic_consume(callback,
                          queue='email_queue',
                          no_ack=False)

    channel.start_consuming()
