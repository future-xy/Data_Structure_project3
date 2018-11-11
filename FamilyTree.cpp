#include "Member.h"
#include "FamilyTree.h"
#include "IOCtr.h"
#include <string>
#include <vector>
#include <queue>
#include <tuple>

//............Public.function...........................
FamilyTree::FamilyTree(Member* anc)
{
	Anc = anc;
}
FamilyTree::~FamilyTree()
{
	Delete(Anc);
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
	Line tup1(0, MyName, p, nullptr);
	History.push_back(tup1);
/*
	Member* Mem = nullptr;
    Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{

		(Mem->children).push_back(p);
	}
	*/

}

void FamilyTree::RemoveChild(string MyName, string MyKid)
{
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		vector<Member*>::iterator iter = Mem->children.begin();
		while (iter != Mem->children.end())
		{
			if ((*iter)->getName() == MyKid)
			{
				Line tup1(1, MyName, *iter, nullptr);
				History.push_back(tup1);
				break;
				//Delete(*iter);
				//delete the iter
			}
			iter++;
		}
	}
}


void FamilyTree::GetMarried(string MyName, string MyWife, string date)//...
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
		ss.setBirth(date);
		//Mem->spouse = ss;
		//Mem->state = true;
		Spouse* p = &ss; //?
		Line tup1(2, MyName, nullptr, p);
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
		Spouse* p = &(Mem->spouse); //?
		Line tup1(3, MyName, nullptr, p);
		History.push_back(tup1);
		// delete spouse
	}
}

void FamilyTree::Die(string MyName)
{
	Line tup1(4, MyName, nullptr, nullptr);
	History.push_back(tup1);
	/*
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		Mem->alive = false;
	}
	*/
}


Status FamilyTree::Log_in(string MyName, unsigned long long pw)
{
	Member* Mem = nullptr;
	Dfs_Tree(MyName, Anc, Mem);
	if (Mem != nullptr)
	{
		if (Mem->getName() != Patriarch->getName())
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
			Member* Mem = nullptr;
			Dfs_Tree(get<1>(hist), Anc, Mem);
			if (Mem != nullptr)
			{
				(Mem->children).push_back(get<2>(hist));
			}
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;

		}
	}

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
		vector <Member*> v = p->children;
		vector <Member*>::iterator iter;
		while (iter != v.end())
		{
			q.push(*iter);
			iter++;
		}
		delete p;
		q.pop();
	}
}
