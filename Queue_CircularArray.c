#include<stdio.h>
#include <stdlib.h>
int rear=0;
int front=0;
const int max=4;
int queue[max];
void enqueue(int data){
    rear=(rear+1)%max;
    if(front == rear){
        printf("Queue overflowed\n");
        if(rear == 0){
            rear=max-1;
        }else{
            rear=rear-1;
        }
        return; 
    }
    queue[rear]=data;
}
int dequeue(){
    if(front == rear){
        printf("Queue is empty\n");
        return -1;
    }else{
        front=(front+1)%max;
        return queue[front];
    }
}
int main(){
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(2);
    printf("The deleted value is %d\n",dequeue());
    return 0;
}