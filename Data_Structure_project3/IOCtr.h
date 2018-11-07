#pragma once

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<fileapi.h>
#include<conio.h>
#include<string>
#include<io.h>


using std::string;
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
	const string pathhead = ".\\";
	while (myfilein >> information)
	{
		if (information.empty() || information == "\n")
			continue;
		FamilyTree newTree(information);
		_finddata_t file_info;
		string cur_path = pathhead + information;
		int handle=	_findfirst(cur_path.c_str(), &file_info);
		if (handle == -1)
			return;
		do
		{
			string attribute;
			if (file_info.attrib == _A_SUBDIR)
				attribute = "dir";
			else
				attribute = "file";

		}
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
	

}
