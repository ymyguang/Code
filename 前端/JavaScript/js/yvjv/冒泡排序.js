var a = [8, 7, 6, 5, 4, 3, 2, 1]
// 第一层循环，控制遍历次数
for (var i in a) {
    // 第二层循环，比较每个数字的大小关系，把最大的数字放到指定位置
    for (var j in a) {
        var t = parseInt(j) + 1;
        if (a[j] > a[t]) { //发现大的数字，与之交换
            var temp;
            temp = a[j];
            a[j] = a[t];
            a[t] = temp;
        }
    }
}
console.log(a)