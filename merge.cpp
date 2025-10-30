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
ListNode* merger(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy; 

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int cunt = 1;
        int n = lists.size();

        while (cunt < n) {
            for (int i = 0; i + cunt < n; i += cunt * 2) {
                lists[i] = merger(lists[i], lists[i + cunt]);
            }
            cunt *= 2;
        }

        return lists[0];
    }
};
