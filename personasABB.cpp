#include "../include/personasABB.h"
#include "colaPersonasABB.h"

struct rep_personasAbb {
    TPersona persona;
    TPersonasABB left;
    TPersonasABB right;
};

TPersonasABB crearTPersonasABB() {
    TPersonasABB bst = NULL;
    return bst;
}

bool esVacioTPersonasABB(TPersonasABB personasABB) {
    return (personasABB == NULL);
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p) {
    if (personasABB == NULL) {
        personasABB = new rep_personasAbb;
        personasABB->persona = p;
        personasABB->left = NULL;
        personasABB->right = NULL;

    } else if (idTPersona(p) < idTPersona(personasABB->persona)) {
        insertarTPersonasABB(personasABB->left, p);

    } else if (idTPersona(p) > idTPersona(personasABB->persona)){
        insertarTPersonasABB(personasABB->right, p);
    }
}

void liberarTPersonasABB(TPersonasABB &personasABB) {
    if (personasABB != NULL) {
        liberarTPersona(personasABB->persona);
        liberarTPersonasABB(personasABB->left);
        liberarTPersonasABB(personasABB->right);

        delete personasABB;
        personasABB = NULL;
    }
}

void imprimirTPersonasABB(TPersonasABB personasABB) {
   if (personasABB != NULL) {
    imprimirTPersonasABB(personasABB->left);
    imprimirTPersona(personasABB->persona);
    imprimirTPersonasABB(personasABB->right);
   }
}  

nat cantidadTPersonasABB(TPersonasABB personasABB) {
    if (personasABB == NULL) {
        return 0;
    } else {
        return 1 + cantidadTPersonasABB(personasABB->left) + cantidadTPersonasABB(personasABB->right);
    }
}

