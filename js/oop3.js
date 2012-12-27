"use strict"

// (other: Number[, yet_another: Number]) -> Number
// Returns the sum of the object's value with the given Number
function add(other, yet_another) {
    return this.value + other + (yet_another || 0)
}

var one = { value: 1, add: add };
var two = { value: 2, add: add };

console.info(one.add(two.value));
console.info(two.add(3));
console.info(one['add'](two.value));

console.info(this);
