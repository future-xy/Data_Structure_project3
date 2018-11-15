#include"Member.h"
#include<sstream>
#include<iostream>
#include<string>

using std::stringstream;
using std::cout;
using std::endl; 

Member::Member(string inform){
	stringstream ss;
	string str;
	ss << inform;
	ss >> str;
	ss >> str;
	if(str=="生")
		alive = true;
	else
		alive = false;
	ss >> str;
	ss >> str;
	lastname = str;
	ss >> str;
	ss >> str;
	firstname = str;
	ss >> str;
	ss >> str;
	birth_date = str;
	unsigned long long pre;
	ss >> str;
	ss >> pre;
	password = pre;
	ss >> str;
	int ao;
	ss >> ao;
	if (ao)
		Id = clansman;
	else
		Id = patriarch;
	ss >> str;
	ss >> str;
	if(str=="男") gender = true;
	else gender = false;
	ss >> str;
	unsigned int temp;
	ss >> temp;
	ss >> str;
	for(unsigned int i=0;i<temp;++i){
		ss >> str;
		child_name.push_back(str);
	}
	ss >> str;
	ss >> str;
	if(str=="已婚"){
		state = true;
		ss >> str;
		ss >> str;
		if(str=="生") spouse.setAlive(true);
		else spouse.setAlive(false);
		ss >> str;
		ss >> str;
		spouse.setName(str);
		ss >> str;
		ss >> str;
		spouse.setBirth(str);
		ss >> str;
		ss >> str;
		spouse.setWedding(str);
		ss >> str;
		if(str=="男") spouse.setGender(true);
		else spouse.setGender(false);
	} else state = false;
}
Spouse& Spouse::operator=(const Spouse& other){
	alive = other.alive;
	birth_date = other.birth_date;
	weddingdate = other.weddingdate;
	name = other.name;
	gender = other.gender;
	return *this;
}
bool Member::getAlive() const{
	return alive;
}
void Member::setAlive(bool al){
	alive = al;
}
string Member::getName() const{
	return lastname + firstname;
}
void Member::setName(string _last,string _first){
	lastname = _last;
	firstname = _first;
}
bool Member::getGender() const{
	return gender;
}
void Member::setGender(bool _gender){
	gender = _gender;
}
string Member::getBirth() const{
	return birth_date;
}
void Member::setBirth(string birth){
	birth_date = birth;
}
string Spouse::getWedding() const{
	return weddingdate;
}
void Spouse::setWedding(string wedding){
	weddingdate = wedding;
}

string Member::getInfo() const{
	string str;
	for(unsigned int i=0;i<info.size();++i){
		str+=(info[i]+'\n');
	}
	return str;
}
void Member::setInfo(string _info){
	while(_info.size()){
		unsigned int pos = _info.find('\n');
		string str = _info.substr(0,pos);
		info.push_back(str);
		_info.erase(0,pos+1);
	}
}
ofstream& operator<<(ofstream& out, const Member& other) {

	out << other.getInfo().c_str();
	return out;
}
ifstream& operator>>(ifstream& in,Member& other){
	string str;
	
	while(in>>str)
	other.info.push_back(str);
	return in;
}
int Member::getGene() const{
	return gene;
}
void Member::setGene(int ge){
	gene = ge;
}
void Member::setPassword(unsigned long long pass){
	password = pass;
}
unsigned long long Member::getPassword() const{
	return password;
}
string Member::Getmessage() const{
	string str;
	str += "存活状态: ";
	if(alive)	str+="生\n";
	else	str+="死\n";
	str += ("姓: "+lastname+' '+"名: "+firstname+'\n');
	str+=("生日: "+birth_date+'\n');
	stringstream ss,_ss;
	string st;
	ss << password;
	ss >> st;
	str += "密码: "; 
	str += st;
	str += '\n';
	if (!Id)
		str += "id: 0\n";
	else
		str += "id: 1\n";
	if(gender)    str+="性别: 男\n孩子数: ";
	else str+="性别: 女\n孩子数: ";
	int num = children.size();
	_ss << num;
	_ss >> st;
	str += st;
	str += '\n';
	str += "孩子名字:";
	for(unsigned int i=0;i<child_name.size();++i)
	str += (' '+child_name[i]);
	str += '\n';
	
	if(state){
		str+="状态: 已婚\n配偶:\n";
		if(spouse.getAlive())	str+="存活状态: 生\n";
		else	str+="存活状态: 死\n";
		str += ("配偶姓名: "+spouse.getName()+'\n');
		str += ("配偶生日: "+spouse.getBirth()+' '+"结婚日期: "+spouse.getWedding()+'\n');
		str += spouse.getGender();
	} else str += "状态: 单身\n";
	return str;
}
bool Spouse::getAlive() const{
	return alive;
}
void Spouse::setAlive(bool _alive){
	alive = _alive;
}
string Spouse::getName() const{
	return name;
}
void Spouse::setName(string _name){
	name = _name;
}
bool Spouse::getGender() const{
	return gender;
}
void Spouse::setGender(bool _gender){
	gender = _gender;
}
string Spouse::getBirth() const{
	return birth_date;
}
void Spouse::setBirth(string birth){
	birth_date = birth;
}
void Member::changeName(string name){
	lastname = name;
}
vector<string> Member::getChildname(){
	return child_name;
}
void Member::marry(Spouse a){
	state = true;
	spouse = a;
}
void Member::divorce(){
	state = false;
}
Spouse Member::getSpouse() const{
	return spouse;
}
void Member::GiveBirth(int id,string last,string first,bool _gender,string birth){
	
	Status _id = clansman;
	Member* son = new Member(true,_id,last,first,_gender,birth,false);
	children.push_back(son);
	child_name.push_back(last+first);
	string str=birth;
	str+=',';
	str+=(lastname+firstname);
	if(_gender)		str+="生了个儿子,儿子姓名:";
	else str+="生了个女儿,女儿姓名:";
	str+=(last+first);
	info.push_back(str);
}
void Member::RemoveChild(string name,string date){
	string str = date;
	str+=",将";
	str+=name;
	str+="逐出家门";
	info.push_back(str);
}
bool Member::Divorce(string date){
	if(!state||(state&&!spouse.alive)) return false;
	else {
		string str = date;
		str+=',';
		str+=getName();
		str+="离婚了\n";
		state = false; 
		info.push_back(str);
		return true;
	}
}
bool Member::Die(string date){
	if(alive){
		string str = date;
		str+=',';
		str+=getName();
		str+="去世了\n";
		alive = false;
		info.push_back(str);
		return true;
	} 
	else return false;
}
bool Member::GetMarried(string name,string birth,string wedding){
	if(!state||(state&&!spouse.alive)){
		spouse.name = name;
		spouse.alive = true;
		spouse.gender = !gender;
		spouse.birth_date = birth;
		spouse.weddingdate = wedding;
		string str = wedding;
		str += ',';
		str += getName();
		str += "结婚了,";
		str += "结婚对象:";
		str += (name+'\n');
		state = true;
		info.push_back(str);
		return true;
	}
	else
	return false;
}

void print(Member* head,int n){//friend
	for(int i=0;i<4*n;++i)
	cout << ' ';
	cout << head->getName() << endl;
	for(unsigned int i=0;i<head->children.size();++i)
	print(head->children[i],n+1);
}
