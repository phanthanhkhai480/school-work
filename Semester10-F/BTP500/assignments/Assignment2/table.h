/*************************************************************/
/*                                                           */
/*    starter file for a2                                    */
/*                                                           */
/*    v1.2: fixed comparison in simpletable::update...       */
/*          note this has no affect on compilation           */
/*          or analysis                                      */
/*    v1.1: fixed typo in simple table update removed _      */
/*          from variable name                               */
/*************************************************************/

#include <string>
#include <utility>
#include <iostream>
using namespace std;

template <class TYPE>
class Table {
public:
	Table() {}
	//replace value (if key exists), otherwise add new
	virtual void update(const std::string& key, const TYPE& value) = 0;
	//remove if key found on table
	virtual bool remove(const std::string& key) = 0;
	//find the value with matching key and return its value
	virtual bool find(const std::string& key, TYPE& value) = 0;
	//# of recs on table
	virtual int numRecords() const = 0;
	virtual bool isEmpty() const = 0;
	virtual ~Table() {}
};

template <class TYPE>
class SimpleTable :public Table<TYPE> {

	struct Record {
		TYPE data_;
		std::string key_;
		Record(const std::string& key, const TYPE& data) {
			key_ = key;
			data_ = data;
		}

	};

	Record** records_;   //the table
	int capacity_;       //capacity of the array

	void grow() {			//O(n): 6n
		Record** tmp = new Record * [capacity_ + 10];		//1
		for (int i = 0; i < capacity_; i++) {				//1 + (n-1) + (n-1)
			tmp[i] = records_[i];							//(n-1)
		}
		for (int i = capacity_; i < capacity_ + 10; i++) {	//1 + (n-1) + (n-1)
			tmp[i] = nullptr;								//(n-1)
		}
		delete[] records_;									//1
		records_ = tmp;										//1
		capacity_ += 10;									//1
	}														//T(n): 6n
															
public:	
	SimpleTable(int capacity);
	//copy constructor
	SimpleTable(const SimpleTable& rhs);
	//copy assignment operator
	SimpleTable(SimpleTable&& rhs);
	//replace value (if key exists), otherwise add new
	virtual void update(const std::string& key, const TYPE& value);
	//remove if key found on table
	virtual bool remove(const std::string& key);
	//find the value with matching key and return its value
	virtual bool find(const std::string& key, TYPE& value);
	//move contructor
	virtual const SimpleTable& operator=(const SimpleTable& rhs);
	//move assignment operator
	virtual const SimpleTable& operator=(SimpleTable&& rhs);
	//# of recs on table
	virtual int numRecords() const;
	virtual bool isEmpty() const { return numRecords() == 0; }
	virtual ~SimpleTable();
};

template <class TYPE>		//O(n): 3n
int SimpleTable<TYPE>::numRecords() const {
	int rc = 0;										//1
	for (int i = 0; records_[i] != nullptr; i++) {	//1 + (n-1) + (n-1)
		rc++;										//(n-1)
	}		
	return rc;										//1
}													//T(n): 3n
														
template <class TYPE>		//O(n): 3n
SimpleTable<TYPE>::SimpleTable(int capacity) : Table<TYPE>() {
	records_ = new Record * [capacity];		//1
	capacity_ = capacity;					//1
	for (int i = 0; i < capacity_; i++) {	//1 + (n-1) + (n-1)
		records_[i] = nullptr;				//(n-1)
	}										//T(n): 3n
}											
											
template <class TYPE>		//O(n): 11n
SimpleTable<TYPE>::SimpleTable(const SimpleTable<TYPE>& rhs) {
	records_ = new Record * [rhs.capacity_];					//1
	capacity_ = rhs.capacity_;									//1
	for (int i = 0; i < rhs.numRecords(); i++) {				//1 + (n-1) + (n-1)
		update(rhs.records_[i]->key_, rhs.records_[i]->data_);	//2 + 9n-1
	}															//T(n): 11n + 3
}																
																
