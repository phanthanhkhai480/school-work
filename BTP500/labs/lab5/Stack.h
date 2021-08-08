#include <iostream>

template<typename T>
class LStack {
	struct Node {
		friend class LStack;
		T data_;
		Node* next_;
		Node(T data, Node* n = nullptr) {
			data_ = data;
			next_ = n;
		}
	};
	Node* first_;
public:
	LStack() {		first_ = nullptr;	}
	void push(T data);
	void pop();
	bool isEmpty();
	T top();
	void initialize();
	void print();
	~LStack();
};

template<typename T>
void LStack<T>::push(T data) {
	Node* nn = new Node(data);
	if (first_ == nullptr) {
		first_ = nn;
	}
	else {
		nn->next_ = first_;
		first_ = nn;
	}
}

template<typename T>
void LStack<T>::pop() {
	if (first_) {
		Node* curr = first_;
		first_ = first_->next_;
		delete curr;
	}
}

template<typename T>
bool LStack<T>::isEmpty() {
	if (first_ == nullptr) return true;
	return false;
}

template<typename T>
T LStack<T>::top() {
	if (first_) return first_->data_;
	return {};
}

template <typename T>
void LStack<T>::initialize() {
	Node* curr = first_;
	while (curr) {
		Node* rm = curr;
		curr = curr->next_;
		delete rm;
	}
}

template<typename T>
void LStack<T>::print() {
	Node* curr = first_;
	while (curr) {
		std::cout << curr->data_ << std::endl;
		curr = curr->next_;
	}
}

template <typename T>
LStack<T>::~LStack() {
	Node* curr = first_;
	while (curr) {
		Node* rm = curr;
		curr = curr->next_;
		delete rm;
	}
}
