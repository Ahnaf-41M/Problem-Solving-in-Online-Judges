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
        ListNode *cur = head, *last = head;
        // ListNode *ans = new ListNode(cur->val);
        ListNode *ans = NULL;

        while (cur != NULL) {
            ListNode *tmp = new ListNode(cur->val);
            if (ans == NULL) {
                ans = new ListNode(cur->val);
            }
            else {
                tmp->next = ans;
                ans = tmp;
            }
            cur = cur->next;
        }
        return ans;
    }
};