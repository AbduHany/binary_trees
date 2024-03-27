#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newroot;

	if (tree == NULL)
		return (NULL);
	newroot = tree->left;
	tree->left = newroot->right;
	newroot->right = tree;
	tree->parent = newroot;
	return (newroot);
}
