#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona {
  TPersonasLDE list;
};

TPilaPersona crearTPilaPersona() {
  TPilaPersona stack = new rep_pilaPersona;
  stack->list = crearTPersonasLDE();
  return stack;
}

void liberarTPilaPersona(TPilaPersona &p) {
  if (p != NULL) {
    liberarTPersonasLDE(p->list);
    delete p;
    p = NULL;
  }
}

nat cantidadEnTPilaPersona(TPilaPersona p) {
  return cantidadTPersonasLDE(p->list);
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona) {
  insertarInicioDeTPersonasLDE(p->list, copiarTPersona(persona));
}

TPersona cimaDeTPilaPersona(TPilaPersona p) {
  return obtenerInicioDeTPersonasLDE(p->list);
}

void desapilarDeTPilaPersona(TPilaPersona &p) {
  eliminarInicioTPersonasLDE(p->list);
}