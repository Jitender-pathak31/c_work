#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    // pointer to the right and left
    struct Node *right, *left;
   
} Node;

// creating a new node

Node* createNode(int val){

    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// inserting value into newNode

Node *insertValue(int arr[], int i, int n){ // i is index, n is elements
    if(i >= n) return NULL; // array is empty

    Node *root = createNode(arr[i]);
    root->left = insertValue(arr, 2*i+1, n);
    root->right = insertValue(arr, 2*i+2, n);

    return root;
}

int heightOfRoot(Node *root){
    if(root == NULL) return -1; // height is zero, is empty

    int leftheight = heightOfRoot(root->left);
    int rightheight = heightOfRoot(root->right);

    return 1 + (leftheight > rightheight ? leftheight:rightheight);

}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / (sizeof(arr[0]));

    Node* root = insertValue(arr, 0, n);
    printf("Height of the tree is: %d\n", heightOfRoot);

    return 0;
}