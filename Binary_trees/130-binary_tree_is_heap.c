#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - checks if tree is complete
 *
 * @tree: pointer to the tree root
 * @i: node index
 * @cnodes: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * check_parent - checks if parent has a greater value than its childs
 *
 * @tree: pointer to the node
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - checks if an input tree is a Max Binary Heap
 *
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/*
#include "binary_trees.h"

 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

 * is_complete - helper func for binary_tree_is_complete
 * @tree: pointer to root of tree
 * @index: index of current node to be verified
 * @size: total number of nodes in tree
 * Return: 1 if true 0 if false
_Bool is_complete(const binary_tree_t *tree, unsigned int index, size_t size)
{
	if (!tree)
		return (true);

	if (index >= size)
		return (false);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}


 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;
	unsigned int i = 0;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (is_complete(tree, i, size));
}

_Bool is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (true);
	if (!tree->right)
		return (tree->n >= tree->left->n);
	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_heap(tree->left) && is_heap(tree->right));
	else
		return (false);
}


 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_complete(tree) && is_heap(tree));
}
 */
