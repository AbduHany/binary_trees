#include "binary_trees.h"

/**
 * get_height - calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure
 * the height of.
 *
 * Return: the height of the tree or 0 if tree is NULL.
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	lheight = 1 + get_height(tree->left);
	rheight = 1 + get_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete_flag;
	size_t height;

	(void)is_complete_flag;
	if (tree == NULL)
		return (0);
	height = get_height(tree);
	printf("HEIGHT IS %ld\n", height);
	return (1);
}
