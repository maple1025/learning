var http = require('http');
var fs = require('fs');
var querystring = require('querystring');

var filename = '/etc/hosts';
var key = Buffer('hosts').toString('base64');
var value = Buffer('hello world!').toString('base64');
var post_data = querystring.stringify({
    Buffer('hosts').toString('base64') : value
})
var options = {
    host: '10.10.124.143',
    port: 1978,
    path: '/rpc/set',
    method: 'POST',
    headers: {
        'Content-Type': 'text/tab-separated-values; colenc=B',
        'Content-Length': value.length
    }
};

//fs.readFile(filename, 'utf8', function (err, data) {
//    if (err) {
//        return console.log(err);
//    }
//    value = Buffer(data).toString('base64');
//    options.path = '?key=' + key + '&value=' + value;
//    console.log("Finish read data from " + filename);
//    console.info("The data is: \n" + data);
//})

var post_req =  http.request(options, function (res) {
    res.on('data', function (chunk) {
        console.log('Response: ' + chunk);
    });
});

post_req.write(post_data);
post_req.end();
