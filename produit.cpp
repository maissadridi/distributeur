#include "produit.h"
#include <cstring>

Produit::Produit(const char* nom, float prix) : valeur(prix) {
    this->nom = new char[strlen(nom) + 1];
    strcpy(this->nom, nom);
}

Produit::~Produit() {
    delete[] nom;
}