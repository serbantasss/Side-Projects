## You can edit this file as much as you want,
## it's not used when grading

from Ex2 import RunLengthBuffer

## auxiliary function to check that a function call
## raises an appropriate error
def must_raise(exctype, f, *args):
    goterr = False
    try:
        f(*args)
    except exctype as exc:
        goterr = True
    return goterr

## test task 1
b = RunLengthBuffer()
assert b.buffer == []

del b # cleanup
print("task 1 tests ok")

## test task 2
b = RunLengthBuffer()
b.buffer = [] # ok, check passes
b._check()
b.buffer = [('a', 2), ('b', 5), ('c', 1)] # ok, check passes
b._check()
b.buffer = [('a', 2), ('b', 5), (['hello'], 4), ('c', 1)] # non-string value
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('hello', 4), ('c', 1)] # string value too long
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('', 4), ('c', 1)] # string value too short
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('h', 't'), ('c', 1)] # non-int count
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('h', 0), ('c', 1)] # non-positive count
assert must_raise(AssertionError, b._check)

del b # cleanup
print("task 2 tests ok")


## test task 3
b = RunLengthBuffer()
b.buffer = [] # ok, check passes
b._check()
b.buffer = [('a', 2), ('b', 5), ('c', 1)] # ok, check passes
b._check()
b.buffer = [('a', 2), ('a', 9), ('b', 5), ('c', 1)] # repeated value
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('b', 9), ('c', 1)] # repeated value
assert must_raise(AssertionError, b._check)
b.buffer = [('a', 2), ('b', 5), ('c', 1), ('c', 9)] # repeated value
assert must_raise(AssertionError, b._check)

del b # cleanup
print("task 3 tests ok")


## test task 4
b = RunLengthBuffer()
b.buffer = []
assert len(b) == 0
b.buffer = [('a', 2)]
assert len(b) == 2
b.buffer = [('a', 2), ('b', 5)]
assert len(b) == 7
b.buffer = [('a', 2), ('b', 5), ('c', 1)]
assert len(b) == 8

del b # cleanup
print("task 4 tests ok")


## test task 5
b = RunLengthBuffer()
b.buffer = []
assert repr(b) == "RLB[]"
b.buffer = [('a', 2)]
assert repr(b) == "RLB[aa]"
b.buffer = [('a', 2), ('b', 5)]
assert repr(b) == "RLB[aabbbbb]"
b.buffer = [('a', 2), ('b', 5), ('c', 1)]
assert repr(b) == "RLB[aabbbbbc]"

del b # cleanup
print("task 5 tests ok")


## test task 6
b = RunLengthBuffer()
b.buffer = []
b.add('a')
assert b.buffer == [('a', 1)]
b.add('a')
assert b.buffer == [('a', 2)]
b.add('b')
assert b.buffer == [('a', 2), ('b', 1)]
for i in range(4):
    b.add('b')
assert b.buffer == [('a', 2), ('b', 5)]
b.add('c')
assert b.buffer == [('a', 2), ('b', 5), ('c', 1)]
b.add('a')
assert b.buffer == [('a', 2), ('b', 5), ('c', 1), ('a', 1)]
b.add('a')
assert b.buffer == [('a', 2), ('b', 5), ('c', 1), ('a', 2)]

assert must_raise(TypeError, b.add, 5) # non-string value
assert must_raise(TypeError, b.add, ['a']) # non-string value
assert must_raise(ValueError, b.add, '') # value too short
assert must_raise(ValueError, b.add, 'hello') # value too long

del b # cleanup
print("task 6 tests ok")

## test task 7
b = RunLengthBuffer()
b.buffer = []
assert must_raise(Exception, b.get)
b.buffer = [('a', 2), ('b', 5), ('c', 1), ('a', 2)]
assert b.get() == 'a'
assert b.buffer == [('a', 1), ('b', 5), ('c', 1), ('a', 2)]
assert b.get() == 'a'
assert b.buffer == [('b', 5), ('c', 1), ('a', 2)]
assert b.get() == 'b'
assert b.buffer == [('b', 4), ('c', 1), ('a', 2)]
assert b.get() == 'b'
assert b.buffer == [('b', 3), ('c', 1), ('a', 2)]
assert b.get() == 'b'
assert b.buffer == [('b', 2), ('c', 1), ('a', 2)]
assert b.get() == 'b'
assert b.buffer == [('b', 1), ('c', 1), ('a', 2)]
assert b.get() == 'b'
assert b.buffer == [('c', 1), ('a', 2)]
assert b.get() == 'c'
assert b.buffer == [('a', 2)]
assert b.get() == 'a'
assert b.buffer == [('a', 1)]
assert b.get() == 'a'
assert b.buffer == []
assert must_raise(Exception, b.get)

del b # cleanup
print("task 7 tests ok")


## test task 8
b = RunLengthBuffer()
b.buffer = []
assert 'a' not in b
assert 'b' not in b
b.buffer = [('a', 2), ('b', 5), ('c', 1), ('a', 2)]
assert 'a' in b
assert 'b' in b
assert 'c' in b
assert 'd' not in b
assert 'hello' not in b
assert 1 not in b

del b # cleanup
print("task 8 tests ok")

print("done")