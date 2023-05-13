#practice
class DictList:
    def __init__(self):
        self.keys = []
        self.vals = []

    def __repr__(self):
        n = len(self.vals)
        return "{" + ", ".join(repr(self.keys[i]) + ": " + repr(self.vals[i]) for i in range(n)) + "}"

    def __setitem__(self, key, value):
        try:
            self.vals[self.keys.index(key)] = value
        except:
            self.keys.append(key)
            self.vals.append(value)
    def __getitem__(self, item):
        try:
            return self.vals[self.keys.index(item)]
        except:
            raise Exception

    def __delitem__(self, key):
        try:
            ind = self.keys.index(key)
            del self.vals[ind]
            del self.keys[ind]
        except:
            raise Exception

    def get(self, item, default = None):
        try:
            ind = self.keys.index(item)
            return self.vals[ind]
        except:
            return default

    def setdefault(self, item, default = None):
        try:
            ind = self.keys.index(item)
            return self.vals[ind]
        except:
            self.keys.append(item)
            self.vals.append(default)
            return default

## The following should all be obvious

"""dl = DictList() # if you change this to dict() the result should be the same
print(f"contents (I): {dl}")

## 1st batch of methods
dl['one'] = 1
print("key 'one':", dl['one'])
# print(dl['two']) # this one should raise an Exception
dl['four'] = 44
dl['three'] = 3
print(f"contents (II): {dl}")
dl['four'] = 4
dl['two'] = 4
print(f"contents (III): {dl}")"""

## 2nd batch of methods
"""del dl['three']
# del dl['three'] # this one should raise an Exception
print("key 'two' with get:", dl.get('two'))
print("key 'three' with get:", dl.get('three', 33))
# dl['three'] # this one should still raise an Exception
print("key 'three' with setdefault:", dl.setdefault('three', 33))
print("key 'three':", dl['three'])
"""
#graded

# Write your code here
import math

class VecRA:
    """
    A 2-d vector represented in polar coordinates (r,theta).
    The angle theta is measured in radians, from the
    positive x axis, counterclockwise. Its range is (-pi,pi].
    When r==0 then theta is set to 0 too.
    """
    def __init__(self, x, y):
        "Constructed from cartesian coordinates (x,y)"
        if not (isinstance(x, (int, float)) and isinstance(y, (int, float))):
            raise Exception("x and y must be int or float")
        r = (x**2 + y**2)**0.5
        # The basic formula for the angle is
        #    theta = math.atan(y / x)
        # but there are a few special cases to consider,
        # and the signs must be taken into account too.
        # This code ensures that the cartesian coordinates
        # can be recovered as
        #    x = r * cos(theta)
        #    y = r * sin(theta)
        if r == 0:
            theta = 0.0
        elif x == 0:
            theta = math.pi / 2 if y > 0 else -math.pi / 2
        else:
            theta = math.atan(y / x)
            if x < 0 and y >= 0:
                theta += math.pi
            elif x < 0 and y < 0:
                theta -= math.pi
        self.r = r
        self.theta = theta

    def __repr__(self):
        return f"VecRA({self.r}, {self.theta})"

    def norm(self):
        return self.r

    def __eq__(self, other):
        if not isinstance(other,VecRA):
            return NotImplemented
        else:
            return self.r == other.r and self.theta == other.theta

    def __complex__(self):
        return complex(self.r * math.cos(self.theta),self.r * math.sin(self.theta))

    def __bool__(self):
        if self.r == 0:
            return False
        else:
            return True

## Create some VecRA objects for the tests
z = VecRA(0, 0)
v = VecRA(-1, 1)
u = VecRA(-2, 2)
w = VecRA(-1.0, 1.0)

## 1st part
print("1st part")
print("--------")
print(f"{v} == {z}: {v == z}")  # False
print(f"{v} == {u}: {v == u}")  # False
print(f"{v} == {w}: {v == w}")  # True
print(f"{v} == 1: {v == 1}")    # False
print(f"1 == {v}: {1 == v}")    # False


import pydoc
print()
print(">>> DOCS:")
print(pydoc.getdoc(VecRA))
print()

print("2nd part")
print("--------")
print(f"bool({z}) == {bool(z)}")  # False
print(f"bool({v}) == {bool(v)}")  # True

print(f"complex({z}) == {complex(z)}") # 0j
print(f"complex({v}) == {complex(v)}") # (-1+1.0000000000000002j)
print(f"complex({u}) == {complex(u)}") # (-2+2.0000000000000004j)
print(f"complex({w}) == {complex(w)}") # (-1+1.0000000000000002j)

