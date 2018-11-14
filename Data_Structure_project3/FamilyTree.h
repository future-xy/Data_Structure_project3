#ifndef _FAMILYTREE_H
#define _FAMILYTREE_H
#include "Member.h"
#include "header.h"

#include <string>
#include <tuple>
using std::tuple;
using std::string;
using std::vector;

//typedef tuple<int, Member*, Member*, Spouse> Line;
typedef tuple<int, string, string, string> Line;
class FamilyTree{
	public:
		FamilyTree(Member* );
		FamilyTree() = default;
   		FamilyTree(bool, Status, string, string, bool, string, bool);
		FamilyTree(string);
		~FamilyTree();

		string GetAnc();

		void SetPatriarch(string);
		
		void _GiveBirth(string MyName, bool , Status , string , string , bool , string , bool);
		void _RemoveChild(string MyName, string MyKid, string date);
		
		void _GetMarried(string MyName, string MyWife, string Birth_date, string Marriage_date);
		void _Divorce(string MaName, string date);
		
		void _Die(string MyName,  string date);
				
		Status Log_in(string MyName, unsigned long long pw);
		bool setPassword(string Myname, unsigned long long pw);

		Member* Search(string MyName);
	
        	void PreRepair(); 
		void Repair();
		string Tree_to_String();
		void Print();

	//	friend ofstream& operator<<(ofstream&, vector <Line>&);
	//	friend ifstream& operator>>(ifstream&, vector <Line>&);
		friend ofstream& operator<<(ofstream&, FamilyTree&);
		friend ifstream& operator>>(ifstream&, FamilyTree&); 
		
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
