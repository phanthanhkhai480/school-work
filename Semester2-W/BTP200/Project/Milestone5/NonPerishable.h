#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include "Item.h"
#include "Error.h"

namespace ict
{
	class NonPerishable : public Item
	{
		Error m_err;
	protected:
		bool ok() const;
		void error(const char* message);
		virtual char signature() const;
	public:
		std::fstream& save(std::fstream& file) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& ostr, bool linear) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator << (std::ostream& os, const NonPerishable& I);
	std::istream& operator >> (std::istream& os, NonPerishable& I);
}

#endif