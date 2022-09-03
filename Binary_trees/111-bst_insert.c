#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created node must
 * become the root node. If the value is already present in the tree, it must
 * be ignored
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = (bst_t *)binary_tree_node(NULL, value);
			return (*tree);
		}
		tmp = *tree;
		while (tmp)
		{
			if (tmp->n == value)
				break;
			if (tmp->n > value)
			{
				if (!tmp->left)
				{
					tmp->left = (bst_t *)binary_tree_node(tmp, value);
					return (tmp->left);
				}
				tmp = tmp->left;
			}
			else if (tmp->n < value)
			{
				if (!tmp->right)
				{
					tmp->right = (bst_t *)binary_tree_node(tmp, value);
					return (tmp->right);
				}
				tmp = tmp->right;
			}
		}
	}
	return (NULL);
}

/*
#include "binary_trees.h"

 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n) * insert in left subtree * 
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		if (value > curr->n) * insert in right subtree *
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
 */

/*
#include "binary_trees.h"

 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *bt = NULL, *node;

	if (!tree)
		return (NULL);
	bt = calloc(1, sizeof(bst_t));
	if (!bt)
		return (NULL);
	bt->n = value;

	if (!*tree)
	{
		*tree = bt;
		return (bt);
	}
	node = *tree;
	while (true)
	{
		if (value == node->n)
		{
			free(bt);
			return (NULL);
		}
		if (value < node->n)
		{
			if (!node->left)
			{
				bt->parent = node;
				return (node->left = bt);
			}
			node = node->left;
		} else
		{
			if (!node->right)
			{
				bt->parent = node;
				return (node->right = bt);
			}
			node = node->right;
		}
	}
}
 */
