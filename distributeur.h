#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include "stock.h"
#include "monnayeur.h"

class Distributeur {
public:
    // Constructeur / Destructeur
    Distributeur();
    ~Distributeur() {}

    // Fonctions d'état
    int produit_demande() const;

    // Autres méthodes
    void delivre_produit();
    void annule_demande();
    void demande_produit(int num);
    void run();

private:
    // Données membres
    int num_produit;
    Stock stock_produits;
    Monnayeur monnayeur;
};

#endif