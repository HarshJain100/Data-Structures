#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head =NULL;
void push(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=head;     
    head=newnode;
}
int pop(){
    if(!head){
        printf("stack is empty\n");
        return -1;
    }
    struct node* temp=head;
    int a=temp->data;
    head=head->link;
    free(temp);
    return a;
}
int main(){
    push(5);
    push(6);
    push(7);
    push(8);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    return 0;
}