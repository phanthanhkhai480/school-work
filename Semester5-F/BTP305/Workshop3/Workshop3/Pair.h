#ifndef PAIR_H	//safe header guard
#define PAIR_H

/*!
* a template dedicated to the workshop
*/

template<typename A, typename B>
class Pair
{
	A key;		/*!< a key attribute of type A !>*/
	B value;	/*!< a value attribute of type B !>*/
public:
	Pair();		/*!< default constructor !>*/
	Pair(const A& abc, const B& abcd);	/*!< set the key-pair attributes !>*/
	const A& getKey() const;	/*!< return stored key information !>*/
	const B& getValue() const;	/*!< return stored value information !>*/
};

#endif 


template<typename A, typename B>
Pair<A, B>::Pair()
{
	//A key = nullptr;
	//B value = nullptr;
}

template<typename A, typename B>
Pair<A, B>::Pair(const A & abc, const B & abcd)
{
	key = abc;
	value = abcd;
}

template<typename A, typename B>
const A & Pair<A, B>::getKey() const
{
	return key;
	// TODO: insert return statement here
}

template<typename A, typename B>
const B & Pair<A, B>::getValue() const
{
	return value;
	// TODO: insert return statement here
}


