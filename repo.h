#pragma once
#include "domain.h"

typedef Produs TElem;

typedef struct {
	TElem* elems;
	int capacitate;
	int lg;
}MyList;

/**
 Creeaza o noua lista de tip MyList
 @return un element de tip MyList
 */
MyList* create_list();

/*
 Destroy list
 @param l - lista
*/
void destroy(MyList* l);

/*
 Inlocuieste produsul de pe poz index din lista cu un nou produs
 @param l		 - lista
 @param index     - indexul prodului de actualizat
 @param new_value - produsul nou
*/
void set(MyList* l, int index, Produs new_value);

/*
  Ia elementul de pe o poz din lista
  @param l   - lista
  @param poz - pozitia elementului, care trebuie sa fie valida
  @return element on the given position
*/
TElem get(MyList* l, int poz);

/*
  Returneza dimensiunea liste
  @param l -lista
  @return numarul de elemente din lista
*/
int size(MyList* l);

/*
  Adauga un element in lista
  @param l  - lista
  @param el - elementul de adaugat
*/
void add(MyList* l, TElem el);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as l
*/
MyList* copyList(MyList* l);


/**
  Sterge elementul de pe poz index din lista
  @param l     - lista
  @param index - indexul elementului de sters
*/
void remove_at(MyList* l, int index);

