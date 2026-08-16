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
    ListNode* mergeLinkedList(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if(list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next;
    }

    ListNode* merge(int left, int right, vector<ListNode*>& lists) {
        if(left == right) return lists[left];

        int mid = left + (right - left)/2;

        ListNode* head1 = merge(left, mid, lists);
        ListNode* head2 = merge(mid + 1, right, lists);

        return mergeLinkedList(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        return merge(0, lists.size() - 1, lists);
    }
};
