import java.util.Scanner;

public class Main {
  public static Scanner scn = new Scanner(System.in);

  public static class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    TreeNode(int val) {
      this.val = val;
    }
  }

  public static int[] diameter(TreeNode root) {
    if (root == null)
      return new int[] { 0, -1 }; // dia,height

    int[] la = diameter(root.left);
    int[] ra = diameter(root.right);

    int dia = Math.max(Math.max(la[0], ra[0]), la[1] + ra[1] + 2);
    int height = Math.max(la[1], ra[1]) + 1;
    return new int[] { dia, height };
  }

  public static int diameterOfBinaryTree(TreeNode root) {
    return diameter(root)[0];
  }

  // input_Section=================================================

  public static TreeNode createTree(int[] arr, int[] IDX) {
    if (IDX[0] > arr.length || arr[IDX[0]] == -1) {
      IDX[0]++;
      return null;
    }

    TreeNode node = new TreeNode(arr[IDX[0]++]);
    node.left = createTree(arr, IDX);
    node.right = createTree(arr, IDX);

    return node;
  }

  public static void solve() {
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = scn.nextInt();

    int[] IDX = new int[1];
    TreeNode root = createTree(arr, IDX);
    System.out.println(diameterOfBinaryTree(root));
  }

  public static void main(String[] args) {
    solve();
  }
}                                                           
