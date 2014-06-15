#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

__interface IInter
{
	virtual void print_msg(void) = 0;
	virtual void print_sy(void) = 0;
	virtual void set_name(bool bo) = 0;
	virtual bool get_name(void);
	virtual string get_smth(void);
	virtual void set_smth(string str) = 0;
	virtual void ust_smth(void)=0;
	//virtual ~IInter() {};
};

class sybd: public IInter
{
public:
	string type;
	double kol;
	double price;
	double shelf_life;
	sybd(void);
	sybd(string str, double dob, double doo, double shelf_lif);
	sybd(const sybd &sdf);
	void set_price(double doo);
	void ust_string(void);
	void ust_double(void);
	void ust_doub(void);
	void ust_dooo(void);
	double get_price(void);
	void set_kol(double dob);
	double get_kol(void);
	void set_type(string str);
	string get_type(void);
	void set_shelf_life(double shelf_lif);
	double get_shelf_life(void);
	void print_msg();
	void print_sy();
	void set_name(bool bo);
	bool get_name();
	string get_smth();
	void ust_smth();
	void set_smth(string str);
	//~sybd();
	friend ostream& operator<<(ostream& output, sybd fru)
	{
		output << "Type: ";
		output << fru.get_type();
		output << " \n";
		output << "How many: ";
		output << fru.get_kol();
		output << " lb";
		output << "\nPrice is: ";
		output << fru.get_price();
		output << "\nShelf life is: ";
		output << fru.get_shelf_life();
		output << " \n\n\n";
		return output;
	}
};