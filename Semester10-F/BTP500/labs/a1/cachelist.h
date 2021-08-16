/*******************************************************************/
/*                                                                 */
/*  A1 Part 2: CacheList starter file                              */
/*                                                                 */
/*  Author1 Name: Khai Phan		 							       */
/*      - class/function list                                      */
/*  Student number: 100901164                                      */
/*  Due Date: Oct 19 (+1 week extension)                           */
/*                                                                 */        
/*  version 1.1: minor changes to add {} so that it compiles       */
/*               without syntax errors as is with tester           */
/*******************************************************************/
#include <iostream>

template <typename T>
class CacheList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		int access_ = 0;
		Node(const T& data=T{}, Node* next=nullptr, Node* prev=nullptr){
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;   //first temp value in Sentinel
	Node* back_;    //last temp value in Sentinel
    int counter_;       //to keep track the size of array

public:
	class const_iterator{
    protected:
		friend class CacheList;
		Node* curr_;
		const_iterator(Node* n) {   curr_ = n;  }
	public:
		const_iterator(){   curr_ = nullptr;    }
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
        const T& operator*()const   {   return this->curr_->data_;  }
	};
	
	class iterator:public const_iterator{
        protected:
			friend class CacheList;
            iterator(Node* curr):const_iterator(curr){}
        public:
            iterator() :const_iterator() {}
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
                this->curr_ = this->curr_->prev_;
                return *this;
            }
            iterator operator--(int){
                iterator old = *this;
                this->curr_ = this->curr_->prev_;
                return old;
            }
            T& operator*()              {   return this->curr_->data_;  }
            const T& operator*()const   {   return this->curr_->data_;  }
        };

	CacheList();
	~CacheList();
	CacheList(const CacheList& rhs);
	CacheList& operator=(const CacheList& rhs);
	CacheList(CacheList&& rhs);
	CacheList& operator=(CacheList&& rhs);
	void insert(const T& data);
	iterator search(const T& data);
	iterator erase(iterator it);
	iterator erase(iterator first, iterator last);
	void merge(CacheList& other);
	bool empty() const;
	int size() const;
	
	const_iterator cbegin() const   {   return const_iterator(this->front_->next_);   }
    iterator begin()                {   return iterator(this->front_->next_);         }
    const_iterator cend() const     {   return const_iterator(this->back_);           }
    iterator end()                  {   return iterator(this->back_);                 }
};

//completed
template <typename T>
CacheList<T>::CacheList(){
	front_ = new Node();
	back_ = new Node();
	front_->next_ = back_;
    front_->prev_ = nullptr;
	back_->prev_ = front_;
    back_->next_ = nullptr;
    this->counter_ = 0;
}

//completed
template <typename T>
CacheList<T>::~CacheList(){
    //set position of node
    Node* temp = front_;
    //check if temp exist or not
    while (temp) {
        Node* rm = temp;
        temp = temp->next_;
        delete rm;
    }
}

//completed
template <typename T>
CacheList<T>::CacheList(const CacheList& rhs){
    this->front_ = new Node();
    this->back_ = new Node();
    this->front_->next_ = this->back_;
    this->back_->prev_ = this->front_;

    Node* temp = rhs.front_->next_;
    int count = 0;
    while (temp != rhs.back_) {
        insert(temp->data_);
        temp = temp->next_;
        count++;
    }
    if (count == rhs.counter_)
        this->counter_ = rhs.counter_;
}

//completed
template <typename T>
CacheList<T>& CacheList<T>::operator=(const CacheList& rhs){
    if (this == &rhs)
        return *this;
    else {
        this->front_ = new Node();
        this->back_ = new Node();
        this->front_->next_ = this->back_;
        this->back_->prev_ = this->front_;

        Node* temp = rhs.front_->next_;
        int count = 0;
        while (temp != rhs.back_) {
            insert(temp->data_);
            temp = temp->next_;
            count++;
        }
        if (count == rhs.counter_)
            this->counter_ = rhs.counter_;
    }
    return *this;
}

//completed
template <typename T>
CacheList<T>::CacheList(CacheList&& rhs){
    this->front_ = new Node();
    this->back_ = new Node();
    this->front_->next_ = this->back_;
    this->back_->prev_ = this->front_;

    Node* temp1 = rhs.front_->next_;
    Node* temp2 = rhs.front_;
    int count = 0;
    if (temp1) {
        while (temp1 != rhs.back_) {
            insert(temp1->data_);
            temp2 = temp1->next_;
            temp1 = nullptr;
            temp1 = temp2;
            count++;
        }
        if (count == rhs.counter_)
            this->counter_ = rhs.counter_;
    }
}

