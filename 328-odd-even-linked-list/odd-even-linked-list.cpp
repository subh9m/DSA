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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> Nodes;
        vector<int> odd;
        vector<int> even;
        ListNode* temp = head;
        while(temp != nullptr){
            int x = temp-> val;
            Nodes.push_back(x);
            temp = temp -> next;
        }
        for(int i = 0; i < Nodes.size(); i += 2) {
            odd.push_back(Nodes[i]);
        }

        for(int i = 1; i < Nodes.size(); i += 2) {
            even.push_back(Nodes[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* insert = dummy;
        for(int i = 0; i < odd.size(); i++){
            ListNode *n = new ListNode(odd[i]);
            insert -> next = n;
            insert = insert -> next;
        }
        for(int i = 0; i < even.size(); i++){
            ListNode *n = new ListNode(even[i]);
            insert -> next = n;
            insert = insert -> next;
        }
        return dummy->next;

    }
};