template <class TYPE>		//O(n): 1
SimpleTable<TYPE>::SimpleTable(SimpleTable<TYPE>&& rhs) {
	capacity_ = rhs.capacity_;		//1
	records_ = rhs.records_;		//1
	rhs.records_ = nullptr;			//1
	rhs.capacity_ = 0;				//1
}									//T(n): 4
									
template <class TYPE>		//if true, O(n): 4n		//if false, O(n): 15n
void SimpleTable<TYPE>::update(const std::string& key, const TYPE& value) {
	int idx = -1;							//1
	int size = numRecords();				//1
	for (int i = 0; i < size; i++) {		//1 + (n-1) + (n-1)
		if (records_[i]->key_ == key) {		//(n-1)
			idx = i;						//(n-1)
		}
	}
	if (idx == -1) {						//1
		if (size == capacity_) {			//1
			grow();							//6n
		}
		records_[size++] = new Record(key, value);	//2
		for (int i = size - 1; i > 0 && records_[i]->key_ < records_[i - 1]->key_; i--) {	//1 + (n-1) + (n-1)
			Record* tmp = records_[i];		//(n-1)
			records_[i] = records_[i - 1];	//(n-1)
			records_[i - 1] = tmp;			//(n-1)
		}
	}
	else {									//1
		records_[idx]->data_ = value;		//2
	}										//if true,  T(n): 4n + 2
											//if false, T(n): 15n - 7				
}		

template <class TYPE>		//if true, O(n): 4n		//if false, O(n): 7n
bool SimpleTable<TYPE>::remove(const std::string& key) {
	int idx = -1;								//1
	for (int i = 0; i < numRecords(); i++) {	//1 + (n-1) + (n-1)
		if (records_[i]->key_ == key) {			//(n-1)
			idx = i;							//(n-1)
		}
	}
	if (idx != -1) {							//1
		int size = numRecords();				//1
		delete records_[idx];					//1
		for (int i = idx; i < size - 1; i++) {	//1 + (n-1) + (n-1)
			records_[i] = records_[i + 1];		//(n-1)
		}
		records_[size - 1] = nullptr;			//1
		return true;							//1
	}
	else {										//1
		return false;							//1
	}											//if true,  T(n): 4n
}												//if false, T(n): 7n + 1

template <class TYPE>		//if true, O(n): 4n		//if false, O(n): 4n
bool SimpleTable<TYPE>::find(const std::string& key, TYPE& value) {
	int idx = -1;								//1
	for (int i = 0; i < numRecords(); i++) {	//1 + (n-1) + (n-1)
		if (records_[i]->key_ == key) {			//(n-1)
			idx = i;							//(n-1)
		}
	}
	if (idx == -1)								//1
		return false;							//1
	else {										//1
		value = records_[idx]->data_;			//1
		return true;							//1
	}											//if true,  T(n): 4n + 1		
}												//if false, T(n): 4n

template <class TYPE>		//O(n): 13n
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(const SimpleTable<TYPE>& rhs) {
	if (this != &rhs) {								//1
		if (records_) {								//1
			while (numRecords() != 0) {				//(n-1)
				remove(records_[0]->key_);			//(n-1)
			}	
			delete[] records_;						//1
		}
		records_ = new Record * [rhs.capacity_];	//2
		capacity_ = rhs.capacity_;					//1

		for (int i = 0; i < rhs.numRecords(); i++) {//1 + (n-1) + (n-1)
			update(rhs.records_[i]->key_, rhs.records_[i]->data_);	//9n-1 + 2
		}

	}
	return *this;									//1
}													//T(n): 13n + 5
						
template <class TYPE>		//O(n): 1
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(SimpleTable<TYPE>&& rhs) {
	swap(records_, rhs.records_);		//1
	swap(capacity_, rhs.capacity_);		//1
	return *this;						//1
}										//T(n): 3

template <class TYPE>		//O(n): 9n
SimpleTable<TYPE>::~SimpleTable() {
	if (records_) {						//1
		int sz = numRecords();			//1
		for (int i = 0; i < sz; i++) {	//1 + (n-1) + (n-1)
			remove(records_[0]->key_);	//7n + 1
		}
		delete[] records_;				//1
	}									//T(n): 9n + 3
}



