#include <iostream>
#include <exception>
#include "binarytree.h"

using std::cout;
using std::cerr;

TreeNode* construct_core (
        const int *start_preorder, const int *end_preorder,
        const int *start_inorder, const int *end_inorder) {
    int root_val = start_preorder[0];
    TreeNode *root = new TreeNode(root_val);

    if (start_preorder == end_preorder) {
        if (start_inorder == end_inorder 
                && *start_preorder == *start_inorder) {
            return root;
        } else {
            cerr << "Invalid input." << std::endl; 
            return nullptr;
        }
    }

    const int *root_inorder = start_inorder;
    while (root_inorder <= end_inorder && *root_inorder != root_val) {
        ++root_inorder;
    }

    if (root_inorder == end_inorder && *root_inorder != root_val) {
        cerr << "Invalid input." << std::endl; 
        return nullptr;
    }

    int left_length = root_inorder - start_inorder;
    const int *left_preorder_end = start_preorder + left_length;
    if (left_length > 0) {
        root->left = construct_core(start_preorder + 1, left_preorder_end,
                start_inorder, root_inorder - 1);
    }
    if (left_length < end_preorder - start_preorder) {
        root->right = construct_core(left_preorder_end + 1, end_preorder,
                root_inorder + 1, end_inorder);
    }

    return root;
}

TreeNode* construct(const int *preorder, const int *inorder, const int len) {
    if (preorder == nullptr || inorder == nullptr || len <= 0) {
        return nullptr;
    }
    return construct_core(preorder, preorder + len - 1,
            inorder, inorder + len - 1);
}


void test(const char *test_name, const int *preorder, const int *inorder,
            int len) {
    if (test_name != nullptr) {
        cout << test_name << " begins: " << std::endl;
    }

    cout << "The preorder sequence is: ";
    for (int i = 0; i < len; i++) {
        cout << preorder[i] << " ";
    }
    cout << std::endl;

    cout << "The inorder sequence is: ";
    for (int i = 0; i < len; i++) {
        cout << inorder[i] << " ";
    }
    cout << std::endl;

    TreeNode *root = construct(preorder, inorder, len);

    print_tree(root);
    cout << std::endl;

    destroy_tree(root);
}

void test1() {
    const int len = 8;
    const int preorder[len] = {1, 2, 4, 7, 3, 5, 6, 8};
    const int inorder[len] = {4, 7, 2, 1, 5, 3, 8, 6};
    test("Test1", preorder, inorder, len);
}

//         1
//        /
//       2
//      /
//     3
//    /
//   4
//  /
// 5

void test2() {
    const int len = 5;
    const int preorder[len] = {1, 2, 3, 4, 5};
    const int inorder[len] = {5, 4, 3, 2, 1};
    test("Test2", preorder, inorder, len);
}


int main() {
    test1();
    test2();

    return 0;
}
