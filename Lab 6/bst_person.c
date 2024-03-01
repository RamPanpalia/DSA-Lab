#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
}Person;

typedef struct node {
    Person value;
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

Node *new_node(Person value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print(Person p){
    printf("ID: %d,\n",p.id);
    printf("Name: %s,\n",p.name);
    printf("Age: %d,\n",p.age);
    printf("Height: %d,\n",p.height);
    printf("Weight: %d,\n",p.weight);
}

Person createPerson(int id, char* name, int age, int height, int weight){
    Person p;
    p.id=id;
    p.name=name;
    p.age=age;
    p.height=height;
    p.weight=weight;
    return p;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        printf("null ");
        return;
    }
    traverse_in_order(node->left);
    print(node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        printf("null ");
        return;
    }
    print(node->value);
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
    print(node->value);
}

void insert(BST *bst, Person value)
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
        if (value.height < current->value.height) 
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

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value.height) 
        {
            return 1;
        } 
        else if (key < current->value.height) 
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
    return current->value.height;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value.height;
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
            if (node->value.height < current->value.height)
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
            if (node->value.height < current->value.height)
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
            if (node->value.height < current->value.height)
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

void removeHalfNodes(Node* root){
    if(root->left==NULL && root->right==NULL) return;
    if(root->left==NULL){
        root->right=NULL;
        free(root->right);
        return;
    }
    if(root->right==NULL){
        root->left=NULL;
        free(root->left);
        return;
    }
    removeHalfNodes(root->left);
    removeHalfNodes(root->right);
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    insert(bst, createPerson(1,"Ramesh",16, 101, 62));
    insert(bst, createPerson(2,"Rahul",19, 106, 63));
    insert(bst, createPerson(3,"Gandhi",36, 103, 64));
    insert(bst, createPerson(4,"Rohit",56, 105, 66));
    insert(bst, createPerson(5,"Ram",21, 107, 69));
    insert(bst, createPerson(6,"Umesh",46, 109, 75));
    insert(bst, createPerson(7,"Soniya",36, 105, 45));
    insert(bst, createPerson(8,"Bumrah",26, 110, 75));
    insert(bst, createPerson(9,"Gumrah",32, 111, 61));
    insert(bst, createPerson(10,"Virat",36, 126, 66));
    insert(bst, createPerson(11,"Kohli",26, 116, 63));
    traverse_in_order(bst->root);
    printf("\n");
    printf("Max = %d\n", find_max(bst));
    printf("Min = %d\n", find_min(bst));
    printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    printf("Successor of root = %d\n", successor(bst->root)->value);
    delete(bst, bst->root->left);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root->right);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root);
    traverse_in_order(bst->root);
    printf("\n");
    return 0;
}