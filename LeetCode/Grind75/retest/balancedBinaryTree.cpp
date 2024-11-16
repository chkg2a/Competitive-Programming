#include <bits/stdc++.h>
#include <chkg2a/fn_bst.h>
using namespace std;
using namespace chk;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (checkHeight(root) != -1);
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
