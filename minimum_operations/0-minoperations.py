#!/usr/bin/python3
"""
Minimum Operations
Calcule le nombre minimal d'opérations (Copy All + Paste) pour
obtenir exactement n caractères H dans un fichier.
"""


def minOperations(n):
    """
    Retourne le nombre minimum d'opérations pour atteindre n caractères H.

    Astuce clé : la réponse est la somme des facteurs premiers de n.
    Exemple : n=12 => 12 = 2 * 2 * 3 => 2 + 2 + 3 = 7 opérations

    Pourquoi ? Chaque fois qu'on fait un "Copy All" puis p-1 "Paste",
    on multiplie le nombre de H par p. Ça coûte exactement p opérations.
    Donc trouver la meilleure séquence revient à factoriser n en facteurs premiers.
    """
    if n <= 1:
        # Impossible d'avoir 0 ou 1 H (on commence déjà avec 1 H)
        return 0

    operations = 0  # Compteur total d'opérations
    divisor = 2     # On commence à tester le plus petit facteur premier

    while n > 1:
        # Tant que n est divisible par le diviseur courant,
        # on "consomme" ce facteur et on ajoute son coût
        while n % divisor == 0:
            operations += divisor  # Ce facteur coûte "divisor" opérations
            n //= divisor          # On divise n par ce facteur
        divisor += 1  # On passe au facteur suivant

    return operations
