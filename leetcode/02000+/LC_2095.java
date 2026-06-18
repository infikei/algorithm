// Solve 2026-06-16

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class LC_2095 {
    public ListNode deleteMiddle(ListNode head) {
        ArrayList<ListNode> list = new ArrayList<>();
        ListNode cur = head;

        while (cur != null) {
            list.add(cur);
            cur = cur.next;
        }

        int n = list.size();
        
        if (n == 1) {
            return null;
        }

        cur = list.get(n / 2);
        ListNode prv = list.get(n / 2 - 1);
        prv.next = cur.next;
        cur.next = null;

        return head;
    }
}