//completed
template <typename T>
CacheList<T>& CacheList<T>::operator=(CacheList&& rhs){
    if (this == &rhs)
        return *this;
    else {
        this->front_ = new Node();
        this->back_ = new Node();
        this->front_->next_ = this->back_;
        this->back_->prev_ = this->front_;

        Node* temp1 = rhs.front_->next_;
        Node* temp2 = rhs.front_;
        int count = 0;
        if (temp1) {
            while (temp1 != rhs.back_) {
                insert(temp1->data_);
                temp2 = temp1->next_;
                temp1 = nullptr;
                temp1 = temp2;
                count++;
            }
            if (count == rhs.counter_)
                this->counter_ = rhs.counter_;
        }   
    }
    return *this;  
}

//completed
template <typename T>
void CacheList<T>::insert(const T& data){
    Node* nn = new Node(data, back_, back_->prev_);
    back_->prev_->next_ = nn;
    back_->prev_ = nn;
    this->counter_++;
}

//completed
template <typename T>
typename CacheList<T>::iterator CacheList<T>::search(const T& data){
    //set value in case nothing is found
    iterator search_ = end();
    Node* current_ = this->front_->next_;
    bool check_ = false;
    
    if (!this->empty()) {
        while (current_ != this->back_) {
            if (current_->data_ == data) {
                current_->access_++;         

                //check if previous is not front (empty node) and
                //current access is >= previous node
                do {
                    if ((current_->access_ >= current_->prev_->access_) && (current_->prev_ != this->front_)) 
                    {
                            //arrange the position of the node
                            current_->prev_->next_ = current_->next_;
                            current_->next_ = current_->prev_;
                            current_->prev_ = current_->next_->prev_;
                            current_->next_->prev_ = current_;
                            current_->prev_->next_ = current_;
                            current_->next_->next_->prev_ = current_->next_; 
                    }
                    else { check_ = true;   }
                       
                } while (check_ == false);
                search_ = iterator(current_);
                break;
            }
            current_ = current_->next_;
        }    
    }
    return search_;
}

//completed
template <typename T>
typename CacheList<T>::iterator CacheList<T>::erase(iterator it) {
    Node* rm = it.curr_;

    if (!this->empty()) {
        if (rm != front_) {
            /*
             //TESTING PURPOSE
            iterator erase_ = begin();
            std::cout << "Object: " << it.curr_->data_ << std::endl;
            std::cout << "Before delete: ";
            while (erase_ != end()) {
                erase_++;
                std::cout << erase_.curr_->data_ << " , ";
            }
            std::cout << std::endl;
            */
          
            rm->prev_->next_ = rm->next_;
            rm->next_->prev_ = rm->prev_;
            it++;
            this->counter_--;
            delete rm;
        }
    }
    return it;
}

//completed
template <typename T>
typename CacheList<T>::iterator CacheList<T>::erase(iterator first, iterator last){
    Node* nodeFirst_ = first.curr_;
    Node* nodeLast_ = last.curr_;

    if (!this->empty()) {
        if (nodeFirst_ != front_) {
            /*
            //TESTING PURPOSE
            iterator erase_ = begin();
            std::cout << "Object: " << first.curr_->data_ << " , " << last.curr_->data_ << std::endl;
            std::cout << "Before delete: ";
            while (erase_ != end()) {
                erase_++;
                std::cout << erase_.curr_->data_ << " , ";
            }
            std::cout << std::endl;
            */

            //connect the prev_ node of the first one being remove
            //to the last iterator (which does not remove)
            nodeFirst_->prev_->next_ = nodeLast_;
            nodeLast_->prev_ = nodeFirst_->prev_;
            
            while (nodeFirst_ != nodeLast_) {
                Node* rm = nodeFirst_;
                nodeFirst_ = nodeFirst_->next_;
                
                delete rm;
                this->counter_--;
            }
        } 
    }  
    return last;
}

