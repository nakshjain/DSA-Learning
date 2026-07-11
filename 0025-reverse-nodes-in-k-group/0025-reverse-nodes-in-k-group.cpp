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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* tmpHead = head;
        ListNode* tmpTail = head;
        int count=k;
        while(tmpTail){
            count--;
            if(!count){
                ListNode* next = tmpTail->next;
                tmpTail->next=NULL;
                tail->next=reverseLL(tmpHead);
                tail=tmpHead;
                tmpHead=next;
                tmpTail=next;
                count=k;
            } else tmpTail = tmpTail->next;
        }
        tail->next=tmpHead;
        return dummy.next;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* pre=NULL;
        while(head){
            ListNode* next = head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};