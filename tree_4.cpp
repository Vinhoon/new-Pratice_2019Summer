	#include <iostream>
	using namespace std;

	struct Node		//Data structure to store a Binary Search Tree node 
	{
		int data;
		Node *left, *right;
	};

	Node *newNode(int key)
	{
		Node *node = new Node;
		node->data = key;
		node->left = node->right = nullptr;

		return node;
	}

	void inorder(Node *root)
	{
		if (root == nullptr)
			return;

		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	Node *minimumkey(Node * curr)
	{
		while (curr->left != nullptr)
		{
			curr = curr->left;
		}
		return curr;
	}

	Node *insert(Node *root, int key)
	{
		if (root == nullptr)	//루트가 없는 경우 키가있는 공간을 만들어 준다 
			return newNode(key);

		if (key < root->data)
			root->left = insert(root->left, key);
		else
			root->right = insert(root->right, key);

		return root;
	}

	void searchKey(Node *&curr, int key, Node *&parent)
	{
		while (curr != nullptr&& curr->data != key)
		{
			parent = curr;

			if (key < curr->data)
				curr = curr->left;
			else
				curr = curr->right;

		}
	}

	void deleteNode(Node *&root, int key)
	{
		//pointer to store  parent of current Node
		// 맨 위에서부터 시작한다고 생각하자
		Node *parent = nullptr;

		Node *curr = root;		//현재를 뿌리라 생각

		searchKey(curr, key, parent);
		// 이걸 통해서 curr이 어딘지 알아내는데 성공함
		//curr을 안다

		if (curr == nullptr)
			return;
		
		//case1 아이가 없을 때
		if (curr->left == nullptr && curr->right == nullptr)
		{
			if (curr != root)
			{
				if (parent->left == curr)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				root = nullptr;
			
			//deallocate the memory
			free(curr);
		}

		//case2 : 아이가 두명 일때
		else if (curr->left &&curr->right)
		{
			Node *successor = minimumkey(curr->right);

			int val = successor->data; //val에 임시로 값을 저장

			deleteNode(root, successor->data);
			curr->data = val;

		}

		// case 3:아이가 한명일 때
		else
		{
			Node *child = (curr->left) ? curr->left : curr->right;

			if (curr != root)
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;

			}
			else
				root = child;

			free(curr);
		}
	}

		int main()
		{
			Node *root = nullptr;
			int keys[] = { 15,10,20,8,12,16 };

			for (int key : keys)
				root = insert(root, key);

			/*deleteNode(root, 16);*/
			inorder(root);

			return 0;
		}






































































