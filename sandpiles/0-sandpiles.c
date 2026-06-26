#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	/* Parcours chaque ligne */
	for (i = 0; i < 3; i++)
	{
		/* Parcours chaque colonne de la ligne */
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" "); /* Espace entre les valeurs */
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if a grid is stable (no cell > 3)
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 *
 * Un sandpile est stable quand aucune cellule ne depasse 3 grains.
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3) /* Cellule instable trouvee */
				return (0);
	return (1); /* Toutes les cellules sont <= 3 */
}

/**
 * topple - Perform one simultaneous toppling round on grid
 * @grid: 3x3 grid
 *
 * Principe : chaque cellule > 3 perd 4 grains et en donne 1
 * a chacun de ses voisins (haut, bas, gauche, droite).
 * On utilise une copie temporaire (temp) pour que toutes les
 * cellules toppent en meme temps (simultanement), et non une
 * par une — sinon les premiers topplings fausseraient les suivants.
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3]; /* Copie pour calcul simultane */

	/* Copier l'etat actuel dans temp */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3) /* Cette cellule doit toppler */
			{
				temp[i][j] -= 4;      /* Perd 4 grains */
				if (i > 0)            /* Voisin du haut existe ? */
					temp[i - 1][j]++;
				if (i < 2)            /* Voisin du bas existe ? */
					temp[i + 1][j]++;
				if (j > 0)            /* Voisin de gauche existe ? */
					temp[i][j - 1]++;
				if (j < 2)            /* Voisin de droite existe ? */
					temp[i][j + 1]++;
			}
		}
	}

	/* Copier le resultat de temp dans grid */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = temp[i][j];
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 sandpile (modified in place, must be stable on return)
 * @grid2: Second 3x3 sandpile
 *
 * Etapes :
 * 1. Additionner grid2 dans grid1 cellule par cellule.
 * 2. Tant que grid1 est instable :
 *    - Afficher grid1 (etat avant le toppling)
 *    - Faire un tour de toppling simultane
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Etape 1 : addition des deux grilles */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Etape 2 : stabilisation par toppling */
	while (!is_stable(grid1))
	{
		printf("=\n");        /* Separateur avant chaque affichage */
		print_grid(grid1);   /* Afficher l'etat instable */
		topple(grid1);       /* Faire un tour de toppling */
	}
}
