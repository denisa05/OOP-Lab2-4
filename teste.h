#pragma once
#ifndef TESTS_H
#define TESTS_H

#include "domain.h"

//Teste adaugare produse
void testAddProduct();

//Test creaza lista
void testCreateList();

//Teste pentru lista
void testIterateList();

//Test copie lista
void testCopyList();

// Test pentru crearea si stergerea unui produs
void testCreateDestroy();

// Test pentru ad?ugarea unui produs
void test_addProduct();

// Test pentru actualizarea unui produs
void test_updateProduct();

// Test pentru ?tergerea unui produs
void test_stergeProdus();

// Test pentru filtrarea produselor dup? produc?tor
void test_getAllProduct_by_producator();

// Test pentru filtrarea produselor dup? pre?
void test_getAllProduct_by_price();

// Test pentru filtrarea produselor dup? cantitate
void test_getAllProduct_by_quantity();

// Test pentru sortarea produselor în ordine cresc?toare dup? pre? ?i cantitate
void test_comparareProduse_crescator();

// Test pentru sortarea produselor în ordine descresc?toare dup? pre? ?i cantitate
void test_comparareProduse_descrescator();

void test_sortare_crescatoare_dupa_pret();
#endif // TESTS_H