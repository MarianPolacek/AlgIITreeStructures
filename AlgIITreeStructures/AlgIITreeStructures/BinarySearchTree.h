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
	void insert_iterative(int value);

	TreeNode* find(int value);
	TreeNode* find_iterative(int value);

	void remove(int value);

	void print_bfs();

	void print_preorder();
	void print_inorder();	
	void print_postorder();

	void print_preorder_iterative();
	void print_inorder_iterative();
	void print_postorder_iterative();

private:
	TreeNode* root;
	
	void insert_recursive_internal(TreeNode* current, int value);
	TreeNode* find_recursive_internal(TreeNode* current, int value);
	void print_preorder_internal(TreeNode* current);
	void print_inorder_internal(TreeNode* current);
	void print_postorder_internal(TreeNode* current);
	TreeNode* remove_recursive_internal(TreeNode* current, int value);
	TreeNode* find_min(TreeNode* current);
};

