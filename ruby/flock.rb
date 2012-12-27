#! /usr/bin/env ruby
#   demo from Ruby Cookbook about file lock

def flock(file, mode)
    success = file.flock(mode)
    if success
        begin
            yield file
        ensure
            file.flock(File::LOCK_UN)
        end
    end
    return success
end

def open_lock(filename, openmode="r", lockmode=nil)
    if openmode == 'r' || openmode == 'rb'
        lockmode ||= File::LOCK_SH
    else
        lockmode ||= File::LOCK_EX
    end
    value = nil
    open(filename, openmode) do |f|
        flock(f, lockmode) do
            begin
                value = yield f
            ensure
                f.flock(File::LOCK_UN)
            end
        end
        return value
    end
end


#open('output', 'w') do |f|
#    flock(f, File::LOCK_EX) do |f|
#        f << "Kiss me, I'v got a write lock on a file!\n"
#    end
#end

t1 = Thread.new do
    puts "Thread 1 is requiring a lock.\n"
    open_lock('output', 'w') do |f|
        puts "Thread 1 has required a lock.\n"
        f << "At last we are alone.\n"
        sleep(5)
    end
    puts "Thread 1 has released its lock.\n"
end

t2 = Thread.new do
    puts "Thread 2 is requiring a lock.\n"
    open_lock('output', 'r') do |f|
        puts "Thread 2 has required a lock.\n"
        puts "File contents: #{f.read}"
    end
    puts "Thread 2 has released its lock.\n"
end

t1.join
t2.join
