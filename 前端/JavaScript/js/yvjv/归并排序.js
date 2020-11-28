// ????

var a = [7, 4, 2]
console.log(a.length)
mergeSort(0, a.length - 1, a)


function merge(l, r, mid, arr) {
    var i = l;
    var j = mid + 1
    var k = 0;
    var t = [];
    while (k <= r - l) {
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                t[k++] = arr[i++];
            }
            else
                t[k++] = arr[j++];
        }
        if (i == mid + 1) {
            t[k++] = arr[j++];
        }
        else
            t[k++] = arr[i++];
    }
    for (var ii = 0,jj = l; jj <= r -l; ii++,jj++) {
        arr[ii] = t[jj];
    }
    return arr;
}

function mergeSort(l, r, arr) {
    var mid = (l + r) / 2     // l????r????
    if (l < r) {
        mergeSort(l, mid, arr); //????
        mergeSort(mid + 1, r, arr); // ????
        merge(l, r, mid, arr);   //??
        return arr;
    }
}