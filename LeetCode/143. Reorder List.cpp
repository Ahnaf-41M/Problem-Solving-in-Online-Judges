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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* cur = head;
        while (cur) {
            v.push_back(cur);
            cur = cur->next;
        }
        int i = 0, j = v.size() - 1;
        cur = NULL;
        while (i <= j) {
            if (cur)
                cur->next = v[i];
            if (i == j) {
                cur = v[i];
                break;
            }
            v[i]->next = v[j];
            cur = v[j];
            i++, j--;
        }
        cur->next = NULL;
    }
};