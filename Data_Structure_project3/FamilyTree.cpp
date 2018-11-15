#include "FamilyTree.h"
#include"IOCtr.h"

#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <sstream>
using std::stringstream;
using std::string;
using std::vector;
using std::tuple;
using std::queue;
using std::get;
using std::cin;
using std::cout;
using std::endl;


//............Public.function...........................
FamilyTree::FamilyTree(Member* anc)
{
	Counting(anc);
	Anc = anc;
	Patriarch = anc;

}
FamilyTree::FamilyTree(bool a, Status b, string c, string d, bool e, string f, bool g)
{
	
	Member* p = new Member(a,b,c,d,e,f,g);
	Anc = p;
	Patriarch = p;
	Counting(p);
}
FamilyTree::~FamilyTree()
{
	Delete(Anc);
	Patriarch = nullptr;
}
/*
FamilyTree::FamilyTree(string Orig)
{
	//Anc = nullptr;
	//TheTree = Orig;
	//Read_Tree(Anc);
	string s;
	stringstream ss;
	ss << Orig;

}*/

string FamilyTree::GetAnc()
{
	return Anc_Name;
}

FamilyTree::FamilyTree(string info)
{
	Anc_Name = info;
}


void FamilyTree::SetPatriarch(string MyName)
{
	Patriarch->Id = clansman;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Mem->Id = patriarch;
		Patriarch = Mem;
	}
}

void FamilyTree::_GiveBirth(string MyName, bool alive, Status id, string lastn, string firstn, bool sex, string birthday, bool sta)
{
	/*Member* p = new Member(MyKid);
	Spouse s;
	Member* Mem = nullptr;
        Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Line tup1(0, Mem, p, s);
		History.push_back(tup1);
		//(Mem->children).push_back(p);
	}*/
	string ohmykid;
	string s;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		ohmykid += Mem->lastname;
		ohmykid += ' ';
		ohmykid += firstn + ' '; 
		ohmykid += ' ';
		if(sex)
		ohmykid += "1 ";
		else ohmykid += "0 ";
		ohmykid += ' ';
		ohmykid += birthday;

		if (Mem->state)
		s = Mem->spouse.getName();
	}
	Line tup1(0, MyName, ohmykid, s);
	History.push_back(tup1);
} 
void FamilyTree::_RemoveChild(string MyName, string MyKid, string date)
{
	/*Spouse s;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		vector<Member*>::iterator iter = Mem->children.begin();
		while (iter != Mem->children.end())
		{
			if ((*iter)->getName() == MyKid)
			{
				Line tup1(1, Mem, *iter, s);
				History.push_back(tup1);
				break;
				//Delete(*iter);
				//delete the iter
			}
			iter++;
		}
	}*/
	string s;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		if (Mem->state)
		s = Mem->spouse.getName();
	}
	Line tup1(1, MyName, MyKid, date);
	History.push_back(tup1);
}

void FamilyTree::_GetMarried(string MyName, string MyWife, string Birth_date, string WeddingDay)
{
	/*Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Spouse ss;
		ss.setAlive(true);
		ss.setName(MyWife);
		if (Mem->gender)
			ss.setGender(false);
		else ss.setGender(true);
		ss.setBirth(Birth_date);
		//ss.setDeath(Death_date);
		ss.setWedding(WeddingDay);
		Line tup1(2, Mem, nullptr, ss);
		History.push_back(tup1);
	}*/
	string ohmywifee;
	string s;
	ohmywifee += MyWife + ' ' + Birth_date + ' ' + WeddingDay;
	Line tup1(2, MyName, s, ohmywifee);
	History.push_back(tup1);
}
void FamilyTree::_Divorce(string MyName, string date)
{
	/*Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		//Mem->state = false;
		Line tup1(3, Mem, nullptr, Mem->spouse);
		History.push_back(tup1);
	}*/
	string s;
	//string ss;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		if (Mem->state)
			s = Mem->spouse.getName();
	}
	Line tup1(3, MyName, date, s);
	History.push_back(tup1);
}

void FamilyTree::_Die(string MyName, string date)
{
	/*Spouse s;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		//Mem->alive = false;
		Line tup1(4, Mem, nullptr, s);
		History.push_back(tup1);
	}*/
	string s;
	Line tup1(4, MyName, date, s);
	History.push_back(tup1);	
}


Status FamilyTree::Log_in(string MyName, unsigned long long pw)
{

	//Counting(Anc);

	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		if (Mem->password != pw)
			return wrong_pw;
		else if (Mem->getName() != Patriarch->getName())
			return clansman;
		else return patriarch;
	}
	else return tourist;
}
bool FamilyTree::setPassword(string MyName, unsigned long long pw)
{
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Mem->setPassword(pw);
		return true;
	}
	else
		return false;
}

