#include <string>
const int MAX_DATA = 1000;

class Stack {
	std::string data[MAX_DATA];
	int count;
public:
	Stack() { count = 0; memset(data, 0, sizeof(data)); }
	
	void push(std::string mdata_) {
		if (count < MAX_DATA - 1) {
			for (int i = count; i > 0; --i) data[i] = data[i - 1];
				data[0] = mdata_;
			count++;
		}
	}
	
	void pop() {
		if (count > 0) {
			--count;
			for (int i = 0; i < count; ++i) data[i] = data[i + 1];
			data[count] = nullptr;
		}
	}
	
	std::string top() {		return data[0];		}
	
	bool isEmpty() {	return count == 0;		}
};