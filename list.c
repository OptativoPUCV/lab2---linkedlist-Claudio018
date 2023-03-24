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
  List *lista = (List *) malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}

void * firstList(List * list) {
  
  if (list->head != NULL)
  {
    struct Node* nodo = list->head;
    list->current = nodo;
    void *data = nodo->data;
    free(nodo);
    return data;
  }
  else{
    return NULL;
  }
}

void * nextList(List * list) {
    if (list->current != NULL && list->current->next != NULL)
    {
      struct Node* nodo = list->current->next;
      list->current = nodo;
      void *data = nodo->data;
      free(nodo);
      return data;
    }
    else{
      return NULL;
    }
}

void * lastList(List * list) {
  if (list->tail != NULL)
  {
    struct Node* nodo = list->tail;
    list->current = nodo;
    return nodo->data;
  }
  else{
   return NULL; 
  }
}

void* prevList(List * list) {
  if (list->current != NULL && list->current->prev != NULL)
  {
    struct Node* nodo = list->current;
    list->current = nodo->prev;
    void* data = nodo->prev->data;
    free(nodo);
    return data;
  }
  else{
   return NULL; 
  }
}

void pushFront(List * list, void * data) {
  struct Node* nodo = createNode(data);
  if(list->head != NULL)
  {
    nodo->next = list->head;
    list->head->prev = nodo;
    list->head = nodo;
  }
  else{
    list->head = nodo;
    list->tail = nodo;
    list->current = nodo;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  if(list->current == NULL){
    pushFront(list,data);
    return;
  }
  struct Node* nodo = createNode(data);
  struct Node* actual = list->current;
  nodo->next = actual->next;
  actual->next = nodo;
  nodo->prev = actual;
  if (nodo->next == NULL)
  {
    list->tail = nodo;
  }
  else{
      nodo->next->prev = nodo;
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
  if (list == NULL)
  {
    return NULL;
  }
  struct Node* actual = list->current;
  void* data = actual->data;

  if (actual == list->head){
    list->head = actual->next;
  }
  else{
    actual->prev->next = actual->next;
  }

  if (actual == list->current)
  {
    list->tail = actual->prev;
  }
  else{
    actual->next->prev = actual->prev;
  }

  list->current = actual->next;
  return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}