// Solve 2026-06-14

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class LC_2130 {

    public int pairSum(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        ListNode node = head;

        while (node != null) {
            list.add(node.val);
            node = node.next;
        }

        int n = list.size();
        int mx = 0;

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            mx = Math.max(mx, list.get(i) + list.get(j));
        }

        return mx;
    }

}