TPersona maxIdPersona(TPersonasABB personasABB) {
    if (personasABB == NULL) {
        return NULL;
    } else {
        while (personasABB->right != NULL) {
            personasABB = personasABB->right;
        }
    }
    return personasABB->persona;
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id) {

    if (personasABB != NULL) {
        if (id < idTPersona(personasABB->persona)) {
            removerTPersonasABB(personasABB->left, id);

        } else if (id > idTPersona(personasABB->persona)) {
            removerTPersonasABB(personasABB->right, id);

        } else {
            if (personasABB->right == NULL && personasABB->left == NULL) {
                liberarTPersona(personasABB->persona);
                delete personasABB;
                personasABB = NULL;

            } else if (personasABB->right == NULL && personasABB->left != NULL) {
                TPersonasABB aux = personasABB->left;
                liberarTPersona(personasABB->persona);
                delete personasABB;
                personasABB = aux;

            } else if (personasABB->right != NULL && personasABB->left == NULL) {
                TPersonasABB aux = personasABB->right;
                liberarTPersona(personasABB->persona);
                delete personasABB;
                personasABB = aux;

            } else if (personasABB->right != NULL && personasABB->left != NULL) {
                TPersona pessoa = copiarTPersona(maxIdPersona(personasABB->left));
                liberarTPersona(personasABB->persona);
                personasABB->persona = pessoa;
                removerTPersonasABB(personasABB->left, idTPersona(personasABB->persona));
                
            }
        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id) {
    bool result = false;

    if (personasABB == NULL) {
        result = false;
    } else {
        if (idTPersona(personasABB->persona) == id) {
            result = true;
        } else if (idTPersona(personasABB->persona) > id) {
            result = estaTPersonasABB(personasABB->left, id);
        } else {
            result = estaTPersonasABB(personasABB->right, id);
        }
    }
    return result;
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id) {

    if (personasABB == NULL) {
        return NULL;
    } else {
        if (idTPersona(personasABB->persona) == id) {
            return personasABB->persona;
        } else {
            if (idTPersona(personasABB->persona) > id) {
                return obtenerDeTPersonasABB(personasABB->left, id);
            } else {
                return obtenerDeTPersonasABB(personasABB->right, id);
            }
        }
    }
}

nat alturaTPersonasABB(TPersonasABB personasABB) {
    if (personasABB == NULL) {
        return 0;
    } else {
        nat heightLeft = alturaTPersonasABB(personasABB->left);
        nat heightRight = alturaTPersonasABB(personasABB->right);

        if (heightLeft > heightRight) {
            return 1 + heightLeft;
        } else {
            return 1 + heightRight; 
        }
    }
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB) {

    if (personasABB == NULL) {
        return true;
    } else {
        nat height = alturaTPersonasABB(personasABB);
        nat amount = cantidadTPersonasABB(personasABB);

        nat quantity = 1;
        for (nat i = 1; i <= height; i++) {
            quantity = quantity * 2;
        }

        if (amount == (quantity - 1)) {
            return true;
        } else {
            return false;
        }
    }
}

TPersonasABB maxABB(TPersonasABB personasABB) {
    if (personasABB == NULL) {
        return NULL;
    } else {
        while (personasABB->right != NULL) {
            personasABB = personasABB->right;
        }
    }
    return personasABB;
}


TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad) {
    TPersonasABB res;
    if (personasABB == NULL) {
        res = NULL;
    } else {    
        TPersonasABB lefty = mayoresTPersonasABB(personasABB->left, edad);
        TPersonasABB righty = mayoresTPersonasABB(personasABB->right, edad);

        if (edadTPersona(personasABB->persona) > edad) {

            res = new rep_personasAbb;
            res->persona = copiarTPersona(personasABB->persona);
            res->left = lefty;
            res->right = righty;

        } else if (lefty == NULL) {
            res = righty;

        } else if (righty == NULL) {
            res = lefty;

        } else {
            TPersonasABB higher = maxABB(lefty);

            res = new rep_personasAbb;
            res->persona = copiarTPersona(personasABB->persona);;
            res->left = lefty;
            res->right = righty;

            removerTPersonasABB(personasABB->left, idTPersona(higher->persona));
        }
    }
    return res;
}

void flatten(TPersonasABB personasABB, TPersonasLDE &newDLL) {
    if (personasABB != NULL) {
        flatten(personasABB->right, newDLL);

        TPersona replica = copiarTPersona(personasABB->persona);
        insertarTPersonasLDE(newDLL, replica, 1);

        flatten(personasABB->left, newDLL);
    }
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB) {
    TPersonasLDE newDLL = crearTPersonasLDE();
    flatten(personasABB, newDLL);
    return newDLL;
}

nat amplitudTPersonasABB(TPersonasABB personasABB) {
    nat max;

    if (personasABB == NULL) {
        return 0;
    } else {
        TColaPersonasABB queue = crearTColaPersonasABB();
        encolarEnTColaPersonasABB(personasABB, queue);
        max = 0;

        while (cantidadEnTColaPersonasABB(queue) > 0) {
            nat nivelActual = cantidadEnTColaPersonasABB(queue);
            
            if (nivelActual > max) {
                max = nivelActual;
            }
            
            for (nat i = 0; i < nivelActual; i++) {
                TPersonasABB front = frenteDeTColaPersonasABB(queue);
                desencolarDeTColaPersonasABB(queue);
                
                if (front->left != NULL) {
                    encolarEnTColaPersonasABB(front->left, queue);
                }

                if (front->right != NULL) {
                    encolarEnTColaPersonasABB(front->right, queue);
                }
            }
        }
        liberarTColaPersonasABB(queue);
    }
    return max;
}

TPilaPersona serializarTPersonasABB(TPersonasABB personasABB) {
    TPersonasABB t = personasABB;
    TPilaPersona stack = crearTPilaPersona();
    TPilaPersona stack1 = crearTPilaPersona();

    if (t == NULL) {
        return NULL;

    } else {
        
        TColaPersonasABB queue = crearTColaPersonasABB();
        encolarEnTColaPersonasABB(t, queue);

        while (cantidadEnTColaPersonasABB(queue) > 0) {
            TPersonasABB front = frenteDeTColaPersonasABB(queue);
            desencolarDeTColaPersonasABB(queue);
            apilarEnTPilaPersona(stack, front->persona);
            
            if (front->left != NULL) {
                encolarEnTColaPersonasABB(front->left, queue);
            }

            if (front->right != NULL) {
                encolarEnTColaPersonasABB(front->right, queue);
            }
        }
        
        while (cantidadEnTPilaPersona(stack) > 0) {
            TPersona top = cimaDeTPilaPersona(stack);
            apilarEnTPilaPersona(stack1, top);
            desapilarDeTPilaPersona(stack);
        }
    liberarTColaPersonasABB(queue);
    liberarTPilaPersona(stack);
    return stack1;
    }
}

TPersonasABB deserializarTPersonasABB(TPilaPersona &pilaPersonas) {
    TPilaPersona p = pilaPersonas;

    if (cantidadEnTPilaPersona(p) == 0) {
        return NULL;
    } else {
        TPersonasABB t = crearTPersonasABB();
        nat amount = cantidadEnTPilaPersona(p);
        TPersona* arr = new TPersona[amount];

        for (nat i = 0; i < amount; i++) {
            arr[i] = copiarTPersona(cimaDeTPilaPersona(p));
            desapilarDeTPilaPersona(p);
        }

        for (nat j = 0; j < amount; j++) {
            insertarTPersonasABB(t, arr[j]);
        }

        delete[] arr;
        liberarTPilaPersona(p);
        return t;
    }
}
