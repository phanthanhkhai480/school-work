#include <iostream>
#include <iomanip>

/*forward declaration*/
template <class T>
class Queue;

template <class T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data, Node* lt=nullptr, Node* rt=nullptr){
			data_=data;
			left_=lt;
			right_=rt;
		}
	};

	Node* root_;
	
	void printPreOrder(Node* subroot)const{
		if(subroot){
			std::cout << subroot->data_ << " ";		
			printPreOrder(subroot->left_);
			printPreOrder(subroot->right_);
		}
	}
	void printInOrder(Node* subroot)const{
		if(subroot){
			printInOrder(subroot->left_);
			std::cout << subroot->data_ << " ";
			printInOrder(subroot->right_);
		}
	}
	void destroy(Node* subroot){
		if(subroot){
			destroy(subroot->left_);
			destroy(subroot->right_);
			delete subroot;
		}
	}
	bool isSame(const Node* left, const Node* right) const;

	/*used by print() to print all nodes at same level*/
	void printLine(Node* data[],int numNodes,int width) const{
		int half=width/2;
		int firsthalf=width%2?half+1:half;

		if(numNodes > 1){
			for(int i=0;i<numNodes;i++){
				if(i%2==0){
					if(data[i]){
						std::cout << std::right <<std::setfill(' ') << std::setw(firsthalf)<< "-";
						std::cout << std::left << std::setfill('-') << std::setw(half) << "-";
					}
					else{
						std::cout << std::right <<std::setfill(' ') << std::setw(firsthalf)<< " ";
						std::cout << std::left << std::setfill(' ') << std::setw(half) << " ";
					}
				}
				else{
					if(data[i]){
						std::cout << std::right << std::setfill('-') << std::setw(firsthalf) << "-";
						std::cout << std::left <<std::setfill(' ') << std::setw(half)<<"-";
					}
					else{
						std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
						std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
					}
				}
			}
			std::cout << std::endl;
		}
		for(int i=0;i<numNodes;i++){
			if(data[i]){
				if(i%2==0){
					std::cout << std::right << std::setw(firsthalf) << "|";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
				}
				else{
					std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<< "|";				
				}
			}
			else{
				std::cout << std::left <<std::setfill(' ') << std::setw(width)<<" ";			
			}
		}
		std::cout << std::endl;		
		for(int i=0;i<numNodes;i++){
			if(data[i]){
				if(i%2==0){
					std::cout << std::right << std::setw(firsthalf) << data[i]->data_;
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<<" ";
				}
				else{
					std::cout << std::right << std::setfill(' ') << std::setw(firsthalf) << " ";
					std::cout << std::left <<std::setfill(' ') << std::setw(half)<< data[i]->data_;				
				}
			}
			else{
				std::cout << std::left <<std::setfill(' ') << std::setw(width)<<" ";			
			}
		}
		std::cout << std::endl;

	}

public:
	BST(){	root_ = nullptr;	}
	BST(const BST& rhs){		
		if ((this != &rhs) && (rhs.root_ != nullptr)) {
			//clear out current data before copying in
			root_ = nullptr;
			copy(rhs.root_);
		}	
	}

	void copy(Node* node) {
		if (node != nullptr) {
			insert(node->data_);
			//loop to copy the data
			copy(node->left_);
			copy(node->right_);
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
	int depth(const T& data) {
		Node* currentNode_ = root_;
		int depth_ = -1;

		if (root_ == nullptr)
			return -1;
		else {
			while (currentNode_ != nullptr) {
				depth_++;
				if (data == currentNode_->data_)
					return depth_;
				//if data is smaller than current Node data
				else if (data < currentNode_->data_) {	
					if (currentNode_->left_ != nullptr)
						currentNode_ = currentNode_->left_;
					else	
						break;
				}
				//if data is larger than current Node data
				else {
					if (currentNode_->right_ != nullptr)
						currentNode_ = currentNode_->right_;
					else
						break;
				}
			}
		}
		return -1;
	}

	void printPreOrder() const{
		printPreOrder(root_);
		std::cout << std::endl;
	}
	void printInOrder() const{
		printInOrder(root_);
		std::cout << std::endl;
	}
	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{

			Node* curr=root_;
			while(curr != nullptr){
				if(data < curr->data_){
					//go left
					if(curr->left_){
						curr=curr->left_;
					}
					else{
						curr->left_=new Node(data);
						curr=nullptr;
					}
				}	
				else{
					//go right
					if(curr->right_){
						curr=curr->right_;
					}
					else{
						curr->right_=new Node(data);
						curr=nullptr;
					}
				}
			}

		}

	}
	bool operator==(const BST& rhs) const;
	void print() const{
		struct Output{
			Node* node_;
			int lvl_;
			int position_;
			Output(Node* n=nullptr,int l=0, int p=0){
				node_=n;
				lvl_=l;
				position_=p;
			}
			void set(Node* n=nullptr,int l=0, int p=0){
				node_=n;
				lvl_=l;
				position_=p;
			}
		};
		Queue<Output> theNodes;
		Node* line[16];
		if(root_){
			for(int i=0;i<16;i++){
				line[i]=nullptr;
			}
			theNodes.enqueue(Output(root_,0,0));
			int currline=0;
			int width=80;
			int numInLine=1;
			while(theNodes.isEmpty()==false){
				Output curr=theNodes.front();
				if(curr.node_->left_)
					theNodes.enqueue(Output(curr.node_->left_,curr.lvl_+1,curr.position_*2));
				if(curr.node_->right_)
					theNodes.enqueue(Output(curr.node_->right_,curr.lvl_+1,curr.position_*2+1));
				theNodes.dequeue();


				if(curr.lvl_>currline){
					printLine(line,numInLine,width);
					width=width/2;
					numInLine=numInLine*2;
					for(int i=0;i<16;i++){
						line[i]=nullptr;
					}
					currline++;

				}
				line[curr.position_]=curr.node_;
			}
			printLine(line,numInLine,width);
			std::cout << std::endl;

		}
		else{
			std::cout << "tree is empty" << std::endl;
		}
	}
	~BST(){	destroy(root_);	}
};

template <class T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	int front_;
	int back_;
	void grow(){
		T* tmp=new T[capacity_*2];
		int j;
		for(int i=0,j=front_;i<used_;i++,j=(j+1)%capacity_){
			tmp[i]=theQueue_[j];
		}
		delete [] theQueue_;
		theQueue_=tmp;
		capacity_=capacity_*2;
		front_=0;
		back_=used_;
	}
public:
	Queue(){
		theQueue_=new T[50];
		capacity_=50;
		used_=0;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}
		theQueue_[back_]=data;
		back_=(back_+1)%capacity_;
		used_++;
	}
	void dequeue(){
		if(!isEmpty()){
			used_--;
			front_=(front_+1)%capacity_;
		}
	}
	T front() const{
		if(!isEmpty()){
			return theQueue_[front_];
		}
		return T{};

	}
	bool isEmpty() const{
		return used_==0;
	}
	~Queue(){
		delete [] theQueue_;
	}	
};
