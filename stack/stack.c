#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint8_t size;
    int capacity;
    uint8_t *array;
}Stacks;

void initStacks(Stacks *stack , uint8_t size){
    stack->capacity = -1 ;
    stack->size = size;
    stack->array = (uint8_t*)malloc(sizeof(uint8_t)*size);
}

bool isEmpty(Stacks stack){
    if (stack.capacity=-1){
        return true ;
    }
    return false ;
}
 
uint8_t size(Stacks stack){
    return stack.capacity+1 ;
} 

bool isFull(Stacks stack){
    if(stack.capacity+1==stack.size){
        return true;
    }
    return false ;
}

void push(Stacks *stack , uint8_t value){
    if(isFull(*stack)){
        printf("FULL");
    }else{
    stack->array[(++(stack->capacity))]=value;
    }
}

void pop(Stacks *stack){
    if(isEmpty(*stack)){
        printf("EMPTY");
    }else{
    stack->array[(stack->capacity)]='\0';
}
}
uint8_t top(Stacks *stack){
    return stack->array[stack->capacity];
}

void duyet(Stacks *stack ){
    
    for(int i=0;i<stack->size;i++){
        printf("%d",stack->size);
    }
}


int main(){
    Stacks stack;
    initStacks(&stack,10);
    push(&stack,12);
    push(&stack,13);
    push(&stack,15);
    //printf("%d\n",top(&stack));
    //size(stack);
    duyet(&stack);
    

    //printf("%d",size(stack));

}