-- MySQL dump 10.13  Distrib 8.0.38, for Win64 (x86_64)
--
-- Host: localhost    Database: erp_sama
-- ------------------------------------------------------
-- Server version	8.0.39

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `parents`
--

DROP TABLE IF EXISTS `parents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `parents` (
  `Id_parent` varchar(15) NOT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `lien_parente` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`Id_parent`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `parents`
--

LOCK TABLES `parents` WRITE;
/*!40000 ALTER TABLE `parents` DISABLE KEYS */;
INSERT INTO `parents` VALUES ('A11Dupont','Alain','Dupont',40,'Père de Alice et Marine Dupont'),('A16Ndiaye','Aissatou','Ndiaye',41,'Mère de Astou Ndiaye'),('B1Sow','Binta','Sow',45,'Mère de Fatou Sow'),('C6Moreau','Caroline','Moreau',42,'Mère de Emma et Manon Moreau'),('F0Diallo','Fatou','Diallo',42,'Mère de Moussa Diallo'),('J4Chevalier','Jean','Chevalier',43,'Père de Thomas et Jade Chevalier'),('M12Seck','Marième','Seck',39,' mère de Aïda Seck'),('O2Faye','Ousmane','Faye',47,'père de Adja Faye'),('S2Mercier','Sylvie','Mercier',38,'Mère de Julien et Guillaume Mercier'),('T5Diallo','Thierno','Diallo',44,'Père de Aby, Fatima et Khady Diallo');
/*!40000 ALTER TABLE `parents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `professeurs`
--

DROP TABLE IF EXISTS `professeurs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `professeurs` (
  `id_prof` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `profession` varchar(50) NOT NULL,
  PRIMARY KEY (`id_prof`),
  CONSTRAINT `check_matiere` CHECK ((`profession` in (_utf8mb4'Mathématiques',_utf8mb4'Français',_utf8mb4'Histoire-Géographie',_utf8mb4'Anglais',_utf8mb4'CPE')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `professeurs`
--

LOCK TABLES `professeurs` WRITE;
/*!40000 ALTER TABLE `professeurs` DISABLE KEYS */;
INSERT INTO `professeurs` VALUES ('A7NDIAYE','Aminata','NDIAYE','Histoire-Géographie'),('F8SECK','Fatou','SECK','CPE'),('M5DIOP','Mamadou','DIOP','Mathématiques'),('P2MARTIN','Pierre','MARTIN','Anglais'),('S3DUBOIS','Sophie','DUBOIS','Français');
/*!40000 ALTER TABLE `professeurs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `seconde_a`
--

