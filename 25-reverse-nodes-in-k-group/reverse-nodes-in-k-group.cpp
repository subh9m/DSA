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
    ListNode* getkthNode(ListNode* head, int k){
        while(head && k > 0){
            k--;
            head = head->next;
        }
        return head;
    }

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp){
            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;
            temp = front;

        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp != nullptr){
            ListNode* kthNode = getkthNode(temp, k-1);

            if(kthNode == nullptr){
                if(prevLast){
                prevLast -> next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            reverseLinkedList(temp);

            if(temp == head){
                head = kthNode;
            } else{
                prevLast -> next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};