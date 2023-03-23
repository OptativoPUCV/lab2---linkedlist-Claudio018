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
  struct Node* node = createNode(data);
  if(lista->head != NULL)
  {
    nodo->next = list->head;
    list->head->prev = node;
    list->head = node;
  }
  else{
    list->head = node;
    list->tail = node;
    list->current = node;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}