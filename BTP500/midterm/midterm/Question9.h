//Question9.h: Source code for the programming section of the MidTerm (Question 9)
//             For the non-sentinel version, enter code from lines 161 (moveToBack) and 166 (eraseFirstBiggerThan).
//             For the sentinel version, enter code from lines 293 (moveToBack) and 298 (eraseFirstBiggerThan).

#include <iostream>

template <typename T>
class DList {
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
	DList() {
		front_ = nullptr;
		back_ = nullptr;
	}
	void push_front(const T& data);
	~DList();

	class const_iterator {
		friend DList;
	protected:
		Node* curr_;
		const DList* list_;
		const_iterator(Node* n, const DList* l) {
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
		friend DList;
		iterator(Node* n, DList* l) :const_iterator(n, l) {}
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
	void moveToBack(iterator it);
	bool eraseFirstBiggerThan(int val);
};


template <typename T>
void DList<T>::push_front(const T& data) {
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
void DList<T>::moveToBack(iterator it) {
	//Enter code here for non-sentinel version
}

template <typename T>
bool DList<T>::eraseFirstBiggerThan(int val) {
	//Enter code here for non-sentinel version
	return true;
}


template <typename T>
DList<T>::~DList() {

}
template <typename T>
class Sentinel {
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
	Sentinel() {
		front_ = new Node();
		back_ = new Node();
		front_->next_ = back_;
		back_->prev_ = front_;
	}
	void push_front(const T& data);
	~Sentinel();

	class const_iterator {
		friend Sentinel;
	protected:
		Node* curr_;
		const_iterator(Node* n) {
			curr_ = n;
		}
	public:
		const_iterator() {
			curr_ = nullptr;
		}
		const_iterator operator++() {
			this->curr_ = this->curr_->next_;
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator rc = *this;
			this->curr_ = this->curr_->next_;
			return rc;
		}
		const_iterator operator--() {
			this->curr_ = this->curr_->prev_;
			return *this;
		}
		const_iterator operator--(int) {
			const_iterator rc = *this;
			this->curr_ = this->curr_->prev_;
			return rc;
		}
		bool operator==(const_iterator rhs) {
			return this->curr_ == rhs.curr_;
		}
		bool operator!=(const_iterator rhs) {
			return this->curr_ != rhs.curr_;
		}
		const T& operator*()const {
			return curr_->data_;
		}
	};
	class iterator :public const_iterator {
		friend Sentinel;
		iterator(Node* n) :const_iterator(n) {}
	public:
		iterator() :const_iterator() {}
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
			this->curr_ = this->curr_->prev_;
			return *this;
		}
		iterator operator--(int) {
			iterator rc = *this;
			this->curr_ = this->curr_->prev_;
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
		return const_iterator(front_->next_);
	}
	iterator begin() {
		return iterator(front_->next_);
	}
	const_iterator cend() const {
		return const_iterator(back_);
	}
	iterator end() {
		return iterator(back_);
	}
	void moveToBack(iterator it);
	bool eraseFirstBiggerThan(int val);
};


template <typename T>
void Sentinel<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_->next_, front_);
	front_->next_ = nn;
	nn->next_->prev_ = nn;
}

template <typename T>
void Sentinel<T>::moveToBack(iterator it) {
	//Enter code here for the sentinel version
	std::cout << "Move to Back code" << std::endl;
	std::cout << "value to move is: " << it.curr_->data_ << std::endl;
	it.curr_->prev_->next_ = it.curr_->next_;
	it.curr_->next_->prev_ = it.curr_->prev_;
	it.curr_->next_ = back_;
	it.curr_->prev_ = back_->prev_;
	
	back_->prev_ = it.curr_;
	back_->prev_->next_ = it.curr_;
}

template <typename T>
bool Sentinel<T>::eraseFirstBiggerThan(int val) {
	//Enter code here for the sentinel version
	std::cout << "Erase First Bigger Than code" << std::endl;
	std::cout << "Val is: " << val << std::endl;
	Node* temp = front_->next_;
	while (temp->data_ > val) {
		Node* rm = temp;
		rm->prev_->next_ = rm->next_;
		rm->next_->prev_ = rm->prev_;
		temp = temp->next_;
		delete rm;
		return true;
	}
	return false;
}

template <typename T>
Sentinel<T>::~Sentinel() {

}
#pragma once
