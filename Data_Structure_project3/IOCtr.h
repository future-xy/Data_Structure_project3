#ifndef IOCTR_H
#define IOCTR_H


#include<iostream>
#include<fstream>
#include<Windows.h>
#include<fileapi.h>
#include<conio.h>
#include<map>
#include<string>
#include<vector>

#include"FamilyTree.h"
#include"Member.h"

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

//To save all familytree
map<string, FamilyTree*> shelf;

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
	patriarch, clansman, tourist, wrong_pw
};
string hometown = "UNKNOW";
Status authority = tourist;
string username;
Status sign_in();
unsigned long long String_HashValue(string s);
void preprocessing();
bool save_all();
void dfs_save(string path, const Member* root);
Member* dfs_get(string path, string name);
string getTxt(ifstream& ifs);

#endif // !IOCTR_H