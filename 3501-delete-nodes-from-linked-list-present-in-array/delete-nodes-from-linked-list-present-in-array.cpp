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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> st (nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* temp = head;

        while(temp != nullptr){
            if(st.find(temp->val) == st.end()){
                curr -> next = new ListNode(temp->val);
                curr = curr->next;
            }
            temp = temp -> next;
        }

        return dummy -> next;


    }
};