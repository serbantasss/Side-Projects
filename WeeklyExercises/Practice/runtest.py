## You can edit this file as much as you want,
## it's not used when grading

from ex import IntSet

## test task 1
s = IntSet(5)
assert len(s) == 0
s.add(2)
assert len(s) == 1
s.add(4)
assert len(s) == 2
s.add(2)
assert len(s) == 2
s.add(0)
assert len(s) == 3
s.add(1)
assert len(s) == 4
s.add(4)
assert len(s) == 4
s.add(3)
assert len(s) == 5

del s # cleanup
print("task 1 tests ok")


## test task 2
s = IntSet(5)
s.add(2)
assert s.mask == [False, False, True, False, False]
assert s.n == 1
s.remove(2)
assert s.mask == [False, False, False, False, False]
assert s.n == 0
s.add(2)
s.add(3)
s.add(0)
assert s.mask == [True, False, True, True, False]
assert s.n == 3
s.remove(3)
s.remove(0)
assert s.mask == [False, False, True, False, False]
assert s.n == 1
s.add(4)
assert s.mask == [False, False, True, False, True]
assert s.n == 2
goterr = False
try:
    s.remove(0)
except KeyError as exc:
    assert exc.args == (0,)
    goterr = True
assert goterr
goterr = False
try:
    s.remove(3)
except KeyError as exc:
    assert exc.args == (3,)
    goterr = True
assert goterr
goterr = False
try:
    s.remove(-1)
except ValueError:
    goterr = True
assert goterr
goterr = False
try:
    s.remove(10)
except ValueError:
    goterr = True
assert goterr
goterr = False
try:
    s.remove('hello')
except TypeError:
    goterr = True
assert goterr

del s # cleanup
del goterr # cleanup
print("task 2 tests ok")


## test task 3
s = IntSet(5)
s.mask = [True, False, True, False, True]
s.n = 3
assert 0 in s
assert 1 not in s
assert 2 in s
assert 3 not in s
assert 4 in s
assert -1 not in s
assert 5 not in s
assert True not in s # no error because isinstance(True, int) == True

goterr = False
try:
    1.0 not in s
except TypeError:
    goterr = True
assert goterr
goterr = False
try:
    'hello' not in s
except TypeError:
    goterr = True
assert goterr

del s # cleanup
print("task 3 tests ok")


## test task 4
s = IntSet(5)
goterr = False
try:
    x = s.pop_rand()
except KeyError:
    goterr = True
assert goterr
s.add(2)
x = s.pop_rand()
assert x == 2
assert s.mask == [False, False, False, False, False]
assert s.n == 0

s.mask = [True, False, True, False, True]
s.n = 3
import random
random.seed(5723)
ss = set()
ss.add(s.pop_rand())
ss.add(s.pop_rand())
ss.add(s.pop_rand())
assert ss == {0, 2, 4}
assert s.mask == [False, False, False, False, False]
assert s.n == 0

del s # cleanup
del goterr # cleanup
print("task 4 tests ok")

## test task 5
s = IntSet(5)
assert repr(s) == '{}'

s.mask = [False, False, True, False, False]
s.n = 1
assert repr(s) == '{2}'

s.mask = [True, False, True, False, True]
s.n = 3
assert repr(s) == '{0, 2, 4}'

s.mask = [True, False, True, True, False]
s.n = 3
assert repr(s) == '{0, 2, 3}'

del s # cleanup
print("task 5 tests ok")
print("done")
