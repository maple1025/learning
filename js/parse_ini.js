/*
 * Parse ini configuration file.
 * http://eloquentjavascript.net/2nd_edition/preview/09_regexp.html
 */

/* jshint node: true */

"use strict";
var fs = require('fs');

function parseINI(string) {
    var currentCategory = {
        name: null,
        fields: []
    };
    var categories = [currentCategory];

    string.split(/\r?\n/).forEach(function(line) {
        var match;
        if (/^\s*(;.*)?$/.test(line)) {
            return;
        } else if (line.match(/^\[(.*)\]$/)) {
            match = line.match(/^\[(.*)\]$/);
            currentCategory = {
                name: match[1],
                fields: []
            };
            categories.push(currentCategory);
        } else if (line.match(/^(\w+)=(.*)$/)) {
            match = line.match(/^(\w+)=(.*)$/);
            currentCategory.fields.push({
                name: match[1],
                value: match[2]
            });
        } else {
            throw new Error("Line '" + line + "' is invalid.");
        }
    });
    return categories;
}

fs.readFile('test.ini', function (err, data) {
    if (err) throw err;
    var categories = parseINI(data.toString());
    console.log(categories);
});
