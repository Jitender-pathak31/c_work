#include <stdio.h>
#include <stdlib.h>

// create a binary tree

typedef struct tree{
    int val;
    struct tree * left;
    struct tree * right;
} tree;

// function to create a new Node
tree * create(int val){
    tree * newNode = (tree*)malloc(sizeof(tree));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert nodes in level order;
tree * insert(int arr[], int i, int n){ // index and number of elements in a array
    if(i >=n) return NULL;

    tree * root = create(arr[i]);
    root->left = insert(arr, 2*i+1, n);
    root->right = insert(arr,2*i+2, n);

    return root;
}

// in-order traversal (left->root->right)
void inOrderTraversal(tree * root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void printTree(tree * root, int space){
    if(root == NULL) return;

    space += 5; 

    printTree(root->right, space);
    printf("\n");
    for(int i = 0; i < space; i++){
        printf(" ");
    }
    printf("%d\n", root->val);

    printTree(root->left, space);
    
}

// main (driver) function
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,14}; //Test array
    int n = sizeof(arr)/sizeof(arr[0]);

    tree * root = insert(arr, 0, n);

    printf("Inorder Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Binary tree structure: \n");
    printTree(root, 0);

    return 0;
}