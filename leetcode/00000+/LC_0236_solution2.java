// Solve 2025-05-15

import java.util.*;

class TreeNode {
    int val;
    int depth;
    TreeNode left;
    TreeNode right;
    TreeNode parent;

    TreeNode(int x) { val = x; }
}

class LeetCode_0236_solution2 {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        ArrayDeque<TreeNode> bfsQue = new ArrayDeque<TreeNode>();
        bfsQue.addLast(root);
        root.depth = 1;

        while (!bfsQue.isEmpty()) {
            TreeNode cur = bfsQue.pollFirst();

            if (cur.left != null) {
                cur.left.parent = cur;
                cur.left.depth = cur.depth + 1;
                bfsQue.addLast(cur.left);
            }

            if (cur.right != null) {
                cur.right.parent = cur;
                cur.right.depth = cur.depth + 1;
                bfsQue.addLast(cur.right);
            }
        }

        while (p.depth > q.depth) {
            p = p.parent;
        }

        while (p.depth < q.depth) {
            q = q.parent;
        }

        while (p != q) {
            p = p.parent;
            q = q.parent;
        }

        return p;
    }

}
