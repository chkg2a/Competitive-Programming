/* 110. Balanced Binary Tree
 *Given a binary tree, determine if it is 
height-balanced

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
*/
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private:
    int checkHeight(TreeNode* node) {
        if(node == NULL){
            return 0;
        }
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if(checkHeight(root) != -1) return true;
        else return false;
    }
};

int main () {
  BST root = NULL;
  root = addtoTree(root, 3);
  root = addtoTree(root, 2);
  root = addtoTree(root, 20);
  root = addtoTree(root, 15);
  root = addtoTree(root, 30); // 1

  /*root = addtoTree(root,5);*/
  /*root = addtoTree(root,4);*/
  /*root = addtoTree(root,3);*/
  /*root = addtoTree(root,2);*/
  /*root = addtoTree(root,1); // 0*/
  Solution sol;
  cout << sol.isBalanced(root);

  return 0;
}
