# ungraded
def listthroughlist(l, inds):
    if not (isinstance(l, list)) or not (isinstance(inds, list)):
        raise Exception
    k = len(l)
    n = len(inds)
    for i in range(0, n):
        if not (isinstance(inds[i], int)):
            raise Exception
        if inds[i] < 0 or inds[i] >= k:
            return None
    r = []
    for i in range(0, n):
        r.append(l[inds[i]])
    return r


# print(f"result = {listthroughlist(['a', 'b', 'c'], [1, 0, 0, 2, 1])}")

# graded

def bubblesort(a):
    if not (isinstance(a, list)):
        raise Exception
    changed = True
    while changed:
        changed = False
        for i in range(0, len(a) - 1):
            if a[i] > a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                changed = True
    return None


a = ['b', 'x', 'a', 'a', 'b', 'e', 'f', 'y']
bubblesort(a)
print(f"a = {a}")
