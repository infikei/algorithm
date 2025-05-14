// Solve 2025-05-14

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) { this.val = val; }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class LeetCode_0104_solution2 {

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        ArrayDeque<TreeNode> bfsQue = new ArrayDeque<TreeNode>();
        bfsQue.addLast(root);
        int depth = 0;

        while (!bfsQue.isEmpty()) {
            depth++;
            int iter = bfsQue.size();

            while (iter-- > 0) {
                TreeNode cur = bfsQue.pollFirst();

                if (cur.left != null) {
                    bfsQue.addLast(cur.left);
                }

                if (cur.right != null) {
                    bfsQue.addLast(cur.right);
                }
            }
        }

        return depth;
    }

}
