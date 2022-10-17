class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n != 0) {
            int gem = n / 5;
            count += gem;
            n = gem;
        }
        return count;
    }
};