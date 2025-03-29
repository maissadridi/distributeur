#ifndef MONNAYEUR_H
#define MONNAYEUR_H

class Monnayeur {
public:
    Monnayeur();
    
    bool exact() const;
    bool assez() const;
    void memorise_prix(float prix);
    void recevoir(float montant);
    float rendre_monnaie();
    float annulation();

private:
    float prix;
    float somme_totale;
};

#endif