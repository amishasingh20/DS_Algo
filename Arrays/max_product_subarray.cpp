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
/* if a 0 is encountered -> then it resets the min and max product
    if all numbers are positive then product always increasing but edge case is 0 and -ve numbers.
    with -ve numbers sign alernate when all numbers are -ve.
    Keep track of minimum and max products
    [-2,0,-1]
1st    max = 0
       min = 0
2nd    max = 0
        min = 0

[2,3,-2,4]
1st run
    prod = 6
    // max of number, older_max*number, older_min*number
    max = 6
    // min of number, older_max*number, older_min*number
    min = min(2*3,3,2*3) = 3
2nd run
    max = max(6*-2,-2, 3*-2) = -2
    min = min(3*-2,-2,6*-2) = -12
    prod = 6
3rd run
    max =(-2*4,4,-12*4) = 4
    min = (-12*4,4,-2*4) = -24
    prod = 6
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0];
        int maxprod = nums[0];
        int minprod = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = maxprod;
            maxprod = max(maxprod*nums[i], nums[i]);
            maxprod = max(maxprod, minprod*nums[i]);
            minprod = min(minprod*nums[i], nums[i]);
            minprod = min(minprod,temp*nums[i]);
            prod = max(maxprod,prod);
        }
        return prod;
    }
};