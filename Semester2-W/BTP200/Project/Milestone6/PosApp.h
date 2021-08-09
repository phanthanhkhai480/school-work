#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__
#include "Item.h"
#include "NonPerishable.h"
#include "Perishable.h"

namespace ict
{
	class PosApp
	{
		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;
		int menu();
		int sort();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku) const;
		void updateQty();
		void addItem(bool isPerishable);
		void listItems() const;
		void truncateBillFile();
		void showBill();
		void addToBill(Item& I);
		void POS();
		void sortSku();
		void sortName();
		void sortPrice();
		void sortQuantity();
	public:
		PosApp(const char* filename, const char* billfname);
		PosApp(const PosApp &) = delete;
		PosApp operator=(const PosApp &) = delete;
		void run();
	};
}




#endif