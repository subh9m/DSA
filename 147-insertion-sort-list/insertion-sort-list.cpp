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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>list;

        ListNode* temp = head;

        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }

        int n = list.size();

        for(int i = 1; i < n; i++){
            int key = list[i];
            int j = i-1;

            while(j >= 0 && list[j] > key){
                list[j+1] = list[j];
                j--;
            }
            list[j+1] = key;
        }

        ListNode* dummy = new ListNode(-1);
        temp = dummy;
        int i = 0;

        while(i < n){
            ListNode* n = new ListNode(list[i]);
            i++;
            temp->next = n;
            temp = temp->next;
        } 
        return dummy->next;
    }
};