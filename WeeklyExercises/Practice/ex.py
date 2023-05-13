# Write your code here
class IntSet:
    def __init__(self, m):
        if not isinstance(m, int):
            raise TypeError("m must be an int")
        if m <= 0:
            raise ValueError("m must be positive")
        self.mask = [False] * m
        self.n = 0

    def _check_arg(self, x):
        if not isinstance(x, int):
            raise TypeError("x must be an int")
        if not (0 <= x < len(self.mask)):
            raise ValueError("x out of bounds")

    def add(self, x):
        self._check_arg(x)
        if self.mask[x]:
            return
        self.mask[x] = True
        self.n += 1

    def __len__(self):
        return self.n

    def remove(self, x):
        self._check_arg(x)
        if self.mask[x] == False:
            raise KeyError(x)
        self.mask[x] = False
        self.n -= 1

    def __contains__(self, item):
        try:
            self._check_arg(item)
            return self.mask[item]
        except ValueError:
            return False

    def pop_rand(self):
        if not len(self):
            raise KeyError
        from random import randint
        while True:
            x = randint(0, len(self.mask)-1)
            if x in self:
                self.remove(x)
                return x

    def __repr__(self):
        return "{"+", ".join(str(i) for i,x in enumerate(self.mask) if x == True)+"}"
print(", ".join("abc"))