//completed
template <typename T>
void CacheList<T>::merge(CacheList& other) {
  
    //if other contain data
    if (!other.empty()) {
        Node* mCurrent_ = front_->next_;
        Node* mOther_ = other.front_->next_;

        //if current list contain data
        if (!this->empty()) {
            //if other list doesn't reached to back, keep doing  
            /*
            //display value of current
            std::cout << "Current: " << std::endl;
            for (int a = 0; a < this->counter_; a++) {
                std::cout << a + 1 << ":" << mCurrent_->data_ << "," << mCurrent_->access_ << std::endl;
                mCurrent_ = mCurrent_->next_;
            }
            mCurrent_ = back_->prev_->next_;
            //display value of other
            std::cout << "Other: " << std::endl;
            for (int a = 0; a < other.counter_; a++) {
                std::cout << a + 1 << ":" << mOther_->data_ << "," << mOther_->access_ << std::endl;
                mOther_ = mOther_->next_;
            }
            mOther_ = other.front_->next_;
            */
            while ((mOther_ != other.back_)) {
                Node* mOtherTemp_ = other.front_;
                if (mOther_->next_ != nullptr)
                    mOtherTemp_ = mOther_->next_;

                //if other list access_ is larger than current
                if (mCurrent_->access_ < mOther_->access_) {
                    //unlinked the node
                    mOther_->prev_->next_ = mOther_->next_;
                    mOther_->next_->prev_ = mOther_->prev_;
                    //relinked the new node
                    mOther_->prev_ = mCurrent_->prev_;
                    mOther_->next_ = mCurrent_;
                    //relink front_ and back_ of current
                    mCurrent_->prev_->next_ = mOther_;
                    mCurrent_->prev_ = mOther_;

                    this->counter_++;
                    mOther_ = mOtherTemp_;       
                }

                //if current list reached back
                //push everything left to the list
                else if (mCurrent_ == this->back_) { 
                    if (mCurrent_->access_ > mOther_->access_) {
                        //unlinked the node
                        mOther_->prev_->next_ = mOther_->next_;
                        mOther_->next_->prev_ = mOther_->prev_;
                        //relinked the new node
                        mOther_->prev_ = mCurrent_->prev_;
                        mOther_->next_ = mCurrent_;
                        //relink front_ and back_ of current
                        mCurrent_->prev_->next_ = mOther_;
                        mCurrent_->prev_ = mOther_;

                        this->counter_++;
                        mCurrent_ = mCurrent_->prev_;
                        mOther_ = mOtherTemp_;
                    }
                }
                //if current list access_ is still greater than others
                else {  mCurrent_ = mCurrent_->next_;   }
            }
            /*
            //display value of current
            mCurrent_ = front_->next_;
            std::cout << "Current: " << std::endl;
            for (int a = 0; a < this->counter_; a++) {
                std::cout << a + 1 << ":" << mCurrent_->data_ << "," << mCurrent_->access_ << std::endl;
                mCurrent_ = mCurrent_->next_;
            }

            //display value of other
            mOther_ = other.front_->next_;
            std::cout << "Other: " << std::endl;
            for (int a = 0; a < other.counter_; a++) {
                std::cout << a + 1 << ":" << mOther_->data_ << "," << mOther_->access_ << std::endl;
                mOther_ = mOther_->next_;
            }   
            */
        }

        //if current list contain only front_ and back_
        else {
            while (mOther_ != other.back_) {
                Node* temp = mOther_->next_;
                //unlinked the node
                mOther_->next_->prev_ = mOther_->prev_;
                mOther_->prev_->next_ = mOther_->next_;
                //relink the node (add front of mCurrent)
                mOther_->prev_ = mCurrent_->prev_;
                mOther_->next_ = mCurrent_;
                //relink front_ and back_ of current
                mCurrent_->prev_ = mOther_;
                mCurrent_->prev_->next_ = mOther_;

                mCurrent_ = mOther_;
                this->counter_++;

                //std::cout << "Other: " << mOther_->data_ << "," << mOther_->access_ << std::endl;
                //std::cout << "Current: " << mCurrent_->data_ << "," << mCurrent_->access_ << std::endl;
                
                mOther_ = temp;
                mCurrent_ = mCurrent_->next_;
            }
        }

        other.front_->next_ = other.back_;
        other.back_->prev_ = other.front_;
        other.counter_ = 0;
        //std::cout << "Other size: " << other.size() << std::endl;
        //std::cout << "Current size: " << this->size() << std::endl;
    }
}

//completed
template <typename T>
bool CacheList<T>::empty() const{
    if (front_->next_ == back_ && back_->prev_ == front_)
        return true;
    return false;
}

//completed
template <typename T>
int CacheList<T>::size() const{
    return this->counter_;
}
