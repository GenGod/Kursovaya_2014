#include "fruit.h"

fruit::fruit(void)
	{
		type = "Oranges";
		kol = 180;
		country = "Turkey";
		price = 130;
		shelf_life = 31;
		name = 0;
	}
fruit::fruit(string str, double dob, string stri, double doo, double shelf_lif)
	{
		type = str;
		kol = dob;
		country = stri;
		price = doo;
		shelf_life = shelf_lif;
		name = 0;
	}
string fruit::get_smth()
	{
		return country;
	}
void fruit::set_smth(string stri)
	{
		country = stri;
	}
void fruit::print_msg()
{
	cout << "Enter the name of fruit, the amount in lb, the price for 1 lb of fruit, the country of origin and shelf life of fruit:" << endl << endl;
}

void fruit::ust_smth()
{
	string stri;
	cin >> stri;
	country = stri;
}
void fruit::print_sy()
{
	cout << *this;
}
bool fruit::get_name()
{
	return name;
}
void fruit::set_name(bool bo)
{
	name = bo;
}

fruit fruit::operator=(fruit fru)
	{
		fru.set_type(type);
		fru.set_smth(country);
		fru.set_kol(kol);
		fru.set_price(price);
		return fru;
	}
fruit::~fruit(){}