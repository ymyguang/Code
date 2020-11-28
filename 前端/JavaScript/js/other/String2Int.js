function string2int(s) {
    var a = [];
    for (let i of s) {
        a.push(i-'0')
    }   
    var ans = a.reduce(
        function (x, y) {
            return x * 10 + y;
        }
    )
    return ans;
}

if (string2int('0') === 0 && string2int('12345') === 12345 && string2int('12300') === 12300) {
    if (string2int.toString().indexOf('parseInt') !== -1) {
        console.log('请勿使用parseInt()!');
    } else if (string2int.toString().indexOf('Number') !== -1) {
        console.log('请勿使用Number()!');
    } else {
        console.log('测试通过!');
    }
}
else {
    console.log('测试失败!');
}



