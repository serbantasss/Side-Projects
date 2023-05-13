# ungraded
def power(b, e):
    if not (isinstance(b, (int, float))) or not (isinstance(e, int)):
        raise Exception
    if e == 0:
        return 1.0
    if e > 0:
        return float(b * power(b, e - 1))
    else:
        return float(power(b, e + 1) / b)


# print(power(4,0))

# graded
def shift_right(a, i1, i2):
    if not (isinstance(a, list)) or not (isinstance(i1, int)) or not (isinstance(i2, int)):
        raise Exception
    if i1 < 0 or i2 < 0 or i1 >= len(a) or i2 >= len(a) or i1 > i2:
        raise Exception
    temp = a[i2]
    for i in range(i2, i1, -1):
        a[i] = a[i - 1]
    a[i1] = temp
    return None


x = ['a', 'b', 'c', 'd', 'e', 'f']
i1 = 1
i2 = 4
shift_right(x, i1, i2)
print(f"a = {x}")
