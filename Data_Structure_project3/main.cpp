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


string ui = "　　　　　　　　　　。。。。　　　　　　　　　　　　　　　　　　　　　　　。。。　　　　。。。　　　　　\n"
"　　　　　　　　　　　。。。。　　　　　　　　　　　　　　。。　　　　　　　。。。　　。。。。　　　　　\n"
"　　　　。。　　　　　　。。。　　　　　　　。　　　　　　。。。　　　　　　。。。　　。。　　　　　　　\n"
"　　　。。。。。。。。。。。。。。。。。。。。。　　　　　　。。。　　　　　。。。　。。。　　。。。　　\n"
"　　　。。。　　　　　　　　　　　　　　　。。。。　　　　　。。。　。。。。。。。。。。。。。。。。。　\n"
"　　。。。　　　　　　　　　　　　　　　。。。　　　　　　　　　　　　　　　　。。　。。。　　。　　　　\n"
"　　。。。　　　　　　　　　　　　。。。。。　　　　　　　　　　　　　。。　　。。　。。。　。。。　　　\n"
"　　　　　。。。。。。。。。。。。。。。。　　　　　　　　　　　　　　。。。　。。　。。。　。。。。　　\n"
"　　　　　　　　　。。。。　　　　　　　　　　　　　　　　　。。。　　　。。。。。　。。。。。。　　　　\n"
"　　　　　　　　。。。。。　　　　　。。。　　　　　。。。。。。。　　　。。。。。　。。。。。　　　　　\n"
"　　　　　　　。。。　。。。　　　。。。。。　　　　　　　　。。。　　　　　　。。　。。。。　　。。。　\n"
"　　　　　。。。　　　。。。。。。。。　　　　　　　　　　　。。。。。。。。。。。。。。。。。。。。。。\n"
"　　　。。。。　　　。。。。。。。。　　　　　　　　　　　　。。。　　　　　　　　　　　　　　　　　　　\n"
"　。。。。　　　　。。。　。。。。。　　　　　　　　　　　　。。。　　　。。　　　　　　　　。。　　　　\n"
"　　　　　　　。。。　　。。。。。。。　　　　　　　　　　　。。。　　　。。。。。。。。。。。。。　　　\n"
"　　　　　　。。。　　。。。。。　。。　　　　　　　　　　　。。。　　　。。。　　　　　　。。。　　　　\n"
"　　　　。。。　　　。。。。。。　。。。　　　　　　　　　　。。。　。。。。。　　　　　　。。。　　　　\n"
"　　。。。　　　　。。。。　。。。　。。。　　　　　　　　　。。。。。。。。。　　　　　　。。。　　　　\n"
"　　　　　　　　。。。　　　。。。　　。。。。　　　　　　　。。。。。　。。。。。。。。。。。。　　　　\n"
"　　　　　　。。。　　　　。。。。　　　。。。。。　　　　　。。。。　　。。。　　　　　　。。。　　　　\n"
"　　　　。。。。　　　　　。。。　　　　　。。　　　　　　　。。。　　　。。。　　　　　　。。。　　　　\n"
"　　。。。。　　　。。。。。。。　　　　　　　　　　　　　　。。。　　　。。。。。。。。。。。。　　　　\n"
"　。。　　　　　　　　。。。。　　　　　　　　　　　　　　　　　　　　　。。。　　　　　　。。。　　　　\n"
"　　　　　　　　　　　　。　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 \n";

