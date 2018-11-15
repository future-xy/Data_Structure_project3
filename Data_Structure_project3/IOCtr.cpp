#include"IOCtr.h"

string hometown = "";
Status authority = tourist;
string username = "";
map<string, FamilyTree*> shelf;


Status sign_in()
{
	cout << "请输入账号：";
	cin >> username;
	cout<< "请输入密码：";
	int i = 0;
	char ch;
	char pw[50];
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b'&&i > 0)
		{
			cout << "\b \b";
			--i;
		}
		else if (ch != '\b'&&ch != '\0')
		{
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	unsigned long long password = String_HashValue(pw);
	int ok_flag = 0;
	//We will judge the status by looking in the map;
	for (auto item : shelf)
	{
		Status temp = item.second->Log_in(username, password);
		if (ok_flag)
			break;
		
		switch (temp)
		{
		case patriarch:
			if (item.second->Search(username)->getAlive() == false)
			{
				cout << "斯人已逝!\n";
				authority = tourist;
				return authority;
			}
			authority = patriarch;
			hometown = item.first;
			ok_flag = 1;
			break;
		case clansman:
			if (item.second->Search(username)->getAlive() == false)
			{
				cout << "斯人已逝!\n";
				authority = tourist;
				return authority;
			}
			authority = clansman;
			hometown = item.first;
			ok_flag = 1;
			break;
		case tourist:
			authority = tourist;
			break;
		case wrong_pw:
			authority = tourist;
			ok_flag = 1;
			break;
		default:
			break;
		}
	}
	return authority;
}
unsigned long long String_HashValue(string s) {
	unsigned long long PrimeBase = 233, PrimeModular = 19260817,
		result = 0;

	for (auto c : s)
		result = (result*PrimeBase + c) % PrimeModular;
	return result;
}
void preprocessing()
{
	ifstream myfilein("Familytree.log");
	if (!myfilein.is_open())
		return;
	string temp;
	myfilein >> temp;
	string information;
	const string path = ".\\";
	while (myfilein >> information)
	{
		if (information.empty() || information == "\n")
			continue;
		ifstream mytxtin(path + information + "\\" + information + "序" + ".txt");
		string info;
		if(mytxtin.is_open())
			info = getTxt(mytxtin);
		FamilyTree* tree_ptr = new FamilyTree(info);
		mytxtin.close();
		mytxtin.open(path + information + "\\" + information + "大事记.csv");
		mytxtin >> (*tree_ptr);
		mytxtin.close();
		string del_path = path + information + "\\" + information + "序.txt";
		DeleteFile(del_path.c_str());
		del_path = path + information + "\\" + information + "大事记.csv";
		DeleteFile(del_path.c_str());
		tree_ptr->Anc = dfs_get(path + information + "\\" + tree_ptr->GetAnc(), tree_ptr->GetAnc(),tree_ptr);
		shelf[information] = tree_ptr;
	}
	myfilein.close();
	DeleteFile("Familytree.log");

}
bool save_all()
{
	string information = "保存的家谱：\n";
	for (auto item : shelf)
	{
		information += item.first + "\n";
	}
	ofstream myfileout( "Familytree.log");
	myfileout << information << endl;
	myfileout.close();
	for (auto item : shelf)
	{
		Member* forefather = item.second->Anc;
		string path = ".\\" + item.first;
		CreateDirectory(path.c_str(), NULL);
		ofstream mytxtout(path + "\\" + item.first + "序" + ".txt");
		mytxtout << item.second->Tree_to_String();
		mytxtout.close();
		mytxtout.open(path + "\\" + item.first + "大事记" + ".csv");
		mytxtout << *item.second;

		mytxtout.close();
		dfs_save(path, forefather);
	}
	return true;
}
void dfs_save(string path, const Member* root)
{
	string cur_path = path + "\\" + root->getName();
	CreateDirectory(cur_path.c_str(), NULL);
	ofstream myfileout(cur_path + "\\" + root->getName() + "家传.txt");
	string info = root->Getmessage();
	myfileout << info;
	myfileout.close();
	myfileout.open(cur_path + "\\" + root->getName() + "生平年表.csv");
	myfileout << (*root);
	myfileout.close();
	const vector<Member*> child =root->children;
	for (auto item : child)
	{
		dfs_save(cur_path + "\\", item);
	}
}
Member* dfs_get(string path, string name,FamilyTree* f)
{
	ifstream myfilein(path + "\\" + name + "家传.txt");
	string info;
	if(myfilein.is_open())
		info = getTxt(myfilein);
	myfilein.close();
	string del_path = path + "\\" + name + "家传.txt";
	DeleteFile(del_path.c_str());
	Member* root = new Member(info);
	myfilein.open(path + "\\" + name + "生平年表.csv");
	if (myfilein.is_open())
		myfilein >> (*root);
	myfilein.close();
	del_path = path + "\\" + name + "生平年表.csv";
	DeleteFile(del_path.c_str());
	vector<string> child = root->getChildname();
	for (auto item : child)
	{
		Member* temp = dfs_get(path + "\\" + item, item, f);
		root->children.push_back(temp);
	}
	DeleteFile(path.c_str());
	if (root->Id == patriarch)
		f->Patriarch = root;

	return root;
}
string getTxt(ifstream& ifs)
{
	if (ifs.bad())
		return "";
	string ans;
	string temp;
	while (ifs >> temp)
	{
		ans += temp + "\n";
	}
	ans.pop_back();

	return ans;
}