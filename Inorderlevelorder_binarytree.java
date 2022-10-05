import java.util.*;

public class Main {
  public static Scanner scn = new Scanner(System.in);

  static class TreeNode {
    int val;
    TreeNode left = null, right = null;

    TreeNode(int val) {
      this.val = val;
    }
  }

  public static TreeNode buildTree(int inorder[], int levelOrder[], int isi, int iei) {
    if (isi > iei)
      return null;

    TreeNode root = new TreeNode(levelOrder[0]);

    int idx = isi;
    while (levelOrder[0] != inorder[idx])
      idx++;

    HashSet<Integer> s = new HashSet<>();
    for (int i = isi; i < idx; i++)
      s.add(inorder[i]);

    int n = iei - isi + 1;
    int[] lLevel = new int[s.size()]; // Left
    int[] rLevel = new int[n - s.size()]; // Right
    int li = 0, ri = 0;
    for (int i = 1; i < n; i++) {
      if (s.contains(levelOrder[i]))
        lLevel[li++] = levelOrder[i];
      else
        rLevel[ri++] = levelOrder[i];
    }

    root.left = buildTree(inorder, lLevel, isi, idx - 1);
    root.right = buildTree(inorder, rLevel, idx + 1, iei);
    return root;
  }

  public static TreeNode buildTree(int[] inorder, int[] levelOrder) {
    int n = levelOrder.length;
    return buildTree(inorder, levelOrder, 0, n - 1);
  }

  // input_section=================================================

  public static void display(TreeNode node) {
    if (node == null)
      return;

    StringBuilder sb = new StringBuilder();
    sb.append((node.left != null ? node.left.val : "."));
    sb.append(" -> " + node.val + " <- ");
    sb.append((node.right != null ? node.right.val : "."));

    System.out.println(sb.toString());

    display(node.left);
    display(node.right);

  }

  public static void solve() {
    int n = scn.nextInt();

    int[] InOrder = new int[n];
    for (int i = 0; i < n; i++)
      InOrder[i] = scn.nextInt();

    int[] LevelOrder = new int[n];
    for (int i = 0; i < n; i++)
      LevelOrder[i] = scn.nextInt();

    TreeNode root = buildTree(InOrder, LevelOrder);
    display(root);
  }

  public static void main(String[] args) {
    solve();
  }

}
                                
