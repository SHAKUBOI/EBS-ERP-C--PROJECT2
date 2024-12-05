#include <iostream>
#include <conio.h>  // For _kbhit() and _getch()
using namespace std;

//Maths, Fr, Hist, Anglais
// Function to draw the table
void edt2nd() {
    // Table header
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;
    cout << "|   Heure    |   Lundi    |   Mardi    |  Mercredi  |   Jeudi    |  Vendredi  |" << endl;
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;

    // Table data rows
    cout << "| 8h-9h      |   Maths    |  Francais  |     --     |  Francais  |  Hist-Geo  |" << endl;
    cout << "| 9h-10h     |  Francais  |   Maths    |   Maths    |  Anglais   |  Hist-Geo  |" << endl;
    cout << "| 10h-11h    |  Francais  |   Maths    |   Maths    |  Anglais   |  Francais  |" << endl;
    cout << "| 11h-12h    |     --     |  Anglais   |  Francais  |   Maths    |     --     |" << endl;
    cout << "| 12h-13h    |  Anglais   |     --     |     --     |     --     |   Maths    |" << endl;
    cout << "| 13h-14h    |  Anglais   |     --     |     --     |     --     |     --     |" << endl;
    cout << "| 14h-15h    |     --     |  Hist-Geo  |     --     |  Hist-Geo  |  Anglais   |" << endl;
    cout << "| 15h-16h    |     --     |     --     |     --     |  Hist-Geo  |     --     |" << endl;

    // Table footer
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;
}
//Stop : better idea, make a dictionnary with an hour as key and matiere as value. then display the list. This will allow for edt editing.
void edt6eme() {
    // Table header
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;
    cout << "|   Heure    |   Lundi    |   Mardi    |  Mercredi  |   Jeudi    |  Vendredi  |" << endl;
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;

    // Table data rows
    cout << "| 8h-9h      |   Maths    |  Francais  |     --     |  Francais  |  Hist-Geo  |" << endl;
    cout << "| 9h-10h     |  Francais  |  Francais  |     --     |  Anglais   |  Hist-Geo  |" << endl;
    cout << "| 10h-11h    |  Francais  |   Maths    |   Maths    |  Anglais   |  Francais  |" << endl;
    cout << "| 11h-12h    |  Anglais   |   Maths    |  Francais  |   Maths    |     --     |" << endl;
    cout << "| 12h-13h    |  Anglais   |     --     |     --     |     --     |   Maths    |" << endl;
    cout << "| 13h-14h    |     --     |     --     |     --     |     --     |     --     |" << endl;
    cout << "| 14h-15h    |     --     |  Hist-Geo  |     --     |  Hist-Geo  |  Anglais   |" << endl;
    cout << "| 15h-16h    |     --     |  Hist-Geo  |     --     |  Hist-Geo  |     --     |" << endl;

    // Table footer
    cout << "+------------+------------+------------+------------+------------+------------+" << endl;
}


void Accueil() {
    std::cout << "Bienvenue Name. Que voulez vous consulter? :\n";
    std::cout << "1. Emploi du temps\n";
    std::cout << "2. Cahier de texte\n";
    std::cout << "3. Notes\n";
    std::cout << "4. Messagerie\n";
    std::cout << "5. Vie scolaire\n";
    std::cout << "Appuyez sur 1, 2, 3, 4, 5 pour choisir une option.\n";
}

void handleInput(char input) {
    switch(input)
    {
    case '1':
        cout<<"Emploi du temps"<<endl;
        edt2nd();
        break;
    case '2':
        cout<<"Cahier de texte"<<endl;
        break;
    case '3':
        cout<<"Notes"<<endl;
        break;
    case '4':
        cout<<"Messagerie"<<endl;
        break;
    case '5':
        cout<<"Vie scolaire"<<endl;
        break;
    default:
            cout<<"Commande invalide"<<endl;
    }

}


int main() {
    Accueil();
    while (true) {
        if (_kbhit()) {  // If a key is pressed
            char key = _getch();  // Capture the key without waiting for Enter
            handleInput(key);
        }
    }
    return 0;
}

