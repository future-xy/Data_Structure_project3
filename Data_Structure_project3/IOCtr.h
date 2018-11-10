#pragma once

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<fileapi.h>
#include<conio.h>
#include<string>
#include<vector>

#include"FamilyTree.h"
#include"Member.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
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


enum Status
{
	patriarch, clansman, tourist
};
string hometown = "UNKNOW";
Status authority = tourist;

Status sign_in()
{
	cout << "萩補秘嬲催��";
	string username;
	cin >> username;
	cout<< "萩補秘畜鷹��";
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
	//We will judge the status by looking in the map;
	for (auto item : shelf)
	{
		Status temp = item.second.Log_in(username, password);

		switch (temp)
		{
		case patriarch:
			authority = patriarch;
			hometown = item.first;
			break;
		case clansman:
			authority = clansman;
			hometown = item.first;
			break;
		case tourist:
			break;
		default:
			break;
		}
	}

}
unsigned long long String_HashValue(string s) {
	unsigned long long PrimeBase = 233, PrimeModular = 19260817,
		result = 0;

	for (auto c : s)
		result = (result*PrimeBase + c) % PrimeModular;
	return result;
}
void preprocessing()
{
	ifstream myfilein("Familytree.log");
	if (!myfilein.is_open())
		return;
	string temp;
	myfilein >> temp;
	string information;
	const string path = ".\\";
	while (myfilein >> information)
	{
		if (information.empty() || information == "\n")
			continue;
		ifstream mytxtin(path + information + "\\" + information + ".txt");
		string info = getTxt(mytxtin);
		FamilyTree newTree(info);
		newTree.Anc = dfs_get(path + information + "\\" + newTree.forefather(), newTree.forefather());
		shelf[information] = newTree;
	}
}
bool save_all()
{
	string information = "隠贋議社惇��\n";
	for (auto item : shelf)
	{
		information += item.first + "\n";
	}
	ofstream myfileout("Familytree.log");
	myfileout << information << endl;
	myfileout.close();
	for (auto item : shelf)
	{
		const Member* forefather = item.second.Anc;
		string path = ".\\" + forefather->getName();
		CreateDirectory(path.c_str(), NULL);
		ofstream mytxtout(path + "\\" + forefather->getName() + ".txt");
		mytxtout << item.second.getString();
		mytxtout.close();
		dfs_save(path, forefather);

	}
}
void dfs_save(string path, const Member* root)
{
	string cur_path = path + root->getName();
	CreateDirectory(cur_path.c_str(), NULL);
	ofstream myfileout(cur_path + "\\" + root->getName() + ".txt");
	string info = root->getInfo();
	myfileout << info;
	myfileout.close();
	myfileout.open(cur_path + "\\" + root->getName() + ".csv");
	myfileout << root;
	myfileout.close();
	const vector<Member*> child =root->children;
	for (auto item : child)
	{
		dfs_save(cur_path + "\\", item);
	}
}
Member* dfs_get(string path, string name)
{
	ifstream myfilein(path + "\\" + name + ".txt");
	string info = getTxt(myfilein);
	myfilein.close();
	myfilein.open(path + "\\" + name + ".csv");
	Member* root = new Member(info);
	myfilein >> (*root);
	myfilein.close();
	vector<string> child = root->getChildname();
	for (auto item : child)
	{
		Member* temp=dfs_get(path + "\\" + item, item);
		root->children.push_back(temp);
	}
	return root;
}
string getTxt(ifstream& ifs)
{
	char ch;
	string ans;
	while (ifs >> ch)
	{
		ans.push_back(ch);
	}
	return ans;
}