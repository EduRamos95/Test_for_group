#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/*
#include "binary_trees.h"
#include <stdio.h>

 * greater_than - check if all values in the tree are greater than a value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
int greater_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		l = greater_than(tree->left, val);
		r = greater_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

 * less_than - check if all values in the tree are less than a specific value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
int less_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		l = less_than(tree->left, val);
		r = less_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_than(tree->left, tree->n) && greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}

	}
	return (0);
}
 */
