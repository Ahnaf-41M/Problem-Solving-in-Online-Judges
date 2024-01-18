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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cur = head, *prev = head;
        while (cur) {
            len++, cur = cur->next;
        }
        if (len == n) {
            return head->next;
        }
        cur = head;
        len -= n;
        while (len > 0) {
            prev = cur;
            cur = cur->next;
            len--;
        }
        prev->next = cur->next;
        return head;
    }
};