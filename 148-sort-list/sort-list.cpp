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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> list;
        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp-> next;
        }
        sort(list.begin(), list.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i = 0; i < list.size(); i++){
            ListNode* n = new ListNode(list[i]);
            curr -> next = n;
            curr = curr -> next;
        }
        return dummy -> next;
    }
};