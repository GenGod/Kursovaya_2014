#define _CRT_SECURE_NO_WARNINGS


#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include "Header.h"

using namespace std;

void swapt(sybd* &fru, sybd* &fgh)
{
	bool n = fru->get_name();
	sybd* rtg = new sybd();
	if(n) sybd* rtg = new ovos();
	else sybd* rtg = new fruit();
	fru->set_type(rtg->get_type());
	fru->set_kol(rtg->get_kol());
	fru->set_price(rtg->get_price());
	fru->set_smth(rtg->get_smth());
	fru->set_name(rtg->get_name());
	fru->set_shelf_life(rtg->get_shelf_life());
	fru->set_type(fgh->get_type());
	fru->set_kol(fgh->get_kol());
	fru->set_price(fgh->get_price());
	fru->set_smth(fgh->get_smth());
	fru->set_name(fgh->get_name());
	fru->set_shelf_life(fgh->get_shelf_life());
	fgh->set_type(rtg->get_type());
	fgh->set_kol(rtg->get_kol());
	fgh->set_price(rtg->get_price());
	fgh->set_smth(rtg->get_smth());
	fru->set_name(rtg->get_name());
	fru->set_shelf_life(rtg->get_shelf_life());
}

void print_smth(vector<sybd*> ovo)
{
	int iy;
	if (ovo.size()==0)
		cout << "BBase is empty.\n";
	else
	{
		cout << "1. Vegetables\n2. Fruits\n3. All elements\n";
		cin >> iy;
		if (iy == 1)
		{
			for (int i = 0; i < ovo.size(); i++)
			{
				if (ovo[i]->get_name())
					ovo[i]->print_sy();
			}
		}
		else if (iy == 2)
		{
			for (int i = 0; i < ovo.size(); i++)
			{
				if (!ovo[i]->get_name())
					ovo[i]->print_sy();
			}
		}
		else
		{
			for (int i = 0; i < ovo.size(); i++)
				ovo[i]->print_sy();
		}
	}
}

int search_smth(vector<sybd*>& ovo,string str)
{
	int j = -1;
	for (int i=0; i < ovo.size(); i++)
	{
		if (ovo[i]->get_type() == str)
		{
			j = i;
			break;
		}
	}
	return j;
}

void delete_smth(vector<sybd*>& vfru)
{
	int f;
	int h = -1;
	int a = 0;
	string str;
	while (1)
	{
		cout << "Enter the name of element to delete:\n";
		cin >> str;
		h = search_smth(vfru, str);
		if (h!=(-1))
		{
			swapt(vfru[h], vfru.back());
			vfru.pop_back();
			cout << "Done!"<<endl;
		}
		else cout << "Element not found" << endl;
		cout << "1. Back to menu\n2. Delete more elements\n" << endl;
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  a++;
				  break;
		}
		case 2: break;
		}
		if (a!=0)
		break;
	}
}

void trans_sybd(vector<sybd*> &vfruit)
{
	string syr;
	string boo;
	string str;
	double doo;
	fruit vfru;
	ovos vovos;
	sybd* sd;
	cout << "Enter the product name to search and transfer:" << endl;
	cin >> syr;
	int uo = search_smth(vfruit,syr);
	if (!vfruit[uo]->get_name())
	{
		cout << "Enter a new presence indicator of GMOs (1 - yes, 0 - no):" << endl;
		cin >> boo;
		vovos.set_kol(vfruit[uo]->get_kol());
		vovos.set_price(vfruit[uo]->get_price());
		vovos.set_type(vfruit[uo]->get_type());
		vovos.set_shelf_life(vfruit[uo]->get_shelf_life());
		vovos.set_smth(boo);
		vovos.set_name(true);
		sd = new ovos(vovos);
	}
	else
	{
		cout << "Enter a new origin country:" << endl;
		cin >> str;
		vfru.set_kol(vfruit[uo]->get_kol());
		vfru.set_price(vfruit[uo]->get_price());
		vfru.set_type(vfruit[uo]->get_type());
		vfru.set_shelf_life(vfruit[uo]->get_shelf_life());
		vfru.set_smth(str);
		vfru.set_name(false);
		sd = new fruit(vfru);
	}
	swapt(vfruit[uo], vfruit.back());
	vfruit.pop_back();
	vfruit.push_back(sd);
}

