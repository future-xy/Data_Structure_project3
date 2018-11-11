#ifndef _FAMILYTREE_H
#define _FAMILYTREE_H
#include "Member.h"
#include "IOCtr.h"
#include <string>
#include <tuple>

typedef tuple<int, string, Member*, Spouse*> Line;

class FamilyTree{
	public:
		FamilyTree(Member* anc);
		~FamilyTree();
        
		string GetAnc();
		void SetPatriarch(string);
		void GiveBirth(string MyName, Member MyKid);
		void RemoveChild(string MyName, string MyKid);
		
		void GetMarried(string MyName, string MyWife, string date);
		void Divorce(string MaName);
		
		void Die(string MyName);
				
		Status Log_in(string MyName, unsigned long long pw);

		Member* Search(string MyName);

		friend void preprocessing();
		friend bool save_all();


		void Repair();
	private:
		Member* Anc; // root
		int count;
		void Dfs_Tree(string MyName, Member* p, Member* &Mem);
		void Delete(Member*);
		vector <Line> History; 

		Member* Patriarch; //zuzhang
	
};

#endif
