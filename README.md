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

#### Diagramme de Séquence
Un exemple de scénario pour le module de présence :
1. L'étudiant scanne son badge.
2. Le système vérifie les informations et enregistre la présence.
3. Un enseignant peut consulter ces données via l'interface.

#### Diagramme de Classes
Le diagramme de classes détaille les différentes classes implémentées dans le projet, telles que :
- **Classe Étudiant :** Avec attributs (nom, matricule, etc.) et méthodes (inscrire, consulter résultats).
- **Classe Cours :** Avec attributs (intitulé, code) et méthodes (assigner enseignant, générer rapport).

Ces diagrammes permettent de visualiser clairement la structure et les interactions du système, facilitant ainsi le développement et la maintenance.

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

> **Auteur du rapport technique** : Jean Léandre TIEMTORE, Ingénieur de données
> 
> 
> Responsable de la conception du système de pointage pour le projet **"EduTrack”**.
> 

---
