#include "monnayeur.h"
#include <iostream>

Monnayeur::Monnayeur() : prix(0), somme_totale(0) {}

bool Monnayeur::exact() const {
    return (somme_totale == prix);
}

bool Monnayeur::assez() const {
    return (somme_totale >= prix);
}

void Monnayeur::memorise_prix(float prix) {
    this->prix = prix;
    somme_totale = 0;
    std::cout << "Prix a payer: " << prix << std::endl;
}

void Monnayeur::recevoir(float montant) {
    somme_totale += montant;
    std::cout << "Somme payee: " << somme_totale << std::endl;
}

float Monnayeur::rendre_monnaie() {
    float monnaie = somme_totale - prix;
    if (monnaie < 0) monnaie = 0;
    std::cout << "Monnaie rendue: " << monnaie << std::endl;
    prix = 0;
    somme_totale = 0;
    return monnaie;
}

float Monnayeur::annulation() {
    float monnaie = somme_totale;
    prix = 0;
    somme_totale = 0;
    std::cout << "Annulation - monnaie rendue: " << monnaie << std::endl;
    return monnaie;
}