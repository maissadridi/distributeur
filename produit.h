#ifndef PRODUIT_H
#define PRODUIT_H

class Produit {
public:
    Produit(const char* nom, float prix);
    ~Produit();
    
    const char* acces_nom() const { return nom; }
    float acces_prix() const { return valeur; }

private:
    char* nom;
    float valeur;
};

#endif