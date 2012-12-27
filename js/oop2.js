"use strict"

var mike = {
    first_name: 'Mike',
    last_name: 'White',
    age: 19,
    gender: 'Male',

    get name() {
        return this.first_name + ' ' + this.last_name;
    },

    set name(new_name) {
        var names;
        names = new_name.trim().split(/\s+/);
        this.first_name = names['0'] || ''
        this.last_name = names['1'] || ''
    }
}

mike.greet = function(person) {
    return this.name + ': Why, hello there, ' + person + '.'
}
var repl = require("repl");
repl.start().context.mike = mike;
