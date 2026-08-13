#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void init_tree(Node*& root) {
	root = NULL;
}

Node* makeNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void themNode(Node*& root, int x) {
	if (root == NULL) {
		Node* p = makeNode(x);
		root = p;
	}
	else {
		if (root->data == x)
			return;
		else if (root->data > x)
			return themNode(root->left, x);
		else
			return themNode(root->right, x);
	}
}

void addNode(Node*& root, int x) {

    // Cây rỗng
    if (root == NULL) {
        root = makeNode(x);
        return;
    }

    Node* tmp = root;

    while (true) {

        if (tmp->data == x) {
            return;
        }

        if (x < tmp->data) {

            if (tmp->left == NULL) {
                tmp->left = makeNode(x);
                return;
            }

            tmp = tmp->left;
        }

        else {

            if (tmp->right == NULL) {
                tmp->right = makeNode(x);
                return;
            }

            tmp = tmp->right;
        }
    }
}

Node* findLeftNode(Node*& root) {
	if (root == NULL)
		return NULL;
	Node* leftNode = root;
	while (leftNode->left != NULL) {
		leftNode = leftNode->left;
	}
	return leftNode;
}

Node* delNode(Node*& root, int key) {
	if (root == NULL)
		return NULL;
	if (key < root->data)
		root->left = delNode(root->left, key);
	else if (key > root->data)
		root->right = delNode(root->right, key);
	// root->data = key
	else {
		//TH1: node la
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		//TH2: node co 1 con
		if (root->left != NULL && root->right == NULL) {
			Node* tam = root->left;
			delete root;
			return tam;
		}
		if (root->left == NULL && root->right != NULL) {
			Node* tam = root->right;
			delete root;
			return tam;
		}
		//TH3: node co 2 con
		// tim node left cua cay ben phai
		if (root->left != NULL && root->right != NULL) {
			Node* leftNode = findLeftNode(root->right);
			root->data = leftNode->data;
			root->right = delNode(root->right, leftNode->data);
		}
	}
	return root;
}

void giaiPhong(Node*& root) {
    if (root == NULL)
        return;

    giaiPhong(root->left);
    giaiPhong(root->right);

    delete root;
    root = NULL;
}

void duyetLRN(Node* root)
{
	if (root != NULL)
	{
		duyetLRN(root->left);
		duyetLRN(root->right);
		cout << root->data << " ";
	}
}

void duyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

void duyetLNR(Node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->data << " ";
		duyetLNR(p->right);
	}
}

int main() {
	Node* root;
	init_tree(root);
	themNode(root, 10);
	themNode(root, 5);
	themNode(root, 15);
	themNode(root, 12);
	themNode(root, 2);
	themNode(root, 7);
	themNode(root, 14);
	themNode(root, 6);
	delNode(root, 5);
	cout << "Duyet LNR: ";
	duyetLNR(root);
	cout << endl;
	cout << "Duyet NLR: ";
	duyetNLR(root);
	cout << endl;
	cout << "Duyet LRN: ";
	duyetLRN(root);
	cout << endl;
	giaiPhong(root);
	return 0;
}