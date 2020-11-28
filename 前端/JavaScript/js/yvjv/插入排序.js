var a = [8, 7, 6, 5, 4, 3, 2, 1]
for (var i = 1; i < a.length; i++) {
    //记录准备插入数
    var X = a[i];       
    // 从自己前一个数字开始                 
    var j = i - 1;
    //与前面已经排序好的数字序列比较
    while (j >= 0 && X < a[j]) {         
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = X;
}

console.log(a)