#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 1 if palindrome, 0 if not (empty list returns 1)
 *
 * Methode :
 * 1. Compter la longueur de la liste
 * 2. Copier les valeurs dans un tableau
 * 3. Comparer le debut et la fin du tableau symetriquement
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int *arr;
	size_t len, i;

	/* Liste vide = palindrome par definition */
	if (*head == NULL)
		return (1);

	/* Etape 1 : compter le nombre de noeuds */
	len = 0;
	current = *head;
	while (current)
	{
		len++;
		current = current->next;
	}

	/* Etape 2 : copier les valeurs dans un tableau */
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);

	current = *head;
	for (i = 0; i < len; i++)
	{
		arr[i] = current->n;  /* Stocker la valeur du noeud */
		current = current->next;
	}

	/* Etape 3 : comparer debut et fin en se rapprochant du centre */
	for (i = 0; i < len / 2; i++)
	{
		if (arr[i] != arr[len - 1 - i])  /* Asymetrie detectee */
		{
			free(arr);
			return (0);
		}
	}

	free(arr);
	return (1);
}
