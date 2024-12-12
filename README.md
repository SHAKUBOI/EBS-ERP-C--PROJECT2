# Rapport Technique - Projet 12 “EduTrack” :  Programation en C++ et Optimisation de la gestion d'une école.
![image](https://github.com/user-attachments/assets/f62ba876-73a9-459e-9832-131fd42d38e5)

# EduTrack ERP - Documentation Technique

EduTrack ERP est un logiciel de gestion complet conçu pour simplifier les tâches administratives, académiques et opérationnelles des établissements d'enseignement. Développé dans le cadre d'un projet scolaire, EduTrack combine une conception modulaire, une interface conviviale et une programmation efficace en C++.

## Contributeurs
- **[Jean Léandre TIEMTORE]** : Chef de Projet, Développement Frontend, Conception de l'Interface
- **[Omar EL GHAZAL]** : Développement Backend, Gestion de la Base de Données
- **[Thierno Lamine DIALLO]** : Documentation et Tests


## Table des Matières
1. [Aperçu du Projet](#aperçu-du-projet)
2. [Principales Fonctionnalités](#principales-fonctionnalités)
3. [Architecture Système](#architecture-système)
4. [Description des Modules](#description-des-modules)
5. [Schématisation des processus](#schématisation-des-processus)
6. [Améliorations Futures](#améliorations-futures)
7. [Outils utilisés](#outils-utilisés)


## Aperçu du Projet
EduTrack vise à répondre aux besoins essentiels des écoles et collèges en intégrant diverses fonctions telles que la gestion des informations sur les étudiants, le suivi des présences, la gestion du personnel et la planification dans une plateforme unifiée.

Les objectifs principaux de ce projet sont :
- Fournir une solution évolutive et efficace adaptée aux établissements éducatifs.
- Mettre en œuvre des algorithmes et structures de données robustes pour des performances optimisées.
- Améliorer l'expérience utilisateur grâce à une conception intuitive et une navigation fluide.

## Principales Fonctionnalités
- **Système d'Information Étudiant :** Gestion des dossiers, des notes et des données démographiques des étudiants.
- **Suivi des Présences :** Suivi automatisé des présences des étudiants et du personnel.
- **Module de Planification :** Création et gestion simplifiées des emplois du temps.
- **Authentification des Utilisateurs :** Accès sécurisé pour les administrateurs, enseignants et étudiants.
- **Gestion des finances  :** Génération de rapports détaillés et de visualisations.

## Architecture Système
Le système EduTrack ERP repose sur une architecture modulaire comprenant les couches suivantes :

1. **Couche de Présentation :**
   - Interface utilisateur conçue pour être claire et facile à utiliser.
   - Éléments graphiques et formulaires implémentés avec des bibliothèques compatibles avec C++.

2. **Couche Logique Métier :**
   - Algorithmes centraux pour l'automatisation des tâches et la prise de décision.
   - Structure modulaire pour la flexibilité et l'évolutivité.

3. **Couche de Données :**
   - Intégration avec une base de données relationnelle pour un stockage sécurisé et efficace des données.
   - Requêtes optimisées pour une récupération et une mise à jour des données en temps réel.


## Description des Modules
1. **Gestion des Étudiants :**
   - Opérations CRUD sur les dossiers des étudiants.
   - Fonctionnalités de recherche et de filtrage.

2. **Gestion du Personnel :**
   - Gestion des profils et des emplois du temps du personnel.
   - Suivi des performances et des congés.

3. **Système de Présence :**
   - Enregistrement et récupération des journaux de présence.
   - Intégration avec des systèmes biométriques (amélioration future).

4. **Planificateur d'Emplois du Temps :**
   - Planification automatisée sans conflit.
   - Interface conviviale avec glisser-déposer.


## Schématisation des processus

### Modèle Conceptuel de Données (MCD)
Le MCD d'EduTrack représente les principales entités et leurs relations dans le système. Voici une explication des principales entités :

- **Étudiant :** Représente les informations personnelles et académiques des étudiants.
- **Cours :** Définit les matières enseignées, associées à un ou plusieurs enseignants.
- **Présence :** Permet de suivre la participation des étudiants à chaque cours.
- **Personnel :** Contient les informations sur les enseignants et le personnel administratif.
- **Emploi du Temps :** Gère la planification des cours et des ressources associées.
![mermaid-MCD](https://github.com/user-attachments/assets/ae408c76-cf89-4bcf-a24d-9ade33460e93)


**Diagramme :**
Le diagramme MCD illustre ces entités et leurs relations. Par exemple :
- Une entité "Étudiant" est liée à plusieurs "Présences".
- Une entité "Cours" est associée à un ou plusieurs "Étudiants" et "Personnel".

### Diagrammes UML
#### Diagramme de Cas d'Utilisation
Ce diagramme met en évidence les principaux acteurs et leurs interactions avec le système :

- **Administrateur :** Gestion des utilisateurs, configuration des modules.
- **Enseignant :** Gestion des cours, consultation des présences.
- **Étudiant :** Accès à l'emploi du temps et aux résultats.
![UML ELEVE](https://github.com/user-attachments/assets/a9913dec-11a7-4a83-b126-28fa84826dfc)
##### Diagramme UML ELEVE

![UML PARENTS](https://github.com/user-attachments/assets/abdc711d-4d20-4c24-9421-72462102f90d)
##### Diagramme UML PARENT

![UML Professeur](https://github.com/user-attachments/assets/d24d51ec-d006-4fd6-8ba8-e7a7eab79268)
##### Diagramme UML PROFESSEUR

![UML CPE](https://github.com/user-attachments/assets/960094a8-a47f-4bba-9fb2-00e7af9d5a72)
##### Diagramme UML CPE

 ![UML COMPTABLE](https://github.com/user-attachments/assets/614b9ac6-937a-46d7-bb6e-2823477b11f7)
##### Diagramme UML COMPTABLE


#### Diagramme de Séquence
Un exemple de scénario pour le module de présence :
1. L'étudiant scanne son badge.
2. Le système vérifie les informations et enregistre la présence.
3. Un enseignant peut consulter ces données via l'interface.
![mermaid-diagram de sequence](https://github.com/user-attachments/assets/5612cc4b-be4e-45ef-98b1-e305d513234e)

#### Diagramme de Classes
Le diagramme de classes détaille les différentes classes implémentées dans le projet, telles que :
- **Classe Étudiant :** Avec attributs (nom, matricule, etc.) et méthodes (inscrire, consulter résultats).
- **Classe Cours :** Avec attributs (intitulé, code) et méthodes (assigner enseignant, générer rapport).
![mermaid-diagram de classe](https://github.com/user-attachments/assets/f4bec9a7-ba67-49f7-893b-66808761ea56)


Ces diagrammes permettent de visualiser clairement la structure et les interactions du système, facilitant ainsi le développement et la maintenance.

## Développement de l'ERP EduTrack

La plateforme EduTrack a été pensée et développée minutieusement par notre équipe afin que ce service soit complet le jour du déploiement; celà passe d'abord par le développement du Backend suivi de l'adaptation Frontend et de l'Intrface Utilisateur. Vous retrouverez dans les fichiers du projet le code du Backend sur lequel nous allons revenir ici.

 ![image](https://github.com/user-attachments/assets/31b3bc07-0f3e-4f7d-9de9-980be2c60de9)

Tout d’abord, on initialise les biblioteque a l’aide de « include ». On ajoute :
Iostream (biblioteque de base), string (pour les chaines de caractere), vector (pour les vecteurs), map et unordered_map (pour les dictionnaires), numeric et iomanip(pour les decalage de texte et formatage de texte). La variable « current_state » servira pour changer letat (espace parent, eleve, page d’accueil). 

#### Accueil
![image](https://github.com/user-attachments/assets/d4929b0d-7b09-4f54-85e6-97d541afbeb7)

On cree une classe utilisateur avec les attributs nom, prenom et id (attribut public accessibles) et password (attribut proteger, accès limité).
On initialise également un construteur Utilisateur.

-------
#### Espace Parent
![image](https://github.com/user-attachments/assets/3d07a157-4fc5-4c49-b128-be1bc84f3c13)
Ensuite on crée la classe parent avec comme attribut enfant (nom du fils ou fille du parent) . Cette classe hérite de la classe utilisateur. Ensuite on initialise les méthodes AfficherMes(pour afficher les messages reçus), envoyerMes (pour envoyer des messages) et la méthode login qui permettra plus tard de vérifier que l’utilisateur est connecté. On ajoute aussi un dictionnaire pour stocker les messages (clé : destinataire et valeur : message)

-------
#### Espace élève
![image](https://github.com/user-attachments/assets/36ff7da9-c1f5-430d-886c-321698307a38)
![image](https://github.com/user-attachments/assets/e57460e2-a5ce-4511-bbb7-3af819d0e2b9)
Enuite on crée la classe Elève avec les attributs classe, absence, retard. On initialise aussi les méthodes ajouterNote (pour ajouter des notes a leleve), afficherNote, afficherMoyenne (qui calcule la moyenne et l’affiche) afficherMes et envoyerMes et login. On ajout un dictionnaire pour les notes et un autres pour les messages.

------
#### Espace professeur
![image](https://github.com/user-attachments/assets/e69c10b9-6869-4ae4-82ba-a87e4942bff8)
Ensuite on crée la classe Prof avec les attributs matière, absence et retard. On ajoute aussi le dictionnaire de message. On ajoute les méthode pour modifier les notes, afficher les messages et envoyer les messages ainsi que la méthode login.

--------
#### Espace CPE
![image](https://github.com/user-attachments/assets/6eef883c-6032-4d0a-9828-f9d26003618b)
Ensuite, on crée la classe cpe qui a pour attribut un dictionnaire pour les messages, les méthodes pour modifier les notes, afficher les messages, envoyer les messages et la methode login.

-------
#### Espace comptable
Enfin on crée la classe Comptable qui a pour attribut studentName, amount et status, les méthodes pour ajouter et modifier les versements d'argent pour chaque élève.

![image](https://github.com/user-attachments/assets/020499ba-ddf5-48ce-b1b7-1927b3ff4128)

![Paiement récents](https://github.com/user-attachments/assets/2f156d31-dc16-4d76-a7d7-6027e08ec6cc)
##### Paiements récents

![Bilan Financier](https://github.com/user-attachments/assets/3f1ea94d-033c-4745-9f42-d79d402f22b7)
##### Bilan Financier

#### instanciation
![image](https://github.com/user-attachments/assets/db69ca43-9638-440d-bc6a-3b5c358a7d5b)
Ensuite, on instancie a l’aide des constructeurs definit dans les classes.

![image](https://github.com/user-attachments/assets/1a8df08a-178f-4d47-885d-d218144613ea)

![image](https://github.com/user-attachments/assets/38d85048-bced-41c6-8fad-323829d330e6)

Ensuite, on stocke les instances (parents, eleves etc) dans des vecteurs. Puis on stocke les devoirs par classe dans des dictionnaires. Ils nous serviront plus loin.

![image](https://github.com/user-attachments/assets/27afb983-b59e-43e2-9c50-0a600badfb7c)

On cree des variable input_id et input_password (qui permettront de verifier si les identifiants sont corrects), un booléen is_logged_in pour savoir si l’utilisateur est connecté ou pas, et une variable page pour savoird dans quelle page se trouve l’utilisateur.
Ensuite, on cree des « variables » pour chaque categorie (parent, prof etc). Cela nous servira plus tard (pour les check sur les attributs ou bien pour selectionner un utilisateur).

![image](https://github.com/user-attachments/assets/90a52c8e-2598-4142-825d-21fe7ae44730)
On cree une fonction qui permet de trouver le destinataire d’un message par son ID. Elle prend en parametre l’identifiant et check sa validité en realisant des egalité sur les utilisateurs de chaque liste.

![image](https://github.com/user-attachments/assets/e7502a11-bb6b-4911-a78a-7f573abcf76f)

La fonction ci-dessus permet d’afficher les messages d’un utilisateur (elle check si un utilisateur est sélectionné sachant qu’il est stocké dans une des variables qu’on a créer precedement).

![image](https://github.com/user-attachments/assets/dd2d8ab6-9995-4b3b-aed1-9f665437939c)
Ensuite, on crée une autre fonction pour envoyer des messages. Elle prend en parametre le nom du destinataire et le message. Ensuite, on realise des checks pour savoir qui est le destinataire (comment le reconnaitre ? En effectuant un check sur l’ID de la variable. Si l’ID nest pas « None », cela signifie que la personne en question est le destinataire du message).

![image](https://github.com/user-attachments/assets/6b05ceb7-34be-4a06-a971-5e98cb2b64bc)

![image](https://github.com/user-attachments/assets/21d07c76-4df9-4033-9e28-14067b7781c1)

On crée une fonction qui nous permettra de choisir les options dans le menu « Messagerie ». Deux options seront disponible : l’envoi de message et l’affichage des messages reçus. Pour l’option 1, on entre l’identifiant du destinataire. 
Ensuite on fait appel a la fonction trouverDestParID qui va, en fonction de l’ID entré (a condition qu’il soit valide), stocker l’utilisateur en question dans une variable (la variable dele, dpro, dpar ou dcpe en fonction de la classe de l’utilisateur).
Ensuite, on insere le message et on appel la fonction envoiMess qui enverra le message (en l’ajoutant au dictionnaire de message du destinataire). La deuxieme option suit le meme principe sauf qu’elle affiche les messages à la place.
La fonction suivante printEdt affiche l’emploi du temps. On parours les cellules de la liste (emploi du temps sous forme de liste, défini precedement) et on affiche la cellule avec une marge de 15 pour afficher l’emploi du temps de manière organiser et lisible.


![image](https://github.com/user-attachments/assets/934e3158-9781-411d-a55a-796ba50cb8fe)
On cree une fonction pour afficher les devoirs. On affiche d’abord la clé du dictionnaire (sachant que, comme vu plus haut, les devoirs sont organisé sous forme de dictionnaire clé valeur avec comme clé la matiere et comme valeur le devoir a faire) ensuite la valeur. Les affichages se font apres un check pour connaitre la classe de l’eleve. 

![image](https://github.com/user-attachments/assets/93aa4226-81d0-4b4b-8dee-e1c7078894ab)

La fonction AfficherEDT affiche l’emploi du temps en fonction de la classe en appelant a fonction printEdt qui elle s’occupe du formattage de la liste sous forme de tableau(pour l’affichage dans la console).


![image](https://github.com/user-attachments/assets/67a9ec65-27ca-4c40-9a9c-6a96d20b1c5f)

Ici, nous avons 3 fonctions. Une pour afficher les absences et retard des eleves (affiche les attributs correspondant).
Meme principe pour la fonction AfficherAbsRetProf. La fonction CheckChildName prend en parametre un objet de type Parent et une liste (liste d’eleves).
Elle parcours les liste pour trouver un eleve ayant le meme nom de famille que le parent.
S’il le trouve, se fils et stocker dans une variable.
Cette fonction est d’une grande importance car elle permettra d’afficher l’emploi du temp du fils ou de la fille dans l’espace de son parent, ainsi que ses devoirs etc.



![image](https://github.com/user-attachments/assets/e1792d48-5568-4bda-96f8-0258457c5cc7)


![image](https://github.com/user-attachments/assets/75479c2f-5387-4d62-bdce-4c430cef8be9)

La fonction credentialsCheck verifie l’identifiant et le mot de passe saisi dans la page d’accueil.
Elle verife si les données saisies existe en faisant appel a la methode login. 
Si les donnnées saisies correspondent, l’etat change en fonction de l’espace auquel on accede(Parent si on passe a l’espace parent, Eleve si on passe à l’espace élève etc). L’utilisateur est donc stocker dans une variable aussi (pour les operations a réaliser).


![image](https://github.com/user-attachments/assets/de331d68-998f-4c1c-8246-9924efb6ac49)

Maintenant on passe à la creation des espaces. Tout d’abord on crée une fonction pour vérifier l’option selectionnée sur la page d’accueil( espace parent, espace eleve etc). Pour cela on utilise un switch sur la valeur d’entré (input) avec un retour par defaut « Commande invalide ». Cette fonction sera fondamentale pour la suite.


![image](https://github.com/user-attachments/assets/b0dc2d57-d806-4c56-969b-7d954dcf7f9d)

Même principe pour l’espace eleve. Pour chaque option, une action sera réalisé (en fonction de l’option) comme l’affichage de l’emploi du temps, des devoirs etc.


![image](https://github.com/user-attachments/assets/9ad6c214-82b5-4f68-8324-8572c20f20fa)

Cette fonction affiche les options disponibles dans l’espace élève. Lorsqu’une option est choisie, on appel la fonction précedente pour lire l’input et agir en fonction de ce dernier. 


![image](https://github.com/user-attachments/assets/abcb0aa9-6ca9-4771-b418-2676c12d6b24)

Cette fonction suit le meme principe que la fonction InputEleve, mais realise les options disponibles pour les parents.


![image](https://github.com/user-attachments/assets/4b945208-d195-4267-b14e-b2d54b060ed1)

La fonction menuParent suit le même principe que la fonction menuEleve mais lis les inputs de la fonction InputParent.


![image](https://github.com/user-attachments/assets/a52f0e11-5379-49d1-8a09-f0d095c570b3)

La fonction ci-dessus ressemble beaucoup à la fonction trouverDestParID (définie précedement) cependant, celle-ci trouve un éleve en fonction du nom de famille.
Si le nom de l’éleve est reconnu, l’eleve est stocké dans une variable. Cette fonction nous sera utile plus loin.


![image](https://github.com/user-attachments/assets/00ab3f2b-1fcd-4e67-9f72-399ffa45dc7c)

La fonction ci-dessus est principalement dédier aux professeurs et au cpe. Elle leur permet de modifier des devoirs, en ajouter ou bien juste les afficher.
Le principe est simple : on saisie le nom de famille de l’élève puis à l’aide de la fonction trouverEleveParNom, on stock l’eleve concerné dans une variable. 
Si l’option 1 est sélectionné, on appel AfficherDev avec comme parametre la variable où l’élève a été stocké.
Pour l’option 2, on tape la classe d’abord, ensuite la matiere et le travail a ajouter.
Les données seront ajouter au dictionnaire de devoirs concernés. 


![image](https://github.com/user-attachments/assets/a7421642-5c39-45e3-8013-9612462bb9cc)


![image](https://github.com/user-attachments/assets/8208a7bb-405f-431b-85c9-caea13a4dc7d)

La fonction MenuNotes est exclusive aux professeurs et cpe. Elle affiche les différentes operations possibles sur les notes comme l’affichage simple des notes et de la moyenne des notes pour un élève (option 1) ou bien la modification/ l’ajout d’une note (option 2 et 3).
Pour ajouter, afficher des notes ou bien pour afficher la moyenne, on appel la methode correspondante définit plus haut dans les classes Eleve et Prof.
Pour la modification, on modifie juste la notes dont la clé est identique à la matière tapée en input.


![image](https://github.com/user-attachments/assets/131bd684-3b57-4342-bfff-ef1cac1c580a)

InputProf suit le même principe que InputEleve. Elle lis les input de l’utilisateur et réagis en fonction de l’option choisie

![image](https://github.com/user-attachments/assets/fda8ed23-671e-4dd3-845b-2cb4f5ae4209)
La fonction menuProf suit le même principe que menuEleve. Elle affiche les options disponibles pour les professeurs et appel InputProf pour lire l’input.


![image](https://github.com/user-attachments/assets/f4229732-8306-4353-a9ef-df8e53377aa8)

La fonction modifierEDT est indispensable pour la fonction qui suit. Tout d’abord, elle affiche l’emploi du temps actuel.
Ensuite, elle prend en input la ligne et la colonne pour identifier l’élement a modifier (des checks sont inclus également afin de vérifier la validité des coordonnées données, et qu’elles n’excedent pas la taille du tableau). 
Ensuite, on tape la nouvelle valeur à insérer dans la cellule (le getline permet de taper un input avec des espaces). Ensuite, on modifie la valeur et on affiche l’emploi du temps modifié.


![image](https://github.com/user-attachments/assets/762bbbec-2e07-4642-94d9-0b6e4327e8a7)


La fonction ModificateurEDT est l’une des seules fonctions exclusives a un seul utilisateur : le cpe.
Elle permet de modifier l’emploi du temps des élèves ou du professeurs et ce en faisant appel a la fonction définie précedement(d’où son importance).


![image](https://github.com/user-attachments/assets/38e07974-50c7-4d88-be74-859c5a80dc25)


![image](https://github.com/user-attachments/assets/da0b65f8-e6d8-4fb2-8750-ef031fadf74e)

La fonction edtAbsRet (edit Absence Retard) est la deuxieme fonction exclusive à un utilisateur (cpe aussi). Elle permet de modifier les absences et retard des élèves et professeurs.
Dans cette fonction, on commence par afficher les options (voir retards/absences ou modifier retard/absence.
Cela se fait en trouvant l’utilisateur concerné par son ID (trouverDestParID) puis l’affichage des absences et retard en fonction de l’utilisateur (élève ou professeur).
La deuxieme option modifie en accedant au valeurs par la clé du dictionnaires des absences et retard.


![image](https://github.com/user-attachments/assets/82f08737-c740-4f81-b6b0-d79029e066dd)

La fonction ci-dessus suit le même principe que les fonctions InputEleve ou InputParent.

![image](https://github.com/user-attachments/assets/8ff913d6-a608-440e-be40-2cb0e7e4153a)

menuCpe suit le même principe que menuEleve ou bien menuParent.


![image](https://github.com/user-attachments/assets/412ff7e4-0ccf-437d-90d7-27c139297c07)

La fonction Accueil est la fonction qui centralise toutes les fonctions précedentes.
Il s’agit de la page d’accueil avec les diverses options (espace parent, eleve etc).
La fonction credentialsCheck est appelé ici pour vérifier les données entrées par l’utilisateur (id et mot de passe).
Ensuite, si la personne est connectée avec succès, on change l’état (current_state) vers l’espace en cours.


![image](https://github.com/user-attachments/assets/be236994-6c30-4ac6-a793-6634c301891d)

![image](https://github.com/user-attachments/assets/dc8526f6-de3b-4a51-bcc6-f99e6b890e0c)

Pour terminer, la fonction main (« main loop ») qui sera excécutée après le debug du code.
Elle est similaire à la fonction Accueil, mais rajoute le « gestionnaire des espaces ». 
De ce fait, elle permettra d’appeler les fonctions des menus (celle qui contiennent toutes les options des epsaces parents, élèves, professeurs et cpe) et donc d’utiliser l’ERP.



## Développement du système de pointage


![pointage Acces autorisé ](https://github.com/user-attachments/assets/d5af6e9f-197c-48d4-b58a-6b087e05ef72)
#### acces autorisé

![pointage acces refusé](https://github.com/user-attachments/assets/8d42fea5-7bc4-43dc-8048-e517207145b1)
#### acces refusé

![Badge inconnu](https://github.com/user-attachments/assets/7c6411ca-25fb-49b7-8f28-5b56e1eaa320)
#### Badge inconnu


## Améliorations Futures
- Intégration avec des plateformes d'apprentissage en ligne.
- Application mobile pour des mises à jour en temps réel.
- Analyses basées sur l'IA pour des recommandations pédagogiques personnalisées.
- Sécurité renforcée des données grâce au chiffrement.


## Outils Utilisés

Pour mener à bien ce projet, plusieurs outils ont été mobilisés :

- **MySQL Workbench et MySQL Commandline** : pour la gestion et la manipulation des données dans la base de données.
- **InstaGantt** :Pour la visualisation de l'avancement du projet.
- **Notion** : pour l’organisation, le suivi des tâches et l’élaboration du rapport.
- **GitHub** : pour le contrôle de version du code et la collaboration sur le projet.
- **CodeBlocks** : pour l’édition du code C++.
- **Visual Studio Code (VSCode)** : pour le lien entre la base donnée et l'application.
- **StackBlitz** : pour la création de l'aperçu de l'interface utilisateur.
- **mermaid** : pour la création des schémas MCD et UML.

## Crédits

> **Auteurs du rapport technique** : Jean Léandre TIEMTORE, Omar EL GHAZAL, Ingénieurs Logiciel
> 
> 
> CO-responsables de la conception de l'ERP et du système de pointage pour le projet **"EduTrack”**.
> 

---
