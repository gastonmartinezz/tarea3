#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct node {
  TPersonasABB t;
  node* next;
};

struct rep_colaPersonasABB {
  node* start;
  node* end;
  nat sum;
};

TColaPersonasABB crearTColaPersonasABB() {
  TColaPersonasABB queue = new rep_colaPersonasABB;
  queue->start = NULL;
  queue->end = NULL;
  queue->sum = 0;
  return queue;
}

void liberarTColaPersonasABB(TColaPersonasABB &c) {
  node* iter = c->start;

  while (iter != NULL) {
    node* toRemove = iter;
    iter = iter->next;
    delete toRemove;
    toRemove = NULL;
  }
    
  delete c;
  c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c) { 
  return c->sum;
}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c) {
  node* ptr = new node;
  ptr->t = t;
  ptr->next = NULL;

  if (c->start == NULL) {
    c->start = ptr;
    c->end = c->start;

  } else {
    c->end->next = ptr;
    c->end = ptr;
    
  }
  c->sum++;
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c) { 
  if (cantidadEnTColaPersonasABB(c) > 0) {
    return (c->start->t);
  } else {
    return NULL;
  }
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {
  if (cantidadEnTColaPersonasABB(c) > 0) {
    node* toRemove = c->start;
    c->start = c->start->next;

    delete toRemove;
    c->sum--;
  }
}