Member* FamilyTree::Search(string MyName)
{
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
        return Mem;
}
void FamilyTree::PreRepair()
{
	for (int i = 0; i < History.size(); ++i)
	{
		Line hist = History[i];
		cout << "事件 " << i+1 << "：" << endl;
		int oper = get<0>(hist);
		stringstream ss;
		Member* Mem = nullptr;
		string lastn,firstn;
		switch (oper) {
		case 0:
			ss << get<2>(hist);
			ss >> lastn;
			ss >> firstn;
			cout << "新生儿！来自" << get<1>(hist) << "、" << get<3>(hist) << "，取名：" << lastn+firstn << endl;
			break;
		case 1:
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				cout << "逐出宗族连带子孙！来自" << get<1>(hist) << "、" << Mem->spouse.getName() << "，姓名：" << get<2>(hist) << endl;
			}
			break;
		case 2:
			ss << get<3>(hist);
			ss >> lastn;
			cout << "喜结连理！祝福" << get<1>(hist)<< "、" << lastn << "夫妇！" << endl;
			break;
		case 3:
			cout << "此事亦难全。" << get<1>(hist)<< "、" << get<3>(hist) << "夫妇决定离婚。" << endl;
			break;
		case 4:
			cout << "节哀。" << get<1>(hist) << "去世。" << endl; 
			break;
		}
		
	}
}
void FamilyTree::Repair()
{
	while (!History.empty())
	{
		Line hist = History.front();
		int oper = get<0>(hist);
		stringstream ss;
		bool alive; int id = 1; string lastn, firstn; bool sex; string birthday; bool sta;
		string Name, wedding;
		Member* Mem;
		switch (oper) {
		case 0:
			Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				ss << get<2>(hist);
				ss >> lastn;
				ss >> firstn;
				ss >> sex;
				ss >> birthday;
				Mem->GiveBirth( id,lastn, firstn, sex, birthday);
			}
			//(get<1>(hist)->children).push_back(get<2>(hist));

			Count_family++;
			Count_family_alive++;
			break;
		case 1:
			Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				vector<Member*>::iterator iter = Mem->children.begin();
				while (iter != Mem->children.end())
				{
					if ((*iter)->getName() == get<2>(hist))
					{
						Mem->RemoveChild(get<2>(hist), get<3>(hist));
						Delete(*iter);
						Mem->children.erase(iter);
						break;
					}
					iter++;
				}
			}
			break;
		case 2:
			Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				ss << get<3>(hist);
				ss >> Name;
				ss >> birthday;
				ss >> wedding;
				Mem->GetMarried(Name, birthday, wedding);
			}
			break;
		case 3:
			Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				Mem->Divorce(get<2>(hist));
			}
			break;
		case 4:
			Member* Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				Mem->Die(get<2>(hist));
			}
			break;
		}
		History.erase(History.begin());
	}
}

string FamilyTree::Tree_to_String()
{
	TheTree.clear();
	TheTree += Anc->getName() + '\n';
	
	/*for (int i = 0; i < History.size(); ++i)
	{
		int n = get<0>(History[i]);
		switch (n) {
		case 0:
			TheTree += "0 " + (get<1>(History[i]))->getName() + ' ' + get<2>(History[i])->getName + '\n';
			break;

		case 1:
			TheTree += "1 " + (get<1>(History[i]))->getName() + ' ' + get<2>(History[i])->getName + '\n';
			break;
		case 2:
			TheTree += "2 " + (get<1>(History[i]))->getName() + ' ' + get<3>(History[i]).getName + '\n';
			break;
		case 3:

			break;
		case 4:

			break;
		}
	}*/
	return TheTree;
}

void FamilyTree::Print()
{
	print(Anc, 0);
}

ofstream& operator<<(ofstream& out, FamilyTree& other) {
	while (!other.History.empty())
	{
		Line hist = other.History.front();
		out << get<0>(hist) << ',' << get<1>(hist) << ',' << get<2>(hist) << ',' << get<3>(hist) << endl;
		other.History.erase(other.History.begin());
	}
	return out;
}
ifstream& operator>>(ifstream& in, FamilyTree& other) {
	string s;
	vector <string> v;
	int i = 0;
	while (getline(in, s, ','))
	{
		v.push_back(s);
		i++;
		if (i == 4)
		{
			i = 0;
			Line tup1(v[0][0] - 48, v[1], v[2], v[3]);
			other.History.push_back(tup1);
			v.clear();
		}
	}
	return in;
}

//................Private.function.....................
void FamilyTree::Dfs_Tree(string MyName, Member* p, Member* &Mem)
{
	if (p->getName() == MyName)
		Mem = p;
	else
	{
		if (!p->children.empty())
		{
			vector <Member*> Childs = p->children;
			vector <Member*>::iterator it = Childs.begin();
			while (it != Childs.end())
			{
			    Dfs_Tree(MyName, *it, Mem);
				it++;
			}
		}
	}
}

void FamilyTree::Delete(Member* anc)
{
	queue <Member*> q;
	Member* p = anc;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		if (!p->children.empty())
		{
			vector <Member*> v = p->children;
			vector <Member*>::iterator iter;
			while (iter != v.end())
			{
				q.push(*iter);
				iter++;
			}
		}
		delete p;
		Count_family--;
		Count_family_alive--;
		q.pop();
	}
}

void FamilyTree::Counting(Member* anc)
{
	Count_family = 0;
	Count_family_alive = 0;
	queue <Member*> q;
	Member* p = anc;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		if (!p->children.empty())
		{
			vector <Member*> v = p->children;
			vector <Member*>::iterator iter;
			while (iter != v.end())
			{
				q.push(*iter);
				iter++;
			}
		}
		Count_family++;
		if (p->alive)
		Count_family_alive++;
		q.pop();
	}
}

