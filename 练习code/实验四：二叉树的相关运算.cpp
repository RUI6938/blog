#include <iostream>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} TreeNode, *Tree;

// 按先序序列创建二叉树
void createBinaryTree(Tree *root) {
    char ch;
    std::cin >> ch;

    if (ch == '@') {
        *root = NULL;
    } else {
        *root = (Tree)malloc(sizeof(TreeNode));
        (*root)->data = ch;
        createBinaryTree(&((*root)->left));
        createBinaryTree(&((*root)->right));
    }
}

// 先序遍历二叉树
void preOrderTraversal(Tree root) {
    if (root!= NULL) {
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 中序遍历二叉树
void inOrderTraversal(Tree root) {
    if (root!= NULL) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// 后序遍历二叉树
void postOrderTraversal(Tree root) {
    if (root!= NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

int main() {
    Tree root;

    std::cout << "请按先序序列输入二叉树节点值（用 '@' 表示空节点）：" << std::endl;
    createBinaryTree(&root);

    std::cout << "按先序遍历，依次输出访问的结点：";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "按中序遍历，依次输出访问的结点：";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "按后序遍历，依次输出访问的结点：";
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
