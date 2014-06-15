#include "ovos.h"

ovos::ovos()
	{
		type = "Tomato";
		kol = 12;
		gmo = false;
		price = 16;
		shelf_life = 38;
		name = 1;
	}
ovos::ovos(string str, double dob, bool boo, double doo, double shelf_lif)
	{
		type = str;
		kol = dob;
		gmo = boo;
		price = doo;
		shelf_life = shelf_lif;
		name = 1;
	}
void ovos::set_smth(string boo)
	{
	if (boo == "true") gmo = 1;
	else gmo = 0;
	}
string ovos::get_smth()
	{
	string str;
	if (gmo)
		str = "true";
	else
		str = "false";
		return str;
	}
void ovos::ust_smth()
{
	string boo;
	cin >> boo;
	set_smth(boo);
}
void ovos::print_msg()
{
	cout << "Enter the name of vegetable, the amount in lb, the price for 1 lb of vegetable, GMO (if there is - 1, otherwise - 0) and shelf life of vegetable:" << endl << endl;;
}
void ovos::print_sy()
{
	cout << *this;
}
bool ovos::get_name()
{
	return name;
}
void ovos::set_name(bool bo)
{
	name=bo;
}

bool ovos::operator==(vector<ovos>::iterator rf)
	{
		if (rf->get_type() == this->get_type())
			return true;
		else return false;
	}
ovos::~ovos(){}