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
    struct Compare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* tail=&dummy;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(ListNode* tmp: lists){
            if(tmp) pq.push(tmp);
        }
        while(!pq.empty()){
            ListNode* minNode = pq.top();
            pq.pop();
            tail->next=minNode;
            tail=tail->next;
            if(minNode->next) pq.push(minNode->next);
        }
        tail->next=NULL;
        return dummy.next;
    }
};