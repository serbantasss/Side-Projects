
class Rational:

    def __init__(self, num, den = 1):
        if not isinstance(num, int):
            raise Exception("num must be an integer")
        if not (isinstance(den, int) and den != 0):
            raise Exception("den must be a non-zero integer")
        from math import gcd
        cmmdc = gcd(num,den)
        num = num//cmmdc
        den = den//cmmdc
        if den<0:
            den*=-1
            num*=-1
        self.num = num
        self.den = den

    def __repr__(self):
        return f"{self.num}//{self.den}"

    def __eq__(self, other):
        if isinstance(other, Rational):
            return self.num == other.num and self.den == other.den
        if isinstance(other, int):
            return self.num == other and self.den == 1
        return NotImplemented

    def __mul__(self, other):
        if not isinstance(other,(Rational,int)):
            raise TypeError

"""## 1st part
print("1st part")
print("--------")
a = Rational(15, 18)    # 5//6
b = Rational(165, -630) # -11//42
z = Rational(0, 8)      # 0//1
print(f"a={a} b={b} z={z}")
c = a * b               # -55//252
d = a * 4               # 10//3
e = 4 * a               # 10//3
print(f"c={c} d={d} e={e}")
# w = a * 4.0           # "unsupported operand type(s)..." error
# w = 4.0 * a           # "unsupported operand type(s)..." error
print()
"""

#graded

# Write your code here
class Book:
    def __init__(self, title, author, year):
        if not isinstance(title, str):
            raise Exception("title must be a string")
        if not isinstance(author, str):
            raise Exception("author must be a string")
        if not isinstance(year, int):
            raise Exception("year must be an integer")

        self.title = title
        self.author = author
        self.year = year

    def __eq__(self, other):
        if isinstance(other, Book):
            return self.title == other.title and \
                   self.author == other.author and \
                   self.year == other.year
        return NotImplemented

    def __repr__(self):
        return f"{repr(self.title)} by {repr(self.author)} ({self.year})"


class Catalog:
    def __init__(self):
        self.lst = []

    def __len__(self):
        return len(self.lst)

    def add(self, other):
        if not isinstance(other, Book):
            raise Exception
        if other not in self.lst:
            self.lst.append(other)

    def filter_by_author(self, author):
        return [item for item in self.lst if (item.author).lower() == author.lower()]

    def search(self, pattern):
        return [item for item in self.lst if pattern in item.title]

## The following should all be obvious

b1 = Book("1984", "George Orwell", 1949)
b2 = Book("Brave new world", "Aldous Huxley", 1932)
b3 = Book("El aleph", "Jorge Louis Borges", 1949)
b4 = Book("The devils of Loudun", "Aldous Huxley", 1952)
b5 = Book("The world as I see it", "Albert Einstein", 1949)

cat = Catalog()

## 1st part
print("1st part")
cat.add(b1)
cat.add(b2)
cat.add(b3)
cat.add(b4)
cat.add(b5)
assert len(cat) == 5
b1bis = Book("1984", "George Orwell", 1949)
cat.add(b1bis) # no effect
assert len(cat) == 5
# cat.add("hello") # must raise an Exception
print("1st part done")
print()

## 2nd part
print("2nd part")
la = cat.filter_by_author("aldous huxley")
assert la == [b2, b4]
la = cat.filter_by_author("aLdoUs huXley")
assert la == [b2, b4]
la = cat.filter_by_author("OOK")
assert len(la) == 0
ls = cat.search("world")
assert ls == [b2, b5]
ls = cat.search("OOK")
assert len(ls) == 0
print("2nd part done")
