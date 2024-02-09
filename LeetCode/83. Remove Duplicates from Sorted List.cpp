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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *prev = head, *cur = head;

        while (cur != NULL) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = prev->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};