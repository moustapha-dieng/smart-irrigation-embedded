# Fonctionnement détaillé

Ce document décrit le comportement du prototype sans supposer de fonctionnalités qui ne sont pas implémentées dans le code.

## Lecture de l'humidité

Le capteur d'humidité est connecté à l'entrée analogique `A0`. La fonction `sensor_read()` retourne directement la valeur lue par `analogRead()`.

La valeur dépend du capteur, du sol, de l'alimentation et des conditions de test. Le projet utilise donc un seuil fixe comme base de fonctionnement, mais ce seuil doit être adapté au montage réel.

## Décision d'arrosage

La logique de décision se trouve dans `main.ino`.

```text
si humidité_mesurée > seuil
    allumer la LED
    démarrer la pompe
sinon
    éteindre la LED
    arrêter la pompe
```

Dans ce projet, une valeur analogique plus élevée est interprétée comme un sol plus sec. Cette interprétation correspond au comportement attendu du montage actuel, mais elle doit être vérifiée lors des essais avec le capteur utilisé.

## Commande de la pompe

La pompe n'est pas commandée directement par une broche Arduino. La broche `D7` commande un module relais, qui commute l'alimentation de la pompe.

Le code considère que le relais est actif à l'état bas :

- `LOW` : relais activé, pompe en marche ;
- `HIGH` : relais désactivé, pompe arrêtée.

Cette convention est isolée dans `actuator.cpp`, ce qui évite de mélanger le détail électrique du relais avec la logique principale.

## Observation pendant les tests

Le programme affiche la valeur du capteur dans le moniteur série à `9600` bauds. Cela permet de choisir un seuil cohérent en comparant les valeurs obtenues dans différentes conditions de sol.

Pour rester rigoureux, les résultats chiffrés et les performances d'arrosage ne sont pas annoncés dans ce dépôt tant qu'ils n'ont pas été mesurés et documentés.

## Points à surveiller

- Vérifier que l'alimentation de la pompe est adaptée.
- Éviter d'alimenter la pompe directement depuis la carte Arduino.
- Confirmer la logique du relais avant de brancher la pompe.
- Ajuster le seuil selon le capteur et le sol.
- Ajouter une sécurité temporelle si le prototype est utilisé hors surveillance.
