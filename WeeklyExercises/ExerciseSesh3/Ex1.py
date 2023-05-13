# Write your code here

class IntQueue:
    def __init__(self, m):
        if not isinstance(m, int):
            raise TypeError
        if not m>0:
            raise ValueError
        self.m = m
        self.data = [0] * m
        self.nxt = m

    def __repr__(self):
        return f"IntQueue(m={self.m}, data={self.data}, nxt={self.nxt})"

    def __len__(self):
        return sum(self.data)

    def put(self, i):
        if i < self.nxt:
            self.nxt = i
        self.data[i] += 1
        return None

    def get(self):
        if self.ntx == self.m:
            raise KeyError
        self.data[self.nxt] -= 1
        ret = self.nxt
        if self.data[self.ntx] == 0:
            for i in range(self.m):
                if self.data[i] > 0:
                    self.nxt = i
                    break
        return ret

    def getdefault(self, default = -1):
        try:
            return self.get()
        except KeyError:
            return default