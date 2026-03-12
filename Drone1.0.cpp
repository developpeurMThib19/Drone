#include <iostream>
#include <string>

class Drone {
    private: 
        float altitude;
        int batterie;
        bool estAllume;
    
    public:
        Drone() {
            altitude = 0.0;
            batterie = 100;
            estAllume = false;
        }

        void allumer() {
            if (estAllume == false) {
                estAllume = true;
                std::cout << "Le drone est maintenant allume.\n";
            } else {
                std::cout << "Le drone est déjà allume.\n";
            }
        }

        void decoller() {
            if (estAllume == false) {
                std::cout << "Impossible de decoller : le drone est eteint.\n";
            } else if (altitude > 0) {
                std::cout << "Le drone est déjà en l'aire.\n";
            } else if (batterie <= 0) {
                std::cout << "Batterie vide. Impossible de decoller.\n";
            } else {
                altitude = 1.0;
                batterie -= 5;
                std::cout << "Le drone decolle.\n";
            }
        }

        void monter() {
            if (estAllume == false) {
                std::cout << "Impossible de monter : le drone est eteint.\n";
            } else if (altitude <= 0) {
                std::cout << "Le drone doit d'abord decoller.\n";
            } else if (batterie <= 0) {
                std::cout << "Batterie vide. Impossible de monter.\n";
            } else {
                altitude += 1.0;
                batterie -= 2;
                std::cout << "Le drone monte.\n";
            }
        }

        void descendre() {
            if (estAllume == false) {
                std::cout << "Impossible de descendre : le drone est eteint./n";
            } else if (altitude <= 0) {
                std::cout << "Le drone est déjà au sol.\n";
            } else {
                altitude -= 1.0;
                batterie -= 1;

                if (altitude <  0) {
                    altitude = 0;
                }
                std::cout << "Le drone descend.\n";
            }
        }

        void afficherEtat() {
            std::cout << "\n--- Etat du drone ---\n";
            std::cout << "Altitude : " << altitude << " m\n";
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

            std::cout << "----------------------\n";
        }
};

int main() {
    Drone drone;
    int choix = 0;

    while (choix != 6) {
        std::cout << "\n=== MENU DRONE ===\n";
        std::cout << "1 - Allumer le drone\n";
        std::cout << "2 - Decoller\n";
        std::cout << "3 - Monter\n";
        std::cout << "4 - Descendre\n";
        std::cout << "5 - Afficher l'etat\n";
        std::cout << "6 - Quitter\n";
        std::cout << "Votre choix : ";
        std::cin >> choix;

        if (choix == 1) {
            drone.allumer();
        } else if (choix == 2) {
            drone.decoller();
        } else if (choix == 3) {
            drone.monter();
        } else if (choix == 4) {
            drone.descendre();
        } else if (choix == 5) {
            drone.afficherEtat();
        } else if (choix == 6) {
            std::cout << "Fermeture du programme.\n";
        } else {
            std::cout << "Choix invalide.\n";
        }
    }

    return 0;
}