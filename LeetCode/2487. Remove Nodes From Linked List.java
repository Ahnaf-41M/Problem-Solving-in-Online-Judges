/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode reverseList(ListNode head) {
        ListNode prevNode = head;
        ListNode curNode = head.next;
        prevNode.next = null;
        while (curNode != null) {
            ListNode nextNode = curNode.next;
            curNode.next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        return prevNode;
    }

    public ListNode removeNodes(ListNode head) {
        if (head.next == null) {
            return head;
        }
        head = reverseList(head);

        ListNode prevNode = head;
        ListNode curNode = head.next;
        prevNode.next = null;
        while (curNode != null) {
            if (curNode.val < prevNode.val) {
                curNode = curNode.next;
            } else {
                ListNode nextNode = curNode.next;
                curNode.next = prevNode;
                prevNode = curNode;
                curNode = nextNode;
            }
        }

        return prevNode;
    }
}