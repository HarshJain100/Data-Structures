#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left,*right;
};
struct node* newNode(int item){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
struct node* balancingFactor(struct node*);
struct node* insert(struct node* root,int key){
    if(!root){
        return newNode(key);
    }
    if(key < root->key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    root=balancingFactor(root);
    return root;
}
int height(struct node* t){
    if(!t){
        return 0;
    }
    if(!(t->left) && !(t->right)){
        return 1;
    }
    int l=height(t->left);
    int r=height(t->right);
    return (1+(l>r?l:r));
}
int diff(struct node* t){
    int l=height(t->left);
    int r=height(t->right);
    return l-r;
}
struct node* LL_Rotation(struct node* t){
    struct node* curr=t->left;
    t->left=curr->right;
    curr->right=t;
    return curr;
}
struct node* RR_Rotation(struct node* t){
    struct node* curr=t->right;
    t->right=curr->left;
    curr->left=t;
    return curr;
}
struct node* RL_Rotation(struct node* t){
    t->right=LL_Rotation(t->right);
    t=RR_Rotation(t);
    return t;
}
struct node* LR_Rotation(struct node* t){
    t->left=RR_Rotation(t->left);
    t=LL_Rotation(t);
    return t;
}
struct node* balancingFactor(struct node* curr){
    int balance=diff(curr);
    if(balance >= 2){
        if(diff(curr->left) > 0){
            curr=LL_Rotation(curr);
        }
        else{
            curr=LR_Rotation(curr);
        }
    }
    else if(balance < -1){
        if(diff(curr->right) > 0){
            curr=RL_Rotation(curr);
        }
        else{
            curr=RR_Rotation(curr);
        }
    }
    return curr;
}
struct node* minValueNode(struct node* curr){
    while(curr->left != NULL){
        curr=curr->left;
    }
    return curr;
}
struct node* deleteNode(struct node* curr,int key){
    if(!curr)
        return curr;
    if(key < curr->key)
        curr->left=deleteNode(curr->left, key);
    else if(key > curr->key)
        curr->right=deleteNode(curr->right, key);
    else{
        if(curr->left == NULL){
            struct node* temp=curr->right;
            free(curr);
            return temp;
        }
        else if(curr->right == NULL){
            struct node* temp=curr->left;
            free(curr);
            return temp;
        }
        else{
            struct node* temp=minValueNode(curr->right);
            curr->key=temp->key;
            curr->right=deleteNode(curr->right,temp->key);
            return curr;
        }
    }
    return curr;
}
int main(){
    struct node* root=NULL;
    root=insert(root,93);
    root=insert(root,23);
    root=insert(root,71);
    root=insert(root,12);
    root=insert(root,16);
    root=insert(root,4);
    root=insert(root,8);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    printf("Minimum value node in the tree is %d\n",minValueNode(root)->key);
    root=deleteNode(root,7);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    return 0;
}