import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int num : arr) {
            map.put(num,map.getOrDefault(num, 0) + 1);
        }
        int size = map.size();
        int[] cnt =  new int[size];
        int m = 0;
        for (int key : map.keySet()){
            cnt[m++] = map.get(key);
        }
        Arrays.sort(cnt);
        for (int c : cnt) {
            if (k >= c){
                size--;
                k -= c;
            }else  {
                break;
        }
    }
        return size;    
    }
}