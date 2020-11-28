// 函数
// -----------------*****************-----------------------

// var abs = function(x) {
//     if (x > 0)
//         return x;
//     else {
//         return -x;
// }
// -----------------*****************-----------------------
// function abs(x) {
//     if (typeof x != 'number')
//         console.log("Not a number")
//     if (x > 0)
//         return x;
//     else {
//         return -x;
//     }
// }
// a = abs('haha', 'hehe', null, -1); // 返回9
// // console.log(a)

// -----------------*****************-----------------------
                // arguments

// function abs(){
//     if (arguments.length === 0){
//         return "casnhu not exits"
//     }
//     else {
//         var x = arguments[0];
//         return x > 0 ? x : -x;
//     }
// }

// var a = abs(-2)
// console.log(a)

// ------------------------------------------------------------


// function a() {
//     console.log(`参数个数：${arguments.length}\n分别是：`)
//     for (var i = 0 ; i < arguments.length;i++){
//         console.log(arguments[i])
//     }
// }

// a(1,2,3)
// -----------------*****************-----------------------
// function foo(a, b) {
//     var i, rest = [];
//     if (arguments.length > 2) {
//         for (i = 2; i < arguments.length; i++) {
//             rest.push(arguments[i]);
//         }
//     }
//     console.log('a = ' + a);
//     console.log('b = ' + b);
//     console.log(rest);
// }


// function foo (a, b, ...rest){
//     console.log('a = ' + a);
//     arguments.length
//     console.log('b = ' + b);
//     console.log(rest);
// }


// function add(x, y, f) {
//     return f(x) + f(y);
// }

// let a = add(-1, 2, Math.abs)
// console.log(a)

var arr = [1,2,3,4,5]
let a = arr.reduce(
    function(x, y){
        return x + y;
    }
)
console.log(a)
function product(arr) {
    var a = arr.reduce(
        function(x, y){
            return x * y;
        }
    )
}