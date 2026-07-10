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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tmp=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode* reversedL=NULL;
        while(tmp){
            ListNode* nxt = tmp->next;
            tmp->next=reversedL;
            reversedL=tmp;
            tmp=nxt;
        }
        while(reversedL){
            ListNode* next = slow->next;
            ListNode* reversedN = reversedL->next;
            slow->next=reversedL;
            reversedL->next=next;
            slow=next;
            reversedL=reversedN;
        }
    }
};