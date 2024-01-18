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
    vector<ListNode*> v;
    ListNode* merge(ListNode* L1, ListNode* L2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (L1 && L2) {
            if (L1->val < L2->val) {
                tail->next = L1;
                L1 = L1->next;
            } else {
                tail->next = L2;
                L2 = L2->next;
            }
            tail = tail->next;
        }
        // while (L1) {
        //     tail->next = L1;
        //     L1 = L1->next;
        //     tail = tail->next;
        // }
        // while (L2) {
        //     tail->next = L2;
        //     L2 = L2->next;
        //     tail = tail->next;
        // }
        if (L1) tail->next = L1;
        if (L2) tail->next = L2;
        return head->next;
    }
    ListNode* mergeLists(int st, int ed) {
        if (st > ed) return NULL;
        if (st == ed)
            return v[st];
        int mid = (st + ed) / 2;
        ListNode* L1 = mergeLists(st, mid);
        ListNode* L2 = mergeLists(mid + 1, ed);
        return merge(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        int n = lists.size();
        v = lists;
        return mergeLists(0, n - 1);
    }
};