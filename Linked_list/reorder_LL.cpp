/*
Two pointer Approach [Tortoise and Hare method]:-
This approach is much faster and efficient in terms of Time and Space Complexity the only drawback is that it looks a little bit lengthy but trust me it's easy to understand.

Two pointer Approach Algorithm:

First let's take two pointers name it as half and temp . temp is faster than half by 1.
When temp reaches the end of linkedlsit half reaches the middle element .So this is how the linkedlist will get divided in two halfes as the center will become a dividing node .
Now reverse the second half .
After reversing the second half, merge the first half and second half
Let's have a dy run before starting the code:-
Let's take the same example as above:

Linked list:[1,2,3,4,5]
* search for the central element, which will be three in our case
* split the list in two halfes that will be [1,2,3] and [4,5]
* Now reverse the second half that will be [5,4]
* Now merge both the halfes
[1,2,3]
	[5,4]
=>[1,5,2,4,3]

[1,2,3,4]

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head,*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondList = slow;
        ListNode *tmp, *prev = nullptr;
        while(secondList) {
            tmp = secondList->next;
            secondList->next = prev;
            prev = secondList;
            secondList = tmp;
        }

        ListNode *first = head, *second = prev;

        while(second && first) {
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

    }
};