double profit(vector<sybd*> &vfru)
{
	double prof = 0.0;
	double fd, ds;
	int h = 0;
	cout << "1. Fruits\n2. Vegetables\n";
	cin >> h;
	switch (h)
	{
	case 1:
	{
			  if (vfru.size() != 0)
			  {
				  for (int i = 0; i < vfru.size(); i++)
				  {
					  if (vfru[i]->get_name() == 1)
					  {
						  fd = vfru[i]->get_price();
						  ds = vfru[i]->get_kol();
						  prof += prof + (fd)*(ds);
					  }
				  }
				  double ghu = prof;
				  double zxc = prof;
				  prof = prof - ((zxc / 100) * 16);
				  return prof;
			  }
			  else return 0;
	}
	case 2:
	{
			  if (vfru.size() != 0)
			  {
				  for (int i = 0; i < vfru.size(); i++)
				  {
					  if (vfru[i]->get_name() == 0)
					  {
						  fd = vfru[i]->get_price();
						  ds = vfru[i]->get_kol();
						  prof += prof + (fd)*(ds);
					  }
				  }
				  double ghu = prof;
				  double zxc = prof;
				  prof = prof - ((zxc / 100) * 16);
				  return prof;
			  }
			  else return 0;
	}
	}
}

void add_smth(vector<sybd*>& vfru)
{
	double dod;
	int g = 0;
	string str;
	int d = 0;
	string r;
	while (1)
	{
		cout << "1. Fruit\n2. Vegetable" << endl;
		int iy;
		cin >> iy;
		if (iy == 1)
		{
			fruit fu;
			fu.print_msg();
			cin >> str;
			fu.set_type(str);
			cin >> dod;
			fu.set_kol(dod);
			cin >> dod;
			fu.set_price(dod);
			cin >> str;
			fu.set_smth(str);
			cin >> dod;
			fu.set_shelf_life(dod);
			sybd* su = new fruit(fu);
			vfru.push_back(su);
			int f;
			cout << "1. Back to menu\n2.Add more\n";
			cin >> f;
			switch (f)
			{
			case 1:
			{
					  d++;
					  break;
			}
			case 2: break;
			}
			if (d != 0)
				break;
		}
		else
		{
			ovos gu;
			gu.print_msg();
			cin >> str;
			gu.set_type(str);
			cin >> dod;
			gu.set_kol(dod);
			cin >> dod;
			gu.set_price(dod);
			cin >> r;
			gu.set_smth(r);
			cin >> dod;
			gu.set_shelf_life(dod);
			sybd* fr = new ovos(gu);
			vfru.push_back(fr);
			int f;
			cout << "1. Back to menu\n2.Add more\n";
			cin >> f;
			switch (f)
			{
			case 1:
			{
					  g++;
					  break;
			}
			case 2: break;
			}
			if (g != 0)
				break;
		}
	}
}

