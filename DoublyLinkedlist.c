#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
}*head;
void create(int n){
    head=(struct node*)malloc(sizeof(struct node));
    int data;
    struct node *temp=head;
    printf("Enter the value of first node: ");
    scanf("%d",&data);
    head->data=data;
    head->next=head->prev=NULL;
    for(int i=2; i<=n; i++){
        scanf("%d",&data);
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;
    }
}
void traverse(){
    struct node *temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertAtBegin(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data you want to enter: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void insertAtEnd(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    int data;
    printf("Enter the data you want to enter: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void insertAtData(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    int data,data1;
    printf("Enter the data you want to enter: ");
    scanf("%d",&data);
    newnode->data=data;
    printf("Enter the data after which you want to enter: ");
    scanf("%d",&data1);
    while(temp->data != data1){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}
int main(){
    create(5);
    traverse();
    insertAtBegin();
    traverse();
    insertAtEnd();
    traverse();
    insertAtData();
    traverse();
    return 0;
}