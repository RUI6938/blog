#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �����½ڵ�
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ����ڵ㵽������
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// ���Ҷ�ӽ��
void printLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->val);
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

// ͳ��Ҷ�ӽ������
int countLeaves(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// ����������߶�
int treeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight? leftHeight : rightHeight) + 1;
}

// �ͷŶ������ڴ�
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;
    // ����һЩ�ڵ㹹��������
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    printf("Ҷ�ӽ�㣺");
    printLeaves(root);
    printf("\n");

    int leafCount = countLeaves(root);
    printf("Ҷ�ӽ��������%d\n", leafCount);

    int height = treeHeight(root);
    printf("�������߶ȣ�%d\n", height);

    // �ͷŶ������ڴ�
    freeTree(root);

    return 0;
}
