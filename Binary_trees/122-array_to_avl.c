#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: input array
 * @size: size of the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	avl_t *root = NULL;

	if (!array)
		return (NULL);
	while (i < size)
	{
		avl_insert(&root, array[i]);
		i++;
	}
	return (root);
}

/*
#include "binary_trees.h"

 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
 */
