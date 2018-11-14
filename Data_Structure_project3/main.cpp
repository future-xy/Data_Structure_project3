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


string ui = "��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"��������������������������������������������������������������������������������������������������������\n"
"�������������������������������������������������������������������������������������������������������� \n";

void Initial()
{
	cout << ui;
	cout << "��ӭʹ�ü��׹��������\n";
	cout << "�����Ƿ��½?\n";
	cout << "0.��\n"
		<< "1.��\n";
	int order;
	cin >> order;
	if (order)
	{
		if (sign_in() == tourist)
		{
			cout << "\n�˺Ż��������";

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
		cout << "�˳�����or���µ�½?\n";
		cout << "0.�˳�\n"
			<< "1.��¼\n";
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
		cout << username << "�峤�����ã�\n";
		cout << "��ѡ�����:\n"
			<< "0.�˳�\n"
			<< "1.���\n"
			<< "2.���\n"
			<< "3.������\n"
			<< "4.�Ƴ�����\n"
			<< "5.����\n"
			<< "6.��������\n"
			<< "7.�鿴���������Ϣ\n"
			<< "8.�ޱ�����\n"
			<< "9.�����峤\n";
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
			cout << "��������ż����:";
			cin >> name;
			cout << "��������ż����:";
			cin >> birthday;
			cout << "������������:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "ף" << username << " " << name << "����úϣ�\n";
			break;
		case 2:
			cout << "������ʱ��:\n";
			cin >> date;
			cout << "�þۺ�ɢ~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "�����������:";
			cin >> name;
			cout << "�����뺢������:";
			cin >> birthday;
			cout << "�����뺢���Ա�:";
			cin >> gender_str;
			if (gender_str == "��")
				gender = true;
			else
				gender = false;
				shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
				break;
		case 4:
			cout << "�����뺢������:\n";
			cin >> name;
			cout << "����������:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "����������:\n";
			cin >> date;
			cout << "�ڰ�˳��\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "������Ҫ���ҵ�����:";
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
					cout << "���޴���\n";
				}
			}
			break;
		case 7:
			cout << "������Ҫ�鿴�ļ���:";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "�˼��ײ�����\n";
			break;
		case 8:
			cout << "���׵ı䶯:\n";
			shelf[hometown]->PreRepair();
			shelf[hometown]->Repair();
			break;
		case 9:
			cout << "�����������峤����:";
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
		cout << username << "�����ã�\n";
		cout << "��ѡ�����:\n"
			<< "0.�˳�\n"
			<< "1.���\n"
			<< "2.���\n"
			<< "3.������\n"
			<< "4.�Ƴ�����\n"
			<< "5.����\n"
			<< "6.��������\n"
			<< "7.�鿴���������Ϣ\n";
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
			cout << "��������ż����:";
			cin >> name;
			cout << "��������ż����:";
			cin >> birthday;
			cout << "������������:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "ף" << username << " " << name << "����úϣ�\n";
			break;
		case 2:
			cout << "������ʱ��:\n";
			cin >> date;
			cout << "�þۺ�ɢ~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "�����������:";
			cin >> name;
			cout << "�����뺢������:";
			cin >> birthday;
			cout << "�����뺢���Ա�:";
			cin >> gender_str;
			if (gender_str == "��")
				gender = true;
			else
				gender = false;
			shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
			break;
		case 4:
			cout << "�����뺢������:\n";
			cin >> name;
			cout << "����������:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "����������:\n";
			cin >> date;
			cout << "�ڰ�˳��\n";
			shelf[hometown]->_Die(username, date);
			break;
		case 6:
			cout << "������Ҫ���ҵ�����:\n";
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
					cout << "���޴���\n";
				}
			}
			break;
		case 7:
			cout << "������Ҫ�鿴�ļ���:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "�˼��ײ�����\n";
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
		cout << "�ο�ģʽ\n";
		cout << "��ǰ����ļ�����:\n";
		for (auto item : shelf)
		{
			cout << "��" << item.first << "��" << endl;
		}
		cout << "��ѡ�����:\n"
			<< "0.�˳�\n"
			<< "1.��������\n"
			<< "2.�鿴���������Ϣ\n"
			<< "3.��������\n";
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
			cout << "������Ҫ���ҵ�����:\n";
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
					cout << "���޴���\n";
				}
			}
			break;
		case 2:
			cout << "������Ҫ�鿴�ļ���:\n";
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "�˼��ײ�����\n";
			break;
		case 3:
			cout << "���������:";
			cin >> temp_family;
			cout << "��������������:";
			cin >> anc_family_name;
			cout << "��������������:";
			cin >> anc_first_name;
			cout << "����������:";
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
	cout << "������ԭ���룺";
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
			cout << "�����������룺";
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
			cout << "�������\n";
		}

	}
}