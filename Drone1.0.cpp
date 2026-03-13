#include <iostream>
#include <string>
#include <vector>

class Drone {
    private: 
        float altitude;
        float altitudeMax;
        int batterie;
        bool estAllume;
        std::vector<std::string> journal;

        void ajouterAuJournal(std::string message) {
            journal.push_back(message);
        }
    
    public:
        Drone() {
            altitude = 0.0;
            altitudeMax = 10.0;
            batterie = 100;
            estAllume = false;
        }

        void allumer() {
            if (estAllume == false) {
                estAllume = true;
                std::cout << "Le drone est maintenant allume.\n";
                ajouterAuJournal("Drone allume");
            } else {
                std::cout << "Le drone est déjà allume.\n";
                ajouterAuJournal("Tentative d'allumage alors que le drone est deja allume");
            }
        }

         void eteindre() {
        if (estAllume == false) {
            std::cout << "Le drone est deja eteint.\n";
            ajouterAuJournal("Tentative d'extinction alors que le drone est deja eteint");
        } else if (altitude > 0) {
            std::cout << "Impossible d'eteindre le drone : il est en vol.\n";
            ajouterAuJournal("Tentative d'extinction refusee : drone en vol");
        } else {
            estAllume = false;
            std::cout << "Le drone est maintenant eteint.\n";
            ajouterAuJournal("Drone eteint");
        }
    }

        void decoller() {
            if (estAllume == false) {
                std::cout << "Impossible de decoller : le drone est eteint.\n";
                ajouterAuJournal("Tentative de decollage refusee : drone eteint");
            } else if (altitude > 0) {
                std::cout << "Le drone est déjà en l'aire.\n";
                ajouterAuJournal("Tentative de decollage refusee : drone deja en l'air");
            } else if (batterie <= 10) {
                std::cout << "Batterie trop faible pour decoller.\n";
                ajouterAuJournal("Tentative de decollage refuse : Batterie trop faible");
            } else {
                altitude = 1.0;
                batterie -= 5;
                std::cout << "Le drone decolle.\n";
                ajouterAuJournal("Drone decolle");
                verifierBatterieCritique();
            }
        }

        void monter() {
        if (estAllume == false) {
            std::cout << "Impossible de monter : le drone est eteint.\n";
            ajouterAuJournal("Tentative de montee refusee : drone eteint");
        } else if (altitude <= 0) {
            std::cout << "Le drone doit d'abord decoller.\n";
            ajouterAuJournal("Tentative de montee refusee : drone au sol");
        } else if (batterie < 2) {
            std::cout << "Batterie trop faible pour monter.\n";
            ajouterAuJournal("Tentative de montee refusee : batterie trop faible");
        } else if (altitude >= altitudeMax) {
            std::cout << "Altitude maximale atteinte.\n";
            ajouterAuJournal("Tentative de montee refusee : altitude maximale atteinte");
        } else {
            altitude += 1.0;
            batterie -= 2;
            std::cout << "Le drone monte.\n";
            ajouterAuJournal("Drone monte");
            verifierBatterieCritique();
        }
    }

        void descendre() {
            if (estAllume == false) {
                std::cout << "Impossible de descendre : le drone est eteint./n";
                ajouterAuJournal("Tentative de descente refusee : drone eteint");
            } else if (altitude <= 0) {
                std::cout << "Le drone est déjà au sol.\n";
                ajouterAuJournal("Tentative de descente refusee : drone deja au sol");
            } else {
                altitude -= 1.0;
                batterie -= 1;

                if (altitude <  0) {
                    altitude = 0;
                }

                if (batterie < 0) {
                    batterie = 0;
                }

                std::cout << "Le drone descend.\n";
                ajouterAuJournal("Drone descend");
            }
        }

        void rechargerBatterie() {
        if (altitude > 0) {
            std::cout << "Impossible de recharger : le drone est en vol.\n";
            ajouterAuJournal("Tentative de recharge refusee : drone en vol");
        } else if (batterie >= 100) {
            batterie = 100;
            std::cout << "La batterie est deja pleine.\n";
            ajouterAuJournal("Tentative de recharge alors que la batterie est deja pleine");
        } else {
            batterie += 20;

            if (batterie > 100) {
                batterie = 100;
            }

            std::cout << "La batterie a ete rechargee.\n";
            ajouterAuJournal("Batterie rechargee");
        }
    }

    void verifierBatterieCritique() {
        if (batterie <= 5 && altitude > 0) {
            std::cout << "Alerte critique : batterie tres faible.\n";
            ajouterAuJournal("Alerte critique batterie");
            atterrissageAutomatique();
        }
    }

    void atterrissageAutomatique() {
        std::cout << "Atterrissage automatique en cours...\n";
        ajouterAuJournal("Atterrissage automatique declenche");

        while (altitude > 0) {
            altitude -= 1.0;

            if (altitude < 0) {
                altitude = 0;
            }

            batterie -= 1;

            if (batterie < 0) {
                batterie = 0;
            }

            std::cout << "Le drone descend automatiquement. Altitude : " << altitude << " m\n";
            ajouterAuJournal("Descente automatique du drone");
        }

        std::cout << "Le drone a atterri automatiquement.\n";
        ajouterAuJournal("Drone pose au sol automatiquement");
    }

        void afficherEtat() {
            std::cout << "\n--- Etat du drone ---\n";
            std::cout << "Altitude : " << altitude << " m\n";
            std::cout << "Altitude  Max : " << altitudeMax << " m\n";
            std::cout << "Batterie : " << batterie << "%\n";

            if (estAllume == true) {
                std::cout << "Etat : allume\n";
            } else {
                std::cout << "Etat : eteint\n";
            }

            if (altitude > 0) {
                std::cout << "Position : en vol\n";
            } else {
                std::cout << "Position : au sol\n";
            }

            if (batterie <= 20) {
                std::cout << "Alerte : batterie faible\n";
            }

            std::cout << "----------------------\n";
        }

        void afficherJournal() {
        std::cout << "\n--- Journal des actions ---\n";

        if (journal.size() == 0) {
            std::cout << "Aucune action enregistree.\n";
        } else {
            for (int i = 0; i < journal.size(); i++) {
                std::cout << i + 1 << " - " << journal[i] << "\n";
            }
        }

        std::cout << "---------------------------\n";
    }

};

int main() {
    Drone drone;
    int choix = 0;

    while (choix != 9) {
        std::cout << "\n=== MENU DRONE ===\n";
        std::cout << "1 - Allumer le drone\n";
        std::cout << "2 - Eteindre le drone\n";
        std::cout << "3 - Decoller\n";
        std::cout << "4 - Monter\n";
        std::cout << "5 - Descendre\n";
        std::cout << "6 - Afficher l'etat\n";
        std::cout << "7 - Recharger la batterie\n";
        std::cout << "8 - Afficher le journal\n";
        std::cout << "9 - Quitter\n";
        std::cout << "Votre choix : ";
        std::cin >> choix;

        if (choix == 1) {
            drone.allumer();
        } else if (choix == 2) {
            drone.eteindre();
        } else if (choix == 3) {
            drone.decoller();
        } else if (choix == 4) {
            drone.monter();
        } else if (choix == 5) {
            drone.descendre();
        } else if (choix == 6) {
            drone.afficherEtat();
        } else if (choix == 7) {
            drone.rechargerBatterie();
        } else if (choix == 8) {
            drone.afficherJournal();
        } else if (choix == 9) {
            std::cout << "Fermeture du programme.\n";
        } else {
            std::cout << "Choix invalide.\n";
        }
    }

    return 0;
}