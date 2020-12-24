#include "binary_trees.h"

/**
 * swap_it - swaps parent and child if needed
 * @new: new node to compare
 * Return: new node
 */

heap_t *swap_it(heap_t *new)
{
	heap_t *newnode = new;
	int tmp;

	while (newnode->parent)
	{
		if (newnode->n > newnode->parent->n)
		{
			tmp = newnode->n;
			newnode->n = newnode->parent->n;
			newnode->parent->n = tmp;
			newnode = newnode->parent;
			continue;
		}
		return (newnode);
	}
	return (new);
}

/**
  * insert_new_node - insert new node to the heap
  * @root: root node
  * Return: newnode
  */
heap_t *insert_new_node(heap_t *root)
{
	sized_t tmp;

	tmp = heap_size(root);
	return (tmp.p);
}

/**
  * heap_size - size of heap
  * @node: new node size
  * Return: size
  */
sized_t heap_size(heap_t *node)
{
	sized_t tmp, left, right;

	tmp.n = 0;
	tmp.p = node;

	if (!node->left || !node->right)
	{
		return (tmp);
	}

	left = heap_size(node->left);
	right = heap_size(node->right);

	if (left.n <= right.n)
	{
		left.n += 1;
		return (left);
	}
	else
	{
		right.n += 1;
		return (right);
	}
}

/**
 * heap_t *heap_insert - insert new node
 * @root: point to root node
 * @value: value to insert
 * Return: new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newnode = NULL;
	heap_t *last = NULL;

	newnode = binary_tree_node(NULL, value);

	if (!newnode)
	{
		return (NULL);
	}

	if (!(*root))
	{
		*root = newnode;
		return (newnode);
	}

	last = insert_new_node(*root);

	if (!last->left)
	{
		last->left = newnode;
	}
	else
	{
		last->right = newnode;
	}

	newnode->parent = last;

	return (swap_it(newnode));
}
