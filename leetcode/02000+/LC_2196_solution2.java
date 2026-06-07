// Solve 2026-06-07

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

class LC_2196_solution2 {

    public TreeNode createBinaryTree(int[][] descriptions) {
        TreeNode[] nodes = new TreeNode[100001];
        Set<Integer> children = new TreeSet<>();

        for (int i = 0; i < descriptions.length; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if (nodes[parent] == null) {
                nodes[parent] = new TreeNode(parent);
            }

            if (nodes[child] == null) {
                nodes[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                nodes[parent].left = nodes[child];
            } else {
                nodes[parent].right = nodes[child];
            }

            children.add(child);
        }

        for (int i = 0; i < descriptions.length; i++) {
            if (!children.contains(descriptions[i][0])) {
                return nodes[descriptions[i][0]];
            }
        }

        return null;
    }

}
