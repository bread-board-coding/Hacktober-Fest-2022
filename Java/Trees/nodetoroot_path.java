import java.util.*;

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

  public static boolean nodeToRootPath(TreeNode root, int data, ArrayList<TreeNode> path) {
    if (root == null)
      return false;
    if (root.val == data) {
      path.add(root);
      return true;
    }

    boolean res = nodeToRootPath(root.left, data, path) || nodeToRootPath(root.right, data, path);
    if (res)
      path.add(root);

    return res;
  }

  public static ArrayList<TreeNode> nodeToRootPath(TreeNode root, int data) {
    ArrayList<TreeNode> path = new ArrayList<>();
    nodeToRootPath(root, data, path);
    return path;
  }

  // input_section=================================================

  public static TreeNode createTree(int[] arr, int[] IDX) {
    if (IDX[0] > arr.length || arr[IDX[0]] == -1) {
      IDX[0]++;
      return null;
    }
    TreeNode Treenode = new TreeNode(arr[IDX[0]++]);
    Treenode.left = createTree(arr, IDX);
    Treenode.right = createTree(arr, IDX);

    return Treenode;
  }

  public static void solve() {
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++)
      arr[i] = scn.nextInt();

    int[] IDX = new int[1];
    TreeNode root = createTree(arr, IDX);

    int data = scn.nextInt();
    ArrayList<TreeNode> ans = nodeToRootPath(root, data);
    if (ans.size() == 0)
      System.out.println();
    for (TreeNode node : ans)
      System.out.print(node.val + " ");

  }

  public static void main(String[] args) {
    solve();
  }
}                         
