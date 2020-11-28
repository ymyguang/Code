def foo(sum):
    while sum < 1000:
        sum = sum + 1
        sum = sum + 1
        sum = sum + 1
        n = yield sum
        print("N的值：",n)
    
for n in foo(5):
    a = n
