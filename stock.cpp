#include "stock.h"
#include <iostream>

Stock::Stock() : current_index(0) {
    for (int i = 0; i < MAX_SORTES; i++) {
        quantites[i] = 0;
        rails[i] = nullptr;
    }
}

int Stock::nb_sortes() const {
    return current_index;
}

int Stock::nb_unites(int num_produit) const {
    if (num_produit < 0 || num_produit >= current_index) return 0;
    return quantites[num_produit];
}

Produit* Stock::ieme(int num_produit) const {
    if (num_produit < 0 || num_produit >= current_index) return nullptr;
    return rails[num_produit];
}

bool Stock::est_vide(int num_produit) const {
    return (num_produit < 0 || num_produit >= current_index || quantites[num_produit] == 0);
}

bool Stock::est_limite() const {
    for (int i = 0; i < current_index; i++) {
        if (quantites[i] < SEUIL) return true;
    }
    return false;
}

int Stock::stocker(Produit* adr_produit, int quantite) {
    int num = rechercher(adr_produit);
    
    if (num != ERR_INCONNU) {
        if (est_plein(num)) return ERR_PLEIN;
        if (quantites[num] + quantite > MAX_QUANTITE) return ERR_DEP;
        quantites[num] += quantite;
    } else {
        if (current_index >= MAX_SORTES) return ERR_PLEIN;
        rails[current_index] = adr_produit;
        quantites[current_index] = quantite;
        current_index++;
    }
    return OK;
}

int Stock::retirer(int num_produit) {
    if (num_produit < 0 || num_produit >= current_index) return ERR_INTERVALLE;
    if (est_vide(num_produit)) return traite_vide(num_produit);
    quantites[num_produit]--;
    return OK;
}

int Stock::traite_vide(int num_produit) {
    return ERR_VIDE;
}

bool Stock::est_plein(int num_produit) const {
    return (num_produit >= 0 && num_produit < current_index && 
           quantites[num_produit] >= MAX_QUANTITE);
}

int Stock::rechercher(Produit* adr_produit) const {
    for (int i = 0; i < current_index; i++) {
        if (rails[i] == adr_produit) return i;
    }
    return ERR_INCONNU;
}