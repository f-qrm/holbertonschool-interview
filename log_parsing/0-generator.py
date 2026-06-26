#!/usr/bin/python3
"""Generator script that simulates HTTP log entries written to stdout."""
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    # Delai aleatoire entre 0 et 1 seconde pour simuler du trafic reel
    sleep(random.random())

    # Ecrire une ligne de log au format attendu par 0-stats.py
    sys.stdout.write(
        "{:d}.{:d}.{:d}.{:d} - [{}] "
        "\"GET /projects/260 HTTP/1.1\" {} {}\n".format(
            random.randint(1, 255),   # Adresse IP aleatoire
            random.randint(1, 255),
            random.randint(1, 255),
            random.randint(1, 255),
            datetime.datetime.now(),  # Date et heure actuelles
            random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
            random.randint(1, 1024)   # Taille du fichier en octets
        )
    )

    # Forcer l'ecriture immediate dans stdout (pas de buffering)
    sys.stdout.flush()
