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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next){
            return nullptr;
        }
        ListNode* temp = head;
        int Nodes = 0;
        while(temp != nullptr){
            Nodes++;
            temp = temp -> next;
        }
        if(Nodes == 1){
            delete head;
            return nullptr;
        }
        int mid = Nodes/ 2;
        temp = head;
        for(int i = 0; i < mid - 1; i++){
            temp = temp -> next;
        }
        
        ListNode* toDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete toDelete;
        return head;
    }
};