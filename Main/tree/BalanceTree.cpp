
#include<iostream>
using namespace std;

#define endl "\n"

struct Node {
	int data;
	Node* left;
	Node* right;
	int height;
};

void init(Node*& root) {
	root = NULL;
}

Node* makeNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}

int getHeight(Node* root) {
	if (root == NULL)
		return 0;
	else
		return root->height;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void update(Node*& root) {
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node* root) {
	if (root == NULL)
		return 0;
	return getHeight(root->left) - getHeight(root->right);
}

void quayPhai(Node*& root) {
	Node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	update(root);
	update(tmp);
	root = tmp;
}

void quayTrai(Node*& root) {
	Node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	update(root);
	update(tmp);
	root = tmp;
}

void addNode(Node*& root, int x) {
	if (root == NULL) {
		root = makeNode(x);
	}
	else {
		if (root->data > x)
			addNode(root->left, x);
		else if (root->data < x)
			addNode(root->right, x);
		else
			return;
	}
	// cap nhap chieu cao
	update(root);
	// kiem tra
	int val = getHeight(root->left) - getHeight(root->right);

	if (val > 1 && root->left->data > x) {
		//lech trai trai
		quayPhai(root);
	}
	else if (val < -1 && root->right->data < x) {
		// phai phai
		quayTrai(root);
	}
	else if (val > 1 && root->left->data < x) {
		// lech trai phai
		quayTrai(root->left);
		quayPhai(root);
	}
	else if (val < -1 && root->right->data > x) {
		// phai trai
		quayPhai(root->right);
		quayTrai(root);
	}
}

Node* leftNode(Node*& root) {
	Node* Node = root;
	while (Node->left != NULL) {
		Node = Node->left;
	}
	return Node;
}

void delNodeNoRec(Node*& root, int key) {
	if (root == NULL) {
		return;
	}
	else {
		Node* tmp = root; // bien can xoa
		Node* flag = NULL; //bien cha cua tmp
		while (tmp != NULL && tmp->data != key) {
			flag = tmp;
			if (tmp->data > key) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
		// ko tim thay key
		if (tmp == NULL) {
			return;
		}
		// node bac 0
		if (tmp->left == NULL && tmp->right == NULL) {
			if (tmp == root) {
				root = NULL;
				delete root;
			}
			else {
				if (flag->data > key) {
					flag->left = NULL;
				}
				else {
					flag->right = NULL;
				}
				delete tmp;
			}
		}
		// co 1 node ben trai
		else if (tmp->left != NULL && tmp->right == NULL) {
			if (tmp == root) {
				root = tmp->left;
				delete tmp;
			}
			else {
				if (flag->data > key) {
					flag->left = tmp->left;
				}
				else {
					flag->right = tmp->left;
				}
				delete tmp;
			}
		}
		// co 1 node ben phai
		else if (tmp->left == NULL && tmp->right != NULL) {
			if (tmp = root) {
				root = tmp->right;
				delete tmp;
			}
			else {
				if (flag->data > key) {
					flag->left = tmp->right;
				}
				else {
					flag->right = tmp->right;
				}
				delete tmp;
			}
		}
		// co 2 node
		else {
			flag = NULL;
			Node* left = tmp->right;
			if (left->left == NULL && left->right == NULL) {
				tmp->data = left->data;
				tmp->right = NULL;
				delete left;
			}
			else if (left->left == NULL && left->right != NULL) {
				tmp->data = left->data;
				tmp->right = left->right;
				left->right = NULL;
				delete left;
			}
			else {
				while (left->left != NULL) {
					flag = left;
					left = left->left;
				}
				if (left->right == NULL) {
					tmp->data = left->data;
					flag->left = NULL;
					delete left;
				}
				else {
					tmp->data = left->data;
					flag->left = left->right;
					left->right = NULL;
					delete left;
				}
			}
		}
	}
}

void searchStandFor(Node*& cur, Node*& temp) {
	if (temp->left != NULL) {
		searchStandFor(cur, temp->left);
	}
	else {
		cur->data = temp->data;
		cur = temp;
		temp = temp->right;
	}
}

void delNode(Node*& root, const int key) {
	if (root == NULL)
		return;
	if (key > root->data)
		delNode(root->right, key);
	else if (key < root->data)
		delNode(root->left, key);
	else {
		//Tim thay node can xoa
		Node* cur = root;
		//TH1: node la hoac node bac 0
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else {
			searchStandFor(cur, root->right);
		}
		delete cur;
	}

	//Cap nhat chieu cao
	if (root == NULL)
		return;

	update(root);

	int val = getBalance(root);

	if (val > 1) {
		//trai
		if (getBalance(root->left) < -1) {
			// trai phai
			quayTrai(root->left);
			quayPhai(root);
		}
		else {
			quayPhai(root);
		}
	}
	else if (val < -1) {
		//phai
		if (getBalance(root->right) > 1) {
			// phai trai
			quayPhai(root->right);
			quayTrai(root);
		}
		else {
			quayTrai(root);
		}
	}
}

void LNR(Node* root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->data << "(" << root->height << ") ";
		LNR(root->right);
	}
}

void NLR(Node* root) {
	if (root != NULL) {
		cout << root->data << "(" << root->height << ") ";
		NLR(root->left);
		NLR(root->right);
	}
}

int main() {
	Node* root;
	init(root);
	addNode(root, 40);
	addNode(root, 60);
	addNode(root, 20);
	addNode(root, 15);
	addNode(root, 5);
	NLR(root);
	cout << endl;
	delNode(root, 60);
	delNode(root, 5);
	NLR(root);
	return 0;
}