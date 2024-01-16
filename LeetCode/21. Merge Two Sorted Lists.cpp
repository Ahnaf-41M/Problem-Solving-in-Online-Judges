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
    ListNode *head = NULL, *ans = NULL;
    void Insert(ListNode* tmp) {
        if (ans == NULL) {
            ans = new ListNode(tmp->val);
            head = ans;
        } else {
            ans->next = tmp;
            ans = tmp;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list2;

        while (p1 != NULL && p2 != NULL) {
            ListNode* tmp;
            if (p1->val < p2->val) {
                tmp = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                tmp = new ListNode(p2->val);
                p2 = p2->next;
            }
            Insert(tmp);
        }
        while (p1 != NULL) {
            ListNode* tmp = new ListNode(p1->val);
            Insert(tmp);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            ListNode* tmp = new ListNode(p2->val);
            Insert(tmp);
            p2 = p2->next;
        }
        return head;
    }
};