#include <assert.h>
#include <string.h>
#include "teste.h"
#include "domain.h"
#include "repo.h"
#include "service.h"
#include <stdlib.h>
#include <stdio.h>

void testCreateList() {
    MyList* l = create_list();
    assert(size(l) == 0);
    destroy(l);
}
void testIterateList() {
    MyList* l = create_list();
    add(l, create_produs(1, "a", "b", "c", 20, 10));
    add(l, create_produs(2, "a2", "b2", "c2", 40, 20));
    assert(size(l) == 2);
    Produs p = get(l, 0);

    assert(strcmp(p.tip, "a") == 0);
    p = get(l, 1);
    assert(strcmp(p.producator, "b2") == 0);
    destroy(l);
}

void testCopyList() {
    MyList* l = create_list();
    add(l, create_produs(1, "a", "b", "c", 20, 10));
    add(l, create_produs(2, "a2", "b2", "c2", 40, 20));
    MyList* l2 = copyList(l);
    assert(size(l2) == 2);
    Produs p = get(l2, 0);
    assert(strcmp(p.tip, "a") == 0);
    destroy_produs(&p);
    destroy(l);
    destroy(l2);
}

void testCreateDestroy() {
    Produs p = create_produs(1, "laptop", "asus", "tuf15", 100.0, 10);
    assert(strcmp(p.tip, "laptop") == 0);
    assert(strcmp(p.producator, "asus") == 0);
    assert(strcmp(p.model, "tuf15") == 0);
    assert(p.pret == 100.0);
    assert(p.cantitate == 10);
    assert(p.id == 1);

    destroy_produs(&p);
    assert(strlen(p.tip) == 0);
    assert(strlen(p.producator) == 0);
    assert(p.id == -1);
}

void testAddProduct() {
    MyList* l = create_list();

    int error = addProduct(l, -3, "a", "b", "c", 20, 10);
    assert(error != 0);
    assert(size(l) == 0);

    error = addProduct(l, 1, "", "b", "c", 20, 10);
    assert(error != 0);
    assert(size(l) == 0);

    error = addProduct(l, 2, "a", "", "c", 20, 10);
    assert(error != 0);
    assert(size(l) == 0);


    error = addProduct(l, 3, "a", "b", "", 20, 10);
    assert(error != 0);
    assert(size(l) == 0);

    error = addProduct(l, 3, "a", "b", "c", -20, 10);
    assert(error != 0);
    assert(size(l) == 0);

    error = addProduct(l, 3, "a", "b", "c", 20, -10);
    assert(error != 0);
    assert(size(l) == 0);

    addProduct(l, 1, "a", "b", "c", 20, 10);
    addProduct(l, 2, "a2", "b2", "c2", 40, 20);

    error = addProduct(l, 2, "e", "e", "e", 20, 10);
    assert(error != 0);
    assert(size(l) == 2);

    MyList* filtered = getAllProduct(l, NULL);
    assert(size(filtered) == 2);

    destroy(filtered);

    filtered = getAllProduct(l, "b2");
    assert(size(filtered) == 1);

    destroy(filtered);
    filtered = getAllProduct(l, "2");
    assert(size(filtered) == 1);

    destroy(filtered);
    filtered = getAllProduct(l, "b");
    assert(size(filtered) == 2);

    destroy(l);
    destroy(filtered);
}

void test_addProduct() {
    MyList* l = create_list();
    assert(size(l) == 0);

    assert(addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10) == 0);
    assert(size(l) == 1);

    assert(addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 5) == 0);
    assert(size(l) == 1);
    assert(get(l, 0).cantitate == 15);

    destroy(l);
}

void test_updateProduct() {
    MyList* l = create_list();
    addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10);
    addProduct(l, 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8);

    assert(updateProduct(l, 1, 2700.0, 12) == 1);
    assert(get(l, 0).pret == 2700.0);
    assert(get(l, 0).cantitate == 12);
    assert(updateProduct(l, 3, 2700.0, 12) == 0);
    destroy(l);
}

void test_stergeProdus() {
    MyList* l = create_list();
    addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10);
    addProduct(l, 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8);

    assert(stergeProdus(l, 1) == 1);
    assert(size(l) == 1);
    assert(stergeProdus(l, 3) == 0);
    destroy(l);
}

void test_getAllProduct_by_producator() {
    MyList* l = create_list();
    addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10);
    addProduct(l, 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8);

    MyList* filtered = getAllProduct(l, "Dell");
    assert(size(filtered) == 1);
    assert(strcmp(get(filtered, 0).producator, "Dell") == 0);
    destroy(l);
    destroy(filtered);
}

void test_getAllProduct_by_price() {
    MyList* l = create_list();
    addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10);
    addProduct(l, 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8);

    MyList* filtered = getAllProductbyprice(l, 2500.0);
    assert(size(filtered) == 1);
    assert(get(filtered, 0).pret == 2500.0);
    destroy(l);
    destroy(filtered);
}

void test_getAllProduct_by_quantity() {
    MyList* l = create_list();
    addProduct(l, 1, "Laptop", "Dell", "Inspiron", 2500.0, 10);
    addProduct(l, 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8);

    MyList* filtered = getAllProductbyquantite(l, 8);
    assert(size(filtered) == 1);
    assert(get(filtered, 0).cantitate == 8);
    destroy(l);
    destroy(filtered);
}

void test_comparareProduse_crescator() {
    Produs p1 = { 1, "Laptop", "Dell", "Inspiron", 2500.0, 10 };
    Produs p2 = { 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8 };
    Produs p3 = { 3, "Tableta", "Apple", "iPad", 1500.0, 15 };

    assert(compararePret(&p1, &p2) == 0);
    assert(compararePret(&p1, &p3) == 1);
    assert(compararePret(&p1, &p1) == 2);
}

void test_comparareProduse_descrescator() {
    Produs p1 = { 1, "Laptop", "Dell", "Inspiron", 2500.0, 10 };
    Produs p2 = { 2, "Telefon", "Samsung", "Galaxy S10", 3000.0, 8 };
    Produs p3 = { 3, "Tableta", "Apple", "iPad", 1500.0, 15 };

    assert(comparareCantitate(&p1, &p2) > 0);
    assert(comparareCantitate(&p1, &p3) == 0);
    assert(comparareCantitate(&p1, &p1) == 0);
}

void test_sortare_crescatoare_dupa_pret() {
    MyList* lista = create_list();

    addProduct(lista, 1,"Produs 1","b","c", 100, 5);
    addProduct(lista, 2,"Produs 2","b","c", 50, 10);
    addProduct(lista, 3,"Produs 3","b","c", 75, 3);

    MyList* lista_sortata = sortare(lista, 1, (sorteaza)compararePret, (sorteaza)comparareCantitate);

    Produs p = lista_sortata->elems[0];
    assert(p.id == 2);

    destroy(lista_sortata);
    lista_sortata = sortare(lista, 0, (sorteaza)compararePret, (sorteaza)comparareCantitate);

    p = lista_sortata->elems[0];
    assert(p.id == 1);

    destroy(lista);
    destroy(lista_sortata);
}