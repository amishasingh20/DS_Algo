//First Attempt --> edge case [1,3] failing target is 3
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r=nums.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(target < nums[l] && nums[l]<nums[mid]){
                l = mid+1;
            }
            else {
                r = mid -1;
            }
        }
        return -1;
    }
};