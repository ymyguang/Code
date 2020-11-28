# for num in range(1,990000000007897897890):
#     low = num % 10
#     mid = (num // 10) % 10
#     max = num //100
#     if low**3 + mid**3 + max**3 == num:
#         print(num,end = " ")
#

# for num in range(100,120):
#     print("%d" % num)
# for 语句用于循环。
#range 生成的数未前开后闭区间。在整个python中的括号逻辑都是这个意义


# for num in range(1,1000000):
for num in range(1,1000000000000000000000000000000000000000):
    num1 = str(num) # int类型中不存在len函数！所以转到str字符类型
    len1 = len(num1)  #获取长度
    forever = num     #记录初始值
    sum = 0           #求和
    while num > 0:
        temp = num % 10
        sum = temp**len1 + sum    #该三行是去数字
        num //= 10
    if sum == forever:
        print(forever,end = " ")
