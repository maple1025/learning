#! /usr/bin/env python

"""Find the first 0 in unkown length sequence 11111111...1110000....00000"""


def increase_search(array, start, end):
    print "round"
    if end - start == 1:
        if array[start] == 0:
            return start
        else:
            return end
    if array[start + (end-start)/2] == 1:
        start = start + (end-start)/2
        return increase_search(array, start, end)
    else:
        end = start + (end-start)/2
        return increase_search(array, start, end)


def find_uplimit(array):
    n = 0
    while array[pow(2, n)] == 1:
        print 'round'
        n += 1
    return pow(2, n)


if __name__ == '__main__':
    a1 = [1] * 1000 + [0] * 10000
    #print find_uplimit(a1)
    print increase_search(a1, 0, find_uplimit(a1))
