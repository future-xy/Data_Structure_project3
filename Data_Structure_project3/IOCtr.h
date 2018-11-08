#pragma once

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<fileapi.h>
#include<conio.h>
#include<string>
#include<vector>

#include"FamilyTree.h"


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

enum Status
{
	patriarch, clansman, tourist
};

Status sign_in()
{
	cout << "ÇëÊäÈëÕËºÅ£º";
	string username;
	cin >> username;
	cout<< "ÇëÊäÈëÃÜÂë£º";
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
	string password = pw;
	//We will judge the status by looking in the map;
	if (true)
		return patriarch;
	else if (true)
		return clansman;
	else
		return tourist;
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
		newTree.Anc = bfs_get(path + information + "\\" + newTree.forefather(), newTree.forefather());
		shelf[information] = newTree;
	}

}
bool save_all()
{
	string information = "±£´æµÄ¼ÒÆ×£º\n";
	for (auto item : shelf)
	{
		information += item.first + "\n";
	}
	ofstream myfileout("Familytree.log");
	myfileout << information << endl;
	myfileout.close();
	for (auto item : shelf)
	{
		bfs_save(".\\", item.second.getRoot);
	}
}
void bfs_save(string path, const Member& root)
{
	string cur_path = path + root.name();
	CreateDirectory(cur_path.c_str(), NULL);
	ofstream myfileout(cur_path + "\\" + root.name() + ".txt");
	string info = root.getInfo();
	myfileout << info;
	myfileout.close();
	myfileout.open(cur_path + "\\" + root.name() + ".csv");
	myfileout << root;
	myfileout.close();
	const vector<Member&> &child = root.getChild();
	for (auto item : child)
	{
		bfs_save(cur_path + "\\", item);
	}
}
Member* bfs_get(string path, string name)
{
	
}
string getTxt(ifstream& ifs)
{

}