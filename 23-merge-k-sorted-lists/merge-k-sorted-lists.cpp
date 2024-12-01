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
#include <queue>

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;
        for (auto list : lists) {
            if (list) minHeap.push(list);
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            current->next = smallest;
            current = current->next;
            if (smallest->next) minHeap.push(smallest->next);
        }
        return dummy->next;
    }
};
