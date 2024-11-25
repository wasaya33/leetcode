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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(slow &&  fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    ListNode* next = nullptr;

    slow->next=nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev to current
        curr = next;        // Move curr to next
    }

    int ans=0;
    while(head && prev){
        ans=max(ans,head->val+prev->val);
        head=head->next;
        prev=prev->next;
    }
        

        return ans;
    }
};