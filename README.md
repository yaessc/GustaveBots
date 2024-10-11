# Table of Contents / Table des matières
[English Version](#project-title-gustave)
  - [Overview](#overview)
  - [Features](#features)
  - [Getting started](#getting-started)
    - [Connections](#connections)
    - [Installation](#installation)
    - [Use](#use)

[Version française](#titre-du-projet--gustave)
  - [Aperçu](#aperçu)
  - [Fonctionnalités](#fonctionnalités)
  - [Pour Commencer](#pour-commencer)
    - [Branchements](#branchements)
    - [Installation](#installation-1)
    - [Utilisation](#utilisation)

# Project title: Gustave

Robot designed as part of the INF1900 - Initial Embedded Systems Project course at Polytechnique Montréal.
 

## Overview
This project involves the development of two autonomous navigation robots. One is capable of traversing and mapping a predefined area by drawing a line using a line follower, and the other is capable of positioning itself in the center of a box and finding its exit using a distance sensor. The robot is designed for Atmel's Atmega324A microcontroller. The aim of the project is to complete several tasks, including line tracking, route mapping, infrared transmission of information and RS232 transmission of mapping.
## Features
Robot 1:
- **Distance detection**: Uses distance sensors to determine its initial position in the box and to position itself in the center of the box accordingly.

Robot 2:
- **Line tracking** : The robot can follow a predefined path marked by lines of electrical tape on a surface.

Both robots:
- **Map Transmission**: Ability to create and transmit a map of the area traversed to a central system.
- **Autonomous Decision-Making**: Implement algorithms for navigational decision-making.
- **Infrared Transmission/Reception**: Ability to transmit and receive information about the line route taken by the robot 2.



## Getting started


### Connections
Robot 1: Distance sensor on PA0, Piezo on PD6 and PD7, LED on PD4 and PD5, pins E and D of JM2 on H-bridge on PD4 and PD6, pins E and D of JM1 on H-bridge on PD5 and PD7.

Robot 2: Line follower D1 on PA0, D2 on PA1, D3 on PA2, D4 on PA3, D5 on PA4, Piezo on PD6 and PD7, LED on PD4 and PD5, H-bridge pins E and D JM2 on PD4 and PD6, H-bridge pins E and D JM1 on PD5 and PD7.

### Installation
1. **Connect the depot** :
2. **Build library** :
   ```bash
   cd ./projet/lib
   make clean;make
   ```
3. **Install the program on the microcontrollers** (make sure the microcontroller is connected) :
   ```bash
   cd ./projet/app1
   make clean;make;make install;
   cd ./projet/app2
   make clean;make;make install;
   ```


### Use
After successfully installing the programs onto the AVR microcontrollers, power the motherboards with a 9-volt battery and the H-bridges with 6 AA batteries to start up in automatic navigation mode. Place Robot 1 inside the box and Robot 2 on the desired line route.

## Missing Functionalities

Due to time constraints, some features and classes initially planned for the project were not implemented. These include:

- **Infrared Transmission and Reception**
- **Robot 1 initial positionning visualization**

Future versions of this project could address these missing features to enhance the overall system.

# Titre du Projet : Gustave

Robot conçu dans le cadre du cours INF1900 - Projet initial de système embarqué à Polytechnique Montréal.
 

## Aperçu
Ce projet consiste en le développement de deux robots de navigation autonome. L'un capable de traverser et de cartographier une zone prédéfinie par un tracé de ligne à l'aide d'un suiveur de ligne et l'autre capable de se placer au centre d'une boite et d'en trouver la sortie en utilisant un capteur de distance. Le robot est conçu pour le microcontrôleur Atmega324A d'Atmel. L'objectif du projet est de compléter plusieurs tâches, qui incluent le suivi de ligne la cartographie d'un parcours, la transmission infrarouge d'informations et la transmission par RS232 de la cartographie.
## Fonctionnalités
Robot 1:
- **Détection de distance** : Utilise des capteurs de distance pour déterminer sa position initale dans la boite et pour se positionner au centre de celle-ci en conséquence.

Robot 2:
- **Suivi de Ligne** : Le robot peut suivre un chemin prédéfini marqué par des lignes de ruban adhésif électrique sur une surface.

Les deux robots:
- **Transmission de Carte** : Capacité de créer et de transmettre une carte de la zone traversée à un système central.
- **Prise de Décision Autonome** : Implémentent des algorithmes pour la prise de décision dans la navigation.
- **Transmission/Réception infrarouge** : Capacité de transmettre et recevoir des informations par rapport au parcours de ligne effectué par le robot 2.


## Pour Commencer


### Branchements
Robot 1: Capteur de distance sur PA0, Piezo sur PD6 et PD7, DEL sur PD4 et PD5, broches E et D de JM2 du pont H sur PD4 et PD6, broches E et D de JM1 du pont H sur PD5 et PD7.

Robot 2: Suiveur de ligne D1 sur PA0, D2 sur PA1, D3 sur PA2, D4 sur PA3, D5 sur PA4, Piezo sur PD6 et PD7, DEL sur PD4 et PD5, broches E et D de JM2 du pont H sur PD4 et PD6, broches E et D de JM1 du pont H sur PD5 et PD7.

### Installation
1. **Cloner le dépôt** :
2. **Construire la librairie** :
   ```bash
   cd ./projet/lib
   make clean;make
   ```
3. **Installer le programme sur les microcontrôleurs** (assurez-vous que le microcontrôleur est connecté) :
   ```bash
   cd ./projet/app1
   make clean;make;make install;
   cd ./projet/app2
   make clean;make;make install;
   ```


### Utilisation
Après avoir réussi à installer les programmes sur les microcontrôleurs AVR, alimentez les cartes mères avec une pile 9 volts et les ponts-H avec 6 piles AA pour démarrer en mode de navigation automatique. Placer le robot 1 à l'intérieur de la boite et le robot 2 sur le parcours de ligne voulu.

## Fonctionnalités manquantes

En raison de contraintes de temps, certaines fonctionnalités et classes initialement prévues pour le projet n'ont pas été mises en œuvre. Il s'agit notamment des éléments suivants

- **Transmission et réception infrarouge** Visualisation du positionnement initial du robot
- **Visualisation du positionnement initial du robot 1**.

Les versions futures de ce projet pourraient intégrer ces fonctionnalités manquantes afin d'améliorer le système dans son ensemble.


