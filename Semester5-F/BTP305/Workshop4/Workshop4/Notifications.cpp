#include <iostream>
#include "Notifications.h"

using namespace std;

namespace w5
{
	Notifications::Notifications()
	{
		this->noti = nullptr;
	}

	Notifications::Notifications(const Notifications & abc)
	{
		for (int i = 0; i < sizeof(abc.noti); i++)
		{
			this->noti[i] = abc.noti[i];
		}
	}

	Notifications & Notifications::operator=(const Notifications & abc)
	{
		if (this != &abc)
		{
			for (int i = 0; i < sizeof(abc.noti); i++)
			{
				this->noti[i] = abc.noti[i];
			}
		}
		return *this;
		// TODO: insert return statement here
	}

	Notifications::Notifications(Notifications && abc)
	{
		this->noti = abc.noti;
	}

	Notifications Notifications::operator=(Notifications && abc)
	{
		if (this != &abc)
			this->noti = abc.noti;
		return *this;
	}

	Notifications::~Notifications()
	{
		delete[] this->noti;
	}

	void Notifications::operator+=(const Message & msg)
	{
		if (sizeof(this->noti) < 10)
		{
			int a = sizeof(this->noti);
			this->noti[a] = msg;
		}
	}

	void Notifications::display(std::ostream & os) const
	{
		for (int i = 0; i < sizeof(this->noti); i++)
			this->noti[i].display(os);
	}


}


