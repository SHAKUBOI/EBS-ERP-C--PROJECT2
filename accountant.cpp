#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>  // For _kbhit() and _getch()
#include <map>
#include <string>

using namespace std;

// Payment structure to track individual student payments
struct Payment {
    string studentName;
    double amount;
    string status;  // "Paid", "Pending", "Late"
};

class SchoolFinances {
private:
    vector<Payment> payments;
    map<string, double> totalPaymentsByStatus;

public:
    // Add a new payment
    void addPayment(string studentName, double amount, string status = "en attente") {
        payments.push_back({studentName, amount, status});
        totalPaymentsByStatus[status] += amount;
    }

    // Update payment status
    void updatePaymentStatus(string studentName, string newStatus) {
        for (auto& payment : payments) {
            if (payment.studentName == studentName) {
                // Subtract from old status total
                totalPaymentsByStatus[payment.status] -= payment.amount;

                // Update status
                payment.status = newStatus;

                // Add to new status total
                totalPaymentsByStatus[newStatus] += payment.amount;
                break;
            }
        }
    }

    // Display all payments
    void displayPayments() {
        cout << "+------------------------------+------------+----------------------+" << endl;
        cout << "| Nom de l'Étudiant            |   Montant  |   Statut             |" << endl;
        cout << "+------------------------------+------------+----------------------+" << endl;

        for (const auto& payment : payments) {
            cout << "| "
                 << setw(28) << left << payment.studentName << " |"
                 << setw(11) << right << fixed << setprecision(2) << payment.amount << " |"
                 << setw(21) << payment.status << " |" << endl;
        }

        cout << "+------------------------------+------------+----------------------+" << endl;
    }

    // Display financial summary
    void displayFinancialSummary() {
        cout << "+---------------------+--------------------+" << endl;
        cout << "| Statut              | Montant Total      |" << endl;
        cout << "+---------------------+--------------------+" << endl;

        for (const auto& entry : totalPaymentsByStatus) {
            cout << "| "
                 << setw(19) << left << entry.first << " | "
                 << setw(18) << right << fixed << setprecision(2) << entry.second << " |" << endl;
        }

        cout << "+---------------------+--------------------+" << endl;
    }
};

// Accountant Menu Interface
void AccountantAccueil() {
    cout << "Interface Comptabilite Scolaire -- Bienvenue, Pierre Ndiaye !\n";
    cout << "1. Ajouter un Paiement\n";
    cout << "2. Mettre a Jour un Paiement\n";
    cout << "3. Afficher Tous les Paiements\n";
    cout << "4. Rapport Financier\n";
    cout << "5. Deconnexion\n";
    cout << "Selectionnez une option (1-5)\n";
}

int main() {
    SchoolFinances finances;

    // Initialiser quelques paiements pour démonstration
    finances.addPayment("Jean Dupont", 50000.00, "Paiement en attente");
    finances.addPayment("Mohamed Seck", 75000.00, "Paiement effectue");
    finances.addPayment("Ibrahima Toure", 60000.00, "retard sur paiement");

    AccountantAccueil();

    while (true) {
        if (_kbhit()) {  // If a key is pressed
            char key = _getch();  // Capture the key without waiting for Enter

            switch(key) {
                case '1': {
                    string name;
                    double amount;
                    cout << "Nom de l'étudiant: ";
                    cin >> name;
                    cout << "Montant du paiement: ";
                    cin >> amount;
                    finances.addPayment(name, amount);
                    cout << "Paiement ajouté avec succès!\n";
                    break;
                }
                case '2': {
                    string name, status;
                    cout << "Nom de l'étudiant: ";
                    cin >> name;
                    cout << "Nouveau statut (Paye/en attente/en retard): ";
                    cin >> status;
                    finances.updatePaymentStatus(name, status);
                    cout << "Statut mis à jour!\n";
                    break;
                }
                case '3':
                    finances.displayPayments();
                    break;
                case '4':
                    finances.displayFinancialSummary();
                    break;
                case '5':
                    cout << "Fermeture de l'interface comptable.\n";
                    return 0;
                default:
                    cout << "Option invalide.\n";
            }

            // Redisplay menu after each action
            AccountantAccueil();
        }
    }
    return 0;
}
