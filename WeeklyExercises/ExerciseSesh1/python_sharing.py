## The Vec2D class is already implemented
class NonFreeUserError(Exception):
    pass
class NoFreeScootersError(Exception):
    pass
class UserNotOnScooterError(Exception):
    pass

class Vec2D:
    def __init__(self, x, y):
        if not (isinstance(x, (float,int)) and isinstance(y, (float,int))):
            raise Exception("x and y must be numbers")
        self.x = float(x)
        self.y = float(y)

    def norm(self):
        return (self.x**2 + self.y**2)**0.5

    def __repr__(self):
        return f"V[{self.x}, {self.y}]"

    def __eq__(self, other):
        if not isinstance(other, Vec2D):
            return False
        return self.x == other.x and self.y == other.y

    def __add__(self, other):
        if not isinstance(other, Vec2D):
            return NotImplemented
        x = self.x + other.x
        y = self.y + other.y
        return Vec2D(x, y)

    def __sub__(self, other):
        if not isinstance(other, Vec2D):
            return NotImplemented
        x = self.x - other.x
        y = self.y - other.y
        return Vec2D(x, y)

    def dist(self, other):
        if not isinstance(other, Vec2D):
            raise Exception("other must be a Vec2D")
        return (self - other).norm()


## returns the position of the minimum in list `l`
def argmin(l):
    return min(enumerate(l),key= lambda x: x[1])[0]

list = [8,9,0]
print(argmin(list))

class Scooter:
    def __init__(self, x, y):
        self.user = None
        self.pos = Vec2D(x, y)
        self.cost = 0.0 #self.cost * dist = total cost of ride

    def isfree(self):
        return self.user is None

    def __repr__(self):
        return f"Scooter({self.pos}, {self.isfree()})"


class SharingService:
    def __init__(self, scooter_poslist):
        self.scooters = [Scooter(x,y) for x,y in scooter_poslist]

    def __repr__(self):
        return f"SS({self.scooters})"

    def free_scooters(self):
        return [x for x in self.scooters if x.isfree()]

    def closest_scooter(self, pos):
        scoot = self.free_scooters()
        return None if len(scoot) == 0 else scoot[min(enumerate(scoot), key= lambda x: pos.dist(x[1].pos))[0]]


class SSUser:
    def __init__(self, service, tpos):
        if not isinstance(service, SharingService):
            raise TypeError("service must be a SharingService")
        self.service = service
        self.pos = Vec2D(*tpos)
        self.scooter = None
        self.credit = 0.0

    def add_credit(self, value):
        self.credit += value

    def __repr__(self):
        return f"SSUser(pos={self.pos}, scooter={self.scooter})"

    def take_scooter(self):
        if self.scooter is not None:
            raise NonFreeUserError
        s = self.service.closest_scooter(self.pos)
        if s is None:
            raise NoFreeScootersError
        self.pos = s.pos
        self.scooter = s
        s.user = self

    def use_scooter(self, new_pos):
        if self.scooter is None:
            raise UserNotOnScooterError
        self.pos = self.scooter.pos = new_pos
        self.scooter.user = None
        self.scooter = None