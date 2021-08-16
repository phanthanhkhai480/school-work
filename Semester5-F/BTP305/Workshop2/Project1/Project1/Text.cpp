#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace w2
{
	Text::Text() 
	{
		this->record = 0;
		this->txt = nullptr;
	}
	
	Text::Text(const std::string& abc)
	{
		ifstream file("gutenberg_shakespeare.file");
		if (!file.is_open())
		{
			cout << "File is not exist!" << endl;
			exit(1);
		}
		else
		{
			string tmp;
			while (getline(file, tmp))
				this->record++;
			if (file.good())
			{
				this->txt = new string[this->record];
				int tempt = this->record;
				for (int i = 0; i < tempt; i++)
					getline(file, this->txt[i]);
			}
		}		
		file.close();	
		
	}

	Text::Text(const Text & abc) : record(abc.record)	{
		this->record = abc.record;
		this->txt = new string[this->record];
		for (int i = 0; i < this->record; i++)
			this->txt[i] = abc.txt[i];		}

	Text & Text::operator=(const Text & abc)	{
		if (this != &abc)	{
			this->record = abc.record;
			if (this->txt != nullptr)	{
				delete[] this->txt;
				this->txt = nullptr;	}
			this->txt = new string[this->record];
			for (int i = 0; i < this->record; i++)
				this->txt[i] = abc.txt[i];	}
		return *this;	}

	Text::Text(Text && abc)	{
		this->record = abc.record;
		this->txt = abc.txt;
		abc.txt = nullptr;	}

	Text & Text::operator=(Text && abc)	{
		if (this != &abc)	{
			this->record = abc.record;
			delete[] this->txt;
			this->txt = abc.txt;
			abc.txt = nullptr;	}
		return *this;	}

	Text::~Text()
	{
		delete[] this->txt;
	}

	size_t Text::size() const
	{
		return this->record;
	}

}