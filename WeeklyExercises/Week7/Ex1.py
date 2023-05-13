#ungraded
def sumi(start,end):
    s=0
    for i in range(start,end+1):
        s+=i
    return s

#print(sumi(-10,-9))
#graded

def number_of_divisors(n):
    d=0
    for i in range(1,n+1):
        if n%i == 0:
            d+=1
    return d

#print (number_of_divisors(12))