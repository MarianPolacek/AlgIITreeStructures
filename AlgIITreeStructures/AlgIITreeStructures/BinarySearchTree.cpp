#include "pch.h"
#include <iostream>
#include "BinarySearchTree.h"
#include <queue>
#include <stack>

BinarySearchTree::TreeNode::TreeNode(int value)
{
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

BinarySearchTree::TreeNode::~TreeNode()
{
	// NOTE: Try to cleanup left and right child, this will recursively cleanup whole subtree
	delete this->left;
	delete this->right;
}


BinarySearchTree::BinarySearchTree()
{
	this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	// NOTE: This will try to cleanup whole tree
	delete this->root;
}


void BinarySearchTree::insert(int value)
{
	// NOTE: Recursive variant of insert, try to create root if it does not exist, or call recursive function
	//			to create new node at proper place

	// 1. Create root, if there is no element
	if (root == nullptr)
	{
		this->root = new TreeNode(value);
	}
	// 2. Call recursive function to create element
	else
	{
		this->insert_recursive_internal(this->root, value);
	}
}

void BinarySearchTree::insert_recursive_internal(TreeNode* current, int value)
{
	// 1. Node with value, already exists, implementation decides, what to do in this case
	if (current->value == value)
	{
		// NOOP
	}
	// 2. Value stored in current node is greater, than inserted value => check left subtree
	else if (current->value > value)
	{
		// 2.1. Left child does not exist, create new leaf
		if (current->left == nullptr)
		{
			current->left = new TreeNode(value);
		}
		// 2.2. Left child does exist, recursively go down left
		else
		{
			this->insert_recursive_internal(current->left, value);
		}
	}
	// 3. Finally, check right tree (value not equal and not less, as to be more)
	else
	{
		// 3.1. Right child does not exist, create new leaf
		if (current->right == nullptr)
		{
			current->right = new TreeNode(value);
		}
		// 3.3. Right child does
		else
		{
			this->insert_recursive_internal(current->right, value);
		}
	}
}


void BinarySearchTree::insert_iterative(int value)
{
	// NOTE: Non-recursive version of insert, hast to locate insert location in loop

	// 1. If there is no root, just create it 
	if (this->root == nullptr)
	{
		this->root = new TreeNode(value);
		return;
	}

	// 2. Prepare variables used in loop,
	TreeNode* current = this->root;

	// 3. Loop indefinitely, loop will be stopped from inside
	while (true)
	{
		// 3.1. Node with value already exists, do nothing and end the loop
		if (current->value == value)
		{
			// NOOP, j
			return;
		}
		// 3.2. Check left subtree
		else if (current->value > value)
		{
			// 3.2.1. Left child does not exist, create it and end the loop
			if (current->left == nullptr)
			{
				current->left = new TreeNode(value);
				return;
			}
			// 3.2.2. Left child does exist, set it as current pointer
			else
			{
				current = current->left;
			}
		}
		// 3.3.Check right subtree
		else
		{
			// 3.3.1. Right child does not exist, create it and end the loop
			if (current->right == nullptr)
			{
				current->right = new TreeNode(value);
				return;
			}
			// 3.3.2. Right child does exist, set it as current pointer
			else
			{
				current = current->right;
			}
		}
	}
}


BinarySearchTree::TreeNode* BinarySearchTree::find(int value)
{
	return this->find_recursive_internal(this->root, value);
}

BinarySearchTree::TreeNode* BinarySearchTree::find_recursive_internal(TreeNode* current, int value)
{
	// 1. Node was not found
	if (current == nullptr)
	{
		return nullptr;
	}
	// 2. Node was found
	else if (current->value == value)
	{
		return current;
	}
	// 3. Value stored in current node is greater, that value we are looking for -> continue to left subtree
	else if (current->value > value)
	{
		return this->find_recursive_internal(current->left, value);
	}
	// 4. Value stored in current node is greater, that value we are looking for -> continue to right subtree
	else
	{
		return this->find_recursive_internal(current->right, value);
	}
}

BinarySearchTree::TreeNode * BinarySearchTree::find_iterative(int value)
{
	// NOTE: Loops while pointer to current node does not contain value, that we are looking for,
	//		or till it is nullptr (node with value does not exist)

	TreeNode* current = this->root;

	while (current != nullptr && current->value != value)
	{
		if (current->value > value)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return current;
}


void BinarySearchTree::print_bfs()
{
	// NOTE: BFS implementation for trees does not require marking of nodes (there are no cycles), due to this
	//			implementation can be simplified (when compared with implementation over generic graphs)

	// NOTE: Use queue as backing structure, push root, take from queue, push left and right, repeat till queue is empty

	std::queue<TreeNode*> queue;

	if (this->root == nullptr)
	{
		return;
	}

	queue.push(this->root);

	while (!queue.empty())
	{
		TreeNode* current = queue.front();
		queue.pop();

		std::cout << current->value << " ";

		if (current->left != nullptr)
		{
			queue.push(current->left);
		}

		if (current->right != nullptr)
		{
			queue.push(current->right);
		}
	}

	std::cout << std::endl;
}

// NOTE: Recursive pre/in/post-order iterations differ only in place, where current node is processed (displayed)
//			all of them ceck for empty current node and then recursively call themselves

void BinarySearchTree::print_preorder()
{
	this->print_preorder_internal(this->root);
	std::cout << std::endl;
}

void BinarySearchTree::print_preorder_internal(TreeNode* current)
{
	if (current == nullptr)
	{
		// NOOP
		return;
	}

	std::cout << current->value << " ";
	this->print_preorder_internal(current->left);
	this->print_preorder_internal(current->right);
}

void BinarySearchTree::print_inorder()
{
	this->print_inorder_internal(this->root);
	std::cout << std::endl;
}

void BinarySearchTree::print_inorder_internal(TreeNode * current)
{
	if (current == nullptr)
	{
		// NOOP
		return;
	}

	this->print_inorder_internal(current->left);
	std::cout << current->value << " ";
	this->print_inorder_internal(current->right);
}

void BinarySearchTree::print_postorder()
{
	this->print_postorder_internal(this->root);
	std::cout << std::endl;
}

void BinarySearchTree::print_postorder_internal(TreeNode * current)
{
	if (current == nullptr)
	{
		// NOOP
		return;
	}

	this->print_postorder_internal(current->left);
	this->print_postorder_internal(current->right);
	std::cout << current->value << " ";
}


void BinarySearchTree::print_preorder_iterative()
{
	// NOTE: Most simple iteration, just push right and left childs to stack loop, 
	//		while there is anything on stack

	// 1. If root is empty, there is nothing to display
	if (this->root == nullptr)
	{
		return;
	}

	// 2. Initialize stack and push root
	std::stack<TreeNode*> stack;
	stack.push(this->root);

	// 3. Loop, while stack is not empty
	while (!stack.empty())
	{
		// 3.1 Check top of stack and display it
		TreeNode* current = stack.top();
		stack.pop();

		std::cout << current->value << " ";

		// 3.2 Push children to stack (NOTE: In reverse order, stack is LIFO)
		if (current->right != nullptr)
		{
			stack.push(current->right);
		}

		if (current->left != nullptr)
		{
			stack.push(current->left);
		}
	}

	std::cout << std::endl;
}

void BinarySearchTree::print_inorder_iterative()
{
	// NOTE: Iterative version of inorder go all the way to most-left leaf, push all nodes to stack.
	//		By taking from stack, alg. returns 'back' top and displays values, after display of value, move to
	//		right subtree (and then again go all the way to left). Repeat, while there is anything on stack

	// If root is empty, there is nothing to display
	if (this->root == nullptr)
	{
		return;
	}

	// A. Initialize variables
	std::stack<TreeNode*> stack;
	TreeNode* current = this->root;

	// B. Main loop, ends if current node is nullpr, or if stack is empty
	while (current != nullptr || !stack.empty())
	{
		// 1. Inner loop, that finds most-left node (in subtree) and pushes everything to stack. 
		while (current != nullptr)
		{
			stack.push(current);
			current = current->left;
		}

		// 2. Take top of stack and display it
		current = stack.top();
		stack.pop();

		std::cout << current->value << " ";

		// 3. Move to right subtree
		current = current->right;
	}

	std::cout << std::endl;
}

void BinarySearchTree::print_postorder_iterative()
{
	// NOTE: Most complex iteration. Has to first display both children and only then root. Similar to inorder,
	//		it goes all the way down to left, but pushes also right children to stack (before current node).
	//		Alg. has to handle case, when it returns top by taking elements from stack - if top of stack is same
	//		as right child of current element, this means, that lef child of current element was already processed,
	//		but right was not - current element has to be swapped with top of stack

	// If root is empty, there is nothing to display
	if (this->root == nullptr)
	{
		return;
	}

	// A. Initialize variables
	std::stack<TreeNode*> stack;
	TreeNode* current = this->root;

	// B. Main loop, ends if current node is nullpr, or if stack is empty
	while (current != nullptr || !stack.empty())
	{
		// 1. Go down to left, but push also right children to stack
		while (current != nullptr)
		{
			// 1.1. If there is right child, push it before current node
			if (current->right != nullptr)
			{
				stack.push(current->right);
			}

			// 1.2. Push current node and move down to the left
			stack.push(current);
			current = current->left;
		}

		// 2. Take top of stack
		current = stack.top();
		stack.pop();

		// 3. If top of stack contains right child of currently processed node, this means, that left child
		//		of this node was already processed and alg. is going up. To display nodes in correct order, 
		//		top of stack has to be processes first (right child has to be processed before parent).
		//		Solution is to swap top of stack with current element
		if (!stack.empty() && current->right == stack.top())
		{
			// NOTE: swap top of stack
			TreeNode* temp = current;
			current = stack.top();
			stack.pop();
			stack.push(temp);
		}
		// 4. Both children were processed (or are nullptr) - display value
		else
		{
			std::cout << current->value << " ";
			current = nullptr;
		}
	}

	std::cout << std::endl;
}


void BinarySearchTree::remove(int value)
{
	this->root = this->remove_recursive_internal(this->root, value);
}

BinarySearchTree::TreeNode * BinarySearchTree::remove_recursive_internal(TreeNode* current, int value)
{
	// 1. Basic case, do nothing
	if (current == nullptr)
	{
		return nullptr;
	}

	// 2. Check left subtree for value
	if (current->value > value)
	{
		current->left = this->remove_recursive_internal(current->left, value);
	}
	// 3. Check right subtree for value
	else if (current->value < value)
	{
		current->right = this->remove_recursive_internal(current->right, value);
	}
	// 4. Found the value, remove it (according to rules)
	else
	{
		// 4.1. No children, just delete it
		if (current->left == nullptr && current->right == nullptr)
		{
			delete current;
			current = nullptr; // NOTE: This makes return easier
		}
		// 4.2. Single child on right, set it instead of current element
		else if (current->left == nullptr)
		{
			TreeNode* temp = current;
			current = current->right;

			// NOTE: Destructor wipes all descedants, so make sure there is no connection, that could be deleted
			temp->right = nullptr;
			delete temp;
		}
		// 4.3. Single child on left, set it instead of current element
		else if (current->right == nullptr)
		{
			TreeNode* temp = current;
			current = current->left;

			// NOTE: Destructor wipes all descedants, so make sure there is no connection, that could be deleted
			current->left = nullptr;
			delete temp;
		}
		// 4.4. Node has both left and right child, has to apply special handling
		else
		{
			// 4.4.1. Find direct descendant (node with minimal value in right subtree)
			TreeNode* descendant = this->find_min(current->right);

			// 4.4.2. Modify value in current node, set it to value from descendant
			current->value = descendant->value;

			// 4.4.3. Remove (now) duplicated value from right subtree
			current->right = this->remove_recursive_internal(current->right, descendant->value);
		}
	}

	// NOTE: Finally return value
	return current;
}

BinarySearchTree::TreeNode* BinarySearchTree::find_min(TreeNode* current)
{
	// NOTE: Loops left till there is nullptr
	if (current != nullptr && current->left != nullptr)
	{
		return this->find_min(current->left);
	}

	return current;
}