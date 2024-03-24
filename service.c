#include "service.h"
#include "repo.h"
#include "domain.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>


int addProduct(MyList* l, int id, char* tip, char* producator, char* model, float pret, int cantitate) {
	for (int i = 0; i < size(l); ++i) {
		Produs existing_product = get(l, i);
		if (existing_product.id == id)
			if (strcmp(existing_product.tip, tip) == 0 && strcmp(existing_product.model, model) == 0 && strcmp(existing_product.producator, producator) == 0) {
				existing_product.cantitate += cantitate;
				set(l, i, existing_product);
				return 0;
			}
			else {
				return 1;
			}
	}

	Produs p = create_produs(id, tip, producator, model, pret, cantitate);
	int succ = validate(p);
	if (succ != 0) return succ;

	add(l, p);
	return 0;
}

int updateProduct(MyList* l, int id, float new_price, int new_quantity) {
	for (int i = 0; i < size(l); ++i) {
		Produs current_product = get(l, i);
		if (current_product.id == id) {
			if (new_price > 0) {
				current_product.pret = new_price;
				set(l, i, current_product);
			}
			if (new_quantity > 0) {
				current_product.cantitate = new_quantity;
				set(l, i, current_product);
			}
			return 1;
		}
	}
	return 0;
}

int stergeProdus(MyList* l, int id) {
	for (int i = 0; i < size(l); ++i) {
		Produs current_product = get(l, i);
		if (current_product.id == id) {
			remove_at(l, i);
			return 1;
		}
	}
	return 0;
}

MyList* getAllProduct(MyList* l, char* typeSubstring) {
	if (typeSubstring == NULL || strlen(typeSubstring) == 0) {
		return copyList(l);
	}
	MyList* rez = create_list();
	for (int i = 0; i < size(l); i++) {
		Produs p = get(l, i);
		if (strstr(p.producator, typeSubstring) != NULL) {
			add(rez, p);
		}
	}
	return rez;
}

MyList* getAllProductbyprice(MyList* l, float pret) {
	MyList* rez = create_list();
	for (int i = 0; i < size(l); i++) {
		Produs p = get(l, i);
		if (p.pret == pret) {
			add(rez, p);
		}
	}
	return rez;
}

MyList* getAllProductbyquantite(MyList* l, int cantitate) {
	MyList* rez = create_list();
	for (int i = 0; i < size(l); i++) {
		Produs p = get(l, i);
		if (p.cantitate == cantitate) {
			add(rez, p);
		}
	}
	return rez;
}

int compararePret(Produs* m1, Produs* m2) {
	if (m1->pret > m2->pret) {
		return 1;
	}
	else 
		if (m1->pret == m2->pret) {
			return 2;
		}

	return 0;
}

int comparareCantitate(Produs* m1, Produs* m2) {
	if (m1->cantitate > m2->cantitate) {
		return 1;
	}	
	return 0;
}

MyList* sortare(MyList* lista, int crescator, sorteaza cmp1, sorteaza cmp2) {
	MyList* list = copyList(lista);
	/*
	for (int i = 0; i < list->lg - 1; i++) {
		for (int j = i + 1; j < list->lg; j++) {
			if ((crescator && cmp1(list->elems[i], list->elems[j]) == 1) ||
				(!crescator && cmp1(list->elems[i], list->elems[j]) == 0)) {
				TElem temporar = list->elems[i];
				list->elems[i] = list->elems[j];
				list->elems[j] = temporar;
			}
			else if ((crescator && cmp2(list->elems[i], list->elems[j]) == 1) ||
				(!crescator && cmp2(list->elems[i], list->elems[j]) == 0)) {
				TElem temporar = list->elems[i];
				list->elems[i] = list->elems[j];
				list->elems[j] = temporar;
			}
		}
	}
	*/
	for (int i = 0; i < list->lg - 1; i++) {
		for (int j = i + 1; j < list->lg; j++) {
			int cmp_result;
			if (crescator) {
				cmp_result = cmp1(list->elems[i], list->elems[j]);
				if (cmp_result == 1 || (cmp_result == 2 && cmp2(list->elems[i], list->elems[j]) == 1)) {
					TElem temporar = list->elems[i];
					list->elems[i] = list->elems[j];
					list->elems[j] = temporar;
				}
			}
			else {
				cmp_result = cmp1(list->elems[i], list->elems[j]);
				if (cmp_result == 0 || (cmp_result == 2 && cmp2(list->elems[i], list->elems[j]) == 1)) {
					TElem temporar = list->elems[i];
					list->elems[i] = list->elems[j];
					list->elems[j] = temporar;
				}
			}
		}
	}
	return list;
}