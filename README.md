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

#### Accueil

-------
#### Espace élève

------
#### Espace Parent

------
#### Espace professeur

--------
#### Espace CPE

--------

#### Espace comptable

![Paiement récents](https://github.com/user-attachments/assets/2f156d31-dc16-4d76-a7d7-6027e08ec6cc)
##### Paiements récents

![Bilan Financier](https://github.com/user-attachments/assets/3f1ea94d-033c-4745-9f42-d79d402f22b7)
##### Bilan Financier


## Développement du système de pointage


![pointage Acces autorisé ](https://github.com/user-attachments/assets/d5af6e9f-197c-48d4-b58a-6b087e05ef72)
#### acces autorisé

![pointage acces refusé](https://github.com/user-attachments/assets/8d42fea5-7bc4-43dc-8048-e517207145b1)
#### acces refusé

![pointage code incorrect](https://github.com/user-attachments/assets/a5a5d874-b1e2-414b-8aa8-be49a1d05bbf)
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
