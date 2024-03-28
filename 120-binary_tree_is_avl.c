#include "binary_trees.h"

/**
 * get_max - get the maximum value of a AVL. (very right node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 *
 * Return: the maximum value.
 */
int get_max(const binary_tree_t *tree)
{
	int max_val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	while (cursor->right)
		cursor = cursor->right;
	max_val = cursor->n;
	return (max_val);
}

/**
 * get_min - get the minimum value of a AVL. (very left node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 *
 * Return: the minimum value.
 */
int get_min(const binary_tree_t *tree)
{
	int min_val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	while (cursor->left)
		cursor = cursor->left;
	min_val = cursor->n;
	return (min_val);
}

/**
 * is_bst - checks if a valid (NON-NULL) tree is a AVL.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid AVL and 0 otherwise.
 */
int is_bst(const binary_tree_t *tree)
{
	int bst_flag = 1, min_right, max_left;

	if (tree == NULL)
		return (1);

	/* checking for max and min numbers of subtrees */
	if (tree->left)
	{
		max_left = get_max(tree->left);
		if (max_left >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		min_right = get_min(tree->right);
		if (min_right <= tree->n)
			return (0);
	}

	/* checking if left and right subtrees are AVLs */
	bst_flag &= is_bst(tree->left);
	bst_flag &= is_bst(tree->right);
	return (bst_flag);

}

int get_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);

	lheight = 1 + get_height(tree->left);
	rheight = 1 + get_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}

int check_heights(const binary_tree_t *tree)
{
	int lh, rh, avl_flag = 1;

	if (tree == NULL)
		return (1);

	lh = get_height(tree->left);
	rh = get_height(tree->right);

	if (abs(lh - rh) > 1)
		avl_flag = 0;
	avl_flag &= check_heights(tree->left);
	avl_flag &= check_heights(tree->right);

	return(avl_flag);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid AVL and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int avl_flag = 1;

	if (tree == NULL)
		return (0);

	else
	{
		avl_flag &= is_bst(tree);
		avl_flag &= check_heights(tree);
	}
	return (avl_flag);
}
