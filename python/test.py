#!/usr/bin/python

import sys

def sayHello():
    print 'Hello world!'

def func(x):
    print 'x is', x
    
    x = 20
    print 'change local x to', x

def say(message, times = 2):
    print message * times

def keyparam(a, b, c = 10):
    '''key parameter.
    test for DocStrings
    call the function by key paramter'''

    print 'a is',a, 'b is', b, 'c is', c

i = 5
func(i)
print 'i is stil',i
sayHello()
say('hello')
say('world', 5)

keyparam(5, 3)
keyparam(c = 90, a = 30, b = 100)
print keyparam.__doc__
#help(keyparam)

for i in sys.argv:
    print i

print '\n\npython path is:\n', sys.path
