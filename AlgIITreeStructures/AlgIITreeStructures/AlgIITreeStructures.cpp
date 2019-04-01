// AlgIITreeStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.insert(1);
	tree.insert(3);
	tree.insert(5);
	tree.insert(7);

	tree.print_inorder();

	BinarySearchTree::TreeNode* fastResult = tree.find(7);

	BinarySearchTree degenerate_tree;

	degenerate_tree.insert(1);
	degenerate_tree.insert(2);
	degenerate_tree.insert(3);
	degenerate_tree.insert(4);
	degenerate_tree.insert(5);
	degenerate_tree.insert(6);
	degenerate_tree.insert(7);

	// NOTE: Print should be same as in previous case
	degenerate_tree.print_inorder();

	BinarySearchTree::TreeNode* slowResult = degenerate_tree.find(7);
}