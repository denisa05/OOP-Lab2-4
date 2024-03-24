#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "domain.h"

Produs create_produs(int id, char* tip, char* producator, char* model, float pret, int cantitate) {
    Produs nou;
    strcpy_s(nou.tip, sizeof(nou.tip), tip);
    strcpy_s(nou.producator, sizeof(nou.producator), producator);
    strcpy_s(nou.model, sizeof(nou.model), model);
    nou.id = id;
    nou.pret = pret;
    nou.cantitate = cantitate;
    return nou;
}


void destroy_produs(Produs* p) {
    //no memory is allocated on the heap
    //nothing to dealocate
    //mark that pet is destroyed, avoid accidental use after destroy
    p->tip[0] = '\0';
    p->model[0] = '\0';
    p->producator[0] = '\0';
    p->id = -1;
    p->cantitate = -1;
    p->pret = -1;
}


int validate(Produs p) {
    if (strlen(p.tip) == 0)
        return 2;

    if (strlen(p.model) == 0)
        return 3;

    if (p.id < 0)
        return 1;

    if (strlen(p.producator) == 0)
        return 4;

    if (p.pret < 0)
        return 5;

    if (p.cantitate < 0)
        return 6;

    return 0;
}
