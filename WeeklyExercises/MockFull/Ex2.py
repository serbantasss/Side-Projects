# Write your code here
class RunLengthBuffer:
    def __init__(self):
        self.buffer = []

    def _check(self):
        assert all(isinstance(ch, str) and isinstance(cnt, int) for ch, cnt in self.buffer)
        assert all(len(ch) == 1 and cnt > 0 for ch, cnt in self.buffer)
        assert all(self.buffer[i][0] != self.buffer[i + 1][0] for i in range(len(self.buffer) - 1))

    def __len__(self):
        return sum(cnt for ch, cnt in self.buffer)

    def __repr__(self):
        return "RLB[" + "".join(ch * cnt for ch, cnt in self.buffer) + "]"

    def add(self, ch):
        if not isinstance(ch, str):
            raise TypeError
        if len(ch) != 1:
            raise ValueError
        if len(self.buffer) == 0 or self.buffer[len(self.buffer) - 1][0] != ch:
            self.buffer.append((ch, 1))
            return None
        cnt = self.buffer[len(self.buffer) - 1][1]
        self.buffer.pop()
        self.buffer.append((ch, cnt + 1))
        return None

    def get(self):
        if len(self.buffer) == 0:
            raise Exception
        cnt = self.buffer[0][1]
        ch = self.buffer[0][0]
        self.buffer.pop(0)
        if cnt > 1:
            self.buffer.insert(0, (ch, cnt - 1))
        return ch

    def __contains__(self, ch):
        if not isinstance(ch, str):
            return False
        if len(ch) != 1:
            return False
        return any(elem[0] == ch for elem in self.buffer)