template <class TYPE>
class LPTable :public Table<TYPE> {

	struct Record {
		TYPE data_;
		std::string key_;
		Record(const std::string& key, const TYPE& data) {
			key_ = key;
			data_ = data;
		}
		
	};

	Record** records_;		//the table
	int capacity_;			//capacity of the array (max size)
	double maxLoadFactor_;	//max % fill rate
	int counter_;			//count number of data in records table

public:
	LPTable(int cap, double maxLoadFactor);
	//copy constructor
	LPTable(const LPTable& rhs);
	//copy assignment operator
	LPTable(LPTable&& rhs);
	//replace value (if key exists), otherwise add new
	virtual void update(const std::string& key, const TYPE& value);
	//remove if key found on table
	virtual bool remove(const std::string& key);
	//find the value with matching key and return its value
	virtual bool find(const std::string& key, TYPE& value);
	//move contructor
	virtual const LPTable& operator=(const LPTable& rhs);
	//move assignment operator
	virtual const LPTable& operator=(LPTable&& rhs);
	virtual int numRecords() const		{	return this->counter_;			}
	virtual bool isEmpty() const		{	return (numRecords() == 0);		}
	size_t capacity() const				{	return this->capacity_;			}
	virtual ~LPTable();
	void grow() {
		//initialize a new temp with data from records_
		Record** temp_ = new Record * [this->capacity_];
		for (int a = 0; a < this->capacity_; a++)
			temp_[a] = records_[a];
		
		int capTemp_ = this->capacity_ * 2;
		int counterTemp_ = 0;
		//copy data back into records
		records_ = new Record * [capTemp_];
		for (int a = 0; a < capTemp_; a++)
			records_[a] = nullptr;

		for (int b = 0; b < this->capacity_; b++) {
			if (temp_[b] != nullptr) {
				std::hash<std::string> hashTemp_;
				std::size_t idx_ = (hashTemp_(temp_[b]->key_) % capTemp_);

				while (true) {
					if (records_[idx_] == nullptr) {
						records_[idx_] = new Record(temp_[b]->key_, temp_[b]->data_);
						counterTemp_++;
						break;
					}

					//back to beginning of table if reached end
					idx_++;
					if (idx_ == capTemp_)
						idx_ = 0;
				}
			}
		}
		this->capacity_ = capTemp_;	
	}
	size_t search(const std::string& key) {
		std::hash<std::string> hashTemp_;
		std::size_t index_ = (hashTemp_(key) % this->capacity_);
		std::size_t initialIndex = index_;

		while (records_[index_] != nullptr) {
			if (records_[index_]->key_ == key) {
				return index_;
			}

			if(records_[index_] == nullptr){
			    index_ = 0;
			}
			//back to beginning of table if reached end
			index_++;
			if (index_ == this->capacity_)
				index_ = 0;

			//break if entire table has been going through
			if (index_ == initialIndex)
				break;
		}
		return index_;
	}
};

//completed
//constructor
template <class TYPE>
LPTable<TYPE>::LPTable(int cap, double maxLoadFactor) : Table<TYPE>() {
	this->capacity_ = cap;
	this->maxLoadFactor_ = maxLoadFactor;
	this->counter_ = 0;
	records_ = new Record * [this->capacity_];
	for (int a = 0; a < this->capacity_; a++) {
		records_[a] = nullptr;
	}
}

//completed
//copy constructor
template <class TYPE>
LPTable<TYPE>::LPTable(const LPTable<TYPE>& rhs) {
	this->capacity_ = rhs.capacity_;
	this->records_ = new Record * [rhs.capacity_];
	this->counter_ = rhs.counter_;
	this->maxLoadFactor_ = rhs.maxLoadFactor_;

	for (int a = 0; a < this->capacity_; a++) {
		if (rhs.records_[a] != nullptr) {
			this->records_[a] = new Record(rhs.records_[a]->key_, rhs.records_[a]->data_);
		}
		else {
			this->records_[a] = nullptr;
		}
	}
}

