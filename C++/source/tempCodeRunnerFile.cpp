void merge(int,int,int,int*);
// void mergesort();

// void mergesort(int l, int r, int arr[]){
//     int mid = (l + r) / 2;
//     if (l <= r) {
//         mergesort(l,mid,arr);
//         mergesort(mid+1,r,arr);
//         merge(l,r,mid,arr);
//     }
// }

// void merge(int l ,int r, int mid, int arr[]){
//     int i = l;
//     int k = 0;
//     int j = mid+1;
//     if (i = mid + 1){
//         t[k++] = arr[j++];
//     }
//     if (j = r + 1){
//         t[k++] = arr[i++];
//     }
//     if (arr[i] > arr[j]) {
//         t[k++] = arr[i++];
//     }
//     else {
//         t[k++] = arr[j++];
//     }
// }