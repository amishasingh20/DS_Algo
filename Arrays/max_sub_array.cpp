//Sliding Window --> Kadane's Algo
/*
If the sum of previous subarray + current element is less that element then max sub array contains only current element
eg: [-2,3,2,1]
1st run --> sum = 2
2nd run --> sum = 1 but the element is greater than sum so sum = 2 and max subarray is [2]
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            sum = max(sum,nums[i]);
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};