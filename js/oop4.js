
// Aliases for the rather verbose methods on ES5
var descriptor = Object.getOwnPropertyDescriptor,
    properties = Object.getOwnPropertyNames,
    define_prop = Object.defineProperty

// (target:Object, source:Object) -> Object
// copies properties from `source` to `target`
function extend(target, source) {
    properties(source).forEach(function(key){
        define_prop(target, key, descriptor(source, key))
    })
    return target
}

var person = Object.create(null)

// () → String
// Returns the full name of object.
function get_full_name() {
    return this.first_name + ' ' + this.last_name
}

// (new_name:String) → undefined
// Sets the name components of the object, from a full name.
function set_full_name(new_name) { var names
    names = new_name.trim().split(/\s+/)
    this.first_name = names['0'] || ''
    this.last_name  = names['1'] || ''
}

Object.defineProperty(person, 'name', { get: get_full_name,
                                        set: set_full_name,
                                        configurable: true,
                                        enumerable: true
                                        })

person.greet = function (person) {
    return this.name + ": hello there, " + person + " ~" 
}

// A pianist is someone who can `play` the piano
var pianist = Object.create(null)
pianist.play = function() {
    return this.name + ' starts playing the piano.'
}

// A singer is someone who can `sing`
var singer = Object.create(null)
singer.sing = function(){
    return this.name + ' starts singing.'
}

var mike = Object.create(person)
mike.first_name = "Mike"
mike.last_name = "White"
mike.age = 19
mike.gender = "Male"

// Then we can move on to adding those abilities to our main objects
extend(mike, pianist)
console.log(mike.play())

console.log(Object.keys(mike))

extend(person, singer)
console.log(mike.sing())
