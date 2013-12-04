#! /usr/bin/env python
"""version writen by langge"""

if __name__ == '__main__':
    a = [1] * 1000 + [0] * 10000
    step = 2
    i, j, k = 0, 0, 0
    while True:
        if a[i] == 1 and a[i+1] == 0:
            print i+1
            break
        elif a[i] == 1:
            i += step**k
            k += 1
            j = 0
            print 'i=%d' % i, 'k= %d' % k
        elif a[i] == 0:
            k = 0
            i -= step**j
            j += 1
            print 'i=%d' % i, 'k=%d' % k
