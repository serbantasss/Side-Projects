## You can edit this file as much as you want,
## it's not used when grading

from Ex2 import Polynomial

import sys
import traceback

## auxiliary function to check that a function call
## raises an appropriate error
def must_raise(exctype, f, *args):
    got_exc = None
    try:
        f(*args)
    except exctype as exc:
        got_exc = exc
    except Exception as exc:
        raise Exception(f"was expecting a {exctype.__name__}, got a {type(exc).__name__} instead") from exc
    if got_exc is None:
        raise Exception(f"No exception raised, was expecting a {exctype.__name__}")
    return got_exc

## keep track of which tasks are failing,
## to print a message at the end
failed_tasks = []

## test task 1
print("testing task 1")
try:
    p = Polynomial([])
    assert p.coeffs == []
    p = Polynomial([0])
    assert p.coeffs == [0]
    p = Polynomial([3, 1, 2])
    assert p.coeffs == [3, 1, 2]
    p = Polynomial(i**2 for i in range(4))
    assert p.coeffs == [0, 1, 4, 9]
    p = Polynomial(None)
    assert p.coeffs == []
    p = Polynomial()
    assert p.coeffs == []

    del p # cleanup
    print("task 1 tests ok")
except:
    failed_tasks.append(1)
    print("task 1 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 2
print("testing task 2")
try:
    p = Polynomial([])
    assert p.coeffs == []
    p = Polynomial([0])
    assert p.coeffs == [0]
    p = Polynomial([3, 1, 2])
    assert p.coeffs == [3, 1, 2]
    p = Polynomial(i**2 for i in range(4))
    assert p.coeffs == [0, 1, 4, 9]
    must_raise(TypeError, Polynomial, ['a'])
    must_raise(TypeError, Polynomial, ['a', 'b'])
    must_raise(TypeError, Polynomial, ['a', 'b', 'c'])
    must_raise(TypeError, Polynomial, ['a', 2])
    must_raise(TypeError, Polynomial, [1, 'b'])
    must_raise(TypeError, Polynomial, ['a', 2, 3])
    must_raise(TypeError, Polynomial, [1, 'b', 3])
    must_raise(TypeError, Polynomial, [1, 2, 'c'])
    must_raise(TypeError, Polynomial, ['a', 'b', 3])
    must_raise(TypeError, Polynomial, ['a', 2, 'c'])
    must_raise(TypeError, Polynomial, [1, 'b', 'c'])
    must_raise(TypeError, Polynomial, [1.0])
    must_raise(TypeError, Polynomial, [1, 2.0, 3])
    must_raise(TypeError, Polynomial, [1, 2.0, 'c'])
    p = Polynomial([False]) # bool is a sub-class of int, thus False is an int
    assert p.coeffs == [0]
    p = Polynomial([0, True])
    assert p.coeffs == [0, 1]

    del p # cleanup
    print("task 2 tests ok")
except:
    failed_tasks.append(2)
    print("task 2 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 3
print("testing task 3")
try:
    p = Polynomial([4, -1]) # 4-x
    assert p.evaluate(0) == 4
    assert p.evaluate(1) == 3
    assert p.evaluate(-1) == 5
    assert p.evaluate(2) == 2
    assert p.evaluate(-2) == 6
    assert p.evaluate(4) == 0
    assert p.evaluate(8) == -4

    p = Polynomial([1])
    for x in range(-10, 11):
        assert p.evaluate(x) == 1

    p = Polynomial([0])
    for x in range(-10, 11):
        assert p.evaluate(x) == 0

    p = Polynomial([])
    for x in range(-10, 11):
        assert p.evaluate(x) == 0

    p = Polynomial([1, 0])
    for x in range(-10, 11):
        assert p.evaluate(x) == 1

    p = Polynomial([0, 1])
    for x in range(-10, 11):
        assert p.evaluate(x) == x

    p = Polynomial([3, -1, 0, 8])
    for x in range(-10, 11):
        assert p.evaluate(x) == 3 - x + 8 * x**3

    print("task 3 tests ok")
except:
    failed_tasks.append(3)
    print("task 3 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 4
print("testing task 4")
try:
    p = Polynomial([3, 1, 2])
    q = Polynomial([3, 1, 2])
    assert p == q
    assert q == p
    q = Polynomial([3, 1, 2, 0])
    assert p == q
    assert q == p
    q = Polynomial([3, 1, 2, 0, 0])
    assert p == q
    assert q == p
    q = Polynomial([2, 1, 2, 0, 0])
    assert p != q
    assert q != p
    q = Polynomial([3, 0, 2, 0, 0])
    assert p != q
    assert q != p
    q = Polynomial([3, 1, 2, 0, 0, 8])
    assert p != q
    assert q != p

    p = Polynomial([0, 0, 2])
    q = Polynomial([0, 0, 2])
    assert p == q
    assert q == p
    q = Polynomial([0, 0, 2, 0])
    assert p == q
    assert q == p
    q = Polynomial([0, 0, 2, 0, 0])
    assert p == q
    assert q == p
    q = Polynomial([0, 0, 2, 0, 0, 0, 0, 0])
    assert p == q
    assert q == p

    p = Polynomial([])
    q = Polynomial([0])
    assert p == q
    assert q == p
    q = Polynomial([0, 0])
    assert p == q
    assert q == p
    q = Polynomial([0, 0, 0])
    assert p == q
    assert q == p
    q = Polynomial([0, 0, 0, 0, 0, 0])
    assert p == q
    assert q == p
    q = Polynomial([1])
    assert p != q
    assert q != p
    q = Polynomial([0, 1])
    assert p != q
    assert q != p
    q = Polynomial([1, 1])
    assert p != q
    assert q != p
    q = Polynomial([0, 0, 0, 1])
    assert p != q
    assert q != p
    q = Polynomial([1, 0, 0, 0])
    assert p != q
    assert q != p
    q = Polynomial([0, 0, 1, 0])
    assert p != q
    assert q != p

    r = (p == [0, 1]) # Python must return False
    assert r is False
    r = p.__eq__([0, 1]) # this must not directly return False
    assert r is not False

    r = (p == None) # Python must return False
    assert r is False
    r = p.__eq__(None) # this must not directly return False
    assert r is not False

    del p, q, r # cleanup
    print("task 4 tests ok")
except:
    failed_tasks.append(4)
    print("task 4 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 5
print("testing task 5")
try:
    ## Polynomial * int
    p = Polynomial([3, 1, 2])
    q = p * 1
    assert type(q) == Polynomial
    assert q.coeffs == [3, 1, 2]
    q = p * 2
    assert type(q) == Polynomial
    assert q.coeffs == [6, 2, 4]
    q = p * (-1)
    assert type(q) == Polynomial
    assert q.coeffs == [-3, -1, -2]

    p = Polynomial([])
    q = p * 1
    assert type(q) == Polynomial
    assert q.coeffs == []
    q = p * (-1000)
    assert type(q) == Polynomial
    assert q.coeffs == []

    p = Polynomial([0, 2, 3, 0])
    q = p * 1
    assert type(q) == Polynomial
    assert q.coeffs == [0, 2, 3, 0]
    q = p * 3
    assert type(q) == Polynomial
    assert q.coeffs == [0, 6, 9, 0]
    q = p * (-5)
    assert type(q) == Polynomial
    assert q.coeffs == [0, -10, -15, 0]
    q = p * True # note: True is an int because bool is a sub-type of int
    assert type(q) == Polynomial
    assert q.coeffs == [0, 2, 3, 0]

    ## Polynomial * (non-int)
    p = Polynomial([2, 5, 1])
    got_err = False
    try:
        q = p * 2.5
    except TypeError: # Python must produce a TypeError, based on what your method *returns*!
        got_err = True
    assert got_err

    got_err = False
    try:
        q = p * '3'
    except TypeError: # Python must produce a TypeError, based on what your method *returns*!
        got_err = True
    assert got_err

    ## int * Polynomial
    p = Polynomial([3, 1, 2])
    q = 1 * p
    assert type(q) == Polynomial
    assert q.coeffs == [3, 1, 2]
    q = 2 * p
    assert type(q) == Polynomial
    assert q.coeffs == [6, 2, 4]
    q = (-1) * p
    assert type(q) == Polynomial
    assert q.coeffs == [-3, -1, -2]
    q = True * p # note: True is an int because bool is a sub-type of int
    assert type(q) == Polynomial
    assert q.coeffs == [3, 1, 2]

    del p, q, got_err # cleanup
    print("task 5 tests ok")
except:
    failed_tasks.append(5)
    print("task 5 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 6
print("testing task 6")
try:
    p = Polynomial([1])
    assert p.degree() == 0
    p = Polynomial([1, 1])
    assert p.degree() == 1
    p = Polynomial([1, -1, 0, 5])
    assert p.degree() == 3
    p = Polynomial([1, -1, 5, 0])
    assert p.degree() == 2
    p = Polynomial([1, -1, -5, 0])
    assert p.degree() == 2
    p = Polynomial([0, 0, 5, 0])
    assert p.degree() == 2
    p = Polynomial([0, 0, -5, 0])
    assert p.degree() == 2
    p = Polynomial([-1, 0, 0, 0])
    assert p.degree() == 0
    p = Polynomial([0])
    assert p.degree() == 0
    p = Polynomial([0, 0])
    assert p.degree() == 0
    p = Polynomial([])
    assert p.degree() == 0

    del p # cleanup
    print("task 6 tests ok")
except:
    failed_tasks.append(6)
    print("task 6 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 7
print("testing task 7")
try:
    p = Polynomial([1])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [1]
    assert p.coeffs is old_coeffs

    p = Polynomial([1, 1])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [1, 1]
    assert p.coeffs is old_coeffs

    p = Polynomial([1, -1, 0, 5])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [1, -1, 0, 5]
    assert p.coeffs is old_coeffs

    p = Polynomial([1, -1, 5, 0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [1, -1, 5]
    assert p.coeffs is old_coeffs
    p.normalize()
    assert p.coeffs == [1, -1, 5]
    assert p.coeffs is old_coeffs

    p = Polynomial([0, 0, 5, 0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [0, 0, 5]
    assert p.coeffs is old_coeffs

    p = Polynomial([0, 0, -5, 0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [0, 0, -5]
    assert p.coeffs is old_coeffs

    p = Polynomial([-1, 0, 0, 0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == [-1]
    assert p.coeffs is old_coeffs

    p = Polynomial([0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == []
    assert p.coeffs is old_coeffs

    p = Polynomial([0, 0])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == []
    assert p.coeffs is old_coeffs

    p = Polynomial([])
    old_coeffs = p.coeffs
    p.normalize()
    assert p.coeffs == []
    assert p.coeffs is old_coeffs

    del p, old_coeffs # cleanup
    print("task 7 tests ok")
except:
    failed_tasks.append(7)
    print("task 7 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 8
print("testing task 8")
try:
    p = Polynomial([3])
    assert repr(p) == "3"
    p = Polynomial([3, 4])
    assert repr(p) == "3+4x"
    p = Polynomial([3, 4, 5])
    assert repr(p) == "3+4x+5x^2"
    p = Polynomial([3, 4, 5, 6])
    assert repr(p) == "3+4x+5x^2+6x^3"
    p = Polynomial([0, 4, 5, 6])
    assert repr(p) == "4x+5x^2+6x^3"
    p = Polynomial([3, 0, 5, 6])
    assert repr(p) == "3+5x^2+6x^3"
    p = Polynomial([3, 4, 0, 6])
    assert repr(p) == "3+4x+6x^3"
    p = Polynomial([3, 4, 5, 0])
    assert repr(p) == "3+4x+5x^2"
    p = Polynomial([3, 0, 0, 6])
    assert repr(p) == "3+6x^3"
    p = Polynomial([0, 0, 0, 6])
    assert repr(p) == "6x^3"

    p = Polynomial([-3])
    assert repr(p) == "(-3)"
    p = Polynomial([-3, -4])
    assert repr(p) == "(-3)+(-4)x"
    p = Polynomial([-3, 4, -5])
    assert repr(p) == "(-3)+4x+(-5)x^2"
    p = Polynomial([3, -4, 5, -6])
    assert repr(p) == "3+(-4)x+5x^2+(-6)x^3"

    p = Polynomial([0])
    assert repr(p) == "0"
    p = Polynomial([])
    assert repr(p) == "0"

    p = Polynomial([3, 1])
    assert repr(p) == "3+x"
    p = Polynomial([3, 1, 5])
    assert repr(p) == "3+x+5x^2"
    p = Polynomial([3, 4, 1, 6])
    assert repr(p) == "3+4x+x^2+6x^3"
    p = Polynomial([0, 4, 5, 1])
    assert repr(p) == "4x+5x^2+x^3"
    p = Polynomial([1, 0, 0, 1])
    assert repr(p) == "1+x^3"
    p = Polynomial([1, -1, 0, 6])
    assert repr(p) == "1+(-1)x+6x^3"
    p = Polynomial([1, 0, 0, 0])
    assert repr(p) == "1"
    p = Polynomial([0, 0, 0, 1])
    assert repr(p) == "x^3"

    del p # cleanup
    print("task 8 tests ok")
except:
    failed_tasks.append(8)
    print("task 8 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 9
print("testing task 9")
try:
    p = Polynomial([3, 1, 2])
    q = Polynomial([1, 0, 1])
    r = p + q
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs
    r = q + p
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs

    p = Polynomial([3, 1, 2, 5])
    q = Polynomial([1, 0, 1])
    r = p + q
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3, 5]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs
    r = q + p
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3, 5]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs

    p = Polynomial([3, 1, 2, 5])
    q = Polynomial([1, 0, 1, -5, 8])
    r = p + q
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3, 0, 8]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs
    r = q + p
    assert type(r) == Polynomial
    assert r.coeffs == [4, 1, 3, 0, 8]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs

    p = Polynomial([])
    q = Polynomial([1, 0, 1, -5, 8])
    r = p + q
    assert type(r) == Polynomial
    assert r.coeffs == [1, 0, 1, -5, 8]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs
    r = q + p
    assert type(r) == Polynomial
    assert r.coeffs == [1, 0, 1, -5, 8]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs

    p = Polynomial([3, -3, -5])
    q = Polynomial([-3, 3, 5])
    r = p + q
    assert type(r) == Polynomial
    assert r.coeffs == [0, 0, 0]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs
    r = q + p
    assert type(r) == Polynomial
    assert r.coeffs == [0, 0, 0]
    assert r is not p and r is not q and r.coeffs is not p.coeffs and r.coeffs is not q.coeffs

    p = Polynomial([3, -3, -5])
    got_err = False
    try:
        r = p + 2.5
    except TypeError: # Python must produce a TypeError, based on what your method *returns*!
        got_err = True
    assert got_err

    p = Polynomial([3, -3, -5])
    got_err = False
    try:
        r = p + [1, 2, 3]
    except TypeError: # Python must produce a TypeError, based on what your method *returns*!
        got_err = True
    assert got_err

    del p, q, r # cleanup
    print("task 9 tests ok")
except:
    failed_tasks.append(9)
    print("task 9 failed:")
    traceback.print_exc(file=sys.stdout)
print()


if len(failed_tasks) == 0:
    print("done, all tests ok")
else:
    print(f"done, failed tasks: {failed_tasks}")
