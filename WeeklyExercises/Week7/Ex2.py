# ungraded
def baselpi(n):
    if (isinstance(n, int) == 0) or (n <= 0):
        raise Exception("NOT positive int")
    s = 0
    for i in range(1, n + 1):
        s += 1 / (i * i)
    return (6 * s) ** 0.5


# print(baselpi(-1))
# graded

def dot_product(a1, a2):
    if not (isinstance(a1, list)) or not (isinstance(a2, list)):
        raise Exception
    if len(a1) != len(a2):
        raise Exception
    n = len(a1)
    r = 0
    for i in range(n):
        r += (a1[i] * a2[i])
    return r

a1 = []
a2 = []
r = dot_product(a1, a2)
print(f"result = {r}")
