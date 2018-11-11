#include "FamilyTree.h"
#include "IOCtr.h"
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using std::string;
using std::vector;
using std::tuple;
using std::queue;
using std::get;


//............Public.function...........................
FamilyTree::FamilyTree(Member* anc)
{
	Counting(anc);
	Anc = anc;
	Patriarch = anc;

}
FamilyTree::~FamilyTree()
{
	Delete(Anc);
	Patriarch = nullptr;
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

void FamilyTree::GiveBirth(string MyName, Member MyKid)//?
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

void FamilyTree::GetMarried(string MyName, string MyWife, string Birth_date, string Death_date)
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
		ss.setDeath(Death_date);
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
	if (Mem != nullptr)
	{
		return Mem;
	}
	return nullptr;
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

void FamilyTree::Save_Tree(int count, string &s)
{

	

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
				if ((*it)->getName() != MyName)
				{
					Dfs_Tree(MyName, *it, Mem);
				}
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
