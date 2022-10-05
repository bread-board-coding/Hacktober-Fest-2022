class Solution {
  static class pair {
    int data;
    int height;
    pair(int data) {
      this.data = data;
      this.height = 1;
    }
    pair(int data, int height) {
      this.data = data;
      this.height = height;
    }
  }

  public int max = 0;

  public pair func(TreeNode node) {
    if (node == null) {
      pair base = new pair(Integer.MIN_VALUE, 0);
      return base;
    }

    pair left = func(node.left);
    pair right = func(node.right);
    pair me = new pair(node.val);

    if (me.data == left.data && me.data == right.data) {
      max = Math.max(max, left.height + right.height + me.height);
      me.height = 1 + Math.max(left.height, right.height);
      return me;
    } else if (me.data != left.data && me.data != right.data) {
      max = Math.max(max, Math.max(left.height, Math.max(right.height, 1)));
      return me;
    } else if (me.data == left.data) {
      me.height += left.height;
      max = Math.max(max, Math.max(me.height, right.height));
      return me;
    } else if (me.data == right.data) {
      me.height += right.height;
      max = Math.max(max, Math.max(me.height, left.height));
      return me;
    }

    return null;
  }

  public int longestUnivaluePath(TreeNode root) {
    if (root == null) return 0;
    pair ans = func(root);
    return max - 1;
  }
}
                                
