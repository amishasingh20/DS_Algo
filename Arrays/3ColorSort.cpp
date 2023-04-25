// 2 Pass-algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++) {
           if(nums[i] == 0 ) {count0++;}
           else if(nums[i]==1){count1++;}
           else{count2++;}
       }
       for(int i = 0; i< nums.size(); i++) {
           if (i<count0){nums[i]=0;}
           else if(i < (count0+count1)){ nums[i]=1;}
           else {nums[i]=2;}
       }
    }
};

// 1 Pass approach
/*
1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 || 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, h = nums.size() -1;
       while(m<=h) {
            if(nums[m]==0) {
                int tmp = nums[m];
                nums[m] = nums[l];
                nums[l] = tmp;
                m++;
                l++;
            }
            else if(nums[m]==2){
                int tmp = nums[m];
                nums[m] = nums[h];
                nums[h] = tmp;
                h--;
            }
            else{
                m++;
            }
        }
    }
};