#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric> // Pour std::accumulate
#include <iomanip>
using namespace std;

int global_input;
string current_state = "None";


// Classe de base Utilisateur
class Utilisateur {
protected:
    string password;
public:
    string Nom;
    string Prenom;
    string ID;
    Utilisateur(string Nom, string Prenom, string ID, string password)
        : Nom(Nom), Prenom(Prenom), ID(ID), password(password) {}

    virtual ~Utilisateur() {}
    string getID() const { return ID; }
};




// Classe Parent
class Parent : public Utilisateur {
public:
    unordered_map<string, string> mesg = {{"Destinataire", "message"}};
    string Enfant;
    Parent(string Nom, string Prenom, string Enfant, string ID, string password)
        : Utilisateur(Nom, Prenom, ID, password), Enfant(Enfant) {}
    void AfficherMes(){
        cout<<"Message recu :\n";
        for (const auto& pair : mesg) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    void envoyerMes(string dest, string mes){
        mesg[dest]=mes;
    }
    // Function to check if the provided ID and password match the stored values
    bool login(string input_id, string input_password) const {
        return (input_id == ID && input_password == password);}
};



// Classe Eleve
class Eleve : public Utilisateur {
public:
    unordered_map<string, int> notes = {{"Mathematiques", 11}, {"Francais", 14}, {"Anglais", 15}, {"HistGeo", 10}}; // Matière -> Note
    unordered_map<string, string> mesg = {{"Destinataire", "message"}};
    string Classe;
    int Absence;
    int Retard;
    Eleve(string Nom, string Prenom, string Classe, int Absence, int Retard, string ID, string password)
        : Utilisateur(Nom, Prenom, ID, password), Classe(Classe), Absence(Absence), Retard(Retard) {}
    void ajouterNote(const string& matiere, int note) {
        notes[matiere] = note;
    }
    void afficherNotes() const {
        cout << "Notes de l'eleve " << Nom << " " << Prenom << " :\n";
        for (const auto& note : notes) {
            cout << note.first << ": " << note.second << "\n";
        }
    }
    void afficherMoyenne() const {
        if (notes.empty()) {
            cout << "Aucune note disponible pour " << Nom << " " << Prenom << ".\n";
            return;
        }
        double somme = accumulate(
            notes.begin(), notes.end(), 0.0,
            [](double total, const pair<string, int>& note) {
                return total + note.second;
            });
        double moyenne = somme / notes.size();
        cout << "Moyenne des notes de " << Nom << " " << Prenom << ": " << moyenne << "\n";
    }
    // Méthode pour donner accès au Prof/CPE
    unordered_map<string, int>& getNotesAccess() {
        return notes; // Référence pour modification
    }
    void AfficherMes(){
        cout<<"Message recu :\n";
        for (const auto& pair : mesg) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    void envoyerMes(string dest, string mes){
        mesg[dest]=mes;
    }
    // Function to check if the provided ID and password match the stored values
    bool login(string input_id, string input_password) const {
        return (input_id == ID && input_password == password);}
};



// Classe Prof
class Prof : public Utilisateur {
public:
    unordered_map<string, string> mesg = {{"Destinataire", "message"}};
    string Matiere;
    int Absence;
    int Retard;
    Prof(string Nom, string Prenom, string Matiere, int Absence, int Retard, string ID, string password)
        : Utilisateur(Nom, Prenom, ID, password), Matiere(Matiere), Absence(Absence), Retard(Retard) {}
    void modifierNote(Eleve& eleve, const string& matiere, int note) {
        auto& notes = eleve.getNotesAccess();
        notes[matiere] = note;
        cout << "Note modifiee : " << matiere << " = " << note << " pour l'eleve " << eleve.Nom << " " << eleve.Prenom << ".\n";
    }
    void AfficherMes(){
        cout<<"Message recu :\n";
        for (const auto& pair : mesg) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    void envoyerMes(string dest, string mes){
        mesg[dest]=mes;
    }
    // Function to check if the provided ID and password match the stored values
    bool login(string input_id, string input_password) const {
        return (input_id == ID && input_password == password);}
};


// Classe CPE
class CPE : public Utilisateur {
public:
    unordered_map<string, string> mesg = {{"Destinataire", "message"}};
    CPE(string Nom, string Prenom, string ID, string password)
        : Utilisateur(Nom, Prenom, ID, password) {}
    void modifierNote(Eleve& eleve, const string& matiere, int note) {
        auto& notes = eleve.getNotesAccess();
        notes[matiere] = note;
        cout << "Note modifiee : " << matiere << " = " << note << " pour l'eleve " << eleve.Nom << " " << eleve.Prenom << ".\n";
    }
    void AfficherMes(){
        cout<<"Message recu :\n";
        for (const auto& pair : mesg) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    void envoyerMes(string dest, string mes){
        mesg[dest]=mes;
    }
    // Function to check if the provided ID and password match the stored values
    bool login(string input_id, string input_password) const {
        return (input_id == ID && input_password == password);}
};





///-------------------------------------------------------------------------------------------------------------------------------------
///------------------------------------------------------- Instanciation ---------------------------------------------------------------



Parent JoeSMITH("SMITH", "Joe", "MathewSMITH", "IDSMITH0", "sss678");
Eleve MamadouDYEN("DYEN", "Mamadou", "2ndD", 0, 0, "IDDYEN", "12345");
Eleve MarieSY("SY", "Marie", "6emeA", 0, 0, "IDSY","12345");
Prof MamadouDIOP("DIOP", "Mamadou", "Maths", 0, 0, "IDDIOP", "12345");
CPE FatouSECK("SECK", "Fatou", "IDSECK", "12345");
Eleve MathewSMITH("SMITH", "Mathew", "2ndD", 0,0, "IDSMITH1", "12345");






///------------------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------- LISTES ET TABLES ----------------------------------------------------------------


//Listes utilisateurs
vector<Parent>parents = {JoeSMITH};
vector<Eleve>eleves = {MamadouDYEN, MarieSY, MathewSMITH};
vector<Prof>professeurs = {MamadouDIOP};
vector<CPE>cpe = {FatouSECK};

//Devoirs
map<string, string>devoirs2D = {{"Maths","P59 N9"}, {"Francais","Lire le texte"}, {"HG","Aucun devoir"}, {"Anglais","Aucun devoir"}};
map<string, string>devoirs6A = {{"Maths","P60 N9 et 10"}, {"Francais","Aucun devoir"}, {"HG","Aucun devoir"}, {"Anglais","P70"}};

//Emplois du temps
vector<vector<string>> edt2nd = {
        {"Horaire", "Lundi", "Mardi","Mercredi", "Jeudi", "Vendredi"},
        {"8h-9h", "Maths", "Anglais","Hist-Geo","Francais","Maths"},
        {"9h-10h", "Maths", "Hist-Geo","Hist-Geo","---","Francais"},
        {"10h-11h", "Francais", "Hist-Geo","Anglais","Anglais","Maths"},
        {"11h-12h", "Francais", "---","Anglais","---","Anglais"},
        {"12h-13h", "--", "---","Maths","Hist-Geo","---"},
};

vector<vector<string>> edt6eme = {
        {"Horaire", "Lundi", "Mardi","Mercredi", "Jeudi", "Vendredi"},
        {"8h-9h", "Maths", "Anglais","Hist-Geo","Francais","Maths"},
        {"9h-10h", "Maths", "Hist-Geo","Hist-Geo","---","Francais"},
        {"10h-11h", "Francais", "Hist-Geo","Anglais","Anglais","Maths"},
        {"11h-12h", "Francais", "---","Anglais","---","Anglais"},
        {"12h-13h", "--", "---","Maths","Hist-Geo","---"},
};


vector<vector<string>> diopm = {
        {"Horaire", "Lundi", "Mardi","Mercredi", "Jeudi", "Vendredi"},
        {"8h-9h", "Cours 6A", "---","Cours 2D","---","Cours 6A"},
        {"9h-10h", "Cours 6A", "Cours 4C","Cours 2D","---","Cours 4D"},
        {"10h-11h", "---", "Cours 4C","Cours 2D","---","Cours 2B"},
        {"11h-12h", "Cours 2D", "Cours 2B","---","Cours 2D","Cours 2B"},
        {"12h-13h", "Cours 5B", "Cours 3A","Cours 3B","Cours 2D","---"},
};









///--------------------------------------------------------------------------------------------------------------------------
///-------------------------------------------------Variables et constantes--------------------------------------------------




string input_id, input_password;
bool is_logged_in = false;
string espace = "None";
string page = "None";

Parent upar=Parent("None", "None", "None", "None", "None");
Eleve uele=Eleve("None", "None", "None", 0, 0, "None", "None");
Prof upro=Prof("None", "None", "None", 0, 0, "None", "None");
CPE ucpe=CPE("None", "None", "None", "None");

Parent dpar=Parent("None", "None", "None", "None", "None");
Eleve dele=Eleve("None", "None", "None", 0, 0, "None", "None");
Prof dpro=Prof("None", "None", "None", 0, 0, "None", "None");
CPE dcpe=CPE("None", "None", "None", "None");









///----------------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------- FONCTIONS --------------------------------------------------------------










void trouverDestnParID(const string& idRechercher) {
    for (const Eleve& eleve : eleves) {
        if (eleve.ID == idRechercher) {
            dele=eleve;
        }
    }
    for (const Parent& parent : parents) {
        if (parent.ID == idRechercher) {
            dpar=parent;
        }
    }
    for (const Prof& prof : professeurs) {
        if (prof.ID == idRechercher) {
            dpro=prof;
        }
    }
    for (const CPE& cp : cpe) {
        if (cp.ID == idRechercher) {
            dcpe=cp;
        }
    }
}
void afficheurMess()
{
    if (dpar.ID != "None")
    {
        dpar.AfficherMes();
    }
    else if (dele.ID != "None")
    {
        dele.AfficherMes();
    }
    else if (dpro.ID != "None")
    {
        dpro.AfficherMes();
    }
    else if (dcpe.ID != "None")
    {
        dcpe.AfficherMes();
    }
}

void envoiMess(string dest, string mess)
{
    if (dpar.ID != "None")
    {
        dpar.envoyerMes(dest, mess);
    }
    else if (dele.ID != "None")
    {
        dele.envoyerMes(dest, mess);
    }
    else if (dpro.ID != "None")
    {
        dpro.envoyerMes(dest, mess);
    }
    else if (dcpe.ID != "None")
    {
        dcpe.envoyerMes(dest, mess);
    }
}

void MenuMessage()
{
    string dest, destinataire, message;
    cout<<"Choisissez une option\n"<<"1. Envoyer message\n"<<"2. Voir message\n";
    int op;
    cin>>op;
    if (op == 1)
    {
        cout<<"Entrez l'identifiant du destinataire\n";
        cin>>dest;
        trouverDestnParID(dest);
        cout<<"Tapez votre message\n";
        cin>>message;
        envoiMess(dest, message);
        cout<<"Message envoyer\n";
    }
    else if (op == 2)
    {
        cout<<"Entrez l'identifiant du destinataire\n";
        string dest;
        cin>>dest;
        trouverDestnParID(dest);
        afficheurMess();
    }
}



//Affichage de l'emploi du temp
void printEdt(const vector<vector<string>>& table) {
    // Iterate over the rows
    for (const auto& row : table) {
        // Iterate over each column in the row
        for (const auto& cell : row) {
            cout << setw(15) << left << cell;  // Format each cell
        }
        cout << endl;  // New line after each row
    }
}

//Affichage des devoirs
void AfficherDev(const Eleve& eleve){
    if (eleve.Classe == "2ndD"){
        for (const auto& pair : devoirs2D) {
        cout << pair.first << " : " << pair.second << endl;
    }}
    else if (eleve.Classe == "6emeA") {
        for (const auto& pair : devoirs6A) {
        cout << pair.first << " : " << pair.second << endl;
    }}
    else {
        cout<<"Une erreur est survenue"<<endl;
    }
}

//Affichage de l'edt en fonction de la classe
void AfficherEDT(const Eleve& eleve){
    if (eleve.Classe == "2ndD"){
        cout<<"Emploi du temps 2nd D\n";
        printEdt(edt2nd);
    }
    else if (eleve.Classe == "6emeA") {
        cout<<"Emploi du temps 6eme A\n";
        printEdt(edt6eme);
    }
    else {
        cout<<"Une erreur est survenue"<<endl;
    }
}

void AfficherEDTProf(const Prof& prof){
    if (prof.Nom == "DIOP"){
        cout<<"Emploi du temps DIOP Mamadou D\n";
        printEdt(diopm);
    }
    else {
        cout<<"Une erreur est survenue"<<endl;
    }
}


//Affichage des absences et des retards des eleves
void AfficherAbsRet(const Eleve& eleve) {
    cout<<"Liste des absences et retard de : "<<eleve.Nom<<" "<<eleve.Prenom<<endl;
    cout<<"Absence : "<<eleve.Absence<<" Retard : "<<eleve.Retard<<endl;
}

//Affichage des absences et des retards
void AfficherAbsRetProf(const Prof& prof) {
    cout<<"Liste des absences et retard de : "<<prof.Nom<<" "<<prof.Prenom<<endl;
    cout<<"Absence : "<<prof.Absence<<" Retard : "<<prof.Retard<<endl;
}


//Verificateur de l'enfant pour l'espace parent
void checkChildName(Parent& parent, const vector<Eleve>& liste) {
    for (const Eleve& eleve : liste)
    {
        if (eleve.Nom == parent.Nom)
        {
            uele=eleve;
        }
    };
};


//Verificateur de l'id et mdp
auto credentialsCheck() {
    cout << "Bienvenue sur Edutrack\n";
    cout << "Entrez votre ID: ";
    cin >> input_id;
    cout << "Entrez votre mot de passe: ";
    cin >> input_password;

    // Check login credentials for each student
    for (const Eleve& elev : eleves) {
        if (elev.login(input_id, input_password)) {
            is_logged_in = true;
            current_state="Eleve";
            uele=elev;
            cout << "Bienvenu, " << elev.Nom << " " << elev.Prenom << " de la " << elev.Classe << "!\n";
            break;
        }
    }
    for (const Parent& par : parents) {
        if (par.login(input_id, input_password)) {
            is_logged_in = true;
            current_state = "Parent";
            upar=par;
            checkChildName(upar, eleves);
            cout << "Bienvenu, " << par.Nom << " " << par.Prenom << "!\n";
            break;
        }
    }
    for (const Prof& prof : professeurs) {
        if (prof.login(input_id, input_password)) {
            is_logged_in = true;
            current_state = "Prof";
            upro=prof;
            cout << "Bienvenu, " << prof.Nom << " " <<prof.Prenom << "!\n";
            break;
        }
    }
    for (const CPE& cp : cpe) {
        if (cp.login(input_id, input_password)) {
            is_logged_in = true;
            current_state = "CPE";
            ucpe=cp;
            cout << "Bienvenu, " << cp.Nom << " " << cp.Prenom <<"!\n";
            break;
        }
    }
    // If login fails
    if (!is_logged_in) {
        cout << "Id ou mot de passe incorrect\n";
    }
    return 0;
}



//Check choix de l'espace
void InputAcc(char input) {
    switch(input)
    {
    case '1':
        espace = "Parent";
        cout<<"Espace parent"<<endl;
        break;
    case '2':
        espace = "Eleve";
        cout<<"Espace eleve"<<endl;
        break;
    case '3':
        espace="Professeur";
        cout<<"Espace professeur"<<endl;
        break;
    case '4':
        espace="CPE";
        cout<<"Espace cpe"<<endl;
        break;
    default:
        cout<<"Commande invalide"<<endl;
    }
}


//Check input espace eleve
void InputEleve(char input) {
    switch(input)
    {
    case '1':
        page = "edt";
        cout<<"\nEmploi du temps\n"<<endl;
        AfficherEDT(uele);
        break;
    case '2':
        page = "devoirs";
        cout<<"\nDevoirs\n"<<endl;
        AfficherDev(uele);
        break;
    case '3':
        page = "notes";
        cout<<"\nNotes\n"<<endl;
        uele.afficherNotes();
        uele.afficherMoyenne();
        break;
    case '4':
        page="message";
        cout<<"\nMessagerie\n"<<endl;
        MenuMessage();
        break;
    case '5':
        espace="vs";
        cout<<"\nVie scolaire\n"<<endl;
        AfficherAbsRet(uele);
        break;
    case '6':
        current_state = "Accueil";
        cout<<"Vous avez ete deconnecte\n\n";
        return;
    default:
        cout<<"\nCommande invalide\n"<<endl;
    };
}

//Affichage des options de l'espace eleve
auto menuEleve() {
    while (current_state=="Eleve") {
    char input;
    cout << "\nChoisissez une option :\n";
    cout << "1. Emploi du temps\n";
    cout << "2. Devoirs\n";
    cout << "3. Notes\n";
    cout << "4. Messagerie\n";
    cout << "5. Vie scolaie\n";
    cout << "6. Se deconnecter\n";
    cin>>input;
    InputEleve(input);
};
}









//------------------------------------------------- OPTIONS ESPACE PARENT --------------------------------------------------


//Check input espace eleve
void InputParent(char input) {
    switch(input)
    {
    case '1':
        page = "edt";
        cout<<"\nEmploi du temps\n"<<endl;
        AfficherEDT(uele);
        break;
    case '2':
        page = "devoirs";
        cout<<"\nDevoirs\n"<<endl;
        AfficherDev(uele);
        break;
    case '3':
        page = "notes";
        cout<<"\nNotes\n"<<endl;
        uele.afficherNotes();
        uele.afficherMoyenne();
        break;
    case '4':
        page="message";
        cout<<"\nMessagerie\n"<<endl;
        MenuMessage();
        break;
    case '5':
        espace="vs";
        cout<<"\nVie scolaire\n"<<endl;
        AfficherAbsRet(uele);
        break;
    case '6':
        current_state = "Accueil";
        cout<<"Vous avez ete deconnecte\n\n";
        return;
    default:
        cout<<"\nCommande invalide\n"<<endl;
    };
}


auto menuParent() {
    while (current_state=="Parent") {
    char input;
    cout << "\nChoisissez une option :\n";
    cout << "1. Emploi du temps\n";
    cout << "2. Devoirs\n";
    cout << "3. Notes\n";
    cout << "4. Messagerie\n";
    cout << "5. Vie scolaie\n";
    cout << "6. Se deconnecter\n";
    cin>>input;
    InputParent(input);
};
}









//---------------------------------------------- OPTIONS ESPACE PROFESSEUR --------------------------------------------------



Eleve* trouverEleveParNom(const vector<Eleve>& liste, const string& nomRecherche) {
    for (const Eleve& eleve : liste) {
        if (std::string(eleve.Nom) == nomRecherche) {
            uele=eleve;
        }
    }
    //return nullptr;
}



void MenuDevoirs()
{
    cout<<"Choisissez une option\n"<<"1. Voir devoirs\n"<<"2. Modifier devoir\n";
    int op;
    string travail;
    cin>>op;
    if (op == 1)
    {
        cout<<"Entrez le nom de famille de l'eleve\n";
        string elv;
        cin>>elv;
        trouverEleveParNom(eleves, elv);
        AfficherDev(uele);
    }
    else if (op == 2)
    {
        cout<<"Entrez la classe :\n";
        string clas;
        cin>>clas;
        if (clas == "2ndD")
        {
            cout<<"Entrer une matiere\n";
            string matiere;
            cin>>matiere;
            cout<<"Entrez le travail a faire\n";
            cin>>travail;
            devoirs2D[matiere] = travail;
            cout << "Modification effectuee avec succes !";
        }
        else if (clas == "6emeA")
        {
            cout<<"Entrer une matiere\n";
            string matiere;
            cin>>matiere;
            cout<<"Entrez le travail a faire\n";
            getline(cin, travail);
            devoirs6A[matiere] = travail;
            cout << "Modification effectuee avec succes !";
        }

    }
}


void MenuNotes()
{
    string matiere, elv;
    int op, note;
    cout<<"Choisissez une option\n"<<"1. Voir notes\n"<<"2. Ajouter note\n"<<"3. Modifier notes\n";
    cin>>op;
    if (op == 1)
    {
        cout<<"Entrez le nom de l'eleve\n";
        cin>>elv;
        trouverEleveParNom(eleves, elv);
        uele.afficherNotes();
        uele.afficherMoyenne();
    }
    if (op == 2)
    {
        cout<<"Entrez le nom de l'eleve\n";
        cin>>elv;
        trouverEleveParNom(eleves, elv);
        cout<<"Tapez la matiere\n";
        cin>>matiere;
        cout<<"Tapez la note\n";
        cin>>note;
        uele.ajouterNote(matiere, note);
        uele.afficherNotes();
        uele.afficherMoyenne();
    }
    else if (op == 3)
    {
        cout<<"Entrez le nom de l'eleve\n";
        cin>>elv;
        trouverEleveParNom(eleves, elv);
        cout<<"Tapez la matiere\n";
        cin>>matiere;
        cout<<"Tapez la note\n";
        cin>>note;
        uele.notes[matiere]=note;
        uele.afficherNotes();
        uele.afficherMoyenne();
    }
}




//Check input espace prof
void InputProf(char input) {
    switch(input)
    {
    case '1':
        page = "edt";
        cout<<"\nEmploi du temps\n"<<endl;
        AfficherEDTProf(upro);
        break;
    case '2':
        page = "devoirs";
        cout<<"\nDevoirs\n"<<endl;
        MenuDevoirs();
        break;
    case '3':
        page = "notes";
        cout<<"\nNotes\n"<<endl;
        MenuNotes();
        break;
    case '4':
        page="message";
        cout<<"\nMessagerie\n"<<endl;
        MenuMessage();
        break;
    case '5':
        espace="vs";
        cout<<"\nVie scolaire\n"<<endl;
        AfficherAbsRetProf(upro);
        break;
    case '6':
        current_state = "Accueil";
        cout<<"Vous avez ete deconnecte\n\n";
        return;
    default:
        cout<<"\nCommande invalide\n"<<endl;
    };
}

auto menuProf() {
    while (current_state=="Prof") {
    char input;
    cout << "\nChoisissez une option :\n";
    cout << "1. Emploi du temps\n";
    cout << "2. Devoirs\n";
    cout << "3. Notes\n";
    cout << "4. Messagerie\n";
    cout << "5. Vie scolaie\n";
    cout << "6. Se deconnecter\n";
    cin>>input;
    InputProf(input);
};
}














//------------------------------------------------- OPTIONS ESPACE CPE --------------------------------------------------



void modifierEDT(vector<vector<string>>& edt) {
    cout << "Emploi du temps actuel : " << endl;
    printEdt(edt);

    // Demander les indices de la case à modifier
    cout << "\nEntrez le numero de la ligne a modifier (1-" << edt.size() - 1 << ") : ";
    int ligne;
    cin >> ligne;

    // Vérifier la validité de la ligne
    if (ligne < 1 || ligne >= edt.size()) {
        cout << "Ligne invalide !" << endl;
        return;
    }

    cout << "Entrez le numero de la colonne a modifier (1-" << edt[0].size() - 1 << ") : ";
    int colonne;
    cin >> colonne;

    // Vérifier la validité de la colonne
    if (colonne < 1 || colonne >= edt[0].size()) {
        cout << "Colonne invalide !" << endl;
        return;
    }

    // Demander la nouvelle valeur
    cout << "Entrez la nouvelle matiere : ";
    string nouvelleValeur;
    cin.ignore(); // Ignore le '\n' restant dans le buffer
    getline(cin, nouvelleValeur);

    // Modifier l'emploi du temps
    edt[ligne][colonne] = nouvelleValeur;
    cout << "Modification effectuee avec succes !" << endl;

    // Afficher l'emploi du temps mis à jour
    cout << "Emploi du temps mis a jour : " << endl;
    printEdt(edt);
}



void ModificateurEDT()
{
    cout<<"Choisissez une categorie :\n"<<"1. Emploi du temps eleve\n"<<"2. Emploi du temps professeur\n";
    int option;
    cin>>option;
    if (option == 1)
    {
        cout<<"Choisissez la classe\n"<<"1. 2ndA\n"<<"2. 6emeA\n";
        cin>>option;
        if (option == 1)
        {
            modifierEDT(edt2nd);
        }
        else if (option == 2)
        {
            modifierEDT(edt6eme);
        }
        else{cout<<"Erreur";}
    }
    else if (option ==2)
    {
        cout<<"Choisissez le professeur\n"<<"1. M. DIOP\n";
        cin>>option;
        if (option == 1)
        {
            modifierEDT(diopm);
        }
        else{cout<<"Erreur";}
    }
    else{cout<<"Erreur";}
};



void edtAbsRet() {
    cout<<"Choisissez une option\n"<<"1. Voir absence/retard\n"<<"2. Modifier absence/retard";
    string id;
    int i, a, r;
    cin>>i;
    if (i == 1)
    {
        cout<<"Tapez l'identifiant de l'utilisateur";
        cin>>id;
        trouverDestnParID(id);
        if (dele.Nom!="None")
        {
            AfficherAbsRet(dele);
        }
        else if (dpro.Nom!="None")
        {
            AfficherAbsRetProf(dpro);
        }
    }
    else if (i == 2)
    {
        cout<<"Entrez l'identifiant de l'utilisateur\n";
        cin>>id;
        trouverDestnParID(id);
        cout<<"Choisissez une option\n"<<"1. Modifier absence\n"<<"2. Modifier retard\n";
        cin>>i;
        if (i == 1)
        {
            cout<<"Entrer le nombre d'absence\n";
            cin>>a;
            if (dele.Nom != "None")
            {
                dele.Absence = a;
                cout<<"Absence et retard modifier :\n";
                cout<<"Absence : "<<dele.Absence<<" "<<"Retard :"<<dele.Retard;
            }
            else if (dpro.Nom != "None")
            {
                dpro.Absence = a;
                cout<<"Absence et retard modifier :\n";
                cout<<"Absence : "<<dpro.Absence<<" "<<"Retard :"<<dpro.Retard;
            }
        }
        else if (i == 2)
        {
            cout<<"Entrer le nombre de retard\n";
            cin>>r;
            if (dele.Nom != "None")
            {
                dele.Retard = r;
                cout<<"Absence et retard modifier :\n";
                cout<<"Absence : "<<dele.Absence<<" "<<"Retard :"<<dele.Retard;
            }
            else if (dpro.Nom != "None")
            {
                dpro.Retard = r;
                cout<<"Absence et retard modifier :\n";
                cout<<"Absence : "<<dpro.Absence<<" "<<"Retard :"<<dpro.Retard;
            }
        }
    }
}




//Check input espace prof
void InputCPE(char input) {
    ucpe=FatouSECK;
    switch(input)
    {
    case '1':
        page = "edt";
        cout<<"\Modifier emploi du temps\n"<<endl;
        ModificateurEDT();
        break;
    case '2':
        page = "devoirs";
        cout<<"\nDevoirs\n"<<endl;
        MenuDevoirs();
        break;
    case '3':
        page = "notes";
        cout<<"\nNotes\n"<<endl;
        MenuNotes();
        break;
    case '4':
        page="message";
        cout<<"\nMessagerie\n"<<endl;
        MenuMessage();
        break;
    case '5':
        espace="vs";
        cout<<"\nVie scolaire\n"<<endl;
        edtAbsRet();
        break;
    case '6':
        current_state = "Accueil";
        cout<<"Vous avez ete deconnect\n\n";
        return;
    default:
        cout<<"\nCommande invalide\n"<<endl;
    };
}




auto menuCpe() {
    while (current_state=="CPE") {
    char input;
    cout << "\nChoisissez une option :\n";
    cout << "1. Modifier emploi du temps\n";
    cout << "2. Devoirs\n";
    cout << "3. Notes\n";
    cout << "4. Messagerie\n";
    cout << "5. Vie scolaie\n";
    cout << "6. Se deconnecter\n";
    cin>>input;
    InputCPE(input);
};
}


///----------------------------------------------------- ACCUEIL -----------------------------------------------------------





//Page d'accueil
void Accueil() {
    char input;
    cout << "Bienvenue sur Edutrack, choisissez votre espace :\n";
    cout << "1. Espace parent\n";
    cout << "2. Espace eleve\n";
    cout << "3. Espace professeur\n";
    cout << "4. Espace cpe\n";
    cout << "Appuyez sur 1, 2, 3, 4 pour choisir une option.\n";
    cin>>input;
    InputAcc(input);
    credentialsCheck();
    if (is_logged_in == true && input == '1')
    {
        current_state="Parent";
    }
    else if (is_logged_in == true && input == '2')
    {
        current_state = "Eleve";
    }
    else if (is_logged_in == true && input == '3')
    {
        current_state = "Prof";
    }
    else if (is_logged_in == true && espace == "cpe")
    {
        current_state = "CPE";
    }
};






///############################################################################################################################
///----------------------------------------------------------------------------------------------------------------------------
///--------------------------------------------------------- MAIN -------------------------------------------------------------




int main() {
    ///Run start
    char input;
    cout << "Bienvenue sur Edutrack, choisissez votre espace :\n";
    cout << "1. Espace parent\n";
    cout << "2. Espace eleve\n";
    cout << "3. Espace professeur\n";
    cout << "4. Espace cpe\n";
    cout << "Appuyez sur 1, 2, 3, 4 pour choisir une option.\n";
    cin>>input;
    InputAcc(input);
    credentialsCheck();
    if (is_logged_in == true && input == '1')
    {
        current_state="Parent";
    }
    else if (is_logged_in == true && input == '2')
    {
        current_state = "Eleve";
    }
    else if (is_logged_in == true && input == '3')
    {
        current_state = "Prof";
    }
    else if (is_logged_in == true && input == '4')
    {
        current_state = "CPE";
    }
    while (true) {
        if (current_state == "Accueil")
        {
            Accueil();
        }
        else if (current_state == "Eleve")
        {
            menuEleve();
        }
        else if (current_state == "Parent" )
        {
            menuParent();
        }
        else if (current_state == "Prof")
        {
            menuProf();
        }
        else if (current_state == "CPE")
        {
            menuCpe();
        }
        else if (current_state == "Accueil")
        {
            Accueil();
        }

    }
}
    /*
    // Definir les notes

    // Ajout de notes par le prof
    MamadouDIOP.modifierNote(MamadouDYEN, "Mathematiques", 15);
    MamadouDIOP.modifierNote(MamadouDYEN, "Physique", 12);

    // Affichage des notes et de la moyenne par l'eleve
    MamadouDYEN.afficherNotes();
    MamadouDYEN.afficherMoyenne();

    return 0;
*/

/*
int main()
{
    trouverEleveParNom(eleves, "DYEN");
}
*/

