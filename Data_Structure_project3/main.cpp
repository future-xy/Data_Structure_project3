#include <iostream>
#include <string>
#include <map>

#include "IOCtr.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::map;


string ui = "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡£¡¡¡¡¡£¡£¡£¡¡¡¡\n"
"¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡\n"
"¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡£¡£¡£¡¡¡¡¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡¡¡£¡£¡¡¡£¡£¡£¡¡¡£¡£¡£¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡¡¡£¡£¡£¡¡¡£¡£¡£¡£¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡£¡£¡£¡£¡¡¡¡¡£¡£¡£¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£\n"
"¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡\n"
"¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡£¡£¡£¡£¡£¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡£¡£¡£¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡¡¡¡¡¡£¡£¡£¡¡¡¡¡¡¡¡\n"
"¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡£¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ \n";

void Initial()
{
	cout << ui;
	cout << "»¶Ó­Ê¹ÓÃ¼ÒÆ×¹ÜÀíÈí¼þ£¡\n";
	cout << "ÇëÎÊÊÇ·ñµÇÂ½?\n";
	cout << "0.·ñ\n"
		<< "1.ÊÇ\n";
	int order;
	cin >> order;
	if (order)
	{
		if (sign_in() == tourist)
		{
			cout << "\nÕËºÅ»òÃÜÂë´íÎó";

		}
	}
	cout << "\n";
	system("pause");
	system("cls");
}
void changePw();
void model_1();
void model_2();
void model_3();
int main() {

	preprocessing();
	int ok = 1;
	while (ok)
	{
		Initial();
		switch (authority)
		{
		case patriarch:
			model_1();
			break;
		case clansman:
			model_2();
			break;
		case tourist:
			model_3();
			break;
		default:
			break;
		}
		cout << "ÍË³ö³ÌÐòorÖØÐÂµÇÂ½?\n";
		cout << "0.ÍË³ö\n"
			<< "1.µÇÂ¼\n";
		cin >> ok;
		system("pause");
		system("cls");
	}
	if (save_all())
		cout << "Bye!\n";
	else
		cerr << "Error!\n";
	return 0;
	
}
void model_1()
{
	int ok = 1;
	const FamilyTree* cur_tree = shelf[hometown];

	while (ok)
	{
		cout << ui;
		cout << username << "×å³¤£¬ÄúºÃ£¡\n";
		cout << "ÇëÑ¡Ôñ²Ù×÷:\n"
			<< "0.ÍË³ö\n"
			<< "1.½á»é\n"
			<< "2.Àë»é\n"
			<< "3.Éúº¢×Ó\n"
			<< "4.ÒÆ³ýº¢×Ó\n"
			<< "5.ËÀÍö\n"
			<< "6.²éÕÒÐÕÃû\n"
			<< "7.²é¿´¼Ò×å»ù±¾ÐÅÏ¢\n"
			<< "8.ÐÞ±à×åÆ×\n"
			<< "9.ìøÈÃ×å³¤\n";
		string name, birthday, marriage_date, gender_str, date;
		bool gender;
		Member* people = nullptr;
		int order;
		cin >> order;
		switch (order)
		{
		case 0:
			ok = 0;
			break;
		case 1:
			cout << "ÇëÊäÈëÅäÅ¼ÐÕÃû:";
			cin >> name;
			cout << "ÇëÊäÈëÅäÅ¼ÉúÈÕ:";
			cin >> birthday;
			cout << "ÇëÊäÈë½á»éÈÕÆÚ:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "×£" << username << " " << name << "°ÙÄêºÃºÏ£¡\n";
			break;
		case 2:
			cout << "ÇëÊäÈëÊ±¼ä:\n";
			cin >> date;
			cout << "ºÃ¾ÛºÃÉ¢~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "Çë¸øº¢×ÓÆðÃû:";
			cin >> name;
			cout << "ÇëÊäÈëº¢×ÓÉúÈÕ:";
			cin >> birthday;
			cout << "ÇëÊäÈëº¢×ÓÐÔ±ð:";
			cin >> gender_str;
			if (gender_str == "ÄÐ")
				gender = true;
			else
				gender = false;
				shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
				break;
		case 4:
			cout << "ÇëÊäÈëº¢×ÓÐÕÃû:\n";
			cin >> name;
			cout << "ÇëÊäÈëÈÕÆÚ:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "ÇëÊäÈëÈÕÆÚ:\n";
			cin >> date;
			cout << "½Ú°§Ë³±ä\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "ÇëÊäÈëÒª²éÕÒµÄÐÕÃû:";
			cin >> name;
			for (auto item : shelf)
			{
				people = item.second->Search(name);
				if (people != nullptr)
				{
					cout << people->Getmessage();
				}
				else
				{
					cout << "²éÎÞ´ËÈË\n";
				}
			}
			break;
		case 7:
			cout << "ÇëÊäÈëÒª²é¿´µÄ¼ÒÆ×:";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "´Ë¼ÒÆ×²»´æÔÚ\n";
			break;
		case 8:
			cout << "×åÆ×µÄ±ä¶¯:\n";
			shelf[hometown]->PreRepair();
			shelf[hometown]->Repair();
			break;
		case 9:
			cout << "ÇëÊäÈëÏÂÈÎ×å³¤ÐÕÃû:";
			cin >> name;
			shelf[hometown]->SetPatriarch(name);
			break;
		case 10:
			changePw();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
void model_2()
{
	int ok = 1;
	const FamilyTree* cur_tree = shelf[hometown];
	while (ok)
	{
		cout << ui;
		cout << username << "£¬ÄúºÃ£¡\n";
		cout << "ÇëÑ¡Ôñ²Ù×÷:\n"
			<< "0.ÍË³ö\n"
			<< "1.½á»é\n"
			<< "2.Àë»é\n"
			<< "3.Éúº¢×Ó\n"
			<< "4.ÒÆ³ýº¢×Ó\n"
			<< "5.ËÀÍö\n"
			<< "6.²éÕÒÐÕÃû\n"
			<< "7.²é¿´¼Ò×å»ù±¾ÐÅÏ¢\n";
		string name, birthday, marriage_date, gender_str, date;
		bool gender;
		Member* people = nullptr;
		int order;
		cin >> order;
		switch (order)
		{
		case 0:
			ok = 0;
			break;
		case 1:
			cout << "ÇëÊäÈëÅäÅ¼ÐÕÃû:";
			cin >> name;
			cout << "ÇëÊäÈëÅäÅ¼ÉúÈÕ:";
			cin >> birthday;
			cout << "ÇëÊäÈë½á»éÈÕÆÚ:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "×£" << username << " " << name << "°ÙÄêºÃºÏ£¡\n";
			break;
		case 2:
			cout << "ÇëÊäÈëÊ±¼ä:\n";
			cin >> date;
			cout << "ºÃ¾ÛºÃÉ¢~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "Çë¸øº¢×ÓÆðÃû:";
			cin >> name;
			cout << "ÇëÊäÈëº¢×ÓÉúÈÕ:";
			cin >> birthday;
			cout << "ÇëÊäÈëº¢×ÓÐÔ±ð:";
			cin >> gender_str;
			if (gender_str == "ÄÐ")
				gender = true;
			else
				gender = false;
			shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
			break;
		case 4:
			cout << "ÇëÊäÈëº¢×ÓÐÕÃû:\n";
			cin >> name;
			cout << "ÇëÊäÈëÈÕÆÚ:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "ÇëÊäÈëÈÕÆÚ:\n";
			cin >> date;
			cout << "½Ú°§Ë³±ä\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "ÇëÊäÈëÒª²éÕÒµÄÐÕÃû:\n";
			cin >> name;
			for (auto item : shelf)
			{
				people = item.second->Search(name);
				if (people != nullptr)
				{
					cout << people->Getmessage();
				}
				else
				{
					cout << "²éÎÞ´ËÈË\n";
				}
			}
			break;
		case 7:
			cout << "ÇëÊäÈëÒª²é¿´µÄ¼ÒÆ×:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "´Ë¼ÒÆ×²»´æÔÚ\n";
			break;
		case 8:
			changePw();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

}
void model_3()
{
	int ok = 1;
	while (ok)
	{
		cout << ui;
		cout << "ÓÎ¿ÍÄ£Ê½\n";
		cout << "µ±Ç°±£´æµÄ¼ÒÆ×ÓÐ:\n";
		for (auto item : shelf)
		{
			cout << "¡¶" << item.first << "¡·" << endl;
		}
		cout << "ÇëÑ¡Ôñ²Ù×÷:\n"
			<< "0.ÍË³ö\n"
			<< "1.²éÕÒÐÕÃû\n"
			<< "2.²é¿´¼Ò×å»ù±¾ÐÅÏ¢\n"
			<< "3.½¨Á¢¼ÒÆ×\n";
		int order = 0;
		cin >> order;
		string name;
		Member* people = nullptr;
		string temp_family, anc_family_name, anc_first_name, birthday;
		FamilyTree* new_tree = nullptr;
		switch (order)
		{
		case 0:
			ok = 0;
			break;
		case 1:
			cout << "ÇëÊäÈëÒª²éÕÒµÄÐÕÃû:\n";
			cin >> name;
			for (auto item : shelf)
			{
				people = item.second->Search(name);
				if (people != nullptr)
				{
					cout << people->Getmessage();
				}
				else
				{
					cout << "²éÎÞ´ËÈË\n";
				}
			}
			break;
		case 2:
			cout << "ÇëÊäÈëÒª²é¿´µÄ¼ÒÆ×:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "´Ë¼ÒÆ×²»´æÔÚ\n";
			break;
		case 3:
			cout << "ÇëÊäÈë¼Ò×å:";
			cin >> temp_family;
			cout << "ÇëÊäÈë×æÏÈÐÕÊÏ:";
			cin >> anc_family_name;
			cout << "ÇëÊäÈë×æÏÈÃû×Ö:";
			cin >> anc_first_name;
			cout << "ÇëÊäÈëÉúÈÕ:";
			cin >> birthday;
			new_tree = new FamilyTree(true, patriarch, anc_family_name, anc_first_name, true, birthday, false);
			shelf[temp_family] = new_tree;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

}
void changePw()
{
	cout << "ÇëÊäÈëÔ­ÃÜÂë£º";
	int i = 0;
	char ch;
	char pw[50];
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b'&&i > 0)
		{
			cout << "\b \b";
			--i;
		}
		else if (ch != '\b'&&ch != '\0')
		{
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	unsigned long long password = String_HashValue(pw);
	
	for (auto item : shelf)
	{
		Status temp = item.second->Log_in(username, password);
		if (temp != wrong_pw)
		{
			cout << "ÇëÊäÈëÐÂÃÜÂë£º";
			int i = 0;
			char ch;
			char pw[50];
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b'&&i > 0)
				{
					cout << "\b \b";
					--i;
				}
				else if (ch != '\b'&&ch != '\0')
				{
					pw[i++] = ch;
					cout << "*";
				}
			}
			pw[i] = '\0';
			unsigned long long password = String_HashValue(pw);
			shelf[hometown]->setPassword(username, password);
			break;
		}
		else
		{
			cout << "ÃÜÂë´íÎó\n";
		}

	}
}