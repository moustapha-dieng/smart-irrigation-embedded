# Smart Irrigation Embedded System

Projet embarqué Arduino pour automatiser l'arrosage d'une plante à partir de la mesure d'humidité du sol.

L'objectif est de réaliser un prototype simple et compréhensible : un capteur d'humidité fournit une valeur analogique, l'Arduino compare cette valeur à un seuil, puis commande une pompe via un relais lorsque le sol est considéré trop sec.

Ce projet est volontairement gardé à un niveau réaliste pour un projet étudiant en systèmes embarqués, électronique et automatique. Il met l'accent sur le câblage, la lecture de capteur, la commande d'un actionneur et une organisation de code lisible.

## Objectifs

- Lire une valeur d'humidité du sol avec un capteur analogique.
- Commander automatiquement une pompe à eau via un module relais.
- Afficher l'état d'arrosage avec une LED.
- Séparer le code en modules simples : capteur, actionneurs et logique principale.
- Documenter le fonctionnement pour pouvoir présenter le projet en entretien.

## Matériel utilisé

- Arduino Uno ou carte compatible
- Capteur d'humidité du sol analogique
- Module relais
- Pompe à eau DC
- Alimentation externe pour la pompe
- LED de statut, résistance et breadboard
- Fils de connexion et tuyau pour l'eau

Brochage utilisé dans le code :

| Élément | Broche Arduino | Rôle |
| --- | --- | --- |
| Capteur d'humidité | `A0` | Lecture analogique |
| Relais | `D7` | Commande de la pompe |
| LED | `D13` | Indication visuelle |

## Fonctionnement du système

1. Le capteur d'humidité mesure l'état du sol et renvoie une valeur analogique.
2. L'Arduino lit cette valeur sur l'entrée `A0`.
3. La valeur est comparée à un seuil fixe défini dans `main.ino`.
4. Avec le montage actuel, une valeur supérieure au seuil est interprétée comme un sol sec :
   - la LED s'allume ;
   - le relais est activé ;
   - la pompe démarre.
5. Lorsque la valeur repasse sous le seuil :
   - la LED s'éteint ;
   - le relais est désactivé ;
   - la pompe s'arrête.

Le seuil utilisé dans le code est une valeur de départ. Il doit être ajusté selon le capteur, le type de sol et les conditions de test.

## Architecture du projet

```text
smart-irrigation-embedded/
├── README.md
├── docs/
│   ├── architecture.md
│   └── fonctionnement.md
├── media/
│   └── photos/
└── src/
    └── main/
        ├── main.ino
        ├── sensor.h
        ├── sensor.cpp
        ├── actuator.h
        └── actuator.cpp
```

Le code est séparé en trois parties :

- `main.ino` : initialise le système, lit le capteur et applique la logique de commande.
- `sensor.cpp/.h` : isole la lecture du capteur d'humidité.
- `actuator.cpp/.h` : regroupe la commande de la LED et de la pompe.

Des explications plus détaillées sont disponibles dans :

- [Architecture technique](docs/architecture.md)
- [Fonctionnement détaillé](docs/fonctionnement.md)

## Installation et utilisation

1. Cloner le dépôt ou télécharger les fichiers.
2. Ouvrir `src/main/main.ino` avec l'IDE Arduino.
3. Vérifier le câblage du capteur, de la LED, du relais et de la pompe.
4. Sélectionner la carte Arduino et le port série dans l'IDE.
5. Téléverser le programme sur la carte.
6. Ouvrir le moniteur série à `9600` bauds pour observer les valeurs du capteur.
7. Ajuster `HUMIDITY_THRESHOLD` dans `main.ino` si le seuil ne correspond pas au montage réel.

Attention : la pompe doit être alimentée avec une alimentation adaptée. Le relais sert à séparer la partie puissance de la partie commande Arduino.

## Vérification du montage

Pour tester le prototype sans annoncer de performance non mesurée, il est possible de vérifier :

- la variation de la valeur du capteur dans le moniteur série ;
- l'allumage de la LED lorsque le seuil est dépassé ;
- le changement d'état du relais ;
- le démarrage et l'arrêt de la pompe.

## Médias

Les fichiers médias du projet sont placés dans `media/photos/`. Les noms ont été normalisés pour rester lisibles dans le dépôt.

## Limites actuelles

- Le seuil d'humidité est fixe dans le code et n'est pas calibré automatiquement.
- Il n'y a pas encore d'hystérésis : la pompe peut changer d'état rapidement si la mesure oscille autour du seuil.
- La durée d'arrosage n'est pas limitée par une temporisation de sécurité.
- Le montage reste un prototype sur breadboard, sans boîtier ni validation en extérieur.
- Aucune mesure longue durée ni consommation électrique n'est fournie dans le dépôt.

## Améliorations futures

Améliorations réalistes à envisager sans les présenter comme déjà implémentées :

- ajouter une phase de calibration du capteur ;
- ajouter une hystérésis pour éviter les basculements rapides autour du seuil ;
- définir une durée maximale d'activation de la pompe ;
- ajouter un capteur de niveau d'eau pour protéger la pompe ;
- passer sur ESP32 pour ajouter une supervision Wi-Fi ;
- enregistrer des mesures dans le temps pour analyser le comportement du sol ;
- réaliser un montage plus propre sur plaque soudée ou PCB simple ;
- concevoir un boîtier pour un usage plus proche du terrain.

## Auteur

Moustapha Dieng  
Étudiant ingénieur - systèmes embarqués, électronique et automatique
