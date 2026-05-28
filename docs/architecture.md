# Architecture technique

Le projet est organisé autour d'une architecture simple adaptée à un prototype Arduino. L'objectif est de garder un code lisible et facile à présenter, sans ajouter de couches inutiles.

## Vue d'ensemble

```text
Capteur d'humidité  ->  Arduino  ->  Relais  ->  Pompe
                           |
                           +-----> LED de statut
```

Le capteur est lu par l'Arduino. La logique principale compare la valeur mesurée à un seuil. Selon le résultat, l'Arduino active ou désactive la LED et le relais qui commande la pompe.

## Répartition des fichiers

| Fichier | Rôle |
| --- | --- |
| `src/main/main.ino` | Point d'entrée du programme Arduino |
| `src/main/sensor.h` | Interface du module capteur |
| `src/main/sensor.cpp` | Lecture analogique du capteur d'humidité |
| `src/main/actuator.h` | Interface des actionneurs |
| `src/main/actuator.cpp` | Commande de la LED et du relais |

## Broches utilisées

| Signal | Broche | Description |
| --- | --- | --- |
| `SENSOR_PIN` | `A0` | Entrée analogique du capteur d'humidité |
| `RELAY_PIN` | `D7` | Sortie de commande du module relais |
| `LED_PIN` | `D13` | LED de statut |

## Choix de conception

Le code sépare la lecture capteur et la commande des actionneurs afin de rendre le programme plus clair :

- `sensor_read()` masque le détail de `analogRead(A0)`.
- `pump_on()` et `pump_off()` masquent le comportement du relais.
- `main.ino` reste centré sur la logique de décision.

Le relais du montage est considéré comme actif à l'état bas dans le code : `LOW` active la pompe et `HIGH` l'arrête. Ce choix doit être vérifié avec le module relais utilisé, car certains modules fonctionnent en logique inverse.

## Cycle d'exécution

1. Initialisation du port série, du capteur et des actionneurs.
2. Lecture de la valeur analogique du capteur.
3. Affichage de la valeur dans le moniteur série.
4. Comparaison avec le seuil d'humidité.
5. Commande de la LED et de la pompe.
6. Attente d'une seconde avant la lecture suivante.