//completed
//copy assignment operator
template <class TYPE>
const LPTable<TYPE>& LPTable<TYPE>::operator=(const LPTable<TYPE>& rhs) {
	records_ = new Record * [rhs.capacity_];
	if (this == &rhs)
		return *this;
	else {
		capacity_ = rhs.capacity_;
		maxLoadFactor_ = rhs.maxLoadFactor_;
		counter_ = rhs.counter_;
		for (int a = 0; a < this->capacity_; a++) {
			if (rhs.records_[a] != nullptr)
				this->records_[a] = new Record(rhs.records_[a]->key_, rhs.records_[a]->data_);
			else
				this->records_[a] = nullptr;
		}
	}
	return *this;
}

//completed
//move constructor
template <class TYPE>
LPTable<TYPE>::LPTable(LPTable<TYPE>&& rhs) {
	this->capacity_ = rhs.capacity_;		
	this->records_ = rhs.records_;
	this->counter_ = rhs.counter_;
	this->maxLoadFactor_ = rhs.maxLoadFactor_;

	rhs.capacity_ = 0;
	rhs.records_ = nullptr;	
	rhs.counter_ = 0;
	rhs.capacity_ = 0;
}

//completed
//move assignment operator
template <class TYPE>
const LPTable<TYPE>& LPTable<TYPE>::operator=(LPTable<TYPE>&& rhs) {
	if (this != &rhs) {
		this->capacity_ = rhs.capacity_;
		this->records_ = rhs.records_;
		this->counter_ = rhs.counter_;
		this->maxLoadFactor_ = rhs.maxLoadFactor_;

		rhs.capacity_ = 0;
		rhs.records_ = nullptr;
		rhs.counter_ = 0;
		rhs.capacity_ = 0;
	}
	return *this;
}

//completed
template <class TYPE>
void LPTable<TYPE>::update(const std::string& key, const TYPE& value) {
	std::size_t update_ = search(key);

	//if update return a found value (other than -1)
	if (records_[update_] != nullptr) {
		records_[update_]->data_ = value;
	}

	//if there is no existing matching value (equal to -1)
	else {
		std::hash<std::string> hashTemp_;
		update_ = (hashTemp_(key) % this->capacity_);
		double load_ = (double)this->counter_ / (double)this->capacity_;
		while (true) {
			if (records_[update_] == nullptr) {
				if (load_ >= this->maxLoadFactor_) {
					grow();
					update_ = search(key);
				}
				records_[update_] = new Record(key, value);
				this->counter_++;
				break;
			}
			else {
				//back to beginning of table if reached end
				update_++;
				if (update_ == this->capacity_)
					update_ = 0;
			}
		}
	}
}

//completed
template <class TYPE>
bool LPTable<TYPE>::find(const std::string& key, TYPE& value) {
	std::size_t find_ = search(key);
	if (records_[find_] != nullptr) {
		if (records_[find_]->key_ == key) {
			//std::cout << "Key in table: " << records_[find_]->key_ << std::endl;
			value = records_[find_]->data_;
			return true;
		}
	}
	return false;
}

//completed
template <class TYPE>
bool LPTable<TYPE>::remove(const std::string& key) {
	std::size_t remove_ = search(key);

	if (isEmpty() == true)
		return false;

	while (true) {
		if (records_[remove_] != nullptr) {
			if(records_[remove_]->key_ == "unmodifiably")
            {
			    std::cout << records_[remove_]->key_ << std::endl;
			    std::cout << remove_ << std::endl;
            }

			records_[remove_]->data_ = '\0';
            records_[remove_]->key_ = '\0';
			this->counter_--;
			return true;
		}
		remove_++;
		if (remove_ == this->capacity_)
			remove_ = 0;
	}
	return false;	
}

//completed
template <class TYPE>
LPTable<TYPE>::~LPTable() {
	if (records_ && this->capacity_ > 0) {								
		for (int a = 0; a < this->capacity_; a++)	
			delete records_[a];
		delete[] records_;
	}
}