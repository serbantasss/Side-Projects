# Write your code here
class Polynomial:
    def __init__(self, iterable = None):
        if iterable is None:
            iterable = []
        self.coeffs = list(iterable)
        if not all(isinstance(x,int) for x in self.coeffs):
            raise TypeError

    def evaluate(self, x):
        return sum((x**pow)*coef for pow,coef in enumerate(self.coeffs))

    def __eq__(self, other):
        if not isinstance(other, Polynomial):
            return NotImplemented
        n1 = len(self.coeffs)
        n2 = len(other.coeffs)
        m = min(n1, n2)
        for i in range(m):
            if self.coeffs[i] != other.coeffs[i]:
                return False
        for i in range(m, n1):
            if self.coeffs[i] != 0:
                return False
        for i in range(m, n2):
            if other.coeffs[i] != 0:
                return False
        return True

    ## T5: write a method for multiplying a polynomial by a scalar,
    ##     and another one for multiplying a scalar by a polynomial
    def __mul__(self, other):
        if not isinstance(other, int):
            return NotImplemented
        return Polynomial([coef*other for coef in self.coeffs])

    def __rmul__(self, other):
        return self*other

    ## T6: write the degree method
    def degree(self):
        ret = 0
        for i,x in enumerate(self.coeffs):
            if x!=0:
                ret = i
        return ret

    ## T7: write the normalize method
    def normalize(self):
        while len(self.coeffs) > self.degree()+1:
            self.coeffs.pop()
        if self.degree() == 0 and self.coeffs == [0]:
            self.coeffs.pop()
        return None

    def __repr__(self):
        lst = []
        for (i, c) in enumerate(self.coeffs):
            ## T8: improve `s` to deal with special cases
            if c == 0:
                continue
            if i == 0:
                if c<0:
                    s = f"({c})"
                else:
                    s = f"{c}"
            else:
                if c == 1:
                    s = f"x"
                elif c < 0:
                    s = f"({c})x"
                else:
                    s = f"{c}x"
            if i>1:
                s += f"^{i}"
            lst.append(s)
        if len(lst) == 0:
            return "0"
        else:
            return "+".join(lst)

    ## T9: write a method for adding Polynomials
    def __add__(self, other):
        if not isinstance(other,Polynomial):
            return NotImplemented
        ret = []
        for i in range(max(len(self.coeffs),len(other.coeffs))):
            if i>=len(self.coeffs):
                ret.append(other.coeffs[i])
            elif i>=len(other.coeffs):
                ret.append(self.coeffs[i])
            else:
                ret.append(self.coeffs[i]+other.coeffs[i])
        return Polynomial(ret)



