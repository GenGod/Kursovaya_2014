#pragma once

#include "sybd.h"

class fruit : public sybd
{
private:
	string type;
	double kol;
	string country;
	double price;
	double shelf_life;
	bool name;
public:
	fruit(void);
	fruit(string str, double dob, string stri, double doo, double shelf_lif);
	void print_msg();
	void ust_smth();
	string get_smth();
	void set_smth(string stri);
	void print_sy();
	bool get_name();
	void set_name(bool bo);
	friend ostream& operator<<(ostream& output, fruit fru)
	{
		output << "Type: ";
		output << fru.get_type();
		output << " \n";
		output << "How many: ";
		output << fru.get_kol();
		output << " lb \nCountry of origin: ";
		output << fru.get_smth();
		output << "\nPrice is: ";
		output << fru.get_price();
		output << "\nShelf life is: ";
		output << fru.get_shelf_life();
		output << " \n\n\n";
		return output;
	}
	fruit operator=(fruit fru);
	~fruit(void);
};