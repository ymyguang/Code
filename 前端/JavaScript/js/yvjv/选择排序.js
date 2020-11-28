var a = [8, 7, 6, 5, 4, 3, 2, 1]
// 循环次数，每一次出来一个指定的数字
for (var i = 0; i < a.length; i++) {
    var maxid = 0;
    // 标记当前数列中最值。
    for (var j = 0; j < a.length -i; j++) {
        if (a[j] < a[maxid]) {
            maxid = j;
        }
    }
    // 循环结束后，将指定位置的数字与本次循环所得到的最值，进行换位。
    var temp = a[maxid];
    a[maxid] = a[a.length - i - 1];
    a[a.length - i - 1] = temp;
}
console.log(a)