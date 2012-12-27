#! /usr/bin/env ruby

require 'pry'

# Call the each method of each collectin in turn.
# This is not a parallel iteration and does not require enumerators.
def sequence(*enumerables, &block)
    enumerables.each do |enumerable|
        enumerable.each(&block)
    end
end

# Iterate the specified collections, interleaving their elements.
# This can't be done efficiently without external iterators.
# Note the use of the uncommon else clause in begin/rescue.
def interleave(*enumerables)
    # Convert enumerable collections to an array of enumerators.
    enumerators = enumerables.map {|e| e.to_enum }
    binding.pry
    # Loop until we don't have any more enumerators.
    until enumerators.empty?
        begin
            e = enumerators.shift
            yield e.next
        rescue StopIteration
        else
            enumerators << e
        end
    end
end

# Iterate the specified collections, yield tuples of values,
# one value from each of the collections. See also Enumerable.zip
def bundle(*enumerables)
    enumerators = enumerables.map{|e| e.to_enum }
    loop { yield enumerators.map {|e| e.next} }
end

# Examples of how these iterators methods work
a,b,c = [1,2,3], 4..6, 'a'..'e'
sequence(a,b,c) {|x| print x}
puts
interleave(a,b,c) {|x| print x}
puts
bundle(a,b,c) {|x| print x}
puts
