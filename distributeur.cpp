#include "distributeur.h"
#include <iostream>

Distributeur::Distributeur() : num_produit(-1) {
    Produit* produit;
    
    produit = new Produit("Orange", 3.00);
    stock_produits.stocker(produit, 5);
    
    produit = new Produit("Cafe_sans", 5.00);
    stock_produits.stocker(produit, 4);
    
    produit = new Produit("Cafe_unpeu", 5.00);
    stock_produits.stocker(produit, 3);
    
    produit = new Produit("Cafe_beaucoup", 5.00);
    stock_produits.stocker(produit, 2);
}

int Distributeur::produit_demande() const {
    return num_produit;
}

void Distributeur::demande_produit(int num) {
    if (num >= 1 && num <= 4) {
        num_produit = num - 1;
        monnayeur.memorise_prix(stock_produits.ieme(num_produit)->acces_prix());
    }
}

void Distributeur::annule_demande() {
    num_produit = -1;
    monnayeur.annulation();
}

void Distributeur::delivre_produit() {
    if (num_produit == -1) return;
    
    if (monnayeur.assez()) {
        if (stock_produits.retirer(num_produit) == OK) {
            std::cout << "Produit delivre: " 
                      << stock_produits.ieme(num_produit)->acces_nom() 
                      << std::endl;
            monnayeur.rendre_monnaie();
        } else {
            std::cout << "Produit epuise!" << std::endl;
        }
    } else {
        std::cout << "Montant insuffisant!" << std::endl;
    }
    
    if (stock_produits.est_limite()) {
        std::cout << "[Appelez le remplisseur!]" << std::endl;
    } else {
        std::cout << "[Remplissage OK]" << std::endl;
    }
}

void Distributeur::run() {
    char repl, rep2;
    int fini = 0;
    float piece;

    while (!fini) {
        std::cout << "[P]roduits, [M]onnayeur, [Q]uitter? ";
        std::cin >> repl;
        
        switch(toupper(repl)) {
            case 'P':
                std::cout << "[Q]uitter ou numero du produit (1-4)? ";
                std::cin >> rep2;
                if (toupper(rep2) == 'Q') break;
                if (rep2 >= '1' && rep2 <= '4') {
                    demande_produit(rep2 - '0');
                }
                break;
                
            case 'M':
                std::cout << "[Q]uitter, [A]nnulation ou piece ([0]:0.50, [1]:1, [2]:2, [5]:5, [D]:10)? ";
                std::cin >> rep2;
                switch(toupper(rep2)) {
                    case 'Q': break;
                    case 'A': annule_demande(); break;
                    case '0': monnayeur.recevoir(0.50); break;
                    case '1': monnayeur.recevoir(1.00); break;
                    case '2': monnayeur.recevoir(2.00); break;
                    case '5': monnayeur.recevoir(5.00); break;
                    case 'D': monnayeur.recevoir(10.00); break;
                    default: std::cout << "Choix invalide!" << std::endl;
                }
                if (produit_demande() != -1 && monnayeur.assez()) {
                    delivre_produit();
                }
                break;
                
            case 'Q':
                fini = 1;
                break;
                
            default:
                std::cout << "Choix invalide!" << std::endl;
        }
    }
}