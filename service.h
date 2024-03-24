#pragma once

#include "repo.h"

typedef int(*sorteaza)(TElem m1, TElem m2);
/*
Add a pet to the store
*/
int addProduct(MyList* l, int id, char* tip, char* producator, char* model, float pret, int cantitate);

/*
  Filter products in the store
  typeSubstring - cstring
  return all products where typeSubstring is a substring of the type
*/
MyList* getAllProduct(MyList* l, char* typeSubstring);


/*
Returneaza o lista cu produsele filtrate dupa un anummit pret
@param l -lista
@param pret - pretul dupa care se filtreaza
@return noua lista filtrata
*/
MyList* getAllProductbyprice(MyList* l, float pret);


/*
Returneaza o lista cu produsele filtrate dupa o anumita cantitate
@param l -lista
@param pret - cantitatea dupa care se filtreaza
@return noua lista filtrata
*/
MyList* getAllProductbyquantite(MyList* l, int cantitate);


/*
Functie ajutatoare pentru sortarea dupra pret
*/
int compararePret(Produs* a, Produs* b);


/*
Functie ajutatoare pentru functia de sortare dupa cantitate
*/
int comparareCantitate(Produs* a, Produs* b);


/*
Sterge un produs dupa id
@param id - id produsului de sters
@param l - lista
@return 1 - daca stergerea a fost efectuata
@retrun 0 -daca stergerea nu a putut fi efectuata
*/
int stergeProdus(MyList* l, int id);

/*
Actualizeaza pretul si/sau cantitatea unui produs din lista dupa id
@param l -lista
@param id - id produsului de actualizat
@param new_price - noul pret al produsului
@param new_quantity - noua cantitate a produsului
@return 1 - daca actualizarea a fost efectuata
@retrun 0 -daca actualizarea nu a putut fi efectuata
*/
int updateProduct(MyList* l, int id, float new_price, int new_quantity);

MyList* sortare(MyList* list, int crescator, sorteaza cmp1, sorteaza cmp2);