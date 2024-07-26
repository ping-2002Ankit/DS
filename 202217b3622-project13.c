#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node* newNode(int val) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = val;
  temp->left = temp->right = NULL;
  return temp;
}

void inorderTraversal(Node* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

Node* deleteNode(Node* root, int key) {
  if (root == NULL) return root;

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node with one or no child
    if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children: Get inorder successor (smallest in right subtree)
    Node* temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main() {
  Node* root = NULL;
  root = newNode(29);
  root->left = newNode(5);
  root->right = newNode(30);
  root->left->left = newNode(1);
  root->left->right = newNode(15);
  root->right->left = newNode(25);
  root->right->right = newNode(40);
  root->left->right->left = newNode(9);
  root->left->right->right = newNode(45);
  root->right->left->left = newNode(7);
  root->right->left->right = newNode(12);
  root->right->right->left = newNode(42);

  printf("Inorder traversal before deletion: ");
  inorderTraversal(root);
  printf("\n");

  root = deleteNode(root, 20);

  printf("Inorder traversal after deletion: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}
