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
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if(!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;

        int sum = val1 + val2 + carry;
        
        int newCarry = sum/10;
        int newVal = sum%10;

        ListNode* nextNode= add((l1 ? l1->next : nullptr), (l2 ? l2->next : nullptr), newCarry);
        
        return new ListNode(newVal, nextNode);

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Recursive method
        return add(l1, l2, 0);
    }
};
