#ifndef KINGDOM_H
#define KINGDOM_H

namespace westeros
{
	class Kingdom
	{
	public:
		char m_name[32];
		int m_population;
	};
	void display(Kingdom &pKingdom);
}

#endif
