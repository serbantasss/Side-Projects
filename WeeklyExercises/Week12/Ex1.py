# practice
import random
def randdarts(n, myseed):
    random.seed(myseed)
    points = 0
    for i in range(n):
        x = random.uniform(-1,1)
        y = random.uniform(-1,1)
        dist = (x**2 + y**2)**0.5
        if dist<0.1:
            points += 100
            continue
        if dist<0.5:
            points += 50
            continue
        if dist<1:
            points += 10
            continue
    return points/n

print (randdarts(20000,874398))

# graded

import math
import random

def randwdir(n ,k, myseed):
    random.seed(myseed)
    dist = 0
    for i in range(n):
        x = y = 0
        for j in range(k):
            angle = random.uniform(0, 2*math.pi)
            x += math.cos(angle)
            y += math.sin(angle)
        dist += (x**2 + y**2)**0.5
    return dist/n
