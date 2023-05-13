dick= {'jan':31, 'feb':28, 'mar':31, 'apr':30, 'may':31, 'jun':30,'jul':31,'aug':31,'sep':30,'oct':31,'nov':30,'dec':31}
def monthlen(luna,zi):
    if not(isinstance(luna,str)):
        raise Exception
    if luna.lower() not in dick.keys():
        raise Exception
    if not(isinstance(zi,int)):
        raise Exception
    if zi<=0 or zi>dick[luna.lower()]:
        raise Exception
    for item in dick:
        if dick[item] == dick[luna.lower()]:
            break
    s = 0
    for key in dick:
        if key == luna.lower():
            break
        else:
            s += dick[key]
    return s+zi


#print(monthlen("dec",31))


#4
def changeoddsigns(lst):
    if not(isinstance(lst,list)):
        raise Exception
    return [v for i, v in enumerate(lst) if i % 2 == 0]

l1 = [3, 6, 9, 12, 15]
changeoddsigns(l1)
l2 = [-2.0, -4.0, -6.0, -8.0]
changeoddsigns(l2)
print(f"modified lists = {l1}")