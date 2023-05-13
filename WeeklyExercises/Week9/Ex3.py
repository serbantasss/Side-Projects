#graded
class Vec2D:
    def __init__(self, x, y):
        # arguments checks omitted
        self.x = x
        self.y = y

    def sub(self, other):
        # argument check omitted
        return Vec2D(self.x - other.x, self.y - other.y)

    def norm(self):
        return (self.x**2 + self.y**2)**0.5

    def dist(self, other):
        # argument check omitted
        return self.sub(other).norm()

class Circle:
    def __init__(self,x,y,r):
        if not isinstance(r,(float,int)):
            raise Exception
        self.c = Vec2D(x,y)
        self.r = r
    def contains(self,other):
        if not isinstance(other, Circle):
            raise Exception
        if self.c.dist(other.c)+other.r <= self.r:
            return True
        else:
            return False

c1 = Circle(3, 4, 5)
c2 = Circle(2, 2, 0.1)
c3 = Circle(0, 0, 1)
c4 = Circle(-2, -2, 0.1)

r1 = c1.contains(c2)
r2 = c1.contains(c3)
r3 = c1.contains(c4)
print(f"results = {r1}, {r2}, {r3}")