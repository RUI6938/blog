#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ����ڵ�
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// �������������������Ϊ����
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

// �ͷŶ������ڴ�
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = NULL;
    // ����ڵ㹹��������
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    // ����������������
    printf("���������������");
    inorderTraversal(root);
    printf("\n");

    // �ͷŶ������ڴ�
    freeTree(root);

    return 0;
}
