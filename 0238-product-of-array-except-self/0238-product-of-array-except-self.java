class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        
        res[0] = 1;
        for(int i=1; i<len; i++){
            res[i] = res[i-1] * nums[i-1];
        }

        int rightProduct = 1;
        for(int i= len-1; i > 0; i--){
            rightProduct *= nums[i];
            res[i-1] *= rightProduct;
        }
        
        return res;
    }
}