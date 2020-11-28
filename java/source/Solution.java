import java.util.*;

class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> t = new ArrayList<Integer>();
        int n = nums.length;    
        for (int i = 0; i < (1 << n); i++) {
            t.clear();
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    t.add(nums[j]);
                }
            }
            ans.add(new ArrayList<Integer>(t));
        }
        return ans;
    }
}