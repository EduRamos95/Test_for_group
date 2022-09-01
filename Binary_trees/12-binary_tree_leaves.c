#include "binary_trees.h"

/**
 * binary_tree_leaves - leaves
 * @tree: pointer to the root
 * Return: num of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_leaves = 0;

	if (tree == NULL)
		return (0);

	if ((tree->right == NULL) && (tree->left == NULL))
		count_leaves += 1;

	count_leaves += binary_tree_leaves(tree->right);
	count_leaves += binary_tree_leaves(tree->left);

	return (count_leaves);
}
