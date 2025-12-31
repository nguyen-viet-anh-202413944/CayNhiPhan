#include <iostream>
using namespace std;
//Bai tap tuan 14 + 15
struct Node {
	int val;
	Node* left;
	Node* right;
};
struct Tree {
	Node* root;
};
struct Node* createNode(int val) {
	Node* newNode = new Node();
	newNode->val = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
struct Tree* createTree(int val) {
	Tree* newTree = new Tree();
	newTree->root = createNode(val);
	return newTree;
}
void insertNode(Tree* tree, int val) {
	Node* newNode = createNode(val);
	if (tree->root == nullptr) {
		tree->root = newNode;
		return;
	}
	Node* current = tree->root;
	Node* parent = nullptr;
	while (true) {
		parent = current;
		if (val < current->val) {
			current = current->left;
			if (current == nullptr) {
				parent->left = newNode;
				return;
			}
		} else {
			current = current->right;
			if (current == nullptr) {
				parent->right = newNode;
				return;
			}
		}
	}
}
void preorder(Node* node) {
	if (node == nullptr) return;
	cout << node->val << ' ';
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node) {
	if (node == nullptr) return;
	inorder(node->left);
	cout << node->val << ' ';
	inorder(node->right);
}

void postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->val << ' ';
}

static Node* cloneTree(Node* node) {
	if (node == nullptr) return nullptr;
	Node* c = createNode(node->val);
	c->left = cloneTree(node->left);
	c->right = cloneTree(node->right);
	return c;
}

static void heapNode(Node* node) {
	if (node == nullptr) return;
	heapNode(node->left);
	heapNode(node->right);

	Node* largest = node;
	if (node->left && node->left->val > largest->val) largest = node->left;
	if (node->right && node->right->val > largest->val) largest = node->right;
	if (largest != node) {
		int temp = node->val;
		node->val = largest->val;
		largest->val = temp;
		heapNode(largest);
	}
}

Tree* createHeapTree(Tree* tree) {
	if (!tree || !tree->root) {
		Tree* empty = new Tree();
		empty->root = nullptr;
		return empty;
	}
	Tree* heapTree = new Tree();
	heapTree->root = cloneTree(tree->root);
	heapNode(heapTree->root);
	preorder(heapTree->root);//Bai 1 phan 2
	return heapTree;
}
bool treeCompare(Node* a, Node* b) {
	if (a == nullptr && b == nullptr) return true;
	if (a == nullptr || b == nullptr) return false;
	return (a->val == b->val) &&
		treeCompare(a->left, b->left) &&
		treeCompare(a->right, b->right);
	//Bai 2 phan 3
	//cay co n phan tu thi so phep so sanh la n
	//do do do phuc tap thoi gian la O(n)
}

int main() {
	//Bai 2 phan 1
	Tree* tree = createTree(4);
	insertNode(tree, 1);
	insertNode(tree, 3);
	insertNode(tree, 2);
	insertNode(tree, 16);
	insertNode(tree, 9);
	insertNode(tree, 10);
	insertNode(tree, 14);
	insertNode(tree, 8);
	insertNode(tree, 7);

	Tree* tree2 = createTree(10);
	insertNode(tree2, 2);
	insertNode(tree2, 3);
	insertNode(tree2, 9);
	insertNode(tree2, 16);
	insertNode(tree2, 9);
	insertNode(tree2, 130);
	insertNode(tree2, 144);
	insertNode(tree2, 81);
	insertNode(tree2, 7);

	//Bai 1 phan 1
	cout << "Preorder: ";
	preorder(tree->root);
	cout << "\nInorder: ";
	inorder(tree->root);
	cout << "\nPostorder: ";
	postorder(tree->root);
	//Bai 2 phan 2
	bool isEqual = treeCompare(tree->root, tree2->root);
	return 0;
}