// var a = ['A', 'B', 'C'];
// var s = new Set(['A', 'B', 'C']);
// var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
// for (var x of a) { // 遍历Array
//     console.log(x);
// }
// for (var x of s) { // 遍历Set
//     console.log(x);
// }
// for (var x of m) { // 遍历Map
//     console.log(x[0] + '=' + x[1]);
// }

// var a = ['A', 'B', 'C'];
// a.name = 'Hello';
// for (var x of a) {
//     console.log(x); // 'A', 'B', 'C'
// }   

console.log("\nArray的iterable")
var a = ['A', 'B', 'C'];
a.forEach (
    function(element, index, array) {
        console.log(element + "   index = " + index)
    }
)
console.log("\nSet的iterable")
var s = new Set(['A', 'B', 'C'])
s.forEach (
    function(element,value,set){
        console.log(element, value)
    }
)
console.log("\nMap的iterable")
var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']])
m.forEach(function (value, key, map) {
    console.log(value,key);
});