from python_sharing import Vec2D, Scooter, SharingService, SSUser

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
    ## test Scooter constructor
    s0 = Scooter(1.0, 0.0)
    assert s0.user is None
    assert isinstance(s0.pos, Vec2D) and s0.pos.x == 1.0 and s0.pos.y == 0.0

    del s0 # cleanup
    print("task 1 tests ok")
except:
    failed_tasks.append(1)
    print("task 1 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 2
print("testing task 2")
try:
    ## test Scooter.isfree
    s0 = Scooter(1.0, 0.0)
    assert s0.isfree()
    s0.user = "FAKE!"
    assert not s0.isfree()

    del s0 # cleanup
    print("task 2 tests ok")
except:
    failed_tasks.append(2)
    print("task 2 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 3
print("testing task 3")
try:
    ## test Scooter printing
    s0 = Scooter(1.0, 0.0)
    assert str(s0) == "Scooter(V[1.0, 0.0], True)"
    s0.user = "FAKE!"
    assert str(s0) == "Scooter(V[1.0, 0.0], False)"

    del s0 # cleanup
    print("task 3 tests ok")
except:
    failed_tasks.append(3)
    print("task 3 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 4
print("testing task 4")
try:
    ## test SharingService constructor
    ss = SharingService([(1,0), (0,2), (-2,1)])
    assert isinstance(ss.scooters, list)
    assert len(ss.scooters) == 3
    for s in ss.scooters:
        assert isinstance(s, Scooter)
        assert s.isfree()
        p = s.pos
        assert isinstance(p, Vec2D)
    assert [(s.pos.x,s.pos.y) for s in ss.scooters] == [(1,0), (0,2), (-2,1)]

    del ss # cleanup
    print("task 4 tests ok")
except:
    failed_tasks.append(4)
    print("task 4 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 5
print("testing task 5")
try:
    ## test SharingService printing
    ss = SharingService([(1,0), (0,2), (-2,1)])
    assert str(ss) == "SS([Scooter(V[1.0, 0.0], True), Scooter(V[0.0, 2.0], True), Scooter(V[-2.0, 1.0], True)])"

    del ss # cleanup
    print("task 5 tests ok")
except:
    failed_tasks.append(5)
    print("task 5 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 6
print("testing task 6")
try:
    ## test SSUser constructor
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    assert u1.service is ss
    assert isinstance(u1.pos, Vec2D) and u1.pos.x == 0 and u1.pos.y == 0

    del ss, u1 # cleanup
    print("task 6 tests ok")
except:
    failed_tasks.append(6)
    print("task 6 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 7
print("testing task 7")
try:
    ## test SSUser printing
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    assert str(u1) == "SSUser(pos=V[0.0, 0.0], scooter=None)"
    u1.scooter = ss.scooters[0]
    assert str(u1) == "SSUser(pos=V[0.0, 0.0], scooter=Scooter(V[1.0, 0.0], True))"

    del ss, u1 # cleanup
    print("task 7 tests ok")
except:
    failed_tasks.append(7)
    print("task 7 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 8
print("testing task 8")
try:
    ## test SharingService.free_scooters
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    u2 = SSUser(ss, (5,1))
    u3 = SSUser(ss, (6,3))
    u4 = SSUser(ss, (-1,-1))
    assert ss.free_scooters() == ss.scooters
    ss.scooters[0].user = u1
    assert ss.free_scooters() == ss.scooters[1:]
    ss.scooters[2].user = u2
    assert ss.free_scooters() == [ss.scooters[1]]
    ss.scooters[0].user = None
    assert ss.free_scooters() == ss.scooters[:2]
    ss.scooters[2].user = None
    assert ss.free_scooters() == ss.scooters

    del ss, u1, u2, u3, u4 # cleanup
    print("task 8 tests ok")
except:
    failed_tasks.append(8)
    print("task 8 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 9
print("testing task 9")
try:
    ## test SharingService.closest_scooter
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    ss.scooters[1].user = u1
    assert ss.closest_scooter(Vec2D(0.5, 0)) == ss.scooters[0]
    assert ss.closest_scooter(Vec2D(0, 1.5)) == ss.scooters[0]
    assert ss.closest_scooter(Vec2D(-3.0, 3.0)) == ss.scooters[2]
    ss.scooters[1].user = None
    assert ss.closest_scooter(Vec2D(0, 1.5)) == ss.scooters[1]

    del ss, u1 # cleanup
    print("task 9 tests ok")
except:
    failed_tasks.append(9)
    print("task 9 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 10
print("testing task 10")
try:
    ## test SSUser.take_scooter
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    u2 = SSUser(ss, (5,1))
    u3 = SSUser(ss, (6,3))
    u4 = SSUser(ss, (-1,-1))

    u1.take_scooter()
    assert u1.scooter is ss.scooters[0]
    assert ss.scooters[0].user is u1
    assert not ss.scooters[0].isfree()
    assert u1.pos == Vec2D(1,0)
    must_raise(Exception, u1.take_scooter)

    u2.take_scooter()
    assert u2.scooter is ss.scooters[1]
    assert ss.scooters[1].user is u2
    assert not ss.scooters[1].isfree()
    assert u2.pos == Vec2D(0,2)

    u3.take_scooter()
    assert u3.scooter is ss.scooters[2]
    assert ss.scooters[2].user is u3
    assert not ss.scooters[2].isfree()
    assert u3.pos == Vec2D(-2,1)

    must_raise(Exception, u4.take_scooter)

    del ss, u1, u2, u3, u4 # cleanup
    print("task 10 tests ok")
except:
    failed_tasks.append(10)
    print("task 10 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 11
print("testing task 11")
try:
    ## test SSUser.use_scooter
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    u2 = SSUser(ss, (5,1))
    u3 = SSUser(ss, (6,3))
    u4 = SSUser(ss, (-1,-1))
    u1.take_scooter()
    u2.take_scooter()
    u3.take_scooter()

    u1.use_scooter(Vec2D(-2,9))
    assert u1.pos == Vec2D(-2,9)
    assert ss.scooters[0].pos == Vec2D(-2,9)
    assert u1.scooter is None
    assert ss.scooters[0].user is None
    assert ss.scooters[0].isfree()
    assert ss.free_scooters() == [ss.scooters[0]]

    must_raise(Exception, u4.use_scooter, Vec2D(2,2))

    u4.take_scooter()
    assert u4.scooter is ss.scooters[0]
    assert ss.scooters[0].user is u4
    assert not ss.scooters[0].isfree()
    assert u4.pos == Vec2D(-2, 9)
    u4.use_scooter(Vec2D(0,0))
    assert u4.pos == Vec2D(0,0)
    assert ss.scooters[0].pos == Vec2D(0,0)
    assert u4.scooter is None
    assert ss.scooters[0].user is None
    assert ss.scooters[0].isfree()

    del ss, u1, u2, u3, u4 # cleanup
    print("task 11 tests ok")
except:
    failed_tasks.append(11)
    print("task 11 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 12
print("testing task 12")
try:
    ## test SSUser.take_scooter
    ss = SharingService([(1,0), (0,2), (-2,1)])
    u1 = SSUser(ss, (0,0))
    u2 = SSUser(ss, (5,1))
    u3 = SSUser(ss, (6,3))
    u4 = SSUser(ss, (-1,-1))

    from python_sharing import NonFreeUserError, NoFreeScootersError, UserNotOnScooterError

    u1.take_scooter()
    must_raise(NonFreeUserError, u1.take_scooter)
    u2.take_scooter()
    u3.take_scooter()
    must_raise(NoFreeScootersError, u4.take_scooter)
    must_raise(UserNotOnScooterError, u4.use_scooter, Vec2D(1,0))

    del ss, u1, u2, u3, u4 # cleanup
    print("task 12 tests ok")
except:
    failed_tasks.append(12)
    print("task 12 failed:")
    traceback.print_exc(file=sys.stdout)
print()

if len(failed_tasks) == 0:
    print("done, all tests ok")
else:
    print(f"done, failed tasks: {failed_tasks}")
