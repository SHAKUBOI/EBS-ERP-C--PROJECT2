#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

enum TypePersonne {
    ELEVE,
    PROFESSEUR,
    PERSONNEL,
    VISITEUR
};

class Personne {
protected:
    std::string nom;
    std::string prenom;
    std::string numeroBadge;
    TypePersonne type;
    bool accesPeriodeAutorise;

public:
    Personne(std::string nom, std::string prenom, std::string numeroBadge, TypePersonne type)
        : nom(nom), prenom(prenom), numeroBadge(numeroBadge), type(type), accesPeriodeAutorise(false) {}

    virtual bool verifierAcces() = 0;

    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    std::string getNumeroBadge() const { return numeroBadge; }
    TypePersonne getType() const { return type; }
};

class Eleve : public Personne {
private:
    std::string classe;
public:
    Eleve(std::string nom, std::string prenom, std::string numeroBadge, std::string classe)
        : Personne(nom, prenom, numeroBadge, ELEVE), classe(classe) {}

    bool verifierAcces() override {
        // Logique spécifique pour les élèves
        return true;
    }
};

class Systeme_Pointage {
private:
    std::map<std::string, Personne*> personnes;

public:
    Systeme_Pointage() {
        std::srand(std::time(nullptr));
    }

    void ajouterPersonne(Personne* p) {
        personnes[p->getNumeroBadge()] = p;
    }

    // Méthode pour vérifier l'existence du badge
    Personne* verifierBadge(std::string numeroBadge) {
        auto it = personnes.find(numeroBadge);

        if (it != personnes.end()) {
            Personne* personne = it->second;

            std::cout << "Badge reconnu : " << personne->getNom() << " "
                      << personne->getPrenom() << std::endl;

            return personne;
        }

        std::cout << "Badge inconnu. Acces refuse." << std::endl;
        return nullptr;
    }

    // Méthode pour simuler le badgeage avec confirmation aléatoire
    void simulerBadgeage() {
        std::string numeroBadge;
        int nombreAleatoire, reponseUtilisateur;

        std::cout << "Veuillez scanner votre badge (entrez le numero de badge) : ";
        std::cin >> numeroBadge;

        // Vérification du badge
        Personne* personne = verifierBadge(numeroBadge);

        // Si le badge n'est pas reconnu, arrêter ici
        if (personne == nullptr) {
            return;
        }

        // Générer un nombre aléatoire entre 1 et 999
        nombreAleatoire = std::rand() % 999 + 1;

        std::cout << "Completez le code de confirmation pour obtenir 1000." << std::endl;
        std::cout << "Le code systeme est : " << nombreAleatoire << std::endl;
        std::cout << "Entrez le nombre complementaire : ";
        std::cin >> reponseUtilisateur;

        // Vérification du code de confirmation
        if (nombreAleatoire + reponseUtilisateur == 1000) {
            // Vérification de l'accès
            if (personne->verifierAcces()) {
                std::cout << "Acces autorise" << std::endl;
            } else {
                std::cout << "Acces refuse" << std::endl;
            }
        } else {
            std::cout << "Code de confirmation incorrect. Acces refuse." << std::endl;
        }
    }
};

int main() {
    Systeme_Pointage systeme;

    // Exemple d'ajout de personnes
    Eleve* eleve1 = new Eleve("Seck", "Mohamed", "BADGE001", "6eme A");
    Eleve* eleve2 = new Eleve("Martin", "Sophie", "BADGE002", "2nd B");

    systeme.ajouterPersonne(eleve1);
    systeme.ajouterPersonne(eleve2);

    // Simulation du badgeage
    systeme.simulerBadgeage();

    return 0;
}
