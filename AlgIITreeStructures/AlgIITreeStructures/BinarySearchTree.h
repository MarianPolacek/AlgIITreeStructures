#pragma once
class BinarySearchTree
{
public:
	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int value;

		TreeNode(int value);
		~TreeNode();
	};

	BinarySearchTree();
	~BinarySearchTree();

	void insert(int value);
	void print_inorder();
	void remove(int value);
	TreeNode* find(int value);

private:
	TreeNode* root;
};

