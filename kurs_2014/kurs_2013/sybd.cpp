#include "sybd.h"

sybd::sybd()
{
	type = "Lettuce";
	kol = 1;
	price = 10;
	shelf_life = 3;
}
sybd::sybd(string str, double dob, double doo, double shelf_lif)
{
	type = str;
	kol = dob;
	price = doo;
	shelf_life = shelf_lif;
}
sybd::sybd(const sybd &sdf)
{
	//this->set_kol(sdf.get_kol());
	//this->set_type(sdf.get_type());
	type = sdf.type;
	kol = sdf.kol;
	price = sdf.price;
	shelf_life = sdf.shelf_life;
	//smth = sdf.smth;
	//name = sdf.name;
}
void sybd::set_price(double doo){ price = doo; }
double sybd::get_price(){ return price; }
void sybd::set_type(string str){ type = str; }
string sybd::get_type(){ return type; }
void sybd::set_kol(double dob){ kol = dob; }
double sybd::get_kol(){ return kol; }
void sybd::set_shelf_life(double shelf_lif){ shelf_life = shelf_lif; }
double sybd::get_shelf_life(){ return shelf_life; }
void sybd::ust_string()
{
	string str;
	cin >> str;
	set_type(str);
}
void sybd::ust_doub()
{
	double dod;
	cin >> dod;
	set_kol(dod);
}
void sybd::ust_dooo()
{
	cout << "Enter new shelf life: " << endl;
	double dod;
	cin >> dod;
	set_shelf_life(dod);
}
void sybd::ust_double()
{
	double dod;
	cin >> dod;
	set_price(dod);
}
void sybd::print_msg()
{
	cout << "" << endl;
}
void sybd::print_sy()
{
	cout << *this;
}
void sybd::set_name(bool bo)
{
	bool name;
	name = bo;
}
bool sybd::get_name()
{
	return 0;
}
string sybd::get_smth()
{
	string atr = "00";
	return atr;
}
void sybd::ust_smth()
{
	cout << "ust_smth";
}
void sybd::set_smth(string str)
{
	string smth;
	smth = str;
}
//sybd::~sybd(void){ delete this; }