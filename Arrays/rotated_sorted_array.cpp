class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l<=h){
            if(nums[l]<=nums[h])
                return nums[l];
            int mid = (l+h)/2;
            if(nums[mid]>nums[h]){
                l = mid+1;
            } else{
               h = mid; //done to check the value pointed by mid as well, we're not checking mid value explicitly.
            }
        }
        return -1;
    }
};
