# practice
def tupsort(l, k):
    return l.sort(key=lambda x: x[k])


# graded
def longest_without_x(it):
    return max([elem for elem in it if 'x' not in elem.lower()], key=lambda x: len(x), default=None)


pula = ['ama','MAre']

print(pula[1].lower())
print(pula)