//Kadane's Algo

// Edge case 0 not taken for consideration and hence getting wrong answer for below eg:
/*
Input: nums = [-2,0,-1]
Expected Output: 0
My output: 1 because of (int product = 1; int maxproduct = 1;)
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int maxproduct = 1;
        for(int i = 0; i < nums.size(); i++){
            product = product*nums[i];
            maxproduct = max(maxproduct, product);
        }

        return maxproduct;
    }
};
/* if a 0 is encountered -> then it resets the min and max product                                         */