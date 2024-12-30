class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i = n-1; i>=0; i--){
            if(digits[i]+1 == 10){
                digits[i] = 0;
            }else{
                ++digits[i];
                break;
            }
        }
        if(digits[0] == 0){
            int[] newDigits = new int[n+1];
            newDigits[0] = 1;
            System.arraycopy(newDigits, 1, digits, 0, n);
            return newDigits;
        }
        return digits;
    }
}