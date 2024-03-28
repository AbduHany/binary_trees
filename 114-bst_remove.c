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
 * find_successor - get the minimum value of a BST. (very left node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 *
 * Return: the minimum value.
 */
int find_successor(const binary_tree_t *tree)
{
	int min_val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	while (cursor->left)
		cursor = cursor->left;
	min_val = cursor->n;
	return (min_val);
}

/**
 * delete_2_children - deletes a node in a BST if it has 2 children
 * @to_delete: pointer to the node to be deleted.
 *
 * Return: pointer to the node that replaces the deleted node.
 */
bst_t *delete_2_children(bst_t *to_delete)
{
	return (to_delete);
}

/**
 * delete_1_child - deletes a node in a BST that has only 1 child.
 * @to_delete: pointer to node to be deleted.
 *
 * Return: pointer to the node that replaces deleted node.
 */
bst_t *delete_1_child(bst_t *to_delete)
{
	bst_t *prev, *next;

	prev = to_delete->parent;
	next = to_delete->left == NULL ? to_delete->right
		: to_delete->left;
	next->parent = prev;
	if (prev->left == to_delete)
		prev->left = next;
	else
		prev->right = next;
	free(to_delete);
	return (prev);
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
	bst_t *to_delete, *prev;

	if (root == NULL)
		return (NULL);
	to_delete = find_node(root, value);
	if (to_delete == NULL)
		return (root);
	if (to_delete->left == NULL && to_delete->right == NULL)
	{
		prev = to_delete->parent;
		if (prev->left == to_delete)
			prev->left = NULL;
		else
			prev->right = NULL;
		free(to_delete);
        }
	else if ((to_delete->left && to_delete->right == NULL) ||
		(to_delete->right && to_delete->left == NULL))
		delete_1_child(to_delete);
	else if (to_delete->left && to_delete->right)
		delete_2_children(to_delete);
	return (root);
}
