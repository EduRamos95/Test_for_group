#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}

/*
   corregir codigo ...falla (se modifica el nodo root cuando inserta un nuevo nodo).
#include "binary_trees.h"

 * balance_left - balances left side
 * @node: pointer to temp node
 * Return: root of tree
avl_t *balance_left(avl_t *node)
{
	avl_t *z, *x, *y, *ret;

	z = node;
	y = z->left;
	if (!y)
		return (NULL);
	x = binary_tree_balance(y) < 0 ? y->right : y->left;
	if (!x)
		return (NULL);
	if (x == y->left)
	{
		ret = binary_tree_rotate_right(z);
		return (ret);
	}
	binary_tree_rotate_left(y);
	ret = binary_tree_rotate_right(z);
	return (ret);
}

 * rebalance - rebalance AVL tree
 * @node: pointer to node to rebalance
 * @tree: double pointer to root of tree
 * Return: pointer to input node
avl_t *rebalance(avl_t *node, avl_t **tree)
{
	avl_t *tmp, *root, *z, *x, *y, *ret = NULL;
	int bal;

	tmp = node;
	while (tmp)
	{
		bal = binary_tree_balance(tmp);
		if (bal > 1)
		{
			root = balance_left(tmp);
			if (root)
				*tree = root;
		}
		else if (bal < -1)
		{
			z = tmp;
			y = z->right;
			if (y)
			{
				x = binary_tree_balance(y) < 0 ? y->right : y->left;
				if (x)
				{
					if (x == y->right)
					{
						ret = binary_tree_rotate_left(z);
					} else
					{
						binary_tree_rotate_right(y);
						ret = binary_tree_rotate_left(z);
					}
				}
			}
			if (ret)
				*tree = ret;
		}
		tmp = tmp->parent;
	}
	return (node);
}

 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *av, *node;

	if (!tree)
		return (NULL);
	av = calloc(1, sizeof(avl_t));
	if (!av)
		return (NULL);
	av->n = value;
	if (!*tree)
	{
		return (*tree = av);
	}
	node = *tree;
	while (node)
	{
		if (value == node->n)
			return (free(av), NULL);
		if (value < node->n)
		{
			if (!node->left)
			{
				av->parent = node;
				node->left = av;
				return (rebalance(node->left, tree));
			}
			node = node->left;
		} else
		{
			if (!node->right)
			{
				av->parent = node;
				node->right = av;
				return (rebalance(node->right, tree));
			}
			node = node->right;
		}
	}
	return (free(av), NULL);
}
 */
