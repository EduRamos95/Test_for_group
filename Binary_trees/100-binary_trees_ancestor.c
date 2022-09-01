#include "binary_trees.h"
/**
 * compare_node - check if 2 nodes are equal
 *
 * @first: first node to match
 * @second: second node to match
 *
 * Return: address of first if are equal, or NULL on failure
 */
binary_tree_t *compare_node(const binary_tree_t *first,
			const binary_tree_t *second)
{
	binary_tree_t *tmp = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		tmp = (binary_tree_t *)first;
	return (tmp);
}

/**
 * binary_trees_ancestor - get lowest common ancestor of two nodes
 *
 * @first: first node to match
 * @second: second node to match
 *
 * Return: address of lowest common ancestor, or NULL on failure
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *com1_parent = NULL;
	binary_tree_t *com2_parent = NULL;
	binary_tree_t *tmp_common_parent = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	com1_parent = (binary_tree_t *)first;
	while (com1_parent != NULL)
	{
		com2_parent = (binary_tree_t *)second;
		while (com2_parent != NULL)
		{
			tmp_common_parent = compare_node(com1_parent, com2_parent);
			if (tmp_common_parent != NULL)
				return (tmp_common_parent);
			com2_parent = com2_parent->parent;
		}
		com1_parent = com1_parent->parent;
	}
	return (tmp_common_parent);

}

/* iterative...
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
*/

/* recursive...
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pop));
}
*/
