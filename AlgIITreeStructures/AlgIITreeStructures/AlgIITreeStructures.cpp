// AlgIITreeStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	std::cout << "Non-degenerate tree: " << std::endl;

	BinarySearchTree tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.insert(1);
	tree.insert(3);
	tree.insert(5);
	tree.insert(7);

	tree.print_bfs();
	
	tree.print_preorder();
	tree.print_preorder_iterative();

	tree.print_inorder();
	tree.print_inorder_iterative();

	tree.print_postorder();
	tree.print_postorder_iterative();

	BinarySearchTree::TreeNode* fastResult = tree.find_iterative(7);

	std::cout << "Degenerate tree: " << std::endl;

	BinarySearchTree degenerate_tree;

	degenerate_tree.insert(1);
	degenerate_tree.insert(2);
	degenerate_tree.insert(3);
	degenerate_tree.insert(4);
	degenerate_tree.insert(5);
	degenerate_tree.insert(6);
	degenerate_tree.insert(7);

	degenerate_tree.print_bfs();

	degenerate_tree.print_preorder();
	degenerate_tree.print_preorder_iterative();

	degenerate_tree.print_inorder();
	degenerate_tree.print_inorder_iterative();

	degenerate_tree.print_postorder();
	degenerate_tree.print_postorder_iterative();

	BinarySearchTree::TreeNode* slowResult = degenerate_tree.find(7);
}