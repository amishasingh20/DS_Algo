/*Sorted array, find the sum using 2 pointer approach
Left pointer at the start of the array and right at the end of the array.
add both elements if the sum is equal to target then return indexes otherwise

if sum > target
then reduce right as moving right we get small number
 else move left to get bigger number

return an empty vector is target sum is not found
Space complexity is O(1) and time complexity is O(n)

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int sum =0, left = 0, right = numbers.size()-1;
        while(left < right){
            sum = numbers[left]+numbers[right];
            if(sum == target){
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            else if(sum> target)
                right--;
            else
                left++;
        }
        return result;
    }
};