void Initial()
{
	cout << ui;
	cout << "散哭聞喘社惇砿尖罷周��\n";
	cout << "萩諒頁倦鞠遜?\n";
	cout << "0.倦\n"
		<< "1.頁\n";
	int order;
	cin >> order;
	if (order)
	{
		if (sign_in() == tourist)
		{
			cout << "\n嬲催賜畜鷹危列";

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
		cout << "曜竃殻會or嶷仟鞠遜?\n";
		cout << "0.曜竃\n"
			<< "1.鞠村\n";
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
		cout << username << "怛海��艇挫��\n";
		cout << "萩僉夲荷恬:\n"
			<< "0.曜竃\n"
			<< "1.潤脂\n"
			<< "2.宣脂\n"
			<< "3.伏頃徨\n"
			<< "4.卞茅頃徨\n"
			<< "5.棒蘭\n"
			<< "6.臥孀侖兆\n"
			<< "7.臥心社怛児云佚連\n"
			<< "8.俐園怛惇\n"
			<< "9.踐斑怛海\n";
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
			cout << "萩補秘塘甜侖兆:";
			cin >> name;
			cout << "萩補秘塘甜伏晩:";
			cin >> birthday;
			cout << "萩補秘潤脂晩豚:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "廝" << username << " " << name << "為定挫栽��\n";
			break;
		case 2:
			cout << "萩補秘扮寂:\n";
			cin >> date;
			cout << "挫詔挫柊~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "萩公頃徨軟兆:";
			cin >> name;
			cout << "萩補秘頃徨伏晩:";
			cin >> birthday;
			cout << "萩補秘頃徨來艶:";
			cin >> gender_str;
			if (gender_str == "槻")
				gender = true;
			else
				gender = false;
				shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
				break;
		case 4:
			cout << "萩補秘頃徨侖兆:\n";
			cin >> name;
			cout << "萩補秘晩豚:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "萩補秘晩豚:\n";
			cin >> date;
			cout << "准挨乏延\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "萩補秘勣臥孀議侖兆:";
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
					cout << "臥涙緩繁\n";
				}
			}
			break;
		case 7:
			cout << "萩補秘勣臥心議社惇:";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "緩社惇音贋壓\n";
			break;
		case 8:
			cout << "怛惇議延強:\n";
			shelf[hometown]->PreRepair();
			shelf[hometown]->Repair();
			break;
		case 9:
			cout << "萩補秘和販怛海侖兆:";
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
		cout << username << "��艇挫��\n";
		cout << "萩僉夲荷恬:\n"
			<< "0.曜竃\n"
			<< "1.潤脂\n"
			<< "2.宣脂\n"
			<< "3.伏頃徨\n"
			<< "4.卞茅頃徨\n"
			<< "5.棒蘭\n"
			<< "6.臥孀侖兆\n"
			<< "7.臥心社怛児云佚連\n";
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
			cout << "萩補秘塘甜侖兆:";
			cin >> name;
			cout << "萩補秘塘甜伏晩:";
			cin >> birthday;
			cout << "萩補秘潤脂晩豚:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "廝" << username << " " << name << "為定挫栽��\n";
			break;
		case 2:
			cout << "萩補秘扮寂:\n";
			cin >> date;
			cout << "挫詔挫柊~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "萩公頃徨軟兆:";
			cin >> name;
			cout << "萩補秘頃徨伏晩:";
			cin >> birthday;
			cout << "萩補秘頃徨來艶:";
			cin >> gender_str;
			if (gender_str == "槻")
				gender = true;
			else
				gender = false;
			shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
			break;
		case 4:
			cout << "萩補秘頃徨侖兆:\n";
			cin >> name;
			cout << "萩補秘晩豚:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "萩補秘晩豚:\n";
			cin >> date;
			cout << "准挨乏延\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "萩補秘勣臥孀議侖兆:\n";
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
					cout << "臥涙緩繁\n";
				}
			}
			break;
		case 7:
			cout << "萩補秘勣臥心議社惇:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "緩社惇音贋壓\n";
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
		cout << "嗄人庁塀\n";
		cout << "輝念隠贋議社惇嗤:\n";
		for (auto item : shelf)
		{
			cout << "ゞ" << item.first << "〃" << endl;
		}
		cout << "萩僉夲荷恬:\n"
			<< "0.曜竃\n"
			<< "1.臥孀侖兆\n"
			<< "2.臥心社怛児云佚連\n"
			<< "3.秀羨社惇\n";
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
			cout << "萩補秘勣臥孀議侖兆:\n";
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
					cout << "臥涙緩繁\n";
				}
			}
			break;
		case 2:
			cout << "萩補秘勣臥心議社惇:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "緩社惇音贋壓\n";
			break;
		case 3:
			cout << "萩補秘社怛:";
			cin >> temp_family;
			cout << "萩補秘怕枠侖箆:";
			cin >> anc_family_name;
			cout << "萩補秘怕枠兆忖:";
			cin >> anc_first_name;
			cout << "萩補秘伏晩:";
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
	cout << "萩補秘圻畜鷹��";
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
			cout << "萩補秘仟畜鷹��";
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
			cout << "畜鷹危列\n";
		}

	}
}