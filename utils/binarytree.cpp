#include <iostream>
#include "binarytree.h"

using std::cout;
using std::endl;

void print_tree(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

void destroy_tree(TreeNode *root) {
    if (root) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
    }
}
