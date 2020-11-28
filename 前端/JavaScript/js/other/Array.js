// // 数组
// var arr = [1,2,4,3,4,4,"dwdee"];  
// var cparr = arr.slice(1010); //切片 
// console.log(`切片元素:${cparr}`)
// console.log(`源元素:${arr}`)

// // 尾部操作
// arr.push("yi","er");  //push element
// console.log(`psuh元素:${arr}`)

// arr.pop();
// console.log(`pop元素:${arr}`)
// console.log('\n')

// // 头部操作
// var arr = [1,2]
// console.log(`源元素:${arr}`) 
// arr.unshift('A','B');
// console.log(`unshift元素:${arr}`)  //头部插入

// arr.shift(); arr.shift(); arr.shift();
// console.log(`shift元素:${arr}`)  //头部弹出
// console.log('\n')

// // 排序操作
// var arr = [223,323,2,1]
// console.log(`原来元素:${arr}`) 
// arr.sort();
// console.log(`排序元素:${arr}`) 
// console.log('\n')

// // 数组反转
// var arr = [1,2,3];
// console.log(`源元素：${arr}`);
// arr.reverse();
// console.log(`反转元素：${arr}`);
// console.log('\n')

// // 数组操作万能方法
// var arr = ['A','B','C','D'];
// console.log(`源数组：${arr}`)
// arr.splice(1,2);
// // 从索引位置1开始，删除两个元素
// console.log(`操作数组：${arr}`)
// // 从索引位置1开始，删除两个元素，且从原位置添加元素
// console.log(`源数组：${arr}`)
// arr.splice(1,0,"C",'D','R');
// console.log(`操作数组：${arr}`)
// console.log('\n')

// // 连接
// var arr = [1,2,4];
// var arr = arr.concat([1,'a','测试']);
// console.log(`操作数组：${arr}`) 
// console.log('\n') 

// // 连接符  -join

// var arr = [1,2,4];
// console.log(`源数组:${arr}`);
// arr = arr.join('-');
// console.log(`操作数组:${arr}`);




var a = ['a', 'b', 'c']
for (var i in a) {
    console.log(i)
    console.log(a[i])
}