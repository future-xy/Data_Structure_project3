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
		FamilyTree() = default;
   		FamilyTree(bool, Status, string, string, bool, string, bool);
		FamilyTree(string);
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
		string Tree_to_String();

		
		friend void preprocessing();
		friend bool save_all();
	private:
		Member* Anc; // root
		string Anc_Name;
		int Count_family;
		int Count_family_alive;
		void Dfs_Tree(string MyName, Member* p, Member* &Mem);
		void Delete(Member*);
		void Counting(Member*);
		//void Save_Tree(int, Member&);
		//void Read_Tree(Member*&);
		string TheTree;
	
		vector <Line> History; 

		Member* Patriarch; //zuzhang
	
};

#endif
