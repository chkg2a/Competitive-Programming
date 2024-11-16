#include <bits/stdc++.h>
#include <chkg2a/fn_bst.h>
using namespace std;
using namespace chk;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {

    int res = 0;
    diameter(root, res);
    return res;
  }

private:
  int diameter(TreeNode *curr, int &res) {

    if (!curr)
      return 0;

    int left = diameter(curr->left, res);
    int right = diameter(curr->right, res);

    res = std::max(res, left + right);

    return std::max(left, right) + 1;
  }
};

int main() {
  Solution sol;

  return 0;
}
