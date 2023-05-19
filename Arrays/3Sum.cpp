/*
Intuition of this Problem:
Set is used to prevent duplicate triplets and parallely we will use two pointer approach to maintain J and k.

NOTE - PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.

Approach for this Problem:
Sort the input array
Initialize an output vector to store the final result
Iterate through the array with a variable i, starting from index 0.
----- At this point the rest of the array can be iterated through similar approach to two sum II---
Initialize two pointers, j and k, with j starting at i+1 and k starting at the end of the array.
In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0. If it is, insert the triplet into the result and increment j and decrement k to move the pointers.
*************To avoid duplicates*************:
Compare if the same current elements pointed by L and R are same as next elements. If the next left and
right elements are not duplicates. Then increament the pointer for the next set.

If the sum is less than 0, increment j. If the sum is greater than 0, decrement k.
After the while loop, iterate through the set and add each triplet to the output vector.
Return the output vector

Space complexity is O(1)(can be O(n) because of sorting)and time complexity is O(n^2)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if(nums.size() < 3)
            return result;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if( i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum < 0)
                    l++;
                else if (sum>0)
                    r--;
                else{
                    result.push_back(vector{nums[i],nums[l],nums[r]});
                    /*Compare if the same current elements pointed by L and R are same as next elements. If the next left and
right elements are not duplicates. Then increament the pointer for the next set.*/
                    while(l<r && nums[l] == nums[l+1])
                        l++;
                    while(l<r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }

        return result;
    }
};

/*
Approach for this Problem:
Sort the input array
Initialize a set to store the unique triplets and an output vector to store the final result
Iterate through the array with a variable i, starting from index 0.
Initialize two pointers, j and k, with j starting at i+1 and k starting at the end of the array.
In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0. If it is, insert the triplet into the set and increment j and decrement k to move the pointers.
If the sum is less than 0, increment j. If the sum is greater than 0, decrement k.
After the while loop, iterate through the set and add each triplet to the output vector.
Return the output vector

Time Complexity and Space Complexity:
Time complexity: O(n^2 logn) // where n is the size of array
Sorting takes O(nlogn) time and loop takes O(n^2) time, So the overall time complexity is O(nlogn + n^2 logn) - O(n^2 logn)
Space complexity: O(n) // for taking hashset.
*/

/Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};