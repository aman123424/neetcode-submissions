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
    ListNode* reverseList(ListNode* head) {
        //Brute Force, created an array to store all the values and then create     Nodes
        if(head == NULL) return NULL;
        vector<int> values;

        ListNode* temp = head;

        while(temp->next != NULL) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        values.push_back(temp->val);

        int n = values.size();
        ListNode* newHead = new ListNode(values[n - 1]);
        ListNode* current = newHead;

        for(int i = n - 2; i >= 0; i--) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }

        return newHead;
    }
};
