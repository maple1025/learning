#! /usr/bin/env ruby
# example from The Ruby Programming Language, 5.8

class Generator
    def initialize(enumerable)
        @enumerable = enumerable
        create_fiber
    end

    def next
        @fiber.resume
    end

    def rewind
        create_fiber
    end

    private
    def create_fiber
        @fiber = Fiber.new do
            @enumerable.each do |x|
                Fiber.yield(x)
            end
            raise StopIteration
        end
    end
end


class FibonacciGenerator
    def initialize
        @x,@y = 0,1
        @fiber = Fiber.new do
            loop do
                @x,@y = @y,@x+@y
                Fiber.yield @x
            end
        end
    end

    def next
        @fiber.resume
    end

    def rewind
        @x,@y = 0,1
    end
end

# Test
g = FibonacciGenerator.new
10.times { print g.next, " " }
g.rewind; puts
10.times { print g.next, " " }
puts

f = Generator.new(1..10)
loop { print f.next }
f.rewind
f = (1..10).to_enum
boop { print f.next }
