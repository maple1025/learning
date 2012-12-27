"use strict";

var mike = Object.create(null);

// () -> String
// Return the full name of object.
function get_full_name() {
    return this.first_name + ' ' + this.last_name;
}

// (new_name:String) -> undefined
// Sets the name components of the object, from a full name.
function set_full_name(new_name) {
    var names;
    names = new_name.trim().split(/\s+/);
    this.first_name = names['0'] || '';
    this.last_name = names['1'] || '';
}

Object.defineProperty(mike, 'name', { get: get_full_name,
                                      set: set_full_name,
                                      configurable: true,
                                      enumerable: true
                                    });

var repl = require("repl");
repl.start().context.mike = mike;
