#include<stdio.h>
#include<stdlib.h>

struct BST{
    int value;
    struct BST* left;
    struct BST* right;
};

typedef struct BST node;

node* create(){
    node *temp = (node*)malloc(sizeof(node));

    printf("Enter the value: ");
    scanf("%d",&(temp->value));
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

void insert(node* root, node* temp){
    if(temp->value>root->value){
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }

    if(temp->value<root->value){
        if(root->left!=NULL){
            insert(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }
}

void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }

}

void inorder(node *root){
    if(root!=NULL){
        preorder(root->left);
        printf("%d ",root->value);
        preorder(root->right);
    }

}

void postorder(node *root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->value);
    }
}

int main(){

    int n;
    node *root = NULL, *temp;

    printf("How many value's do you want to enter: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        temp = create();
        if(root==NULL){
            root=temp;
        }
        else
        {
            insert(root,temp);
        }
    }
    printf("\npre traval: \n");
    preorder(root);

    printf("\nin traval: \n");
    inorder(root);

    printf("\npost traval: \n");
    postorder(root);
    return 0;
}








