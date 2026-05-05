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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)return head;

        int size = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            size++;
            temp = temp->next;
        }

        k = k % size;
        if(k == 0)return head;

        temp -> next = head;
        int steps = size - k;

        ListNode* newTail = head;

        while(steps-1){
            newTail = newTail->next;
            steps--;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};