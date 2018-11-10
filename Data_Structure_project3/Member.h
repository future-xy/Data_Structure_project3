#pragma once
#include<vector>
#include<iostream>
#define Max_size 10
using namespace std;
class Spouse{
	private:
		bool alive;
		string firstname;
		string lastname;
		bool gender;
		string birth_date;
		string death_date;
		
	public:
		Spouse();
		~Spouse();
		bool getAlive() const;
		void setAlive(bool);
		string getName() const;
		void setName(string,string);
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
		bool gender;
		string birth_date;
		string death_date;
		vector<string> info;
		Spouse spouse;
		enum identity{patriarch, clansman, tourist};
		unsigned long long password;
		bool state; //true:married false:single
		vector<Member*> children;
		vector<string> child_name;
		
	public:
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
		void setInfo(string);
		int getGene() const;
		void setGene(int);
		void setPassword(unsigned long long);
		void marry(Spouse);
		void divorce();
		unsigned long long getPassword() const;
		string Getmessage();//all message
		void changeName(string);//change lastname
		friend vector<Member*>& getChild();
		friend vector<string>& getChildname(); //return names of children
};
