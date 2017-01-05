#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void print_tree(TreeNode *root);
void destroy_tree(TreeNode *root);

#endif
