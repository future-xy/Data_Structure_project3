#pragma once
#include<vector>
#include<string>
#define Max_size 10
using namespace std;
class Spouse{
	private:
		bool alive;
		string name;
		bool gender;
		string birth_date;
		string death_date;
		
	public:
		Spouse();
		~Spouse();
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
		string firstname;
		string lastname;
		bool gender;//true male false female
		string birth_date;
		string death_date;
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
		Member();
		Member(string);
		~Member();
		
		bool getAlive() const;
		void setAlive(bool);
		string getName() const;//the whole name
		void setName(string,string);//lastname firstname
		bool getGender() const;
		void setGender(bool);
		string getBirth() const;
		void setBirth(string);
		string getDeath() const;
		void setDeath(string);
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
		friend ostream& operator<<(ostream&,const Member&);
		friend istream& operator>>(istream&,Member&);
};