void file_save(vector<sybd*>& vovos, int right, string username)
{
	switch (right)
	{
	case 1:
	{
			  char* ch;
			  wchar_t* wch;
			  string put = "C:\\BBase\\Premium\\";
			  string put2 = put;
			  put += username;
			  string name_p;
			  int hu = put.capacity();
			  int uy = 0;
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  CreateDirectoryW(L"C:\\BBase\\Premium\\", NULL);
			  ch = new char[hu];
			  wch = new wchar_t[hu];
			  strcpy(ch, put.c_str());
			  for (int i = 0; i < hu; i++)
				  MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &ch[i], 1, &wch[i], 1);
			  CreateDirectoryW(wch, NULL);
			  put += "\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created):" << endl;
			  cin >> name_p;
			  put += name_p;
			  put += ".dba";
			  ofstream out(put);
			  for (uy; uy != vovos.size(); uy++)
			  {
				  out << vovos[uy]->get_name();
				  out << " ";
				  out << vovos[uy]->get_type();
				  out << " ";
				  out << vovos[uy]->get_kol();
				  out << " ";
				  out << vovos[uy]->get_price();
				  out << " ";
				  out << vovos[uy]->get_smth();
				  out << " ";
				  out << vovos[uy]->get_shelf_life();
				  out << "\n";
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 2:
	{
			  cout << "In free version you can't save more than 30 items!\n";
			  int uy = 0;
			  int j = 0;
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  string name_p;
			  string put = "C:\\BBase\\Gewonlich\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created)" << endl;
			  cin >> name_p;
			  put += name_p;
			  put += ".dba";
			  ofstream out(put);
			  for (uy; uy != vovos.size(); uy++)
			  {
				  out << vovos[uy]->get_name();
				  out << " ";
				  out << vovos[uy]->get_type();
				  out << " ";
				  out << vovos[uy]->get_kol();
				  out << " ";
			      out << vovos[uy]->get_price();
			      out << " ";
				  out << vovos[uy]->get_smth();
				  out << " ";
				  out << vovos[uy]->get_shelf_life();
				  out << "\n";
				  if (j < 10)
					  j++;
				  else break;
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 3:
	{
			  cout << "You can't save data to disk in the trial version!";
			  break;
	}
	}
}

vector<sybd*> load_file(int right)
{
	vector<sybd*> vovos;
	string put;
	string str, dfg;
	double dod, dob, goh;
	string boo;
	fruit voso;
	ovos vos;
	bool n = false;
	cout << "Enter path to file as: C:\\Folder_Name\\File_Name.dba\n";
	cin >> put;
	ifstream in(put);
	if (!in)
	{
		cout << "File not found!\n";
	}
	else
	{
		switch (right)
		{
		case 1:
		{
				  while (in)
				  {
					  in >> n;
					  if (n)
					  {
						  in >> str >> dod >> dob >> boo >> goh;
						  vos.set_name(n);
						  vos.set_type(str);
						  vos.set_kol(dod);
						  vos.set_price(dob);
						  vos.set_smth(boo);
						  vos.set_shelf_life(goh);
						  sybd* syb = new ovos(vos);
						  vovos.push_back(syb);
					  }
					  else
					  {
						  in >> str >> dod >> dob >> dfg >> goh;
						  voso.set_name(n);
						  voso.set_type(str);
						  voso.set_kol(dod);
						  voso.set_price(dob);
						  voso.set_smth(dfg);
						  voso.set_shelf_life(goh);
						  sybd* syb = new fruit(voso);
						  vovos.push_back(syb);
					  }
				  }
				  vovos.pop_back();
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 2:
		{
				  cout << "In free version you can't load more than 10 items from the file." << endl;
				  int j = 0;
				  while (in)
				  {
					  in >> n;
					  if (n)
					  {
						  in >> str >> dod >> dob >> boo >> goh;
						  vos.set_name(n);
						  vos.set_type(str);
						  vos.set_kol(dod);
						  vos.set_price(dob);
						  vos.set_smth(boo);
						  vos.set_shelf_life(goh);
						  sybd* syb = new ovos(vos);
						  vovos.push_back(syb);
					  }
					  else
					  {
						  in >> str >> dod >> dob >> dfg >> goh;
						  voso.set_name(n);
						  voso.set_type(str);
						  voso.set_kol(dod);
						  voso.set_price(dob);
						  voso.set_smth(dfg);
						  voso.set_shelf_life(goh);
						  sybd* syb = new fruit(voso);
						  vovos.push_back(syb);
					  }
					  if (j < 9)
						  j++;
					  else break;
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 3:
		{
				  cout << "In trial version you can load from the file one item only." << endl;
				  in >> n;
				  if (n)
				  {
					  in >> str >> dod >> dob >> boo >> goh;
					  vos.set_name(n);
					  vos.set_type(str);
					  vos.set_kol(dod);
					  vos.set_price(dob);
					  vos.set_smth(boo);
					  vos.set_shelf_life(goh);
					  sybd* syb = new ovos(vos);
					  vovos.push_back(syb);
				  }
				  else
				  {
					  in >> str >> dod >> dob >> dfg >> goh;
					  voso.set_name(n);
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(dfg);
					  voso.set_shelf_life(goh);
					  sybd* syb = new fruit(voso);
					  vovos.push_back(syb);
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		}
	}
	in.close();
	return vovos;
}

void menu(vector<sybd*>& vfru, int right, string user_name)
{
	int h;
	int d;
	int t = 0;
	int e = 0;
	double right2 = right;
	while (1)
	{
		cout << "1. Start\n2. Exit program" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
		{
				  while (1)
				  {
					  t = 0;
					  cout << "What do you want to do?\n1. Add a new element\n2. Delete an existing element\n3. Find an element in BBase\n4. Save BBase of elements to disk\n5. Load BBase of elements from the disk\n6. Show BBase of elements on the screen\n7. Move product to another category\n8. Profits from the sale of all elements stock including tax equal\n9.Exit program\n" << endl;
					  cin >> h;
					  switch (h)
					  {
					  case 1:
					  {
								add_smth(vfru);
								break;
					  }
					  case 2:
					  {
								delete_smth(vfru);
								break;
					  }
					  case 3:
					  {
								string str;
								int f;
								while (1)
								{
									int z = 0;
									cout << "Enter name of element to search:\n" << endl;
									cin >> str;
									int ut = search_smth(vfru, str);
									if (ut != -1)
									{
										cout << "Change information about it?\n1.Yes\n2.No\n3.Return to menu\n\n\n";
										cin >> f;
										switch (f)
										{
										case 1:
										{
												  while (1)
												  {
													  bool bo = vfru[ut]->get_name();
													  int k;
													  if (bo)
													  {
														  cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.GMO\n4.Amount (in lb)\n5. Shelf life (in month)\n6. Return to previous menu\n\n\n";
													  }
													  else
														  cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.Origin country\n4.Amount (in lb)\n5. Shelf life (in month)\n6. Return to previous menu\n\n\n";
													  cin >> k;
													  switch (k)
													  {
													  case 1:
													  {
																cout << "Enter a new name: \n";
																vfru[ut]->ust_string();
																break;
													  }
													  case 2:
													  {
																cout << "Enter a new price:\n";
																vfru[ut]->ust_double();
																break;
													  }
													  case 3:
													  {
																if (bo) cout << "Enter a new indicator of presence of GMOs (1 - yes, 0 - no)\n";
																else cout << "Enter a new origin country\n";
																vfru[ut]->ust_smth();
																break;
													  }
													  case 4:
													  {
																cout << "Enter a new amount (in lb)\n";
																vfru[ut]->ust_doub();
																break;
													  }
													  case 5:
													  {
																vfru[ut]->ust_dooo();
																break;
													  }
													  case 6:
													  {
																z++;
																break;
													  }
													  }
													  if (z != 0)
														  break;
												  }
										}
										case 2:
										{
												  z++;
												  break;
										}
										case 3:
										{
												  z++;
												  break;
										}
										}
									}
									else cout << "Element not found" << endl;
									if (z != 0)
										break;
								}
								break;
					  }
					  case 4:
					  {
								file_save(vfru, right, user_name);
								break;
					  }
					  case 5:
					  {
								vfru = load_file(right2);
								break;
					  }
					  case 6:
					  {
								print_smth(vfru);
								break;
					  }
					  case 7:
					  {
								trans_sybd(vfru);
								break;
					  }
					  case 8:
					  {
								double tem = profit(vfru);
								cout << "Profits from the sale of elements stock including tax equal is " << tem << "$" << endl;
								break;
					  }
					  case 9:
					  {
								t++;
								break;
					  }
					  }
					  if (t != 0)
						  break;
				  }
				  e++;
				  break;
		}
		case 2:
		{
				  e++;
				  break;
		}
		}
			if (e != 0)
				break;
	}
}

void reg(vector<password>& vpas)
{
	string sdf, dfg;
	int fgh;
	password gi;
	cout << "New User Registration:\nEnter your username and password and program version(1 - Premium, 2 - Free, 3 - Trial) : " << endl;
	cin >> sdf;
	int iy = 0;
	vector<password>::iterator it = vpas.begin();
	for (it; it != vpas.end(); ++it)
	{
		if (it->get_name() == sdf)
		{
			cout << "User already exist" << endl;
			iy++;
		}
		if (iy > 0)
			break;
	}
	if (iy == 0)
	{
		gi.set_name(sdf);
		cin >> dfg;
		gi.set_pass(dfg);
		cin >> fgh;
		gi.set_access(fgh);
		vpas.push_back(gi);
		ofstream out("C:\\BBase\\Pass\\key.serd");
		vector<password>::iterator it = vpas.begin();
		for (it; it != vpas.end(); ++it)
		{
			out << it->get_name();
			out << " ";
			out << it->get_pas();
			out << " ";
			out << it->get_access();
			out << "\n";
		}
	}
}

int main()
{
	int hgjf=0;
	vector<sybd*> suj;
    vector<password> vpas;
	vector<password>::iterator bh;
	vector<ovos> vovos;
	vector<fruit> vfru;
	password gi;
	string sdf,dfg;
	int asd = 0;
	int h;
    int xcv = 0;
	CreateDirectoryW(L"C:\\BBase", NULL);
	CreateDirectoryW(L"C:\\BBase\\Pass", NULL);
	ifstream in("C:\\BBase\\Pass\\key.serd");
	while (in)
	{
		string str1, str2;
		int fgh;
		in >> str1 >> str2 >> fgh;
		gi.set_name(str1);
		gi.set_pass(str2);
		gi.set_access(fgh);
		vpas.push_back(gi);
	}
	if (vpas.capacity())
	{
		vpas.pop_back();
	}
	while (1)
	{
		if (!vpas.capacity())
		{
			reg(vpas);
		}
		else
		{
			vector<password>::iterator hj = vpas.end();
			vector<password>::iterator it = vpas.begin();
			cout << "Authorization:\n1. Register\n2. Log into existing account\n3. Exit programm " << endl;
			cin >> h;
			switch (h)
			{
			case 1:
			{
					  reg(vpas);
					  break;
			}
			case 2:
			{
					  while (1)
					  {
						  cout << "Enter username and password: " << endl;
						  cin >> sdf;
						  cin >> dfg;
						  for (it; it != vpas.end(); it++)
						  {
							  if ((it->get_name() == sdf) && (it->get_pas() == dfg))
							  {
								  hj = it;
							  }
						  }
						  if (hj != vpas.end())
						  {
							  menu(suj, hj->get_access(), hj->get_name());
							  vector<password>::iterator uy = vpas.begin();
							  ofstream out("C:\\BBase\\Pass\\key.serd");
							  for (uy; uy != vpas.end(); uy++)
							  {
								  out << uy->get_name();
								  out << " ";
								  out << uy->get_pas();
								  out << " ";
								  out << uy->get_access();
								  out << "\n";
							  }
							  asd++;
							  break;
						  }
						  else
						  {
							  cout << "Invalid username and/or password. Try again. Maybe, you want return to main menu?" << endl << "1. Return to main menu\n2. Try again\n";
							  int asg;
							  cin >> asg;
							  if (asg == 1)
								  xcv++;
						  }
						  if (xcv != 0)
							  break;
					  }
					  break;
			}
			case 3: 
			{
				hgjf++;
				break; 
			}
			}
		}
		if (asd != 0 || hgjf>0)
		break;
	}
	return 0;
}