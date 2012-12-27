"use strict";
var tyrant = require("./tyrant");
var sys = require('util');
var fs = require('fs');
var amqp = require('amqp');

// read data from file
var input = fs.readFileSync('game_1.html', 'utf8');


// put data to tt
var msg_id = '123456';
var key = msg_id;

function pub_email(key) {
    var url = "amqp://guest:guest@10.10.69.125:5672",
        ex_opt = {type: 'direct', durable: true},
        que_opt = {durable: true},
        ex_name = 'sendcloud',
        que_name = 'email_queue',
        conn_mq = amqp.createConnection({url: url}, function () {
            console.log('Connected to rabbitmq.');
        });

    conn_mq.on('ready', function (key) {
        var exchange = conn_mq.exchange(ex_name, ex_opt);

        var queue = conn_mq.queue(que_name, que_opt, function () {
            queue.bind(exchange, queue.name);
            exchange.publish(queue.name, {msg_id: key}, function () {
                console.log("Publish one msg to mq.");
                conn_mq.end( function () {
                    console.log('connection to mq closed.')
                });
            });
        });
    });
}

// First store `key-value data: msg_id => data` to TT,
// then queue the msg_id to RabbitMQ.
function sequence_store(key, data) {
    console.time('tt-put-time');
    var conn_tt = tyrant.connect(1978, '10.10.124.143');
    conn_tt.addListener("connect", function () {
        conn_tt.put(key, input, function (err) {
            if (err) {
                console.log(err);
                // processing the error, e.g. mv the email to err_dir
            } else {
                console.log('Put key: ' + key +
                            ', and ' + input.length + ' Byte data to TT.');
                console.timeEnd('tt-put-time');
                // queue the msg_id to RabbitMQ
                pub_email(key);
            }
        });

        // get the data from TT
        console.time('tt-get-time');
        conn_tt.get(key, function (err, value) {
            if (err) {
                console.log(err);
            }
            console.timeEnd('tt-get-time');
            console.log('Get ' + value[0].length + ' Byte data from TT.');
            conn_tt.quit();
        });
    });
}

sequence_store(key, input);
