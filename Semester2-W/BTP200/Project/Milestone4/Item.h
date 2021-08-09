#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "POS.h"
#include "PosIO.h"

namespace ict{
  // class Item
	class Item : public PosIO
	{
		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
	public:
		Item();
		Item(const char*,const char*, double, bool);
		Item(const Item &other);
		Item& operator=(const Item&);
		virtual ~Item();
		void sku(const char* sku);
		void name(const char* name);
		void quantity(const int quantity);
		void price(const double price);
		void taxed(const bool taxed);
		const char* sku()const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		double cost()const;
		bool isEmpty();
		bool operator ==(const char*);
		int operator +=(int);
		int operator -=(int);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
	};

  // end class Item
  // operator += 
  double operator+=(double& d, const Item& I);
  // operator << and operator >>
	std::ostream& operator << (std::ostream& os, const Item& I);
	std::istream& operator >> (std::istream& os, Item& I);
}


#endif