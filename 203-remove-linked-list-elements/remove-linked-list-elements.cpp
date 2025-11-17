/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* toDelete = cur->next;
                cur->next = cur->next->next;
                delete toDelete;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
