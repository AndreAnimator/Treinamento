// Binary Tree in C++

#include <stdlib.h>

#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
};

// New node creation
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return (node);
}

struct node *insertNode(struct node *temp, int key){
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(temp == NULL)
    {
        temp = newNode(key);
    }
    // If the given key is greater than
    // node's key then go to right subtree
    else if(temp->data < key){
        temp->right = insertNode(temp->right, key);
        temp->right->parent = temp;
    }
    else
    {
        temp->left = insertNode(temp->left, key);
        temp->left->parent = temp;
    }
    return temp;
}

// Traverse Preorder
void traversePreOrder(struct node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

int main() {
    struct node *tree = NULL;
    struct node *empty;
    int C = 0;
    int N = 0;
    int S = 0;
    cin >> C;
    for(int i = 0; i < C; i++){
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> S;
            // 8 3 10 14 6 4 13 7 1
            tree = insertNode(tree, S);
        }
        cout << "Case " << i + 1 << ":" << endl;
        cout << "Pre.:";
        traversePreOrder(tree);
        cout << endl;
        cout << "In..:";
        traverseInOrder(tree);
        cout << endl;
        cout << "Post:";
        traversePostOrder(tree);
        cout << endl << endl;
        tree = empty;
    }
}
