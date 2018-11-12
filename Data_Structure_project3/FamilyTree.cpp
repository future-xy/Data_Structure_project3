#include "FamilyTree.h"
#include "IOCtr.h"
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
}
FamilyTree::~FamilyTree()
{
	Delete(Anc);
	Patriarch = nullptr;
}

FamilyTree::FamilyTree(string Orig)
{
	Anc = nullptr;
	TheTree = Orig;
	Read_Tree(Anc);
}

string FamilyTree::GetAnc()
{
	return Anc->getName();
}

void FamilyTree::SetPatriarch(string MyName)
{
	Patriarch->Id = clansman;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Mem->Id = patriarch;
	}
}

void FamilyTree::GiveBirth(string MyName, Member MyKid)
{
	Member* p = new Member(MyKid);
	Spouse s;
	Member* Mem = nullptr;
        Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Line tup1(0, Mem, p, s);
		History.push_back(tup1);
		//(Mem->children).push_back(p);
	}
} 
void FamilyTree::RemoveChild(string MyName, string MyKid)
{
	Spouse s;
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
	}
}

void FamilyTree::GetMarried(string MyName, string MyWife, string Birth_date, string WeddingDay)
{
	Member* Mem = nullptr;
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
	}
}
void FamilyTree::Divorce(string MyName)
{
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		//Mem->state = false;
		Line tup1(3, Mem, nullptr, Mem->spouse);
		History.push_back(tup1);
	}
}

void FamilyTree::Die(string MyName)
{
	Spouse s;
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		//Mem->alive = false;
		Line tup1(4, Mem, nullptr, s);
		History.push_back(tup1);
	}
	
}


Status FamilyTree::Log_in(string MyName, unsigned long long pw)
{
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
		cout << "事件 " << i << "：" << endl;
		int oper = get<0>(hist);
		switch (oper) {
		case 0:
			cout << "新生儿！来自" << get<1>(hist) << "、" << get<3>(hist).getName() << "，取名：" << get<2>(hist)->getName() << endl;
			break;
		case 1:
			cout << "请求逐出宗族连带子孙！来自" << get<1>(hist) <<"、" << get<3>(hist).getName() << "，姓名：" << get<2>(hist)->getName() << endl;
			break;
		case 2:
			cout << "喜结连理！祝福" << get<1>(hist)<< "、" << get<3>(hist).getName() << "夫妇！" << endl;
			break;
		case 3:
			cout << "此事亦难全。" << get<1>(hist)<< "、" << get<3>(hist).getName() << "夫妇决定离婚。" << endl;
			break;
		case 4:
			cout << "叹息。" << get<1>(hist) << "，昔人已逝，节哀。" << endl; 
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
		switch (oper) {
		case 0:
			(get<1>(hist)->children).push_back(get<2>(hist));
			Count_family++;
			Count_family_alive++;
			break;
		case 1:
			Delete(get<2>(hist));
			break;
		case 2:
			(get<1>(hist))->spouse = get<3>(hist);
			(get<1>(hist))->state = true;
			break;
		case 3:
			(get<1>(hist))->state = false;
			break;
		case 4:
			(get<1>(hist))->alive = false;
			Count_family_alive--;
			break;
		}
		History.erase(History.begin());
	}
}

string FamilyTree::Tree_to_String()
{
	TheTree.clear();
	Save_Tree(0, Anc);
	return TheTree;
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

void FamilyTree::Save_Tree(int count, Member* p)
{
	/*for (int i = 0; i < count; ++i)
	{
		TheTree += '*';
	}
	TheTree += ' ';
	*/
	if (p->alive)
		TheTree += "1 ";
	else TheTree += "0 ";

	if (p->Id == 0)
		TheTree += "0 ";
	else TheTree += "1 ";

	TheTree += p->lastname + ' ' + p->firstname + ' ';
	
	if (p->gender)
		TheTree += "1 ";
	else TheTree += "0 ";

	TheTree += p->birth_date + ' ';
	
	if (p->state)
	{
		TheTree += "1 ";
		TheTree += p->spouse.getName + ' ' + p->spouse.getBirth + ' ' + p->spouse.getWedding() + ' ';
	}
	else TheTree += "0 ";

	TheTree += (char)(p->children.size() + 48);
	TheTree += '\n';
	for (int i = 0; i < p->children.size(); ++i)
	{
		Save_Tree(count + 1, (p->children)[i]);
	}
}

//alive(a), Id(b), lastname(c), firstname(d), gender(e), birth_date(f), state(i)

void FamilyTree::Read_Tree(Member*& p)
{
	p = new Member;
	stringstream ss;
	ss << TheTree;
	int i;
	string s;
	ss >> i;
	p->alive = i;
	ss >> i;
	if (i)
		p->Id = clansman;
	else
	{
		p->Id = patriarch; 
		Patriarch = p;
	}
	ss >> s;
	p->lastname = s;
	ss >> s;
	p->firstname = s;
	ss >> i;
	p->gender = i;
	ss >> s;
	p->birth_date = s;
	ss >> i;
	p->state = i;
	if (i)
	{
		ss >> s;
		Spouse couple;
		couple.setName(s);
		ss >> s;
		couple.setBirth(s);
		ss >> s;
		couple.setWedding(s);
		p->spouse = couple;
	}
	ss >> i;
	for (int j = 0; j < i; ++j)
	{
		Member* ptr = nullptr;
		Read_Tree(ptr);
		p->children.push_back(ptr);
	}
}
