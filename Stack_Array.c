#include<stdio.h>
#include<stdlib.h>
int top=-1;
const int max=50;
int stack[max];
void push(int data){
    if(top == max -1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=data;
}
int pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
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
    return 0;
}