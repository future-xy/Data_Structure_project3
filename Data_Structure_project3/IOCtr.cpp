#include"IOCtr.h"

Status sign_in()
{
	cout << "ÇëÊäÈëÕËºÅ£º";
	cin >> username;
	cout<< "ÇëÊäÈëÃÜÂë£º";
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
	//We will judge the status by looking in the map;
	for (auto item : shelf)
	{
		Status temp = item.second->Log_in(username, password);

		switch (temp)
		{
		case patriarch:
			authority = patriarch;
			hometown = item.first;
			break;
		case clansman:
			authority = clansman;
			hometown = item.first;
			break;
		case tourist:
			break;
		default:
			break;
		}
	}

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
		ifstream mytxtin(path + information + "\\" + information + ".txt");
		string info;
		if(mytxtin.is_open())
			info = getTxt(mytxtin);
		FamilyTree* tree_ptr = new FamilyTree(info);
		mytxtin.close();
		string del_path = path + information + "\\" + information + ".txt";
		DeleteFile(del_path.c_str());
		tree_ptr->Anc = dfs_get(path + information + "\\" + tree_ptr->GetAnc(), tree_ptr->GetAnc());
		shelf[information] = tree_ptr;
	}
	myfilein.close();
	DeleteFile("Familytree.log");

}
bool save_all()
{
	string information = "±£´æµÄ¼ÒÆ×£º\n";
	for (auto item : shelf)
	{
		information += item.first + "\n";
	}
	ofstream myfileout("Familytree.log");
	myfileout << information << endl;
	myfileout.close();
	for (auto item : shelf)
	{
		Member* forefather = item.second->Anc;
		string path = ".\\" + forefather->getName();
		CreateDirectory(path.c_str(), NULL);
		ofstream mytxtout(path + "\\" + forefather->getName() + ".txt");
		mytxtout << item.second->Tree_to_String();
		mytxtout.close();
		dfs_save(path, forefather);
	}
}
void dfs_save(string path, const Member* root)
{
	string cur_path = path + root->getName();
	CreateDirectory(cur_path.c_str(), NULL);
	ofstream myfileout(cur_path + "\\" + root->getName() + ".txt");
	string info = root->getInfo();
	myfileout << info;
	myfileout.close();
	myfileout.open(cur_path + "\\" + root->getName() + ".csv");
	myfileout << root;
	myfileout.close();
	const vector<Member*> child =root->children;
	for (auto item : child)
	{
		dfs_save(cur_path + "\\", item);
	}
}
Member* dfs_get(string path, string name)
{
	ifstream myfilein(path + "\\" + name + ".txt");
	string info;
	if(myfilein.is_open())
		info = getTxt(myfilein);
	myfilein.close();
	string del_path = path + "\\" + name + ".txt";
	DeleteFile(del_path.c_str());
	Member* root = new Member(info);
	myfilein.open(path + "\\" + name + ".csv");
	if (myfilein.is_open())
		myfilein >> (*root);
	myfilein.close();
	del_path = path + "\\" + name + ".csv";
	DeleteFile(del_path.c_str());
	vector<string> child = root->getChildname();
	for (auto item : child)
	{
		Member* temp=dfs_get(path + "\\" + item, item);
		root->children.push_back(temp);
	}
	DeleteFile(path.c_str());
	return root;
}
string getTxt(ifstream& ifs)
{
	if (ifs.bad())
		return "";
	char ch;
	string ans;
	while (ifs >> ch)
	{
		ans.push_back(ch);
	}
	return ans;
}