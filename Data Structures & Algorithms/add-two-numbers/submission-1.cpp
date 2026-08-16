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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* current = &result;
        int carry = 0;

        while(l1 && l2) {
            int sum = carry + l1->val + l2->val;
            current->next = new ListNode(sum%10);
            current = current->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int sum = l1->val + carry;
            current->next = new ListNode(sum%10);
            current = current->next;
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2) {
            int sum = l2->val + carry;
            current->next = new ListNode(sum%10);
            current = current->next;
            carry = sum/10;
            l2 = l2->next;
        }

        if(carry) current->next = new ListNode(carry);

        return result.next;
    }
};
