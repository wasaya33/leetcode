#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;
            ListNode* prev = dummy;

            while (prev->next != nullptr && prev->next->val < current->val) {
                prev = prev->next;
            }

            current->next = prev->next;
            prev->next = current;

            current = nextNode;
        }

        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }
};