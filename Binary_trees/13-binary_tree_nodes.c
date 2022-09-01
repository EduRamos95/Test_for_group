#include "binary_trees.h"
/**
 * binary_tree_nodes - func that counts the nodes with at least 1 child
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 0 if NULL or number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	size += binary_tree_nodes(tree->left);
	size += binary_tree_nodes(tree->right);
	return (size + 1);
}
