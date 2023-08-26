#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
      uint8_t value;
      struct Node *next;
}Node;

Node *makeNode(uint8_t x){
     Node *ptr = (Node*)malloc(sizeof(Node));
     ptr->value = x ;
     ptr->next = NULL;
     return ptr;
}
 
void push(Node **queue,uint8_t x){
    Node *newnode = makeNode(x);
    if(*queue == NULL){
        *queue = newnode;
        return ;
    }
    Node *temp = *queue ;
    while(temp->next != NULL){
        temp =  temp->next;
    }
    temp->next = newnode;
}

void pop(Node **queue ){
    if(*queue == NULL) return ;
    Node *temp = *queue ;
    (*queue)=(*queue)->next ;
    free(temp);
}

uint8_t size(Node *queue){
    uint8_t n = 0;
    while(queue != NULL){
        queue = queue->next;
        ++n;
    }
    return n;
}

bool isEmpty(Node *queue){
    if(queue == NULL){
        return true;
    }
    return false ; 

}

uint8_t front(Node *queue){
    return queue->value ; 
}

void duyet(Node *queue){
      while(queue != NULL){
            printf("%d",queue->value);
            queue = queue->next;
      }
}

int main(){
    Node *queue = NULL ; 
    push(&queue,5);
    push(&queue,6);
    push(&queue,7);
    push(&queue,8);
    push(&queue,9);
    pop(&queue);
    duyet(queue);
    printf("\n%d",size(queue));
    printf("\n%d",front(queue));
    
}




