from sports_league import SportsLeague

import sys
import traceback
from contextlib import redirect_stdout
import io

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

## another auxiliary function to inspect what gets printed
def grabstdout(f, *args):
    s = io.StringIO()
    with redirect_stdout(s):
        r = f(*args)
    return s.getvalue(), r

## keep track of which tasks are failing,
## to print a message at the end
failed_tasks = []

## test task 1
print("testing task 1")
try:
    league = SportsLeague("The Calvinball World League")
    assert league.teams == {}
    assert league.leaguename == "The Calvinball World League"
    must_raise(TypeError, SportsLeague, 43)
    must_raise(ValueError, SportsLeague, "")

    del league # cleanup
    print("task 1 tests ok")
except:
    failed_tasks.append(1)
    print("task 1 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 2
print("testing task 2")
try:
    league = SportsLeague("The Calvinball World League")
    assert len(league) == 0
    league.teams = {'A':1.0}
    assert len(league) == 1
    league.teams = {'A':1.0, 'B':2.0}
    assert len(league) == 2

    del league # cleanup
    print("task 2 tests ok")
except:
    failed_tasks.append(2)
    print("task 2 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 3
print("testing task 3")
try:
    league = SportsLeague("The Calvinball World League")
    assert league.teams == {}
    league.addteam("Shorts",  0.9)
    assert league.teams == {"Shorts": 0.9}
    league.addteam("Talls",   1.5)
    assert league.teams == {"Shorts": 0.9, "Talls": 1.5}
    league.addteam("Olds",    0.5)
    assert league.teams == {"Shorts": 0.9, "Talls": 1.5, "Olds": 0.5}
    league.addteam("Mutants", 2.0)
    assert league.teams == {"Shorts": 0.9, "Talls": 1.5, "Olds": 0.5, "Mutants": 2.0}

    must_raise(ValueError, league.addteam, "A", "B") # → fail attempting to convert "B" to a float
    must_raise(ValueError, league.addteam, "", 2.0)  # → ValueError (empty name)
    must_raise(ValueError, league.addteam, "A", 0.0) # → ValueError (non-positive strength)
    must_raise(KeyError, league.addteam, "Talls", 1.5) # → KeyError (already there)

    league.addteam("Talls", 1.0, True) # force=True → overwrite
    assert league.teams == {'Shorts': 0.9, 'Talls': 1.0, 'Olds': 0.5, 'Mutants': 2.0}

    del league # cleanup
    print("task 3 tests ok")
except:
    failed_tasks.append(3)
    print("task 3 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 4
print("testing task 4")
try:
    from sports_league import dictranking
    assert dictranking({"a": 2, "b": 5, "c": 3}) == ["b", "c", "a"]
    assert dictranking({"a": 2, "b": 5, "c": 1}) == ["b", "a", "c"]
    assert dictranking({"a": 8, "b": 5, "c": 1}) == ["a", "b", "c"]

    print("task 4 tests ok")
except:
    failed_tasks.append(4)
    print("task 4 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 5
print("testing task 5")
try:
    league = SportsLeague("The Calvinball World League")
    league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}
    assert list(filter(lambda x: len(x)>0, map(lambda x: x.rstrip(), str(league).splitlines()))) == \
        ["The Calvinball World League:", " * Mutants: 2.0", " * Talls: 1.5", " * Shorts: 0.9", " * Olds: 0.5"]

    del league # cleanup
    print("task 5 tests ok")
except:
    failed_tasks.append(5)
    print("task 5 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 6
print("testing task 6")
try:
    league = SportsLeague("The Calvinball World League")
    league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}
    assert league._strength('Olds', False) == 0.5
    assert league._strength('Olds', True) == 0.6
    assert league._strength('Mutants', False) == 2.0
    assert league._strength('Mutants', True) == 2.4

    del league # cleanup
    print("task 6 tests ok")
except:
    failed_tasks.append(6)
    print("task 6 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 7
print("testing task 7")
try:
    league = SportsLeague("The Calvinball World League")
    league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}

    h1 = [0, 0, 0]
    h2 = [0, 0, 0, 0, 0]
    t = 1000
    for n in range(t):
        s1, s2 = league.match('Olds', 'Mutants')
        assert 0 <= s1 <= 2
        assert 0 <= s2 <= 4
        h1[s1] += 1/t
        h2[s2] += 1/t
    assert all(map(lambda x: 0.25 <= x <= 0.41, h1))
    assert all(map(lambda x: 0.13 <= x <= 0.27, h2))

    h1 = [0, 0, 0, 0, 0, 0]
    h2 = [0, 0]
    t = 1000
    for n in range(t):
        s1, s2 = league.match('Mutants', 'Olds')
        assert 0 <= s1 <= 5
        assert 0 <= s2 <= 1
        h1[s1] += 1/t
        h2[s2] += 1/t
    assert all(map(lambda x: 0.10 <= x <= 0.23, h1))
    assert all(map(lambda x: 0.42 <= x <= 0.58, h2))

    del league, h1, h2, t, n, s1, s2 # cleanup
    print("task 7 tests ok")
except:
    failed_tasks.append(7)
    print("task 7 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 8
print("testing task 8")
try:
    league = SportsLeague("The Calvinball World League")
    league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}

    for i in range(10):
        results = league.tournament()
        assert type(results) == dict
        assert results.keys() == league.teams.keys()
        for n,l in results.items():
            assert type(l) == list
            assert len(l) == 3
            for y in l:
                assert type(y) == int
                assert 0 <= y <= 6
            assert sum(l) == 6

        totw, totl, totd = 0, 0, 0
        for n,l in results.items():
            totw += l[0]
            totd += l[1]
            totl += l[2]

        assert totw == totl
        assert totw + totl + totd == 24


    del league, results, totw, totd, totl, i, n, l, y # cleanup
    print("task 8 tests ok")
except:
    failed_tasks.append(8)
    print("task 8 failed:")
    traceback.print_exc(file=sys.stdout)
print()

## test task 9
print("testing task 9")
try:
    from sports_league import getpoints
    assert getpoints([2, 3, 4]) == 9
    assert getpoints([1, 0, 2]) == 3
    assert getpoints([0, 5, 8]) == 5

    from sports_league import analyze_results
    results = {'Shorts': [1, 2, 3], 'Talls': [2, 1, 3], 'Olds': [2, 2, 2], 'Mutants': [4, 1, 1]}
    s, r = grabstdout(analyze_results, results)
    assert r is None
    assert s == "Tournament results:\nMutants 13\nOlds 8\nTalls 7\nShorts 5\n"

    del results, s, r # cleanup
    print("task 9 tests ok")
except:
    failed_tasks.append(9)
    print("task 9 failed:")
    traceback.print_exc(file=sys.stdout)
print()


## test task 10
print("testing task 10")
try:
    league = SportsLeague("The Calvinball World League")
    league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}

    for n in [1, 10, 100, 1000]:
        r = league.odds(n)
        assert type(r) == dict
        assert r.keys() == league.teams.keys()
        for l in r.values():
            assert type(l) == list
            assert len(l) == len(league.teams)
            assert abs(sum(l) - 1) < 1e-12
        for i in range(len(league.teams)):
            s = 0.0
            for l in r.values():
                s += l[i]
            assert abs(s - 1) < 1e-12
        if n == 1000:
            assert sorted(r, key=lambda k: r[k][0]) == ['Olds', 'Shorts', 'Talls', 'Mutants']

    del league, n, r, l, i, s # cleanup
    print("task 10 tests ok")
except:
    failed_tasks.append(10)
    print("task 10 failed:")
    traceback.print_exc(file=sys.stdout)
print()

if len(failed_tasks) == 0:
    print("done, all tests ok")
else:
    print(f"done, failed tasks: {failed_tasks}")
