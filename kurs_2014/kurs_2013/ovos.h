#pragma once

#include "sybd.h"

class ovos : public sybd
{
private:
	string type;
	double kol;
	bool gmo;
	double price;
	double shelf_life;
	bool name;
public:
	ovos(void);
	ovos(string str, double dob, bool boo, double doo, double shelf_lif);
	void print_msg();
	void set_smth(string boo);
	string get_smth();
	void print_sy();
	void ust_smth();
	bool get_name();
	void set_name(bool bo);
	friend ostream& operator<<(ostream& output, ovos fru)
	{
		output << "Type: ";
		output << fru.get_type();
		output << " \n";
		output << "How many: ";
		output << fru.get_kol();
		output << " lb \nGMO: ";
		if (fru.get_smth() == "false")
			output << "no GMO";
		else
			output << "GMOs are present";
		output << "\nPrice is: ";
		output << fru.get_price();
		output << "\nShelf life is: ";
		output << fru.get_shelf_life();
		output << " \n\n\n";
		return output;
	}
	ovos operator=(ovos vo);
	bool operator==(vector<ovos>::iterator rf);
	~ovos(void);
};