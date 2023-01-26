#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head;
void create(int n){
    int data;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter first node data: ");
    scanf("%d",&data);
    struct node*temp=head;
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
        newnode->link=head;
        temp->link=newnode;
        temp=temp->link;
    }
    printf("List created successfully!\n");
}
int count(){
    int c=0;
    struct node* temp=head;
    if(!head){
        return 0;
    }
    do{
        c++;       
        temp=temp->link;
    }while(temp!=head);
    return c;
}
int main(){
    create(5);
    printf("%d",count());
    return 0;
}