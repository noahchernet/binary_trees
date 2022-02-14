#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the node to be created
 * @value: the value the node holds
 *
 * Return: pointer to the new node, or NULL if unsuccessful
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	/*
	 * Link the new node to the parent if the parent exists
	 */
	if (parent)
		new_node->parent = parent;
	return (new_node);
}
