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
			cout << "²éÎÞ´ËÈË\n";
		}
	}
}
void model_1();
void model_2();
void model_3();
int main() {

	preprocessing();
	Initial();
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
		string name, birthday, marriage_date;
		Member* people = nullptr;
		int order;
		cin >> order;
		switch (order)
		{
		case 1:
			cout << "ÇëÊäÈëÅäÅ¼ÐÕÃû:";
			cin >> name;
			cout << "";
			cin >> birthday;
			cout << "";
			cin >> marriage_date;
			shelf[hometown]->GetMarried(username, name, birthday, marriage_date);
			cout << "×£" << username << " " << name << "°ÙÄêºÃºÏ£¡\n";
			break;
		case 2:
			cout << "ºÃ¾ÛºÃÉ¢~\n";
			shelf[hometown]->Divorce(username);
			break;
		case 3:

			break;
		case 4:
			cout << "ÇëÊäÈëº¢×ÓÐÕÃû:\n";
			cin >> name;
			shelf[hometown]->RemoveChild(username, name);

			break;
		case 5:
			cout << "½Ú°§Ë³±ä\n";
			shelf[hometown]->Die(username);
			break;
		case 6:
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
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "´Ë¼ÒÆ×²»´æÔÚ\n";
			break;
		case 8:
			cout << "×åÆ×µÄ±ä¶¯:\n";

			break;
		case 9:
			cout << "ÇëÊäÈëÏÂÈÎ×å³¤ÐÕÃû:";
			cin >> name;
			shelf[hometown]->SetPatriarch(name);
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
		string name, birthday, marriage_date;
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
			cout << "";
			cin >> birthday;
			cout << "";
			cin >> marriage_date;
			shelf[hometown]->GetMarried(username, name, birthday, marriage_date);
			cout << "×£" << username << " " << name << "°ÙÄêºÃºÏ£¡\n";
			break;
		case 2:
			cout << "ºÃ¾ÛºÃÉ¢~\n";
			shelf[hometown]->Divorce(username);
			break;
		case 3:

			break;
		case 4:
			cout << "ÇëÊäÈëº¢×ÓÐÕÃû:\n";
			cin >> name;
			shelf[hometown]->RemoveChild(username, name);

			break;
		case 5:
			cout << "½Ú°§Ë³±ä\n";
			shelf[hometown]->Die(username);
			break;
		case 6:
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
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "´Ë¼ÒÆ×²»´æÔÚ\n";
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
			cin >> name;
			for (auto item : shelf)
			{
				people = item.second->Search(name);
				if (people != nullptr)
				{

				}
				else
				{
					cout << "²éÎÞ´ËÈË\n";
				}
			}
			break;
		case 2:
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