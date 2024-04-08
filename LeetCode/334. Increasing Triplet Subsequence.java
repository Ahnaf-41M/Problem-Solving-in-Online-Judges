class Solution {
    public boolean increasingTriplet(int[] nums) {
        if (nums.length < 3) return false;

        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;

        for (int x : nums) {
            if (firstMin >= x) {
                firstMin = x;
            } else if (secondMin >= x) {
                secondMin = x;
            } else {
                return true;
            }
        }
        return false;
    }
}