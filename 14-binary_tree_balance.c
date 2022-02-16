#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a binary tree
 *
 * Return: the balance factor of @tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;

	if (!tree)
		return (0);
	balance_factor = (int) (binary_tree_height(tree->left) - binary_tree_height
		(tree->right));

	/**
	 * If tree->right is a leaf, balance_factor becomes height of the left
	 * tree minus 1
	 */
	if (tree->right && !tree->right->left && !tree->right->right)
		balance_factor -= 1;
	/**
	 * If tree->left is a leaf, balance_factor becomes 1 minus height of the
	 * right tree
	 */
	else if (tree->left && !tree->left->left && !tree->left->right)
		balance_factor += 1;

	return (balance_factor);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a binary tree
 *
 * Return: height of the @tree, NULL otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (right_height > left_height)
		return (right_height);
	return (left_height);
}
