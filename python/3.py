name=[1,2,3]
n = name
name.append(2)
n.append(33)
print(id(name))
print(id(n))
print(n)
print(name)