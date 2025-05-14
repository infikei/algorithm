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

class TreeNodeInfo {
    TreeNode node;
    int depth;

    TreeNodeInfo(TreeNode node, int depth) {
        this.node = node;
        this.depth = depth;
    }
}

class LeetCode_0104_solution3 {

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        ArrayDeque<TreeNodeInfo> bfsQue = new ArrayDeque<TreeNodeInfo>();
        bfsQue.addLast(new TreeNodeInfo(root, 1));
        int maxDep = 0;

        while (!bfsQue.isEmpty()) {
            TreeNodeInfo cur = bfsQue.pollFirst();
            maxDep = Math.max(maxDep, cur.depth);

            if (cur.node.left != null) {
                bfsQue.addLast(new TreeNodeInfo(cur.node.left, cur.depth + 1));
            }

            if (cur.node.right != null) {
                bfsQue.addLast(new TreeNodeInfo(cur.node.right, cur.depth + 1));
            }
        }

        return maxDep;
    }

}
