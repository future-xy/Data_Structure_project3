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



void Initial()
{
	preprocessing();
//	cout << ui;
	int order;
	cin >> order;
	if (order)
	{
		if (sign_in() == tourist)
		{
			cout << "查无此人\n";
		}
	}
}
void model_1();
void model_2();
void model_3();
int main() {

	Initial();
	int ok = 1;
	while (ok)
	{
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
		cout << username << "族长，您好！\n";
		cout << "请选择操作:\n"
			<< "0.退出\n"
			<< "1.结婚\n"
			<< "2.离婚\n"
			<< "3.生孩子\n"
			<< "4.移除孩子\n"
			<< "5.死亡\n"
			<< "6.查找姓名\n"
			<< "7.查看家族基本信息\n"
			<< "8.修编族谱\n"
			<< "9.禅让族长\n";
		string name, birthday, marriage_date;
		Member* people = nullptr;
		int order;
		cin >> order;
		switch (order)
		{
		case 1:
			cout << "请输入配偶姓名:";
			cin >> name;
			cout << "";
			cin >> birthday;
			cout << "";
			cin >> marriage_date;
			shelf[hometown]->GetMarried(username, name, birthday, marriage_date);
			cout << "祝" << username << " " << name << "百年好合！\n";
			break;
		case 2:
			cout << "好聚好散~\n";
			shelf[hometown]->Divorce(username);
			break;
		case 3:

			break;
		case 4:
			cout << "请输入孩子姓名:\n";
			cin >> name;
			shelf[hometown]->RemoveChild(username, name);

			break;
		case 5:
			cout << "节哀顺变\n";
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
					cout << "查无此人\n";
				}
			}
			break;
		case 7:
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "此家谱不存在\n";
			break;
		case 8:
			cout << "族谱的变动:\n";

			break;
		case 9:
			cout << "请输入下任族长姓名:";
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
		cout << username << "，您好！\n";
		cout << "请选择操作:\n"
			<< "0.退出\n"
			<< "1.结婚\n"
			<< "2.离婚\n"
			<< "3.生孩子\n"
			<< "4.移除孩子\n"
			<< "5.死亡\n"
			<< "6.查找姓名\n"
			<< "7.查看家族基本信息\n";
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
			cout << "请输入配偶姓名:";
			cin >> name;
			cout << "";
			cin >> birthday;
			cout << "";
			cin >> marriage_date;
			shelf[hometown]->GetMarried(username, name, birthday, marriage_date);
			cout << "祝" << username << " " << name << "百年好合！\n";
			break;
		case 2:
			cout << "好聚好散~\n";
			shelf[hometown]->Divorce(username);
			break;
		case 3:

			break;
		case 4:
			cout << "请输入孩子姓名:\n";
			cin >> name;
			shelf[hometown]->RemoveChild(username, name);

			break;
		case 5:
			cout << "节哀顺变\n";
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
					cout << "查无此人\n";
				}
			}
			break;
		case 7:
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "此家谱不存在\n";
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
		cout << "当前保存的家谱有:\n";
		for (auto item : shelf)
		{
			cout << "《" << item.first << "》" << endl;
		}
		cout << "请选择操作:\n"
			<< "0.退出\n"
			<< "1.查找姓名\n"
			<< "2.查看家族基本信息\n"
			<< "3.建立家谱\n";
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
					cout << "查无此人\n";
				}
			}
			break;
		case 2:
			cin >> name;
			if (shelf.count(name))
				cout << shelf[name]->Tree_to_String();
			else
				cout << "此家谱不存在\n";
			break;
		case 3:
			cout << "请输入家族:";
			cin >> temp_family;
			cout << "请输入祖先姓氏:";
			cin >> anc_family_name;
			cout << "请输入祖先名字:";
			cin >> anc_first_name;
			cout << "请输入生日:";
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