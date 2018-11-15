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


string ui = "　　　　　　　　　　家家家家　　　　　　　　　　　　　　　　　　　　　　　谱谱谱　　　　谱谱谱　　　　　\n"
"　　　　　　　　　　　家家家家　　　　　　　　　　　　　　谱谱　　　　　　　谱谱谱　　谱谱谱谱　　　　　\n"
"　　　　家家　　　　　　家家家　　　　　　　家　　　　　　谱谱谱　　　　　　谱谱谱　　谱谱　　　　　　　\n"
"　　　家家家家家家家家家家家家家家家家家家家家家　　　　　　谱谱谱　　　　　谱谱谱　谱谱谱　　谱谱谱　　\n"
"　　　家家家　　　　　　　　　　　　　　　家家家家　　　　　谱谱谱　谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱　\n"
"　　家家家　　　　　　　　　　　　　　　家家家　　　　　　　　　　　　　　　　谱谱　谱谱谱　　谱　　　　\n"
"　　家家家　　　　　　　　　　　　家家家家家　　　　　　　　　　　　　谱谱　　谱谱　谱谱谱　谱谱谱　　　\n"
"　　　　　家家家家家家家家家家家家家家家家　　　　　　　　　　　　　　谱谱谱　谱谱　谱谱谱　谱谱谱谱　　\n"
"　　　　　　　　　家家家家　　　　　　　　　　　　　　　　　谱谱谱　　　谱谱谱谱谱　谱谱谱谱谱谱　　　　\n"
"　　　　　　　　家家家家家　　　　　家家家　　　　　谱谱谱谱谱谱谱　　　谱谱谱谱谱　谱谱谱谱谱　　　　　\n"
"　　　　　　　家家家　家家家　　　家家家家家　　　　　　　　家谱谱　　　　　　谱谱　谱谱谱谱　　谱谱谱　\n"
"　　　　　家家家　　　家家家家家家家家　　　　　　　　　　　谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱谱\n"
"　　　家家家家　　　家家家家家家家家　　　　　　　　　　　　谱谱谱　　　　　　　　　　　　　　　　　　　\n"
"　家家家家　　　　家家家　家家家家家　　　　　　　　　　　　谱谱谱　　　谱谱　　　　　　　　谱谱　　　　\n"
"　　　　　　　家家家　　家家家家家家家　　　　　　　　　　　谱谱谱　　　谱谱谱谱谱谱谱谱谱谱谱谱谱　　　\n"
"　　　　　　家家家　　家家家家家　家家　　　　　　　　　　　谱谱谱　　　谱谱谱　　　　　　谱谱谱　　　　\n"
"　　　　家家家　　　家家家家家家　家家家　　　　　　　　　　谱谱谱　谱谱谱谱谱　　　　　　谱谱谱　　　　\n"
"　　家家家　　　　家家家家　家家家　家家家　　　　　　　　　谱谱谱谱谱谱谱谱谱　　　　　　谱谱谱　　　　\n"
"　　　　　　　　家家家　　　家家家　　家家家家　　　　　　　谱谱谱谱谱　谱谱谱谱谱谱谱谱谱谱谱谱　　　　\n"
"　　　　　　家家家　　　　家家家家　　　家家家家家　　　　　谱谱谱谱　　谱谱谱　　　　　　谱谱谱　　　　\n"
"　　　　家家家家　　　　　家家家　　　　　家家　　　　　　　谱谱谱　　　谱谱谱　　　　　　谱谱谱　　　　\n"
"　　家家家家　　　家家家家家家家　　　　　　　　　　　　　　谱谱谱　　　谱谱谱谱谱谱谱谱谱谱谱谱　　　　\n"
"　家家　　　　　　　　家家家家　　　　　　　　　　　　　　　　　　　　　谱谱谱　　　　　　谱谱谱　　　　\n"
"　　　　　　　　　　　　家　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 \n";

