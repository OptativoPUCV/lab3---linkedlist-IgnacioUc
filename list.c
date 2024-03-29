#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* list = (List*)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void * firstList(List * list) {
  if (list == NULL || list->head == NULL){
    return 0;
  }
  list->current = list->head;

  return list->current->data;
}  


void * nextList(List * list) {
  if (list == 0 || list->head == 0){
    return NULL;
  }
  if (list->current == 0){
    return NULL;
  }
  if (list->current->next == 0){
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;

}

void * lastList(List * list) {
  if (list == NULL || list->head == NULL){
    return NULL; 
  }
  list->current = list->tail;
  return list->current->data;
  
}

void * prevList(List * list) {
  if (list == NULL || list->head == NULL){
    return 0;
  }
  if (list->current == NULL){
    return 0;
  }
  if (list->current->prev == NULL){
    return 0;
  }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  if (list == NULL){
    return;
  }
  Node * new = createNode(data);
  if (list->head == NULL){
    list->head = new;
    list->tail = new;
    
  }
  else{
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
  }
  
  }
    


void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list, data);
  
}

void pushCurrent(List * list, void * data) {
  if (list == NULL){
    return;
  }
  Node * new = createNode(data);
  if (list->current == NULL){
    list->head = new;
    list->tail = new;
    
  }
  else{
    new->next = list->current->next;
    new->prev = list->current;
    if (list->current->next != NULL){
      list->current->next->prev = new;
      
    }
    list->current->next = new;
    if (list->current == list->tail){
      list->tail = new;
    }
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list == NULL){
    return 0;
  }
  if (list->current == NULL){
    return 0;
  }
  void * data = list->current->data;
  if (list->current->prev != NULL){
    list->current->prev->next = list->current->next;
    
  }
  if (list->current->next != NULL){
    list->current->next->prev = list->current->prev;
    
  }
  if (list->current == list->head){
    list->head = list->current->next;
  }
  if (list->current == list->tail){
    list->tail = list->current->prev;
  }
  free(list->current);
  list->current = NULL;
  return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}