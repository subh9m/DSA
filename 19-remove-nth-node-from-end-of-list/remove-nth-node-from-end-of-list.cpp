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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> list;
        ListNode* temp = head;
        while(temp != nullptr) {
            list.push_back(temp->val);
            temp = temp -> next;
        }
        int x = list.size();
        for(int i = x - n ; i < x - 1; i++) {
            list[i] = list[i+1];
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i = 0; i < x - 1; i++) {
            ListNode* n = new ListNode(list[i]);
            curr -> next = n;
            curr = curr -> next;
        }
        return dummy -> next;
    }
};