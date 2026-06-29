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
    int pairSum(ListNode* head) {
        vector<int>list;

        ListNode* temp = head;

        while(temp != nullptr){
            list.push_back(temp->val);
            temp = temp->next;
        }

        int maxSum = 0;
        int i = 0;
        int j = list.size() - 1;

        while(i < j){
            int sum = list[i++] + list[j--];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};