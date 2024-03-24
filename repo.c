#include "repo.h"
#include <assert.h>
#include <string.h>
#include <malloc.h>

MyList* create_list() {
	MyList* nou = malloc(sizeof(MyList));

	if (nou == NULL)
		return NULL;

	nou->capacitate = 1;
	nou->lg = 0;
	nou->elems = malloc(sizeof(Produs) * nou->capacitate);

	return nou;
}

void destroy(MyList* l) {
	//for (int i = 0; i < l->lg; i++)
		//destroy_produs(&(l->elems[i]));
	free(l->elems);
	free(l);
}

void set(MyList* l, int index, Produs new_value) {
	l->elems[index] = new_value;
}


TElem get(MyList* l, int poz) {
	return l->elems[poz];
}


int size(MyList* l) {
	return l->lg;
}


void resize(MyList* l) {
	l->capacitate *= 2;
	TElem* newElem = malloc(l->capacitate * sizeof(TElem));

	if (newElem == NULL) {
		return;
	}

	for (int i = 0; i < l->lg; i++)
		newElem[i] = l->elems[i];

	free(l->elems);
	l->elems = newElem;
}

void add(MyList* l, TElem el) {
	if (l->lg == l->capacitate)
		resize(l);
	l->elems[l->lg] = el;
	l->lg++;
}


void remove_at(MyList* l, int index) {
	for (int i = index; i < size(l) - 1; ++i) {
		l->elems[i] = l->elems[i + 1];
	}

	l->lg--;
}

MyList* copyList(MyList* l) {
	MyList* rez = create_list();
	for (int i = 0; i < size(l); i++) {
		TElem p = get(l, i);
		add(rez, p);
	}
	return rez;
}