void Initial()
{
	cout << ui;
	cout << "欢迎使用家谱管理软件！\n";
	cout << "请问是否登陆?\n";
	cout << "0.否\n"
		<< "1.是\n";
	int order;
	cin >> order;
	if (order)
	{
		if (sign_in() == tourist)
		{
			cout << "\n账号或密码错误";

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
		system("cls");
		cout << "退出程序or重新登陆?\n";
		cout << "0.退出\n"
			<< "1.登录\n";
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
		cout << username << "族长，您好！\n";
		cout << "请选择操作:\n"
			<< "0.退出\n"
			<< "1.结婚\n"
			<< "2.离婚\n"
			<< "3.生子\n"
			<< "4.移除孩子\n"
			<< "5.死亡\n"
			<< "6.查找姓名\n"
			<< "7.查看家族基本信息\n"
			<< "8.修编族谱\n"
			<< "9.禅让族长\n"
			<< "10.修改密码\n";
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
			cout << "请输入配偶姓名:";
			cin >> name;
			cout << "请输入配偶生日:";
			cin >> birthday;
			cout << "请输入结婚日期:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "祝" << username << " " << name << "百年好合！\n";
			break;
		case 2:
			cout << "请输入时间:\n";
			cin >> date;
			cout << "好聚好散~\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "请给孩子起名:";
			cin >> name;
			cout << "请输入孩子生日:";
			cin >> birthday;
			cout << "请输入孩子性别:";
			cin >> gender_str;
			if (gender_str == "男")
				gender = true;
			else
				gender = false;
				shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
				break;
		case 4:
			cout << "请输入孩子姓名:\n";
			cin >> name;
			cout << "请输入日期:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "请输入日期:\n";
			cin >> date;
			cout << "节哀顺变\n";
			shelf[hometown]->_Die(username, date);
			return;
			break;
		case 6:
			cout << "请输入要查找的姓名:";
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
			cout << "请输入要查看的家谱:";
			cin >> name;
			if (shelf.count(name))
				shelf[name]->Print();
			else
				cout << "此家谱不存在\n";
			break;
		case 8:
			cout << "族谱的变动:\n";
			shelf[hometown]->PreRepair();
			shelf[hometown]->Repair();
			break;
		case 9:
			cout << "请输入下任族长姓名:";
			cin >> name;
			shelf[hometown]->SetPatriarch(name);
			authority = clansman;
			return;
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
		cout << username << "，您好！\n";
		cout << "请选择操作:\n"
			<< "0.退出\n"
			<< "1.结婚\n"
			<< "2.离婚\n"
			<< "3.生子\n"
			<< "4.移除孩子\n"
			<< "5.死亡\n"
			<< "6.查找姓名\n"
			<< "7.查看家族基本信息\n"
			<< "8.修改密码\n";
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
			cout << "请输入配偶姓名:";
			cin >> name;
			cout << "请输入配偶生日:";
			cin >> birthday;
			cout << "请输入结婚日期:";
			cin >> marriage_date;
			shelf[hometown]->_GetMarried(username, name, birthday, marriage_date);
			cout << "祝" << username << " " << name << "百年好合！\n";
			break;
		case 2:
			cout << "请输入时间:\n";
			cin >> date;
			cout << "好聚好散。\n";
			shelf[hometown]->_Divorce(username, date);
			break;
		case 3:
			cout << "请给孩子起名:";
			cin >> name;
			cout << "请输入孩子生日:";
			cin >> birthday;
			cout << "请输入孩子性别:";
			cin >> gender_str;
			if (gender_str == "男")
				gender = true;
			else
				gender = false;
			shelf[hometown]->_GiveBirth(username, true, clansman, "", name, gender, birthday, true);
			break;
		case 4:
			cout << "请输入孩子姓名:\n";
			cin >> name;
			cout << "请输入日期:\n";
			cin >> date;
			shelf[hometown]->_RemoveChild(username, name, date);

			break;
		case 5:
			cout << "请输入日期:\n";
			cin >> date;
			cout << "节哀顺变\n";
			shelf[hometown]->_Die(username, date);
			return;
			break;
		case 6:
			cout << "请输入要查找的姓名:\n";
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
			cout << "请输入要查看的家谱:\n";
			cin >> name;
			if (shelf.count(name))
				shelf[name]->Print();
			else
				cout << "此家谱不存在\n";
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
		cout << "游客模式\n";
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
			cout << "请输入要查找的姓名:\n";
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
		case 2:
			cout << "请输入要查看的家谱:\n";
			cin >> name;
			if (shelf.count(name))
				shelf[name]->Print();
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
void changePw()
{
	cout << "请输入原密码：";
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
			cout << "\n请输入新密码：";
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
			cout << "密码错误\n";
		}

	}
}
