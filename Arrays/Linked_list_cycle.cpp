// Detect the cycle in linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * TC: O(n) SC: O(n)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;

        while(head != nullptr) {
            if(s.find(head) != s.end()) {
                return true;
            }

            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

/*Linked List Cycle - Floyd's Tortoise and Hare(slow and fast pointer)
If there is a cycle in the list then f and s will be equal in the iteration of list
TC: O(n) SC: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s = head,*f = head;
        //if fast pointer reaches null then no cycle in the linked list.
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s==f)
                return true;
        }
        return false;
    }
};