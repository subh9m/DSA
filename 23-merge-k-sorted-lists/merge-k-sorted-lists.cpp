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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>>q;
        if(lists.size()==0) return nullptr;

        int n = lists.size();
        for(int i = 0; i < n; i++) {
            ListNode* temp = lists[i];
            while(temp != nullptr){
                q.push(temp->val);
                temp=temp->next;
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!q.empty()){
            int a = q.top();
            q.pop();
            ListNode* n = new ListNode(a);
            if(head == nullptr && tail == nullptr){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
        return head;
    }
};