#ifndef _FAMILYTREE_H
#define _FAMILYTREE_H
#include "Member.h"
#include "IOCtr.h"
#include <string>
#include <tuple>
using std::tuple;
using std::string;
using std::vector;

typedef tuple<int, Member*, Member*, Spouse> Line;

class FamilyTree{
	public:
		FamilyTree(Member* );
		~FamilyTree();
        
		string GetAnc();

		void SetPatriarch(string);
		
		void GiveBirth(string MyName, Member MyKid);
		void RemoveChild(string MyName, string MyKid);
		
		void GetMarried(string MyName, string MyWife, string Birth_date, string Marriage_date);
		void Divorce(string MaName);
		
		void Die(string MyName);
				
		Status Log_in(string MyName, unsigned long long pw);

		Member* Search(string MyName);
	
                void PreRepair(); 
		void Repair();
		
		void Save_Tree(int, string&);

		
		friend void preprocessing();
		friend bool save_all();
	private:
		Member* Anc; // root
		int Count_family;
		int Count_family_alive;
		void Dfs_Tree(string MyName, Member* p, Member* &Mem);
		void Delete(Member*);
		void Counting(Member*);
		vector <Line> History; 

		Member* Patriarch; //zuzhang
	
};

#endif
