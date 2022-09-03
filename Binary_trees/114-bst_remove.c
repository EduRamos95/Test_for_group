#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to root of tree
 * @value: input value
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);
		tree = value < tree->n ? tree->left
			: tree->right;
	}
	return ((bst_t *)tree);
}

/**
 * swap - swaps two nodes in binary tree
 * @node: first node
 * @new: second node
 * Return: pointer to root
 */
bst_t *swap(bst_t *node, bst_t *new)
{
	bst_t *temp = NULL;
	_Bool left_child = false;

	if (node->parent)
		left_child = node->parent->left == node;
	if (new->parent && new->parent != node)
		new->parent->left = NULL;
	new->parent = node->parent;
	if (node->parent)
	{
		if (left_child)
			node->parent->left = new;
		else
			node->parent->right = new;
	}
	if (node->left != new)
	{
		new->left = node->left;
		node->left->parent = new;
	}
	if (node->right && node->right != new)
	{
		new->right = node->right;
		node->right->parent = new;
	}
	temp = new;
	while (temp->parent)
		temp = temp->parent;
	free(node);
	return (temp);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to root of tree
 * @value: input value
 * Return: pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *temp;
	_Bool left_child = false;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
	if (!node)
		return (NULL);
	if (node->parent)
		left_child = node->parent->left == node;
	if (!node->right && !node->left)
	{
		if (!node->parent)
		{
			free(node);
			return (NULL);
		}
		if (left_child)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		temp = node->parent;
		while (temp->parent)
			temp = temp->parent;
		free(node);
		return (temp);

	}
	if (!node->right)
		return (swap(node, node->left));
	temp = node->right;
	while (temp->left)
		temp = temp->left;
	return (swap(node, temp));
}

/*

   #include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	* No children or right-child only *
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	* Left-child only *
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	* Two children *
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

 */
