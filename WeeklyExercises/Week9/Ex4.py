class SetDict:
    def __init__(self):
        self.dct = dict()

    def add(self, other):
        if other not in self.dct:
            self.dct[other] = True

    def remove(self, other):
        if other not in self.dct:
            raise Exception
        else:
            self.dct.pop(other)

    def show(self):
        return '{'+ ', '.join(repr(key[0])  for key in self.dct.items())+'}'


sd = SetDict()
sd.add(3)
sd.add(2)
sd.add(1)
sd.add(2)
print(f"contents (I): {sd.show()}")
sd.remove(3)
sd.add(5)
print(f"contents (II): {sd.show()}")
# sd.remove(3) # this one should raise an Exception
sd.remove(5)
sd.remove(1)
sd.remove(2)
print(f"contents (III): {sd.show()}")

pla = SetDict()
pla.add('hello')
pla.add('world')
print(pla.show())
