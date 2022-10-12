// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
// If such an arrangement is not possible, it must rearrange it as the lowest possible order (
// i.e., sorted in ascending order). The replacement must be in place and use only constant extra memory.

// Given an array of integers nums of size n, find the next permutation.

// Input Format
// First Parameter - number n

// Second Parameter - array nums of size n

// Output Format
// return the array of integers.

// Example 1:
// Input:
//     3
//     1 2 3
// Output:
//     1 3 2
// Example 2:
// Input:
//     3
//     3 2 1
// Output:
//     1 2 3
// Example 3:
// Input:
//     3
//     1 1 5
// Output:
//     1 5 1
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)


vector<int> solve(int n, vector<int> nums){

    int k , l;
    for(k=n-2;k>=0;k--){
        if(nums[k]<nums[k+1]) break;
    }
    if(k<0) {
        reverse(nums.begin(),nums.end());
    }
    else {
        for(l=n-1;l>k;l--){
            if(nums[l]>nums[k]) break;
        }
        swap(nums[l],nums[k]);
        reverse(nums.begin()+k+1,nums.end());
    }
    return nums;
}


// int main(){
// int n;
// vector<int> nums;
// cin >> n;
// for (int i = 0; i < n; i++){
// int temp;
// cin >> temp;
// nums.push_back(temp);
// }
// vector<int> out = solve(n, nums);
// for (int i: out){
// cout << i << ' ';
// }
// return 0;
// }
