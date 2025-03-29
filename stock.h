#ifndef STOCK_H
#define STOCK_H

#include "produit.h"

// Constantes
const int MAX_SORTES = 5;
const int MAX_QUANTITE = 10;
const int SEUIL = 2;

const int ERR_INCONNU = -1;
const int ERR_INTERVALLE = 0;
const int OK = 0;
const int ERR_PLEIN = 1;
const int ERR_VIDE = 2;
const int ERR_DEP = 3;

class Stock {
private:
    int current_index;  // Renommé pour éviter le conflit
    int quantites[MAX_SORTES];
    Produit* rails[MAX_SORTES];

public:
    Stock();
    ~Stock() {}

    int nb_sortes() const;
    int nb_unites(int num_produit) const;
    Produit* ieme(int num_produit) const;

    bool est_vide(int num_produit) const;
    bool est_limite() const;

    int stocker(Produit* adr_produit, int quantite);
    int retirer(int num_produit);
    int traite_vide(int num_produit);

private:
    bool est_plein(int num_produit) const;
    int rechercher(Produit* adr_produit) const;
};

#endif