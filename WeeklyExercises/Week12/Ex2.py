# practice
def zdict(it_k, it_v):
    return dict([(x,y) for x,y in zip(it_k, it_v)])

# graded option 1
def avg_r_prod(it1, it2):
    z = [(x*y)/(i+1) for i, (x,y) in enumerate(zip(it1, it2))]
    return sum(z)/len(z)

i1 = [2, 4, 6]
i2 = [3, 5, 4]
print(avg_r_prod(i1, i2))

