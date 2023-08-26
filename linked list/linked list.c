#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
typedef struct Node {
      uint8_t value;
      struct Node *next;
}Node;

Node *createNode(uint8_t value){
      Node *ptr = (Node*)malloc(sizeof(Node));
      ptr->value = value;
      ptr->next = NULL;
      return ptr;
}

void duyet(Node *node){
      while(node != NULL){
            printf("%d",node->value);
            node = node->next;
      }
}

void pushFront(Node **ptp,uint8_t value){
      // Node *temp = *ptp;
      // *ptp = createNode(value);
      // (*ptp)->next = temp;
      Node *temp =createNode(value);
      temp->next = *ptp ;
      *ptp = temp;

}

void pushBack(Node **ptp,uint8_t value){
      if(*ptp == NULL){
            *ptp = createNode(value);
            
      }else{
      Node *temp = *ptp ;
      while(temp->next != NULL){
            temp=temp->next;
      }
      temp->next=createNode(value);
  }
}

void insert(Node **ptp, uint8_t value , uint8_t position){
      Node *temp=*ptp;
      if(position==1){
                  pushFront(ptp,value);
                  return;
      }
      for(int i=1 ; i<position-1 ; i++){
            if(temp->next != NULL){
            temp=temp->next;
      }
      }
      Node *p = createNode(value);
      p->next = temp->next ;
      temp->next = p;
}
void popFront(Node **ptp){
      if(*ptp == NULL) return;
      Node *temp = *ptp;
      *ptp = (*ptp)->next;
      free(temp);
} 
 
void popBack(Node **ptp){ 
      if(*ptp == NULL) return;
      Node *temp = *ptp ;
      if(temp->next == NULL){
            *ptp = NULL ; 
            free(temp);
            return;
      }
      while (temp->next->next != NULL){
            temp = temp->next;
      }
      // Node *last = temp->next;
      // temp->next = NULL;
      // free(last);
      free(temp->next);
      temp->next=NULL;
} 

void erase(Node **ptp , uint8_t position){
      Node *temp = *ptp ; 
      if(*ptp == NULL) return ;
      if(position == 1 ) popFront(ptp);
      else{  
            for(uint8_t i=1 ; i< position -1 ; i++){
                temp = temp->next;
            }
            Node *p = temp->next;
            temp->next = temp->next->next;
            free(p);
            return;
      }
}

uint8_t getData(Node **ptp,uint8_t position){
      Node *temp = *ptp ;
      uint8_t i = 1;
      while(temp!=NULL){
          if(position==i){
            return temp->value;
          }
          temp=temp->next;
          i++;
      }
}

int main(){
      Node *node = NULL ;
     
      for(int i=0;i<5;i++){
            pushFront(&node,i);
      }
      //insert(&node,7,2);
      // popFront(&node);
      // popBack(&node);
      erase(&node,2);
      duyet(node);
      printf("\n");
      printf("%d",getData(&node,2));
      return 0;
}