DROP TABLE IF EXISTS `seconde_a`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `seconde_a` (
  `Id_eleve` varchar(10) NOT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `sexe` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`Id_eleve`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `seconde_a`
--

LOCK TABLES `seconde_a` WRITE;
/*!40000 ALTER TABLE `seconde_a` DISABLE KEYS */;
INSERT INTO `seconde_a` VALUES ('A0Ndiaye','Adama','Ndiaye',16,'Homme'),('A1Gueye','Aïssatou','Gueye',15,'Femme'),('A2Faye','Amadou','Faye',15,'Homme'),('A2Sy','Astou','Sy',15,'Femme'),('A3Diouf','Abdoulaye','Diouf',16,'Homme'),('A3Sall','Arame','Sall',15,'Femme'),('A4Barry','Awa','Barry',15,'Femme'),('A4Niang','Alioune','Niang',16,'Homme'),('A5Diop','Abdou','Diop',16,'Homme'),('B0Ndoye','Bineta','Ndoye',16,'Femme'),('B1Camara','Bamba','Camara',16,'Homme'),('C0Diarra','Cheikh','Diarra',16,'Homme'),('D0Ly','Daouda','Ly',16,'Homme'),('F0Sow','Fatou','Sow',16,'Femme'),('F1Ndao','Fatima','Ndao',15,'Femme'),('I0Touré','Ibrahima','Touré',16,'Homme'),('K0Diop','Khady','Diop',15,'Femme'),('K1Fofana','Khadija','Fofana',15,'Femme'),('M0Diallo','Moussa','Diallo',15,'Homme'),('M1Cissé','Mariama','Cissé',15,'Femme'),('M1Seck','Mamadou','Seck',16,'Homme'),('M2Diagne','Modou','Diagne',16,'Homme'),('M2Gueye','Mariétou','Gueye',15,'Femme'),('M3Faye','Mame Diarra','Faye',15,'Femme'),('M3Ndiaye','Mactar','Ndiaye',16,'Homme'),('M4Bâ','Mamour','Bâ',16,'Homme'),('N0Thiam','Ndeye','Thiam',15,'Femme'),('O0Mbaye','Ousmane','Mbaye',16,'Homme'),('R0Ndiaye','Rokhaya','Ndiaye',15,'Femme'),('S0Diouf','Seynabou','Diouf',15,'Femme'),('S1Guèye','Souleymane','Guèye',16,'Homme');
/*!40000 ALTER TABLE `seconde_a` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `seconde_b`
--

DROP TABLE IF EXISTS `seconde_b`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `seconde_b` (
  `Id_eleve` varchar(10) NOT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `sexe` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`Id_eleve`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `seconde_b`
--

LOCK TABLES `seconde_b` WRITE;
/*!40000 ALTER TABLE `seconde_b` DISABLE KEYS */;
INSERT INTO `seconde_b` VALUES ('A0Dupont','Alice','Dupont',16,'Femme'),('A1Fourn','Arthur','Fournier',16,'Homme'),('A2Bouvier','Anaïs','Bouvier',15,'Femme'),('A3Dumont','Adrien','Dumont',17,'Homme'),('A4Dufour','Anaïs','Dufour',15,'Femme'),('C0Fournier','Camille','Fournier',15,'Femme'),('C1Olivier','Chloé','Olivier',15,'Femme'),('C1Renault','Clément','Renault',16,'Homme'),('E0Moreau','Emma','Moreau',15,'Femme'),('G0Mercier','Guillaume','Mercier',17,'Homme'),('H0Lefevre','Hugo','Lefevre',16,'Homme'),('J0Mercier','Julien','Mercier',17,'Homme'),('J1Lefebvre','Jade','Lefebvre',15,'Femme'),('L0Blanc','Lucie','Blanc',15,'Femme'),('L1Fontai','Léa','Fontaine',15,'Femme'),('L2Faure','Léo','Faure',16,'Homme'),('L3Guerin','Lucas','Guerin',16,'Homme'),('M0Leroy','Marine','Leroy',15,'Femme'),('M1Dubois','Maxime','Dubois',16,'Homme'),('M1Girard','Manon','Girard',15,'Femme'),('M2Lacroi','Mathis','Lacroix',16,'Homme'),('M3Gaillard','Mathieu','Gaillard',16,'Homme'),('N0Meunier','Noémie','Meunier',15,'Femme'),('P0Roux','Pauline','Roux',15,'Femme'),('Q0Morel','Quentin','Morel',16,'Homme'),('S0Blanch','Sophie','Blanchard',17,'Femme'),('S1Bertrand','Salomé','Bertrand',15,'Femme'),('T0Cheval','Thomas','Chevalier',16,'Homme'),('T1Masson','Théo','Masson',17,'Homme');
/*!40000 ALTER TABLE `seconde_b` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sixieme_a`
--

DROP TABLE IF EXISTS `sixieme_a`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sixieme_a` (
  `Id_eleve` varchar(10) NOT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `sexe` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`Id_eleve`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sixieme_a`
--

LOCK TABLES `sixieme_a` WRITE;
/*!40000 ALTER TABLE `sixieme_a` DISABLE KEYS */;
INSERT INTO `sixieme_a` VALUES ('A0Ba','Aliou','Ba',12,'Homme'),('A10Ndiaye','Anta','Ndiaye',11,'Femme'),('A11Diop','Amadou','Diop',12,'Homme'),('A12Ndiaye','Amath','Ndiaye',13,'Homme'),('A13Diop','Alassane','Diop',12,'Homme'),('A14Faye','Adja','Faye',11,'Femme'),('A15Diop','Awa','Diop',11,'Femme'),('A5Ba','Aïssatou','Ba',12,'Femme'),('A6Ndiaye','Astou','Ndiaye',11,'Femme'),('A7Camara','Awa','Camara',12,'Femme'),('A8Diallo','Aby','Diallo',11,'Femme'),('A9Seck','Aïda','Seck',11,'Femme'),('B2Mbaye','Baye','Mbaye',13,'Homme'),('B3Gueye','Bineta','Gueye',11,'Femme'),('B4Diouf','Babacar','Diouf',12,'Homme'),('C2Diagne','Cheikh','Diagne',12,'Homme'),('C3Diatta','Coumba','Diatta',11,'Femme'),('F2Sall','Fatimata','Sall',13,'Femme'),('F3Diouf','Fatou','Diouf',11,'Femme'),('F4Diallo','Fatimat','Diallo',13,'Femme'),('I1Diop','Ibou','Diop',12,'Homme'),('I2Lo','Ibrahima','Lo',12,'Homme'),('K0Diop','Khadim','Diop',12,'Homme'),('K4Diallo','Khady','Diallo',11,'Femme'),('M10Bâ','Mame Fatou','Ba',12,'Femme'),('M4Niang','Marième','Niang',13,'Femme'),('M5Faye','Mamadou','Faye',12,'Homme'),('M6Sy','Moustapha','Sy',12,'Homme'),('M7Mbaye','Mouhamadou','Mbaye',12,'Homme'),('M8Sall','Malick','Sall',12,'Homme'),('M9Gueye','Maimouna','Gueye',11,'Femme'),('N0Diouf','Ndèye','Diouf',11,'Femme'),('N1Seck','Ndeye','Seck',12,'Femme'),('O1Touré','Ousmane','Touré',12,'Homme'),('P0Gueye','Pape','Gueye',12,'Homme'),('S0Ndiaye','Samba','Ndiaye',12,'Homme'),('S2Dieng','Sokhna','Dieng',12,'Femme'),('S3Diallo','Souleymane','Diallo',12,'Homme'),('S4Ndiaye','Seydina','Ndiaye',13,'Homme');
/*!40000 ALTER TABLE `sixieme_a` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sixieme_b`
--

DROP TABLE IF EXISTS `sixieme_b`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sixieme_b` (
  `Id_eleve` varchar(10) NOT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `sexe` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`Id_eleve`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sixieme_b`
--

LOCK TABLES `sixieme_b` WRITE;
/*!40000 ALTER TABLE `sixieme_b` DISABLE KEYS */;
INSERT INTO `sixieme_b` VALUES ('A10Boucher','Anaïs','Boucher',11,'Femme'),('A6Leroy','Anaïs','Leroy',11,'Femme'),('A7Meunier','Arthur','Meunier',12,'Homme'),('A8Fournier','Adrien','Fournier',12,'Homme'),('A9Vallée','Anaïs','Vallée',11,'Femme'),('C2Dumont','Chloé','Dumont',11,'Femme'),('C3Faure','Clément','Faure',13,'Homme'),('C4Dufour','Camille','Dufour',11,'Femme'),('C5Marchand','Chloé','Marchand',11,'Femme'),('E1Fontaine','Emma','Fontaine',12,'Femme'),('E2Bertrand','Emma','Bertrand',11,'Femme'),('G1Guérin','Guillaume','Guérin',13,'Homme'),('H1Guérin','Hugo','Guérin',12,'Homme'),('J2Cheval','Jade','Chevalier',11,'Femme'),('J3Leblanc','Julien','Leblanc',12,'Homme'),('J4Bigot','Jade','Bigot',11,'Femme'),('L3Gaillard','Léa','Gaillard',11,'Femme'),('L4Lacroix','Lucas','Lacroix',13,'Homme'),('L5Bouvier','Lucie','Bouvier',11,'Femme'),('L6Masson','Léo','Masson',12,'Homme'),('L7Poulain','Léa','Poulain',11,'Femme'),('L8Mercier','Lucas','Mercier',12,'Homme'),('M11Legrand','Mathieu','Legrand',12,'Homme'),('M1Gosselin','Manon','Gosselin',11,'Femme'),('M4Girard','Mathis','Girard',13,'Homme'),('M5Moreau','Manon','Moreau',11,'Femme'),('M6Morel','Mathieu','Morel',12,'Homme'),('M7Dupont','Marine','Dupont',11,'Femme'),('M8Morel','Maxime','Morel',12,'Homme'),('M9Dupuis','Mathis','Dupuis',13,'Homme'),('N2Lefebvre','Noémie','Lefebvre',11,'Femme'),('P1Roux','Pauline','Roux',11,'Femme'),('Q1Mercier','Quentin','Mercier',12,'Homme'),('Q2Berger','Quentin','Berger',12,'Homme'),('S5Blanc','Salomé','Blanc',11,'Femme'),('T2Roussel','Thomas','Roussel',12,'Homme'),('T3Olivier','Théo','Olivier',12,'Homme'),('T4Guérard','Théo','Guérard',13,'Homme');
/*!40000 ALTER TABLE `sixieme_b` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-11-22  8:22:37
