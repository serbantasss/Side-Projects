#ungraded
def deeptan(l):
    from math import sin,atan,pi
    mata=[[atan(sin(2*l[0][0]/pi))]+l[0][1:len(l[0])]]
    return mata+l[1:len(l)]

l = [[0.5, 0.2], [0.3, 0.4]]
r = deeptan(l)
print(f"result = {r}")
print(f"original = {l}")