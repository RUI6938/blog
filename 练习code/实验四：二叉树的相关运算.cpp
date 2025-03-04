#include <iostream>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} TreeNode, *Tree;

// ���������д���������
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

// �������������
void preOrderTraversal(Tree root) {
    if (root!= NULL) {
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// �������������
void inOrderTraversal(Tree root) {
    if (root!= NULL) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// �������������
void postOrderTraversal(Tree root) {
    if (root!= NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

int main() {
    Tree root;

    std::cout << "�밴������������������ڵ�ֵ���� '@' ��ʾ�սڵ㣩��" << std::endl;
    createBinaryTree(&root);

    std::cout << "���������������������ʵĽ�㣺";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "���������������������ʵĽ�㣺";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "���������������������ʵĽ�㣺";
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
