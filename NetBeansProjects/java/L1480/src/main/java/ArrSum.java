/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author admin
 */
public class ArrSum {
    public int[] ArrSum (int[] nums){
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length;i++){
                sum[i] +=sum[i-1] + nums[i];
            }
        return sum;    
    }
}
    

