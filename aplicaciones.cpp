#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista) {

    TPilaPersona stack = crearTPilaPersona();
    
    while (cantidadTPersonasLDE(lista) > 0) {
        TPersona foremost = obtenerInicioDeTPersonasLDE(lista);
        
        while (cantidadEnTPilaPersona(stack) > 0 && edadTPersona(foremost) < edadTPersona(cimaDeTPilaPersona(stack))) {
            desapilarDeTPilaPersona(stack);
        }
        
        apilarEnTPilaPersona(stack, foremost);
        eliminarInicioTPersonasLDE(lista);
    }

    return stack;
}

bool sumaPares(nat k, TConjuntoIds c){
    bool res = false;
    nat cant = cantMaxTConjuntoIds(c);

    for (nat i = 1; i <= cant; i++) {
        if (perteneceTConjuntoIds(i, c)) {
            nat sub = k - i;

            if (sub != i && perteneceTConjuntoIds(sub, c)) {
                res = true;
            }
        }
    }
    return res;
}