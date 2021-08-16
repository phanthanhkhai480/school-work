/**************************************************/
/*                                                */
/*  Lab 4 Starter file                            */
/*                                                */
/*  Namei Khai Phan                               */
/*  Student number: 100901164                     */
/*  Due Date: Oct 16                              */
/*                                                */
/**************************************************/

#include <iostream>

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList(){
		front_ = nullptr;
		back_ = nullptr;
	} 
	void push_front(const T& data);
	~DList();

	class const_iterator{
	protected:
		friend class DList;
		const DList* myList_;
		Node* curr_;
		
		const_iterator(Node* n, const DList* list) {
			this->curr_ = n;
			this->myList_ = list;
		}
	public:
		const_iterator() {
			this->curr_ = nullptr;
			this->myList_ = nullptr;
		}
		//++ then return the value of that node
		const_iterator operator++(){
			if(this->curr_){
				this->curr_ = this->curr_->next_;
			}		
			else {
				if(this->myList_){
					this->curr_ = this->myList_->front_;
				}
			}
           		return *this;
		}
		//return the value of the node, then ++
		const_iterator operator++(int){
			const_iterator old=*this;
            		if(this->curr_) {
				this->curr_ = this->curr_->next_;
			}
			else{
				if(this->myList_){
					this->curr_ = this->myList_->front_;
				}
			}
            		return old;
		}
		const_iterator operator--(){
			if(this->curr_){
                		this->curr_ = this->curr_->prev_;
            		}
            		else{
                		if(this->myList_){
                    			this->curr_ = this->myList_->back_;
              	  		}
            		}
            		return *this;
		}
		const_iterator operator--(int){
			const_iterator old=*this;
            		if(this->curr_){
                		this->curr_ = this->curr_->prev_;
            		}
            		else{
                		if(this->myList_){
                    			this->curr_ = this->myList_->back_;
                		}	
            		}
            		return old;        
		}
		bool operator==(const_iterator rhs) const{
         		if(this->myList_ == rhs.myList_ && this->curr_ == rhs.curr_)
                		return true;
            		return false;
		}
		bool operator!=(const_iterator rhs) const{
			if(this->myList_ != rhs.myList_ || this->curr_ != rhs.curr_)
				return true;
			return false;
		}
		const T& operator*()const{
			return this->curr_->data_;
		}
	};
	class iterator:public const_iterator{
		friend class DList;
		iterator(Node* curr, DList* theList):const_iterator(curr, theList){}	
	public:
		iterator():const_iterator(){}
        	iterator operator++(){
			this->curr_ = this->curr_->next_;
			return *this;	
		}   
        	iterator operator++(int){
			iterator old = *this;
			this->curr_ = this->curr_->next_;
			return old;
		}
        	iterator operator--(){
			this -> curr_ = this -> curr_ ->prev_;
		        return *this;	
		}
        	iterator operator--(int){
			iterator old = *this;
			this -> curr_ = this -> curr_ -> prev_;
			return old;
		}
        	T& operator*(){		
			return this->curr_->data_;	
		}
        	const T& operator*() const{	
			return this->curr_->data_;	
		} 
	};

	const_iterator cbegin() const{
		return const_iterator(front_,this);
	}
    	const_iterator cend() const{
		return const_iterator(nullptr,this);
	}
    	iterator begin(){
		return iterator(front_,this);
	}
    	iterator end(){
		return iterator(nullptr,this);
	}	        
};


template <typename T>
void DList<T>::push_front(const T& data){
	Node* nn=new Node(data,front_);
	if(front_!=nullptr)
		front_->prev_=nn;
	else
	        back_=nn;
		front_=nn;
}

template <typename T>
DList<T>::~DList(){
	front_ = nullptr;
	back_ = nullptr;
}


template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	~Sentinel();

	class const_iterator{
		friend class Sentinel;
		Node* curr_;
		const_iterator(Node* n) {
			curr_ = n;
		}
	public:
		const_iterator(){
			curr_ = nullptr;
		}
		
		const_iterator operator++(){
			curr_ = curr_->next_;
			return *this;
		}
		const_iterator operator++(int){
			const_iterator old = *this;
			curr_ = curr_->next_;
			return old;
		}
		const_iterator operator--(){
			curr_ = curr_->prev_;
			return *this;
		}
		const_iterator operator--(int){
			const_iterator old = *this;
			curr_ = curr_->prev_;
			return old;
		}
		bool operator==(const_iterator rhs){
			if(this->curr_ == rhs.curr_)
				return true;
			return false;
		}
		bool operator!=(const_iterator rhs){
			if(this->curr_ != rhs.curr_)
				return true;
			return false;
		}
		const T& operator*()const{
			return this->curr_->data_;
		}
	};
	class iterator:public const_iterator{
		friend class Sentinel;
		iterator(Node* curr):const_iterator(curr){}
	public:
		iterator();
		iterator operator++(){
			this -> curr_ = this -> curr_ ->next_;
			return *this;
		}
		iterator operator++(int){
			iterator old  = *this;
		        this -> curr_ = this -> curr_ -> next_;
			return old;       
		}
		iterator operator--(){
			this->curr_ = this->curr_->prev;
			return *this;
		}
		iterator operator--(int){
			iterator old = *this;
			this->curr_ = this->curr_->prev_;
			return old;
		}
		T& operator*(){
			return this->curr_->data_;
		}
		const T& operator*()const{
			return this->curr_->data_;
		}
	};
	const_iterator cbegin() const{
		return const_iterator(front_->next_);
	}
	iterator begin(){
		return iterator(front_->next_);
	}
	const_iterator cend() const{
		return const_iterator(back_);
	}
	iterator end(){
		return iterator(back_);
	}
};


template <typename T>
void Sentinel<T>::push_front(const T& data){
	Node* nn = new Node(data,front_->next_,front_);
        front_->next_->prev_=nn;
	front_->next_=nn;
}


template <typename T>
Sentinel<T>::~Sentinel(){
	front_->next_ = back_;
	back_->prev_ = front_;
}
