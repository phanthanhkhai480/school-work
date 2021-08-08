//List.h - non-sentinel doubly-linked self adjusting list
//
// 17-Oct-20  M. Watler   Created.
#include <iostream>

template <typename T>
class SelfAdjustingList {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	SelfAdjustingList() {
		front_ = nullptr;
		back_ = nullptr;
	}
	void push_front(const T& data);
	~SelfAdjustingList();

	class const_iterator {
		friend SelfAdjustingList;
	protected:
		Node* curr_;
		const SelfAdjustingList* list_;
		const_iterator(Node* n, const SelfAdjustingList* l) {
			curr_ = n;
			list_ = l;
		}
	public:
		const_iterator() {
			curr_ = nullptr;
			list_ = nullptr;
		}
		const_iterator operator++() {
			curr_ = curr_->next_;
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator rc = *this;
			curr_ = curr_->next_;
			return rc;
		}
		const_iterator operator--() {
			if (curr_) {
				curr_ = curr_->prev_;
			}
			else {
				if (list_)
					curr_ = list_->back_;
			}
			return *this;
		}
		const_iterator operator--(int) {
			const_iterator rc = *this;
			if (curr_) {
				curr_ = curr_->prev_;
			}
			else {
				if (list_)
					curr_ = list_->back_;
			}
			return rc;

		}
		bool operator==(const_iterator rhs) {
			return curr_ == rhs.curr_ && list_ == rhs.list_;
		}
		bool operator!=(const_iterator rhs) {
			return !(curr_ == rhs.curr_ && list_ == rhs.list_);
		}
		const T& operator*()const {
			return curr_->data_;
		}
	};
	class iterator :public const_iterator {
		friend SelfAdjustingList;
		iterator(Node* n, SelfAdjustingList* l) :const_iterator(n, l) {}
	public:
		iterator() :const_iterator() {
		}
		iterator operator++() {
			this->curr_ = this->curr_->next_;
			return *this;

		}
		iterator operator++(int) {
			iterator rc = *this;
			this->curr_ = this->curr_->next_;
			return rc;
		}
		iterator operator--() {
			if (this->curr_) {
				this->curr_ = this->curr_->prev_;
			}
			else {
				if (this->list_)
					this->curr_ = this->list_->back_;
			}
			return *this;
		}
		iterator operator--(int) {
			iterator rc = *this;
			if (this->curr_) {
				this->curr_ = this->curr_->prev_;
			}
			else {
				if (this->list_)
					this->curr_ = this->list_->back_;
			}
			return rc;
		}
		T& operator*() {
			return this->curr_->data_;
		}
		const T& operator*()const {
			return this->curr_->data_;
		}

	};
	const_iterator cbegin() const {
		return const_iterator(front_, this);
	}
	iterator begin() {
		return iterator(front_, this);
	}
	const_iterator cend() const {
		return const_iterator(nullptr, this);

	}
	iterator end() {
		return iterator(nullptr, this);
	}

	// Solution to question 9
	template <typename T>
	iterator search(const T& v) {
		Node* curr = front_->next_;//If v is at the front, we won't move it, so we
								   //start our search from the next to front node
		Node* currprev = front_;
		while (curr != nullptr && curr->data_ != v) {//For non-sentinel nodes, the back is a nullptr
			currprev = curr;
			curr = curr->next_;
		}
		if (curr != nullptr) {
			//unlink curr
			currprev->next_ = curr->next_;
			if (curr->next_)	curr->next_->prev_ = curr->prev_;

			//insert curr at the front
			front_->prev_ = curr;
			curr->next_ = front_;
			front_ = curr;
			curr->prev_ = nullptr;
		}
		return iterator(curr, this);
	}

};


template <typename T>
void SelfAdjustingList<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_);
	if (front_) {
		front_->prev_ = nn;
	}
	else {
		back_ = nn;
	}
	front_ = nn;
}


template <typename T>
SelfAdjustingList<T>::~SelfAdjustingList() {

}
