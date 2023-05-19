/*
 Container With Most Water
 Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case,
the max area of water (blue section) the container can contain is 49.

Brute force*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea = INT_MIN, area;
        for(int i =0; i<n; i++){
            for(int j = i;j<n;j++) {
                area = min(height[i],height[j])*(j-i);
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};

//Two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxarea = INT_MIN, area;
        //shrinking window, left/right initially at endpoints, shift the pointer with min height
        while(l<r){
            area = min(height[l],height[r])*(r-l);
            maxarea = max(maxarea, area);
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};