## You can edit this file as much as you want,
## it's not used when grading

from ExGraded import DTree

### 1st batch: depth
print("1st batch of tests")

t = DTree()
assert t.depth() == 0

## add root
t.add("root")
assert t.depth() == 1

## add 1st layer, collect the nodes for later tests
for data in ["n0", "n1", "n2"]:
    t.add(data)
    assert t.depth() == 2

## add 2nd layer, collect the nodes for later tests
for data in ["n00", "n01", "n02", "n10", "n11"]:
    t.add(data)
    assert t.depth() == 3

print("1st batch ok")
print()








### 2nd batch: attach_tree
print("2nd batch of tests")

## create a tree with 2 layers, 9 nodes
t = DTree()
for data in ["root", "n0", "n1", "n2", "n00", "n01", "n02", "n10", "n11"]:
    t.add(data)

## create another tree with 3 nodes, 2 layers
t2 = DTree()
for data in ["R", "K0", "K1"]:
    t2.add(data)

## attach the second tree to the first, it should end up as a child of n1
t.attach_tree(t2)
assert len(t) == 12
assert len(t2) == 0
t._check()
t2._check()
print("this line should show the new nodes as children of n1")
print(t) # inspect visually to check everything's ok
print()

## attaching a tree to an empty tree: basically transfer the whole thing
t_repr = repr(t)
t2.attach_tree(t)
assert len(t) == 0
assert len(t2) == 12
t._check()
t2._check()
assert repr(t2) == t_repr

print("2nd batch seems ok")
print()








### 3rd batch: internal _find method
print("3rd batch of tests")

## create a tree
t = DTree()

## test that the correct error is raised
try:
    t._find("hello")
except ValueError:
    pass

## add 9 nodes (2 layers); collect the nodes for later tests
allnodes = []
allnodesnames = ["root", "n0", "n1", "n2", "n00", "n01", "n02", "n10", "n11"]
for data in allnodesnames:
    n = t.add(data)
    allnodes.append(n)

i = 0
for i in range(len(allnodes)):
    assert t._find(allnodesnames[i]) is allnodes[i]

## test that the correct error is raised
try:
    t._find("hello")
except ValueError:
    pass

print("3rd batch ok")
print()







### 4th batch: the `in` operator
print("4th batch of tests")

## create a tree
t = DTree()
assert "hello" not in t

## add 9 nodes (2 layers)
allnodesnames = ["root", "n0", "n1", "n2", "n00", "n01", "n02", "n10", "n11"]
for data in allnodesnames:
    t.add(data)

for data in allnodesnames:
    assert data in t

assert "hello" not in t

print("4th batch ok")
print()







### 5th batch: cut_subtree
print("5th batch of tests")

## create a tree
t = DTree()

## test that the correct error is raised
try:
    t.cut_subtree("hello")
except ValueError:
    pass

## add 9 nodes (2 layers); collect the nodes for later tests
allnodes = []
allnodesnames = ["root", "n0", "n1", "n2", "n00", "n01", "n02", "n10", "n11"]
for data in allnodesnames:
    n = t.add(data)
    allnodes.append(n)

t2 = t.cut_subtree("n1")

assert len(t2) == 3
assert len(t) == 6

assert t2.root is allnodes[2]
print("these lines should show the 1st tree without n1 and the 2nd tree rooted at n1 with n10,n11 as children")
print(f"t={t}")
print(f"t2={t2}")
print()

t3 = t.cut_subtree("root")
assert len(t3) == 6
assert len(t) == 0
assert t3.root is allnodes[0]

print("these lines should show the 1st tree being empty and the 2nd like the previous t")
print(f"t={t}")
print(f"t3={t3}")
print()

print("5th batch seems ok")
print()