#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int top = -1;
int stack[16];
int max = sizeof(stack)/sizeof(int);

bool isFull(){
    if(top >=max-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top <=-1){
        return true;
    }
    else{
        return false;
    }
}

void push(int val){
    if(!isFull()){
        top++;
        stack[top] = val;
    }
    else{
        printf("Stack is full!\n");
    }
}

void pop(){
    if(!isEmpty()){
        top--;
    }
    else{
        printf("Stack is empty!\n");
    }
}

int getTop(){
    if(!isEmpty()){
        return stack[top];
    }
    else{
        printf("Stack is empty, returned with exit code -1\n");
        return -1;
    }
}

void printStack(){
    if(!isEmpty()){
        printf("[ ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("]\n");
    }
    else{
        printf("[ ]\n");
    }
}
int getSize(){
    return top+1;
}

int main(){
    push(10);
    push(2);
    push(12);
    push(3);
    push(10);
    push(16);
    pop();
    printStack();
}

