#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;
Node* create(){
    int x;
    Node* newnode=malloc(sizeof(Node));
    printf("Enter the data for the nodes(-1 for no data): ");
    scanf("%d",&x);
    if(x == -1){
        return NULL;
    } 
    newnode->data=x;
    printf("Enter the left child data rooted at %d\n",newnode->data);
    newnode->left=create();
    printf("Enter the right child data rooted at %d\n",newnode->data);
    newnode->right=create();
    return newnode;
}
void inorder(Node *curr){
    if(curr){
        inorder(curr->left);
        printf("%d ",curr->data);
        inorder(curr->right);
    }
}
void preorder(Node *curr){
    if(curr){
        printf("%d ",curr->data);
        preorder(curr->left);
        preorder(curr->right);
    }
}
void postorder(Node *curr){
    if(curr){
        postorder(curr->left);
        postorder(curr->right);
        printf("%d ",curr->data);
    }
}
int NN(Node* t){
    if(t){
        return (1+NN(t->left)+NN(t->right));
    }
    else{
        return 0;
    }
}
int countL(struct node* t){
    if(t==NULL){
        return 0;
    }
    if(!(t->left) && !(t->right)){
        return 1;
    }
    else{
        return (countL(t->left)+countL(t->right));
    }
}
int countNLN(struct node* t){
    if(t==NULL){
        return 0;
    }
    if(!(t->left) && !(t->right)){
        return 0;
    }else{
        return (1+countNLN(t->left)+countNLN(t->right));
    }
}
int FN(struct node* t){
    if(!t){
        return 0;
    }
    if((t->left)&&(t->right)){
        return (1+FN(t->left)+FN(t->right));
    }else{
        return (FN(t->left)+FN(t->right));
    }
}
int NFN(struct node* t){
    if(!t){
        return 0;
    }
    if(!(t->left) || !(t->right)){
        return (1+NFN(t->left)+NFN(t->right));
    }else{
        return (NFN(t->left)+NFN(t->right));
    }
}
int H(Node* t){
    if(!t){
        return 0;
    }
    if(!(t->left) && !(t->right)){
        return 0;
    }else{
        int l=H(t->left);
        int r=H(t->right);
        return (1+(l>r?l:r));
    }
}
int main(){
    Node* root=create();
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("Number of nodes in tree is %d\n",NN(root));
    printf("Number of leaf nodes in tree is %d\n",countL(root));
    printf("Number of non-leaf nodes in tree is %d\n",countNLN(root));
    printf("Number of full nodes in tree is %d\n",FN(root));
    printf("Number of non-full nodes in tree is %d\n",NFN(root));
    printf("Height of tree is %d\n",H(root));
    return 0;
}