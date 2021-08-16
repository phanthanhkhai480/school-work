#ifndef LIST_H	//safe header guard
#define LIST_H
#include <stddef.h>

/*!
* a template dedicated to the workshop
*/

template<typename T, int N>
class List
{
	size_t num;								/*!< type data of T with attribute num !>*/
	T arrays[N];							/*!< array of type T with dimension of num >!*/
public:
	List();									/*!< default constructor !>*/
	size_t size() const;					/*!< return the size in array !>*/
	const T& operator[] (int index) const;	/*!< returns the requested array index !>*/
void operator+=(const T& abc);	};			/*!< add elements to array !>*/

#endif


	template<class T, int N>
	List<T, N>::List()	{
		//this->arrays = nullptr;
		this->num = 0;	}

	template<class T, int N>
	size_t List<T, N>::size() const	{
		return size_t(num);	}

	template<class T, int N>
	const T & List<T, N>::operator[]
	(int index) const	{
		return arrays[index];	}

	template<class T, int N>
	void List<T, N>::operator+=
	(const T & abc)	{
		arrays[num] = abc;
		num++;	}


