#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Message.h"

using namespace std;

namespace w5
{
	Message::Message()
	{
		this->mess = "";
		this->reply = "";
		this->tweet = "";
		this->user = "";
	}

	Message::Message(std::ifstream & in, char c)
	{
		if (!in.is_open())
		{
			cout << "File does not exist!" << endl;
			exit(1);
		}
		else
		{
			int count;	in >> count;
			in.ignore(1, '\n');
			for (int i = 0; i < count; i++)
			{
				string tmp, tmp1;
				getline(in, this->mess);
				istringstream temp(this->mess);

				getline(temp, this->user, ' ');
				getline(temp, tmp, ' ');
				getline(temp, tmp1);
				if (tmp.length() < 1 && tmp1.length() < 1)
				{

				}

				if (tmp[0] = '@')
					this->reply = tmp;
				else
					this->tweet = tmp + tmp1;

			}
		}
		in.close();
	}

	bool Message::empty() const
	{
		if (this->mess == "" && this->reply == "" &&
			this->tweet == "" && this->user == "")		//empty() already available in <string>
			return true;
		return false;
	}

	void Message::display(std::ostream & os) const
	{
		if (empty() != true)
		{
			os << "Message" << endl;		
			if (this->reply != "")
			{
				os << " User  :" << this->user << endl;
				os << " Reply :" << this->reply << endl;
			}
				os << " Tweet :" << this->tweet << endl;
		}
	
	}

}


