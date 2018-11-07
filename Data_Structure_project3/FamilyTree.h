class FamilyTree{
	public:
		FamilyTree(Member anc);
		void GiveBirth(string MyName, Member MyKid);
		void RemoveChild(string MyName, Member MyKid);
		
		void GetMarried(string MyName, string MyWife);
		void Divorce(string MaName);
		
		void Die(string MyName);
		
		void appendIntroduction(string MyName);
		
		Member Search(string MyName);
		
		
	private:
		Member* Anc; // root
		int count;
	
};
