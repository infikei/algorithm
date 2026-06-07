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

class LC_2196 {

    int findRoot(int[][] descriptions) {
        Set<Integer> set = new TreeSet<>();

        for (int i = 0; i < descriptions.length; i++) {
            set.add(descriptions[i][0]);
        }

        for (int i = 0; i < descriptions.length; i++) {
            set.remove(descriptions[i][1]);
        }

        Iterator<Integer> iterator =  set.iterator();
        return iterator.next();
    }

    public TreeNode createBinaryTree(int[][] descriptions) {
        TreeNode[] nodes = new TreeNode[100001];

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
        }

        int root = findRoot(descriptions);
        return nodes[root];
    }

}
