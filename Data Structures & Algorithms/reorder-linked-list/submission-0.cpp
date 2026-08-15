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
    void reorderList(ListNode* head) {
        vector<int> elements;

        ListNode* temp = head;

        while(temp) {
            elements.push_back(temp->val);
            temp = temp->next;
        }

        int n = elements.size();
        ListNode* newHead = new ListNode(elements[0]);
        ListNode* curr = newHead;

        int count = 1;

        int i = 1;

        while(count != n) {
            //count is odd, pick from back
            if(count%2) {
                ListNode* node = new ListNode(elements[n-i]);
                curr->next = node;
                curr = node;
            }
            //count is even, pick from front
            else {
                ListNode* node = new ListNode(elements[i]);
                curr->next = node;
                curr = node;
                i++;
            }
            count++;
        }

        ListNode* temp2 = head;
        ListNode* curr2 = newHead;

        while(curr2) {
            temp2->val = curr2->val;
            temp2 = temp2->next;
            curr2 = curr2->next;
        }

    }
};
