#include "binary_trees.h"

/**
 * find_node - searches for a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: pointer to the node containing a value equal to value.
 * or NULL if nothing is found or tree is NULL.
 */
bst_t *find_node(const bst_t *tree, int value)
{
	bst_t *cursor;

	if (tree == NULL)
		return (NULL);
	cursor = (bst_t *)tree;
	while (cursor)
	{
		if (value < cursor->n)
			cursor = cursor->left;
		else if (value > cursor->n)
			cursor = cursor->right;
		else
			return (cursor);
	}
	return (cursor);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where
 * you will remove a node
 * @value: value to remove in the tree.
 *
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_delete;

	to_delete = find_node(root, value);
	if (to_delete == NULL)
		return (NULL);
}
