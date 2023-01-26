#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head;
void create(int n){
    int data;
    struct node* temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter first node data: ");
    scanf("%d",&data);
    temp=head;
    head->data=data;
    head->link=NULL;
    for(int i=2; i<=n; i++){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode == NULL){
            printf("Memory not allocated\n");
            return;
        }
        scanf("%d",&data);
        newnode->data=data;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
        
    }
    printf("List created successfully!\n");
}

void traverse(){
    struct node* temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void newBegin(){
    struct node* newnode = malloc(sizeof(struct node));
    int data;
    printf("Enter the data you want to add in the beginning: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->link=head;
    head=newnode;
}

void insertEnd(){
    struct node* temp=head, *newnode=malloc(sizeof(struct node));
    int data;
    printf("Enter the data you want to add in the end: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->link=NULL;
    while(temp->link){
        temp=temp->link;
    }
    temp->link=newnode;
}

void insertAfterData(){
    struct node* temp = head, *newnode=malloc(sizeof(struct node));
    int data,data1;
    printf("Enter the data after which you which you want to insert: ");
    scanf("%d",&data1);
    printf("Enter the data you want to add: ");
    scanf("%d",&data);
    newnode->data=data;
    while(temp->data!=data1){
        temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;
}

void deleteFromBeginning(){
    struct node *temp=head;
    head=head->link;
    free(temp);
}

void deleteFromEnd(){
    struct node* temp=head;
    while(temp->link->link){
        temp=temp->link;
    }
    free(temp->link);
    temp->link=NULL;
}

void deleteAfterData(){
    struct node* temp=head;
    int data1;
    printf("Enter the data you want to delete: ");
    scanf("%d",&data1);
    while(temp->link->data!=data1){
        temp=temp->link;
    }
    struct node *temp2=temp->link;
    temp->link=temp->link->link;
    free(temp2);
}

void movingLastNodeToFront(){
    struct node *p,*q;
    p=head;
    while(p->link){
        q=p;
        p=p->link;
    }
    q->link=NULL;
    p->link=head;
    head=p;
}

void ReverseI(){
    struct node *prev=NULL,*next=NULL,*curr=head;
    while(curr){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void reverseR(struct node* curr, struct node* prev){
    if(curr){
        reverseR(curr->link,curr);
        curr->link=prev;
    }
    else{
        head=prev;
    }
}

void traverseR(struct node* curr){
    if(curr){
        printf("%d ",curr->data);
        traverseR(curr->link);
    }else{
        printf("\n");
    }
}

void printReverse(struct node* curr){
    if(curr){
        printReverse(curr->link);
        printf("%d ",curr->data);
        if(curr == head){
            printf("\n");
        }
    }
}

void sort(){
    struct node *p=head, *temp1, *temp2, *min, *prev, *q;
    q=NULL;
    while(p!=NULL){
        prev=NULL;
        min=temp1=p;
        temp2=p->link;
        while(temp2!=NULL){
            if(min->data > temp2->data){
                min=temp2;
                prev=temp1;
            }
            temp1=temp2;
            temp2=temp2->link;
        }
        if(prev == NULL)
            p=p->link;
        else
            prev->link=min->link;
        min->link=NULL;
        if(q==NULL)
            q=min;
        else{
            temp1=q;
            while(temp1->link != NULL)
                temp1=temp1->link;
            temp1->link=min;
        }
    }
    head=q;
}

int main(){

    create(5);
    traverse();
    sort();
    traverse();
    return 0;
}