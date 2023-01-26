#include<stdio.h>
#include <stdlib.h>
int front=-1;
int rear=-1;
const int max=50;
int queue[max];
void insert(int data){
    if(rear == max-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    rear+=1;
    queue[rear]=data;
}
int delete(){
    if(front == -1 || front>rear){
        printf("Queue Underflow\n");
        return;
    }
    return queue[front++];
}
void display(){
    if(front == -1 || front>rear){
        printf("Queue is empty\n");
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    insert(5);
    insert(7);
    insert(9);
    insert(2);
    display();
    printf("The deleted value is %d\n",delete());
    display();
    printf("The deleted value is %d\n",delete());
    display();
    return 0;
}