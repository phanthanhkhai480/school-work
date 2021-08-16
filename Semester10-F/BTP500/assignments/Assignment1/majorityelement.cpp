/*******************************************************************/
/*                                                                 */
/*  A1 Part 3: Majority Element starter file                       */
/*                                                                 */
/*  Author1 Name: Khai Phan		 							       */
/*      - class/function list                                      */
/*  Student number: 100901164                                      */
/*  Due Date: Oct 19 (+1 week extension)                           */                                                                
/*******************************************************************/
#include <iostream>
bool findCandidate(int array[],int& candidate, int sz);
bool majorityElement(const int arr[], int& majority, int sz);

bool majorityElement(const int arr[], int& majority, int sz){
	//ignore if size of arr is less than 1
	if (sz > 0) {
		int* arr1 = new int[sz];	//initialize new array to copy
		int counter_ = 0;			//count the # repeat in array
		int value = 0;				//new majority number

		//create a copy of arr;
		for (int a = 0; a < sz; a++)
			arr1[a] = arr[a];

		//if candidate is exist, received value will be true
		if (findCandidate(arr1, value, sz)) {
			//receive the final value from findCandidate
			//check for # of repeated times
			for (int b = 0; b < sz; b++) {
				if (value == arr[b])
					counter_++;
			}
		}
		//check if findCandidate return the correct majority value
		if (counter_ > (sz / 2)) {
			majority = value;
			return true;
		}
	}
	return false;
}

bool findCandidate(int array[], int& candidate, int sz){
	//ignore if size of arr is less than 1
	if (sz > 0) {
		bool candidate_ = false;

		if (sz > 1) {
			int* arr1 = new int[sz];	//initialize new array to copy
			int counter_ = 0;			//counter for position override in array[]

			//create a copy of arr;
			for (int a = 0; a < sz; a++)
				arr1[a] = array[a];

			//increment by 2 because we compare as a pair
			for (int b = 0; b < sz - 1; b += 2) {
				if (arr1[b] == arr1[b+1])
					//if 2 values are equals
					//overwrite the array with new values
					array[counter_++] = arr1[b];
			}

			candidate_ = findCandidate(array, candidate, counter_);
			//initialize odd array value
			if (!candidate_ && ((sz % 2) != 0)) {
				candidate = array[sz - 1];
				candidate_ = true;
			}	
		}
		//return if there is 1 value left
		else {	
			candidate = array[0];
			candidate_ = true;
		}
		return candidate_;
	}
	return false;
}
