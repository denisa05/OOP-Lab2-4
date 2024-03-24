#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "service.h"
#include "repo.h"
#include "domain.h"
#include "teste.h"

void testAll() {
	testCreateDestroy();
	testCreateList();
	testIterateList();
	testCopyList();
	testAddProduct();
	test_addProduct();
	test_comparareProduse_crescator();
	test_comparareProduse_descrescator();
	test_getAllProduct_by_price();
	test_getAllProduct_by_producator();
	test_getAllProduct_by_quantity();
	test_stergeProdus();
	test_updateProduct();
	test_sortare_crescatoare_dupa_pret();
}

void printAllProduct(MyList* l) {
	printf("Produse:\n");
	for (int i = 0; i < size(l); i++) {
		Produs p = get(l, i);
		printf("ID:%d Tip:%s Producator:%s Model:%s Pret:%0.2f Cantitate:%d\n", p.id, p.tip, p.producator, p.model, p.pret, p.cantitate);
	}
}

void readProdus(MyList* l) {
	int id;
	printf("Id:");
	scanf_s("%d", &id);

	char tip[30];
	printf("Tip:");
	scanf_s("%s", tip, 30);

	char producator[30];
	printf("Producator:");
	scanf_s("%s", producator, 30);

	char model[30];
	printf("Model:");
	scanf_s("%s", model, 30);

	float pret;
	printf("Pret:");
	scanf_s("%f", &pret);

	int cantitate;
	printf("Cantitate:");
	scanf_s("%d", &cantitate);

	int error = addProduct(l, id, tip, producator, model, pret, cantitate);
	if (error != 0) {
		printf("\033[1;31m");
		printf("Invalid product.\n");
		printf("\033[0m");
	}
	else {
		printf("\033[1;36m");
		printf("Product added.\n");
		printf("\033[0m");
	}
}

void filterProd(MyList* l) {
	printf("Type filter substring:");
	char filterStr[30];
	scanf_s("%s", filterStr, 30);

	MyList* filteredL = getAllProduct(l, filterStr);
	printf("\n\n");
	printAllProduct(filteredL);
	destroy(filteredL);
}

