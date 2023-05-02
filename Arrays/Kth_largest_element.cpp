/*
Intuition:
The problem asks to find the kth largest element in an array. One way to solve this problem is to sort the array and return the kth element from the end (i.e., kth largest element). However, the time complexity of this approach would be O(nlogn) due to the sorting process.

Approach:
We can use a heap data structure to efficiently find the kth largest element in the array. There are two types of heaps we can use for this problem: a min heap and a max heap.

Min Heap:
We can use a min heap to keep track of the k largest elements seen so far. We iterate over the array, and for each element, we insert it into the heap. If the size of the heap becomes larger than k, we remove the minimum element from the heap. At the end, the top element of the heap will be the kth largest element in the array.

Max Heap:
We can also use a max heap to keep track of the k largest elements seen so far. We initialize the heap with all the elements in the array. We then pop the top element from the heap k-1 times to get the kth largest element in the array.

Complexity:
Time complexity:
Min Heap: The time complexity of this approach is O(nlogk), where n is the size of the array and k is the number of largest elements we need to keep track of in the heap. We iterate over n elements and each heap operation takes logk time.

Max Heap: The time complexity of this approach is O(nlogn), where n is the size of the array. We initialize the heap with n elements, and each heap operation takes logn time.

Space complexity:
Min Heap: The space complexity of this approach is O(k), where k is the number of largest elements we need to keep track of in the heap.

Max Heap: The space complexity of this approach is O(n), where n is the size of the array as we need to store all the elements in the heap.

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
MIN_HEAP

3
2 3
1 2 3 <- greater than 2
pop -> 2 3
2 3 5
3 5
5 6
4 5 6
5 6 <- the top is Kth largest number
https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
*/

//MIN_HEAP
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> min_heap;
       for(int num : nums) {
           min_heap.push(num);
           if(min_heap.size() > k) {
               min_heap.pop();
           }
       }

       return min_heap.top();
    }
};

//Geeks for geeks https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

/*MAX heap
After insertion: 6 5 4 3 2 1
After K-1 iterations --> 1 top will be 5
return top
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> max_heap(nums.begin(), nums.end());
       for(int i = 0; i < k -1; i++) {
           max_heap.pop();
       }
       return max_heap.top();
    }
};