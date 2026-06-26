#include "lists.h"

/**
 * check - recursive helper that compares nodes from outside in
 * @left: pointer to the current left node (advances as recursion unwinds)
 * @right: current right node (goes deeper at each recursive call)
 * Return: 1 if palindrome so far, 0 otherwise
 *
 * Principe :
 * - On descend recursivement jusqu'a la fin de la liste (right -> NULL)
 * - En remontant, on compare right (qui revient de la fin) avec *left
 *   (qui part du debut et avance a chaque retour de recursion)
 * - Aucune allocation memoire supplementaire : on utilise la pile d'appels
 */
static int check(listint_t **left, listint_t *right)
{
	/* Cas de base : on a atteint la fin de la liste */
	if (right == NULL)
		return (1);

	/* Descendre recursivement vers la fin */
	if (!check(left, right->next))
		return (0);

	/* En remontant : comparer gauche et droite */
	if ((*left)->n != right->n)
		return (0);

	/* Avancer le pointeur gauche vers le centre */
	*left = (*left)->next;
	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 1 if palindrome, 0 if not (empty list returns 1)
 */
int is_palindrome(listint_t **head)
{
	listint_t *left;

	/* Liste vide = palindrome */
	if (*head == NULL)
		return (1);

	/* left est une copie locale pour ne pas modifier *head chez l'appelant */
	left = *head;
	return (check(&left, *head));
}
