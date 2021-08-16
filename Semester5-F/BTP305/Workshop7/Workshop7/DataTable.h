/*!\File DataTable.h
// \Brief BTP305 Workshop 7: STL Container
// \Details    Longer description of file
// \Version 1.0
// \Date 10/11/2018
// \Author Khai Phan
// \copyright GNU Public License.
**/

#ifndef DATA_TABLE_H
#define DATA_TABLE_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>
#include <string>

namespace w7
{
	template<typename T>
	class DataTable
	{
		std::vector<T> x_int;	/*!< Vector of type T holding independent (x) value !>*/
		std::vector<T> y_int;	/*!< Vector of type T holding dependent (y) value !>*/
		int decimalCount;		/*!< set number of zeros for decimal number !>*/
		int width;				/*!< set width length for each field !>*/
	public:
		DataTable(std::ifstream & abc, const int& wdt, const int& decimal);
			/*!< custom constructor!>*/
		T mean() const;			/*!< function type T calculate mean !>*/
		T sigma() const;		/*!< function type T calculate sample standard deviation !>*/
		T median() const;		/*!< function type T calculate median !>*/
		void regression(T& slope, T& y_intercept) const;
			/*!< function calculate slope and y_intercept(dependent value) !>*/
		void display(std::ostream&) const;
			/*!< display function !>*/
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& data)
	{
		data.display(os);
		return os;
	}



	template<typename T>
	DataTable<T>::DataTable(std::ifstream & abc, 
		const int& wdt, const int& decimal)
	{	this->width = wdt;
		this->decimalCount = decimal;
		T x_tmp, y_tmp;

		if (abc.is_open() == true)
		{	while (abc.good())
			{	abc >> x_tmp >> y_tmp;
				if (!abc.fail())
				{	x_int.push_back(x_tmp);
					y_int.push_back(y_tmp);
				}	}	}	}


	template<typename T>
	T DataTable<T>::mean() const
	{
		T temp, avg;
		temp = std::accumulate(y_int.begin(), y_int.end(), (T)0);
		avg = temp / y_int.size();
		return avg;
	}

	template<typename T>
	T DataTable<T>::sigma() const
	{
		T sum;
		sum = std::accumulate(y_int.begin(), y_int.end(), (T)0, [&](T a, T b)
		{
			return (a + (b - mean())*(b - mean()) / (y_int.size() - 1));
		});

		T sigma = sqrt(sum);
		return sigma;
	}

	template<typename T>
	T DataTable<T>::median() const
	{
		std::vector<T> temp = y_int;
		std::sort(temp.begin(), temp.end());
		T tmp = temp[ceil(temp.size() / 2)];
		return tmp;
	}

	template<typename T>
	void DataTable<T>::regression(T & slope, T & y_intercept) const
	{
		T x_total, y_total, xy_total, xx_total;

		x_total = std::accumulate(x_int.begin(), x_int.end(), (T)0);
		y_total = std::accumulate(y_int.begin(), y_int.end(), (T)0);
		xy_total = std::inner_product(x_int.begin(), x_int.end(), y_int.begin(), (T)0);
		xx_total = std::inner_product(x_int.begin(), x_int.end(), x_int.begin(), (T)0);
		int size = x_int.size();

		slope = ((size)*(xy_total)-(x_total)*(y_total)) /
			((size)*(xx_total)-(x_total)*(x_total));
			y_intercept = ((y_total)-(slope)*(x_total)) / (size);

	}

	template<typename T>
	void DataTable<T>::display(std::ostream &os) const
	{
		int count = x_int.size();
		os << std::setw(width) << "x"
			<< std::setw(width) << "y" << std::endl;
		os << std::fixed << std::setprecision(decimalCount);
		
		for (int temp = 0; temp < count ; temp++)
		{
			os << std::setw(width) << x_int[temp]
				<< std::setw(width) << y_int[temp] << std::endl;
		}
	}

}

#endif // ! DATA_TABLE_H

