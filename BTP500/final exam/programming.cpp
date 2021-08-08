	//print PreOrder Traversal
	void PrintPreorder(Node *node) {
		if (node == NULL)
			return;
		cout << " data:" << node->data_ << endl;
		PrintPreorder(node->left_);
		PrintPreorder(node->right_);
	}

	//print Inorder Traversal
	void PrintInorder(Node *node) {
		if (node == NULL)
			return;
		PrintInorder(node->left_);
		cout << " data:" << node->data_ << endl;
		PrintInorder(node->right_);
	}

	//print PostOrder Traversal
	void PrintPostorder(Node *node) {
		if (node == NULL)
			return;
		PrintPostorder(node->left_);
		PrintPostorder(node->right_);
		cout << " data:" << node->data_ << endl;
	}

	
	//find the Max node
	Node* FindMax(Node *node) {
		if (node == NULL)
			/* There is no element in the tree */
			return NULL;
		if (node->right_) /* Go to the right sub tree to find the max element */
			return FindMax(node->right_);
		else
			return node;
	}

	//find the Min node
	Node* FindMin(Node *node) {
		if (node == NULL)
			/* There is no element in the tree */
			return NULL;
		if (node->left_) /* Go to the left sub tree to find the min element */
			return FindMin(node->left_);
		else
			return node;
	}
	
	//insert node
	Node * Insert(Node *node, int data) {
		if (node == NULL) {
			Node *temp;
			temp = (Node *)new (sizeof(Node));//Should use new
			temp->data_ = data;
			temp->left_ = temp->right_ = NULL;
			return temp;
		}

		if (data > (node->data_))
			node->right_ = Insert(node->right_, data);
		else if (data < (node->data_))
			node->left_ = Insert(node->left_, data);
		/* Else there is nothing to do as the data is already in the tree. */
		return node;

	}

	//find node
	Node * Find(Node *node, int data) {
		if (node == NULL)
			/* Element is not found */
			return NULL;
		if (data > node->data_)
			/* Search in the right sub tree. */
			return Find(node->right_, data);
		else if (data < node->data_)
			/* Search in the left sub tree. */
			return Find(node->left_, data);
		else
			/* Element Found */
			return node;
	}

//finding the height of the Tree
	int height(Node *node)//See AVLTree.cpp of week 10
	{ 
		if (node == NULL)
			/* Element is not found */
			return NULL; /* tree is empty */
		return 1 + max(height(node->left), height(node->right)); 
	}  
	int max(int a, int b) { return (a >= b)? a: b;}  


	//find the Breadth-First Traversal
	void Tree::breadthFirst()//See notes under Trees>>Iterative Methods
	{
	  /* Temporary queue. */
	  Queue queue;
	  Tree *traverse;

	  /*
	   * Gotta put something in the queue initially,
	   * so that we enter the body of the loop.
	   */

	  queue.insert(root);

	  while (!queue.isEmpty()) {
		traverse = queue.remove();

		Visit the node pointed to by traverse.

		/*
		 * If there is a left child, add it
		 * for later processing.
		 */
		if (traverse->getLeftSubTree() != NULL)
		  queue.insert(traverse->getLeftSubTree());

		/*
		 * If there is a right child, add it
		 * for later processing.
		 */
		if (traverse->getRightSubTree() != NULL)
		  queue.insert(traverse->getRightSubTree());
	  }
	}
	
	
	void remove(const T& data){
		Node* currentNode_ = this->root_;
		Node* previousNode_ = nullptr;	//Parent of node to be found

		while (currentNode_ != nullptr) {
			//if current data is found
			if (data == currentNode_->data_)
				break;

			//if current data is smaller, go left
			else if (data < currentNode_->data_) {
				if (currentNode_->left_ != nullptr) {
					previousNode_ = currentNode_;
					currentNode_ = currentNode_->left_;
				}
			}

			//if current data is larger, go right
			else if (data > currentNode_->data_) {
				if (currentNode_->right_ != nullptr) {
					previousNode_ = currentNode_;
					currentNode_ = currentNode_->right_;
				}
			}
		}


		//if data is found
		if (currentNode_ != nullptr) {
			//check if deleting node contain any sub data
			if (currentNode_->left_ == nullptr && currentNode_->right_ == nullptr) {
				//Root node is the node to be deleted and is the only node in the tree
				if (currentNode_ == root_) {
					this->root_ = nullptr;
					delete currentNode_;
				}
				else {
					if (previousNode_ != nullptr) {
						//If the parent of curr has a child curr
						if (previousNode_->left_ == currentNode_) {
							previousNode_->left_ = nullptr;
							delete currentNode_;
						}
						else if (previousNode_->right_ == currentNode_) {
							previousNode_->right_ = nullptr;
							delete currentNode_;
						}
					}
				}
			}

			//if deleting node contain only left or right sub data 
			else if ((currentNode_->left_ != nullptr && currentNode_->right_ == nullptr) ||
				(currentNode_->right_ != nullptr && currentNode_->left_ == nullptr)) {
				
				Node* temp = nullptr;
				//if sub node is on the left
				if (currentNode_->left_ != nullptr && currentNode_->right_ == nullptr)
					temp = currentNode_->left_;
				
				//if sub node is on the right
				else if (currentNode_->right_ != nullptr && currentNode_->left_ == nullptr)
					temp = currentNode_->right_;
				
				
				if (currentNode_ == root_)
					root_ = temp;
				else {
					if (previousNode_->left_ == currentNode_) {
						previousNode_->left_ = temp;
						delete currentNode_;
					}
					else if (previousNode_->right_ == currentNode_) {
						previousNode_->right_ = temp;
						delete currentNode_;
					}
				}
			}

			//if deleting node contain both left and right sub data
			else {
				Node* tempNodes_ = currentNode_->right_;
				Node* tempPrevious_ = nullptr;
				Node* rightNode_ = nullptr;

				//move as far left as possible
				//always keep previous 1 node behind temp, for linking purpose
				while (tempNodes_->left_ != nullptr) {
					tempPrevious_ = tempNodes_;
					tempNodes_ = tempNodes_->left_;
				}
				
				if (tempNodes_ != nullptr) {
					//assign position to the only right node
					rightNode_ = tempNodes_->right_;

					//check if the node behind tempNodes (current successor)
					if (previousNode_ != nullptr) {
						if (previousNode_->right_ == currentNode_) {
							previousNode_->right_ = tempNodes_;
							tempNodes_->left_ = currentNode_->left_;
							tempNodes_->right_ = currentNode_->right_;
							tempPrevious_->left_ = rightNode_;
						}
						if (previousNode_->left_ == currentNode_) {
							previousNode_->left_ = tempNodes_;
							tempNodes_->left_ = currentNode_->left_;
						}
					}
					
					//Node to be removed is root
					if (currentNode_ == this->root_) {
						tempPrevious_->left_ = rightNode_;
						tempNodes_->right_ = this->root_->right_;
						tempNodes_->left_ = this->root_->left_;
						this->root_ = tempNodes_;
					}
					delete currentNode_;
				}
			}
		}
	}



















