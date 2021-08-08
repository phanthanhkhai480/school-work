	//reason to use Queue for negative number is first-in, first-out
	//reason to use Stack for positive number is first-in, last-out

	Queue queue1, queue2;
	Stack stack1;
	
	, zeroes = 0, ;
	for (int i = 0; i < size; i)
	{
		int num = arr[]
		//when while detect a 0, list divide will stop to push data
		//into the main Queue, ready to put into array
		while (num != 0)
		{
			//divide list of negative and positive
			if (num < 0)
				queue1.enqueue(num);
			else
				stack1.push(num);
			i++;
			num = arr[i];
		}
		while (queue1, .front())
			//add deleted data in queue1 into queue2
			queue2.enqueue(queue1, .dequeue());
		while (stack1.top())
			queue2.enqueue(stack1.pop());
		i++;
		zeroes++;
	}

	//allocate size for new array without 0s
	newarr = new int[(i-zeroes)];
	i = 0;
	while (queue2.front())
	{
	  newarr[i] = queue2.dequeue();
	  i++;
	}
	
	
	//alternatively, we can use only queue to arrange the data
	Queue queue1, queue2, queue3;
	
	int num = arr[0], zeroes = 0, i;
	for (i = 1; i < size; i)
	{
		//when while detect a 0, list divide will stop to push data
		//into the main Queue, ready to put into array
		while (num != 0)
		{
			//divide list of negative and positive
			if (num < 0)
				queue1.enqueue(num);
			else
				queue2.enqueue(num);
			i++;
			num = arr[i];
		}
		while (queue1.front())
			//add deleted data in queue1 into queue2
			queue3.enqueue(queue1.dequeue());
		while (queue2.front())
			queue3.enqueue(queue2.dequeue());
		i++;
		zeroes++;
	}

	//allocate size for new array without 0s
	newarr = new int[(i-zeroes)];
	i = 0;
	//passing data
	while (queue3.front())
	{
	  newarr[i] = queue3.dequeue();
	  i++;
	}

	
	//for Palindrome question
	bool isPalindrome(const char* s, int len) {
		if(len == 0 || len == 1)
			return true;
		else {
			if(str[0] == str[len-1] && isPalindrome(&str[1], len - 2)) {
				return true;
			}
			return false;
		}
		return false;
	}

	
	//for search question
	template <typename T>
	iterator search(const T& data){
		//set value in case nothing is found
		iterator search_ = end();
		Node* current_ = this->front_->next_;
		bool check_ = false;
		
		if (!this->empty()) {
			while (current_ != this->back_) {
				if (current_->data_ == data) {
					current_->access_++;         
					
					//for Sentinel
					//temporary remove the node
					current_->prev_->next_ = current_->next_;
					current_->next_->prev_ = current_->prev_;
					current_->next_ = nullptr;
					current_->prev_ = nullptr;
					
					//move the node to the first node
					current_->next_ = front_->next_;
					current_->prev_ = front_;
					front_->next_ = current_;
					front_->next_->prev_ = current_;
					
					//for non-Sentinel
					//temporary remove the node
					current_->prev_->next_ = current_->next_;
					current_->next_->prev_ = current_->prev_;
					current_->next_ = nullptr;
					current_->prev_ = nullptr;
					
					//move the node to the first node
					front_->prev_ = curr_;
					curr_->next_ = front_;
					front_ = curr_;
					curr_->prev_ = nullptr;
					
					//only use if the search is require to arrange by count_
					/* 
					//check if previous is not front (empty node) and
					//current access is >= previous node
					do {
						if ((current_->access_ >= current_->prev_->access_) && 
							(current_->prev_ != this->front_)) 
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
					*/
					
					search_ = iterator(current_);
					break;
				}
				current_ = current_->next_;
			}    
		}
		return search_;
	}


	//merge sort (with recursive)
	//main method passing vector array need to be sorted
	//mergeSort constructor will pass to other constructor
	//for sorting, depends on # of args
	template <class TYPE>
	void mergeSort(vector<TYPE>& arr){
		vector<TYPE> tmp(arr.size());
		//call mergeSort with the array, the temporary
		//and the starting and ending indices of the array
		mergeSort(arr,tmp,0,arr.size()-1);
	}
	
	//this function sorts arr from index start to end recursively
	template <class TYPE>
	void mergeSort(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int end){
		if (start<end){
			int mid=(start+end)/2;
			mergeSort(arr,tmp,start,mid);
			mergeSort(arr,tmp,mid+1,end);
			merge(arr,tmp,start,mid+1,end);
		}
	}
	
	//merge sorted array
	template <class TYPE>
	void merge(vector<TYPE>& arr, vector<TYPE>& tmp, 
					int start,int start2, int end)	{
		int aptr=start;
		int bptr=start2;
		int i=start;
		//check if 2 array are not collide into each others
		while(aptr < start2 && bptr <= end){
			//prioritize first half of array coming in
			if(arr[aptr] < arr[bptr])
				//add first half in...
				tmp[i++] = arr[aptr++];
			else
				//then the second half
				tmp[i++] = arr[bptr++];
		}
		
		while(aptr < start2){
			tmp[i++]=arr[aptr++];
		}
		
		while(bptr<=end){
			tmp[i++]=arr[bptr++];
		}
		//passing tmp array into main array
		for(i=start;i<=end;i++){
			arr[i]=tmp[i];
		}
	}
	
	//quick sorted array
	//left is 0 and right is end of the array position
	void quick(int arr[], int left, int right) {
		if(left < right) {
			int size = right-left+1;
			
			//find the pivot point
			int pivotpt = (left + right)/2;
			
			int left_ = left;
			int right_ = right-1;
			
			//begin number to compare
			int pivot = arr[pivotpt];
			
			//passing pivot point to the end
			swap(arr[pivotpt], arr[right_]);
			
			//set new pivotpt to distinguish 2 arrays
			pivotpt = right_;
			
			//methodology here is to increment the left side to find
			//a number > pivot, keep it position and wait for the right
			//side to find a number < pivot, then swap the 2
			while (left_ < right_) {
				//if left number < pivot number, keep it
				//if number on the left side < pivot number
				//and ensure left_ doesn't go over to end 
				while (left_ < right-1 && arr[left_] < pivot)
					//increase the position on left side
					left_++;
					
				//if right number > pivot number, keep it
				//if number on the right side > pivot number
				//and ensure that right_ doesn't reach arr[0]
				while (right_ > 0 && arr[right_] > pivot)
					//increase the position on right side
					right_++;
					
				//swap the number (right = < pivot, left = > pivot)
				if(left_ < right_)
					swap(arr[left_++], arr[right_--];
			}
			
			//ensure left_ and right_ are equa and 
			//last position of left_ is still < pivotpt
			if(left_ == right_ && arr[left_] < arr[pivotpt])
				left_++;
			
			//put the original pivot back to its original position
			//at this stage, pivotpt is sure to be in the exact sorted place
			swap(arr[left_], arr[pivotpt]);
			
			
			quick(arr, left, left_-1);
			quick(arr, left_+1, right);
		}
	}
	
	void quick(int arr[], int size) {
		quick(arr, 0, size-1);
	}

