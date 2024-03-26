#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full and 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full_flag_l, is_full_flag_r;

	if (tree == NULL)
		return (0);
	if ((tree->left && tree->right) ||
	    (tree->left == NULL && tree->right == NULL))
	{
		is_full_flag_l = binary_tree_is_full(tree->left);
		is_full_flag_r = binary_tree_is_full(tree->right);
	}
	else
		return (1);
	return (!(is_full_flag_l || is_full_flag_r));
}
