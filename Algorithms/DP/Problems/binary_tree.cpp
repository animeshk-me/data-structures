// Note: This is the binary search tree implementation not a generic one.

#include<bits/stdc++.h>

using namespace std;

struct treeNode {
  int data;
  struct treeNode * left;
  struct treeNode * right;
};

struct treeNode * AddNode(struct treeNode * root, int num);
struct treeNode * CreateBabyNode(int num);
void InorderTraversal(struct treeNode * root);
int AddSum(struct treeNode * root);

int main() {
  struct treeNode * root = NULL;
  root = AddNode(root, 10);
  root = AddNode(root, 190);
  root = AddNode(root, 132);
  root = AddNode(root, 123);
  root = AddNode(root, 234);
  root = AddNode(root, 1223);
  root = AddNode(root, 122);
  root = AddNode(root, 49);
  root = AddNode(root, 133);
  root = AddNode(root, 1224);
  root = AddNode(root, 7);
  root = AddNode(root, -33);
  InorderTraversal(root);
  cout << "Sum = " << AddSum(root->right) << endl;

  return 0;
}


struct treeNode * AddNode(struct treeNode * root, int num) {
  if (root != NULL) {
    if (root->data > num) {
      if (root->left != NULL) {
        root->left = AddNode(root->left, num);
      } else {
        root->left = CreateBabyNode(num);
      }
    } else {
      if (root->right != NULL) {
        root->right = AddNode(root->right, num);
      } else {
        root->right = CreateBabyNode(num);
      }
    }
  } else {
    root = CreateBabyNode(num);
  }
  return root;
}

struct treeNode * CreateBabyNode(int num) {
  struct treeNode *temp = (struct treeNode*)malloc(sizeof(struct treeNode));
  temp->data = num;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void InorderTraversal(struct treeNode * root){
  if (root != NULL) {
    if (root->left != NULL)
      InorderTraversal(root->left);
    cout << root->data << " ";
    if (root->right != NULL)
      InorderTraversal(root->right);
  }
}

int AddSum(struct treeNode * root) {
  if (root == NULL)
    return 0;
  return (AddSum(root->left) + AddSum(root->right) + root->data);
}