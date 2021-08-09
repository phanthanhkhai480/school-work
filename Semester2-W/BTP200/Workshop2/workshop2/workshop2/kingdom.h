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
	void display(Kingdom pKingdom[], int num);
	void display(Kingdom pKingdom[], int num1, int min);
	void display(Kingdom pKingdom[], int num2, const char* name);
}

#endif
