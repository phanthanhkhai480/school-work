// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H

// TODO: westeros namespace
namespace westeros
{
	// TODO: define the class Kingdom in the westeros namespace
	class Kingdom
	{
	public:
		char m_name[32];
		int m_population;
		int m_count;
	};

	// TODO: add the declaration for the function display(...),
	//         also in the westeros namespace
	void display(Kingdom &theKingdom);
	void display(Kingdom *theKingdom, int);
	void display(Kingdom *theKingdom, int, int);
	void display(Kingdom *theKingdom, int, const char* name);
}

#endif
