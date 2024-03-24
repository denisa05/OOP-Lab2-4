#pragma once

typedef struct {
	int id;
	char tip[50];
	char producator[50];
	char model[50];
	float pret;
	int cantitate;

} Produs;

/**
 * Functia creeaza un element de tip produs
 * @param id		  - id-ul produsului
 * @param  producator - producatorul produsului
 * @param  model      - modelul produsului
 * @param  pret		  - pretul produsului
 * @param  cantitate  - cantitatea de produse
 * @return produsul cu caracteristicile de mai sus
 * */
Produs create_produs(int id, char* tip, char* producator, char* model, float pret, int cantitate);

/**
 * Functia valideaza o posibila materie
 * @param p - Produs
 * @return 0 sau 1, in functie de validitatea intrarii
 */
int validate(Produs);

/**
 * Functia distruge un element de tip produs
 * @param produs - produsul de distrus
 */
void destroy_produs(Produs* produs);
