#include"Member.h"
#include<sstream>

using std::stringstream;

Member::Member(string inform){
	stringstream ss;
	string str;
	ss << inform;
	ss >> str;
	if(str=="生")
		alive = true;
	else
		alive = false;
	ss >> str;
	lastname = str;
	ss >> str;
	firstname = str;
	ss >> str;
	birth_date = str;
	unsigned long long pre;
	ss >> pre;
	password = pre;
	ss >> str;
	if(str=="男") gender = true;
	else gender = false;
	unsigned int temp;
	ss >> temp;
	for(unsigned int i=0;i<temp;++i){
		ss >> str;
		child_name.push_back(str);
	}
	ss >> str;
	if(str=="已婚"){
		state = true;
		ss >> str;
		if(str=="生") spouse.setAlive(true);
		else spouse.setAlive(false);
		ss >> str;
		spouse.setName(str);
		ss >> str;
		spouse.setBirth(str);
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
ofstream& operator<<(ofstream& out, Member& other) {
	string str = other.getInfo();
	out << str;
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
	if(alive)	str+="生\n";
	else	str+="死\n";
	str += (lastname+' '+firstname+'\n');
	str+=(birth_date+'\n');
	stringstream ss,_ss;
	string st;
	ss << password;
	ss >> st;
	str += st;
	str += '\n';
	
	if(gender)    str+="男\n孩子数:";
	else str+="女\n孩子数:";
	int num = children.size();
	_ss << num;
	_ss >> st;
	str += st;
	str += '\n';
	for(unsigned int i=0;i<child_name.size();++i)
	str += (child_name[i]+'\n');
	
	if(state){
		str+="已婚\n配偶:\n";
		if(spouse.getAlive())	str+="生\n";
		else	str+="死\n";
		str += (spouse.getName()+'\n');
		str += (spouse.getBirth()+'\n'+spouse.getWedding()+'\n');
		str += spouse.getGender();
	} else str += "单身\n";
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
	Status _id;
	switch(id){
		case 0:
			_id = patriarch;
			break;
		case 1:
			_id = clansman;
			break;
		case 2:
			_id = tourist;
			break;
		case 3:
			_id = wrong_pw;
			break;
	}
	Member* son = new Member(true,_id,last,first,_gender,birth,false);
	children.push_back(son);
	child_name.push_back(last+first);
	string str;
	str+=getTime();
	str+=',';
	str+=(lastname+firstname);
	if()		str+="生了个儿子,儿子姓名:";
	else str+="生了个女儿,女儿姓名:";
	str+=name;
	info.push_back(str);
}
void Member::RemoveChild(string name){
	string str;
	str+=getTime();
	str+=',';
	str+="将";
	str+=name;
	str+="逐出家门";
	info.push_back(str);
}
bool Member::Divorce(){
	if(!state||(state&&!spouse.alive)) return false;
	else {
		string str;
		str+=getTime();
		str+=',';
		str+=getName();
		str+="离婚了";
		state = false; 
		info.push_back(str);
		return true;
	}
}
bool Member::Die(){
	if(alive){
		string str;
		str+=getTime();
		str+=',';
		str+=getName();
		str+="去世了";
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
		string str;
		str+=getTime();
		str+=',';
		str+=getName();
		str+="结婚了,";
		str+="结婚对象:"
		str+=name;
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
