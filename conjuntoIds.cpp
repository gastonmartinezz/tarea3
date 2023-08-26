#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
    bool* elem;
	nat cantMax;
	nat cant;
};

TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds a = new rep_conjuntoIds;
	a->cantMax = cantMax;
	a->elem = new bool[cantMax+1];
	a->cant = 0;

	for (nat i = 1; i <= cantMax; i++) {
		a->elem[i] = false;
	}

	return a;
};

bool esVacioTConjuntoIds(TConjuntoIds c){
	return (c->cant == 0);
};

void insertarTConjuntoIds(nat id, TConjuntoIds &c){
    if (id > 0 && id <= c->cantMax && !c->elem[id]) {
		c->elem[id] = true;
		c->cant++;
	}
}; 

void borrarTConjuntoIds(nat id, TConjuntoIds &c){
	if (id > 0 && id <= c->cantMax && c->elem[id]) {
		c->elem[id] = false;
		c->cant--;
	}
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	if (id > 0 && id <= c->cantMax && c->elem[id]) {
		return true;
	} else {
		return false;
	}
};

nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cant;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c){
    for (nat i = 1; i <= c->cantMax; i++) {
		if (c->elem[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c){
	delete[] c->elem;
    delete c;
	c = NULL;
};

TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	nat n = c1->cantMax;
	TConjuntoIds newC = crearTConjuntoIds(n);

	for (nat i = 1; i <= n; i++) {
		if (c1->elem[i] || c2->elem[i]) {
			insertarTConjuntoIds(i, newC);
		}
	}

	return newC;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	nat n = c1->cantMax;
	TConjuntoIds newC = crearTConjuntoIds(n);

    for (nat i = 1; i <= n; i++) {
        if (c1->elem[i] && c2->elem[i]) {
            insertarTConjuntoIds(i, newC);
        }
    }

    return newC;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	nat n = c1->cantMax;
	TConjuntoIds newC = crearTConjuntoIds(n);

    for (nat i = 1; i <= n; i++) {
        if (c1->elem[i] && !c2->elem[i]) {
            insertarTConjuntoIds(i, newC);
        }
    }

    return newC;
};
