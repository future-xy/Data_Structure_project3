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

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

extern map<string, FamilyTree*> shelf;

extern string hometown;
extern string username;
Status sign_in();
extern Status authority;

void preprocessing();
bool save_all();

unsigned long long String_HashValue(string s);
void dfs_save(string path, const Member* root);
Member* dfs_get(string path, string name);
string getTxt(ifstream& ifs);

#endif // !IOCTR_H