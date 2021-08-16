
	int BST::findSmallest(int v){
		Node* temp_ = root_;
		//first check the existance of node before going any further
		if(temp_ != nullptr)
		{
			while(true){
				//if v is equal than current node data
				//go find the smallest possble value
				if(v == temp_->data_){
					if(temp_->left_)
						temp_ = temp_->left_;
					else
						return temp_->data;
				}
					
				//if v is larger than current node data
				//go right
				else if(v > temp_->data_)
					temp_ = temp_->right_;
				//if v is smaller than current node data
				//go left
				else if (v < temp_->data_)
					temp_ = temp_->left;
			}			
		}	
		return -1;
	}
	
	
	
		
	int BST::count() const{
		Node* temp_ = root_;
		int count_ = 0;
		if(temp_ != nullptr){
		    counter(temp_, count_);	
		}
		return count_;
	}
	
	void BST::counter(Node* node_, int num_){
		if(node_->left_){
			num_++;
			node_ = node_->left_;
			counter(node_, num_);
		}
		if(node_->right_){
			num_++;
			node_ = node_->right_;
			counter(node_, num_);
		}
	}