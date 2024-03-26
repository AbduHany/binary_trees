#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the binary tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	binary_tree_t *cursor = (binary_tree_t*)tree;

	if (tree == NULL)
		return (0);

	while (cursor->left != NULL || cursor->right != NULL)
	{
		height++;
		if (cursor->left)
			cursor = cursor->left;
		else
			cursor = cursor->right;
	}
	return (height);
}
