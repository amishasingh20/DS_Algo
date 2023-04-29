/*
1. Brut force -> compare each number to the rest of the array to see if they are same. If yes then
true or else return false. Time complexity is O(n^2) and space complexity is O(1).

2. Sort the array and compare the adjacent elements to see if they are same. If yes then
true or else return false. Time complexity is O(nlog(n)) [logn added beacuse of sorting of the array] and space complexity is O(1).

3. Use set and check the size of the set is equal to size of array. if yes no duplicate or else duplicate.
Time complexity is O(1) and space complexity is O(n).

4. Use set and add each element to set. before adding check if the element is present in the set. If yes then
true or else return false.
To insert into a set time complexity is O(1) and we iterate through the array once so total time complexity is O(n) and space complexity is O(n).
*/

/*
A set is an associative container available in the C++ Standard Template Library(STL) that is used
for unique elements in a specific order, it internally uses the working principle of a Binary Search Tree to store elements.
Time complexity to insert each element is O(logn), to insert n elements O(nlogn)

Different Ways to Initialize a set in C++:

1. Initialization using the default constructor.
    set<int>New_set;

        // set.insert() method to
        // insert elements to the set
        New_set.insert(5);
2. Initialization using an Initializer List
    to pass a predefined list of elements (initializer_list) as an argument to the default constructor of the set
    set<int>New_set({4, 3, 9, 2, 0, 6});
3. Initialization Using an Array(providing starting and ending pointers)
    The elements can be added to the set using an array of the same data type.
    // Initialize an array of
    // integers
    int old_arr[] = {4, 3, 6, 1, 8};
    int n = (sizeof(old_arr) /
             sizeof(old_arr[0]));

    // Adding these elements stored
    // in the array
    set<int>New_set(old_arr,
                    old_arr + n);

4. Initialization Using a Vector (providing starting and ending pointers)
    One can store the elements to the set using a vector of the same data type.
    // Initialize a vector of integers
    vector<int>old_arr = {4, 1, 8, 2, 9};

    // Adding these elements
    // stored in the vector
    set<int>New_set(old_arr.begin(),
                    old_arr.end());

5. Initialization From Another Set Using the Copy Constructor
    One way to initialize a set is to copy contents from another set one after another by using the copy constructor.
     // Initialize an unordered_set
    // using default constructor
    set<int>old_set;

    // set.insert() method to insert
    // elements to the unordered_set
    old_set.insert(5);
    old_set.insert(3);
    old_set.insert(4);
    old_set.insert(1);
    old_set.insert(2);


    // Create a new_set where contents
    // of the previous set will be
    // copied using copy constructor
    set<int>New_set(old_set);

An unordered_set is an unordered associative container implemented using a hash table where keys are hashed into indices of a hash table so that the insertion is always randomized. All operations on the unordered_set take constant time O(1) on an average which can go up to linear time O(n) in the worst case which depends on the internally used hash function, but practically they perform very well and generally provide a constant time lookup operation.

The unordered_set can contain a key of any type – predefined or user-defined data structure but all the keys must be unique. It is defined inside <unordered_set> header file as std::unordered_set class.
Time complexity to insert each element is O(1), to insert n elements O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set_dup({nums.begin(), nums.end()});
        if(set_dup.size() == nums.size())
            return false;

        return true;
    }
};