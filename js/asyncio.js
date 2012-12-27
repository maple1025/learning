var fs = require('fs'),
    processId;

fs.readdir(".", function (err, filenames) {
    var i;
    for (i = 0; i < filenames.length; i++) {
        console.log(filenames[i]);
    }
    console.log("Ready.");
})

processId = process.getuid();

console.log(processId);
