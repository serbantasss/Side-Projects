def issorted(a):
    l=len(a)
    for x in range(l-1):
        if a[x]>a[x+1]:
            return False
    return True


l1 = [[1,2], [2,3], [2,3], [3,4]]
l2 = {'x':1, 'y':5, 'z':2}
r1 = issorted(l1)
#print(f"results = {r1}")

#graded
def isunique_mut(a):
    a = sorted(list(a))
    for i in range(0,len(a)-1):
        if a[i] == a[i+1]:
            return False
    return True

l1 = [[1,2],[1,1],[1,2]]
l2 = {'x':1 ,'y':0, 'z':0}
r2 = isunique_mut("abca")
print(f"results = {r2}")