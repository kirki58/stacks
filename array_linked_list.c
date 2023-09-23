#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* stack;
int top = -1;

bool isEmpty(){
    if(top <= -1){
        return true;
    }
    else{
        return false;
    }
}

void printStack(){
    if(!isEmpty()){
        struct Node* temp = stack;
        printf("[ ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
    else{
        printf("[ ]\n");
    }
}

void push(int val){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = stack;
    stack = newNode;
    top++;
}

void pop(){
    if(!isEmpty()){
        struct Node* head = stack;
        stack = stack->next;
        free(head);
        top--;
    }
    else{
        printf("Stack is empty!\n");
    }
}

int getTop(){
    if(!isEmpty()){
        return stack->data;
    }
    else{
        printf("Stack is empty, returned with exit code -1\n");
        return -1;
    }
}

int getSize(){
    return top+1;
}

int main(){
    stack =  (struct Node*) malloc(sizeof(struct Node));
    push(10);
    printf("%d\n",getTop());
}