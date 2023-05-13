# practice
class LLNode:
    def __init__(self, data, nxt=None):
        if not (isinstance(nxt, LLNode) or nxt is None):
            raise Exception("nxt must be either an LLNode or None")
        self.data = data
        self.nxt = nxt

    def __repr__(self):
        return f"N[{repr(self.data)}]"


class LList:
    def __init__(self):
        self.head = None

    def __repr__(self):
        s = "LL:HEAD->"
        current = self.head
        while current is not None:
            s += repr(current) + "->"
            current = current.nxt
        s += "LL:NONE"
        return s

    def __len__(self):
        n = 0
        current = self.head
        while current is not None:
            n += 1
            current = current.nxt
        return n

    def isempty(self):
        return self.head is None

    def prepend(self, data):
        self.head = LLNode(data, self.head)

    def pop_head(self):
        if self.isempty():
            raise Exception("empty list")
        head = self.head
        data = head.data
        self.head = head.nxt
        head.nxt = None  # not really necessary
        return data

    def append(self, data):
        current = self.head
        if current is None:
            self.head = LLNode(data)
        else:
            while True:
                if current.nxt is None:
                    current.nxt = LLNode(data)
                    break
                current = current.nxt

    def __contains__(self, item):
        current = self.head
        while current is not None:
            if current.data == item:
                return True
            current = current.nxt
        return False


"""## 1st part
ll = LList()


## 2nd part
ll.append('three')
print(f"contents (III): {ll}")
ll.prepend('two')
ll.prepend('one')
print(f"contents (IV): {ll}")
ll.append('four')
ll.append('five')
print(f"contents (V): {ll}")
ll.pop_head()
ll.append('six')
ll.pop_head()
print(f"contents (VI): {ll}")"""


# graded

# Write your code here
class Tape:
    def __init__(self):
        self.lst = []

    def __repr__(self):
        if len(self.lst) > 0:
            return "Tape[" + str(self.lst)[1:-1] + ", ...]"
        else:
            return "Tape[...]"

    def __eq__(self, other):
        if not isinstance(other, Tape):
            return NotImplemented
        if len(self.lst) == len(other.lst):
            return self.lst == other.lst
        if len(self.lst) > len(other.lst):
            return self.lst[:len(other.lst)] == other.lst and all(item == 0 for item in self.lst[len(other.lst):])
        else:
            return other.lst[:len(self.lst)] == self.lst and all(item == 0 for item in other.lst[len(self.lst):])

    def __getitem__(self, key):
        if not isinstance(key, int) or key < 0:
            raise Exception
        if key >= len(self.lst):
            return 0
        else:
            return self.lst[key]

    def __setitem__(self, key, value):
        if not isinstance(key, int) or key < 0:
            raise Exception
        while len(self.lst) <= key:
            self.lst.append(0)
        self.lst[key] = value


## 1st part
print("1st part")
print("--------")
t1 = Tape()
t2 = Tape()
print(f"t1 = {t1}")                    # t1 = Tape[...]
### modify the lists manually if t1[i] = x is not yet implmented
t1.lst = [4, 2, 0, 1]
t2.lst = [4, 2]
print(f"t1 = {t1}")                    # t1 = Tape[4, 2, 0, 1, ...]
print(f"t2 = {t2}")                    # t2 = Tape[4, 2, ...]
print(f"{t1} == {t2} -> {t1 == t2}")   # False
t2.lst = [4, 2, 0, 1]
print(f"{t1} == {t2} -> {t1 == t2}")   # True
t2.lst = [4, 2, 0, 1, 0, 0]
print(f"{t1} == {t2} -> {t1 == t2}")   # True
print(f"{t2} == {t1} -> {t2 == t1}")   # True
print(f"{t1} == 5 -> {t1 == 5}")       # False
print()