void run() {
	MyList* allProd = create_list();
	int ruleaza = 1;
	while (ruleaza) {
		printf("\033[1;33m");
		printf("---------------------- BINE ATI VENIT ---------------------------\n\n\n");
		printf("\033[0m");

		printf("\033[1;36m");
		printAllProduct(allProd);
		printf("\n\n\n");
		printf("\033[0m");

		printf("\033[1;33m");
		printf("1 Adauga produs nou\n2 Actualizare produse(pret sau cantitate)\n3 Sterge produs dupa id\n4 Vizualizare produse din stoc");
		printf("\n5 Vizualizare lista produse filtrate dupa un criteriu\n0 Exit\nCommand:");
		printf("\033[0m");
		int cmd = 0;
		scanf_s("%d", &cmd);
		if (cmd == 1) {

			readProdus(allProd);
		}
		else
			if (cmd == 2) {

				int opt;
				int id;
				float nou;
				int nou_c;
				printf("Apasati 1 daca vreti sa modificati pretul, 2 daca vreti sa modificati cantitatea sau 3 pentru ambele!");
				scanf_s("%d", &opt);

				if (opt == 1) {

					printf("Introduce-ti id-ul produsului pe care doriti sa il modificati: ");
					scanf_s("%d", &id);
					printf("Introduce-ti noul pret al produsului: ");
					scanf_s("%f", &nou);
					if (updateProduct(allProd, id, nou, 0) == 1)
						printf("Produs actualizat cu succes!\n");
					else {
						printf("\033[1;31m");
						printf("Ceva a mers prost! Te rog incearca din nou!\n");
						printf("\033[0m");
					}

				}
				else
					if (opt == 2) {

						printf("Introduce-ti id-ul produsului pe care doriti sa il modificati: ");
						scanf_s("%d", &id);
						printf("Introduce-ti noua cantitate a produsului: ");
						scanf_s("%d", &nou_c);
						if (updateProduct(allProd, id, 0, nou_c) == 1)
							printf("Produs actualizat cu succes!\n");
						else {
							printf("\033[1;31m");
							printf("Ceva a mers prost! Te rog incearca din nou!\n");
							printf("\033[0m");
						}
					}
					else
						if (opt == 3) {
							printf("Introduce-ti id-ul produsului pe care doriti sa il modificati: ");
							scanf_s("%d", &id);
							printf("Introduce-ti noul pret al produsului: ");
							scanf_s("%f", &nou);
							printf("Introduce-ti noua cantitate a produsului: ");
							scanf_s("%d", &nou_c);
							if (updateProduct(allProd, id, nou, nou_c) == 1)
								printf("Produs actualizat cu succes!\n");
							else {
								printf("\033[1;31m");
								printf("Ceva a mers prost! Te rog incearca din nou!\n");
								printf("\033[0m");
							}
						}
						else
						{
							printf("\033[1;31m");
							printf("Optiune invalida! Va rugam incercati din nou!\n\n\n");
							printf("\033[0m");
						}
			}
			else
				if (cmd == 3) {

					int id_sterg;
					printf("Introduce-ti id-ul produsului pe care doriti sa il stergeti: ");
					scanf_s("%d", &id_sterg);
					if (stergeProdus(allProd, id_sterg) == 0) {
						printf("\033[1;31m");
						printf("Ceva a mers prost! Te rog incearca din nou!\n");
						printf("\033[0m");
					}
					else
						printf("Produs sters cu succes!\n");
				}
				else
					if (cmd == 4) {

						MyList* filteredL;
						int cresc;
						printf("Introduce-ti 1 daca doriti ordonare crescatoare sau 0 altfel: ");
						scanf_s("%d", &cresc);

						if (cresc == 1 || cresc == 0) {

							filteredL=sortare(allProd, cresc, (sorteaza)compararePret,(sorteaza)comparareCantitate);
							printAllProduct(filteredL);
							destroy(filteredL);
							
							}
							else {
								printf("\033[1;31m");
								printf("Optiune invalida! Va rugam incercati din nou!\n\n\n");
								printf("\033[0m");
							}
					}
					else
						if (cmd == 5) {

							MyList* filteredL;
							int opt_f;
							printf("Alegeti criteriul dupa care sa fie filtrate produsele:\n");
							printf("1 pentru producator, 2 pentru pret si 3 pentru cantitate: ");
							scanf_s("%d", &opt_f);
							if (opt_f == 1) {
								printf("\033[1;36m");
								filterProd(allProd);
								printf("\033[0m");
							}
							else
								if (opt_f == 2) {
									float pret;
									printf("Introduce-ti pretul dupa care se filtreaza: ");
									scanf_s("%f", &pret);
									filteredL = getAllProductbyprice(allProd, pret);
									printf("\n\n");
									printf("\033[1;36m");
									printAllProduct(filteredL);
									printf("\033[0m");
									destroy(filteredL);
								}
								else
									if (opt_f == 3) {
										int cantitate;
										printf("Introduce-ti cantitatea dupa care se filtreaza: ");
										scanf_s("%d", &cantitate);
										filteredL = getAllProductbyquantite(allProd, cantitate);
										printf("\n\n");
										printf("\033[1;36m");
										printAllProduct(filteredL);
										printf("\033[0m");
										destroy(filteredL);
									}
									else
									{
										printf("\033[1;31m");
										printf("Optiune invalida! Va rugam incercati din nou!\n\n\n");
										printf("\033[0m");
									}
						}
						else
							if (cmd == 0) {
								ruleaza = 0;
							}
							else {
								printf("\033[1;31m");
								printf("Optiune invalida! Va rugam incercati din nou!\n\n\n");
								printf("\033[0m");
							}

	}
	destroy(allProd);
}
