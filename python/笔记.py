一# eval函数的介绍：
    # eval函数就是实现list、dict、tuple与str之间的转化
    # 在python中,eval()是评估函数,用处是去掉最外层引号,然后进一步处理
    # 解释:python中 input()默认录入的是字符串类型
    # 如果用户输入了123,其实读取的是字符串"123"
    # 这时候需要eval(input())来获取整数123,才能进行进一步的计算
    # 之所以说eval()用处是去掉最外层引号是因为,
    # 举例说明吧,
    # eval(" '你好' "),会输出字符串"你好"
    # eval("print("WOW")"),经过评估函数处理之后 会输出字符串"WOW"
    # A=10
    # eval("print(A)")
    # #经过评估函数处理,会输出整数 10
a = eval(input("输入值："))
print(type(a))