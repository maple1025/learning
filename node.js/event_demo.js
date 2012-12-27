"use strict";
var events = require('events');

var eventEmitter = new events.EventEmitter();

eventEmitter.on('someOccurence', function (message) {
    console.log(message);
});
eventEmitter.emit('someOccurence', 'Something happened!');
