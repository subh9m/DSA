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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<int, vector<int>, greater<int>> q;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != nullptr) {
            q.push(temp1->val);
            temp1 = temp1 -> next;
        }
        while(temp2 != nullptr){
              q.push(temp2->val);
              temp2 = temp2 -> next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!q.empty()){
            int a = q.top();
            q.pop();
            ListNode* n = new ListNode(a);
            temp -> next = n;
            temp = temp -> next;
        }
        return dummy->next;
        
    }
};