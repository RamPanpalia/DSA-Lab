#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        printf("null ");
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        printf("null ");
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
    if (node == NULL)
    {
        printf("null ");
        return;
    }
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int mxValBST(Node* root){
    if(root==NULL) return INT_MIN;
    int maxi=max(mxValBST(root->left),mxValBST(root->right));
    return max(root->value,maxi);
}

int mnValBST(Node* root){
    if(root==NULL) return INT_MAX;
    int mini=min(mnValBST(root->left),mnValBST(root->right));
    return min(root->value,mini);
}

bool isValidBST(Node* root){
    if(root==NULL) return true;
    if(root->value>=mxValBST(root->left) && root->value<=mnValBST(root->right)){
        return isValidBST(root->left) && isValidBST(root->right);
    }
    return false;
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

int height(Node* root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

// void giveMuktiToAllChildNodes(Node *atma){
//     if(atma==NULL) return;
//     giveMuktiToAllChildNodes(atma->left);
//     giveMuktiToAllChildNodes(atma->right);
//     // atma->left=NULL;
//     // atma->right==NULL;
//     // atma=NULL;
//     free(atma);
//     return;
// }

// void removeHalfNodes(Node* root){
//     if(root==NULL) return;
//     if(root->left!=NULL && root->right!=NULL){
//         removeHalfNodes(root->left);
//         removeHalfNodes(root->right);
//         return;
//     }
//     if(root->right!=NULL) giveMuktiToAllChildNodes(root->right);
//     if(root->left!=NULL) giveMuktiToAllChildNodes(root->left);
// }



void freeAll(Node *node){
    if(node==NULL) return;
    freeAll(node->left);
    freeAll(node->right);
    node=NULL;
    free(node);
    return;
}

void removeHalfNodes(Node* root){
    if(root==NULL) return;
    if(root->left!=NULL && root->right!=NULL){
        removeHalfNodes(root->left);
        removeHalfNodes(root->right);
        return;
    }
    if(root->right!=NULL) freeAll(root->right);
    if(root->left!=NULL) freeAll(root->left);
}

BST* constructBST(int *arrey, int n){
    BST *bst = new_bst();
    for(int i=0;i<n;i++) insert(bst,arrey[i]);
    return bst;
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    int array[] = {20,21,1,2,3,4,5,7};
    BST *bst = constructBST(array,8);
    // BST *bst = new_bst();
    // insert(bst, 2);
    // insert(bst, 1);
    // insert(bst, 3);
    // insert(bst, 4);
    // insert(bst, 5);
    // insert(bst, 6);
    // insert(bst, 7);
    // insert(bst, 8);
    // insert(bst, 12);
    // insert(bst, 11);
    // insert(bst, 13);
    // insert(bst, 14);
    // insert(bst, 15);
    // insert(bst, 16);
    // insert(bst, 17);
    // insert(bst, 18);
    traverse_in_order(bst->root);
    printf("\n");
    printf("Max = %d\n", find_max(bst));
    printf("Min = %d\n", find_min(bst));
    printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    printf("Successor of root = %d\n", successor(bst->root)->value);
    traverse_pre_order(bst->root);
    printf(" <= PreOrder Traversal\n");
    traverse_in_order(bst->root);
    printf(" <= InOrderTraversal\n");
    traverse_post_order(bst->root);
    printf(" <= PostOrderTraversal\nHeight: ");
    printf("%d", height(bst->root));
    printf("\n");
    removeHalfNodes(bst->root);
    traverse_in_order(bst->root);
    printf(" <= InOrderTraversal after removing halfNodes\n");

    printf("%s",isValidBST(bst->root)?"Valid":"InValid");
    // delete(bst, bst->root->left);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root->right);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root);
    // traverse_in_order(bst->root);
    printf("\n");
    return 0;
}