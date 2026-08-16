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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> elements;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* l = lists[i];

            while(l) {
                elements.push_back(l->val);
                l = l->next;
            }
        }

        sort(elements.begin(), elements.end());

        ListNode dummy(0);
        ListNode* current = &dummy;

        for(int i = 0; i < elements.size(); i++) {
            current->next = new ListNode(elements[i]);
            current = current->next;
        }

        return dummy.next;
    }
};
