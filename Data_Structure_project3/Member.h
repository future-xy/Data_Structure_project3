#pragma once
#include<vector>
#include<string>
#include<fstream>

#define Max_size 10

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class Spouse{
	private:
		bool alive;
		string name;
		bool gender;
		string birth_date;
		string death_date;
		
	public:
		Spouse() = default;
		~Spouse() = default;
		bool getAlive() const;
		void setAlive(bool);
		string getName() const;
		void setName(string);
		bool getGender() const;
		void setGender(bool);
		string getBirth() const;
		void setBirth(string);
		string getDeath() const;
		void setDeath(string);
		Spouse& operator=(const Spouse&);
};

class Member{
	private:
		int gene;
		bool alive;
		Status Id;
		
		string firstname;
		string lastname;
		bool gender;//true male false female
		string birth_date;
		string weddingdate;
		vector<string> info;
		Spouse spouse;
		Member* father;
		enum identity{patriarch, clansman, tourist};
		unsigned long long password;
		bool state; //true:married false:single
		vector<Member*> children;
		vector<string> child_name;
		
	public:
		friend class FamilyTree;
		Member() = default;
		Member(string);
		Member(bool a,Status b,string c,string d,bool e,string f,bool i):
		alive(a),Id(b),lastname(c),firstname(d),gender(e),birth_date(f),state(i){
			password = String_HashValue(birth_date);
		}
		~Member() = default;
		
		bool getAlive() const;
		void setAlive(bool);
		string getName() const;//the whole name
		void setName(string,string);//lastname firstname
		bool getGender() const;
		void setGender(bool);
		string getBirth() const;
		void setBirth(string);
		string getWedding() const;
		void setWedding(string);
		string getInfo() const;//shengping
		Spouse getSpouse() const;
		void setInfo(string);
		int getGene() const;
		void setGene(int);
		void setPassword(unsigned long long);
		void marry(Spouse);
		void divorce();
		unsigned long long getPassword() const;
		string Getmessage();//all message
		void changeName(string);//change lastname
		vector<string> getChildname(); //return names of children
		friend ofstream& operator<<(ofstream&,Member&);
		friend ifstream& operator>>(ifstream&,Member&);
		friend void dfs_save(string path, const Member* root);
		friend Member* dfs_get(string path, string name);
};
