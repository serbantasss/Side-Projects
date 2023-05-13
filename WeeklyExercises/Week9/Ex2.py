#graded

class Vec3D:
    def __init__(self,x,y,z):
        if not isinstance(x,(float,int)):
            raise Exception
        if not isinstance(y,(float,int)):
            raise Exception
        if not isinstance(z,(float,int)):
            raise Exception
        self.x = x
        self.y = y
        self.z = z
    def dot(self,other):
        if not isinstance(other,Vec3D):
            raise Exception
        return float(self.x*other.x + self.y*other.y + self.z*other.z)

v1 = Vec3D(3, 4, 1)
v2 = Vec3D(-1.0, 2.0, 1.5)
r1 = v1.dot(v2)
r2 = v2.dot(v1)
print(f"results = {r1}, {r2}")