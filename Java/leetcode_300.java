import java.util.Arrays;

public class Q_300 {
    public class Solution_recursion_with_memorization {

        public int lengthOfLIS(int[] nums) {

            // memo[i][j]memo[i][j] represents the length of the LIS possible using
            //      * nums[i] as the previous element considered to be included/not included in the LIS,
            //      * nums[j]nums[j] as the current element considered to be included/not included in the LIS.
            int memo[][] = new int[nums.length + 1][nums.length];

            for (int[] l : memo) {
                Arrays.fill(l, -1);
            }

            return lengthofLIS(nums, -1, 0, memo);
        }

        public int lengthofLIS(int[] nums, int previndex, int currentIndex, int[][] memo) {
            if (currentIndex == nums.length) {
                return 0;
            }

            // @note: prev+1
            if (memo[previndex + 1][currentIndex] >= 0) {
                return memo[previndex + 1][currentIndex];
            }

            int taken = 0;
            if (previndex < 0 || nums[currentIndex] > nums[previndex]) {
                taken = 1 + lengthofLIS(nums, currentIndex, currentIndex + 1, memo);
            }

            int nottaken = lengthofLIS(nums, previndex, currentIndex + 1, memo);

            // record before return
            memo[previndex + 1][currentIndex] = Math.max(taken, nottaken);

            return memo[previndex + 1][currentIndex];
        }

    }


}
