#include "Tree.h"

Tree::Tree()
{
}

void Tree::createRoot()
{
	string x = "";
	std::cin >> x;
	son = new DecisionTreeNode(x);
}

DecisionTreeNode * Tree::findQustion()
{
	string temp;
	std::cin >> temp;
	if (this->son->findQ(temp))std::cout << "found"; else std::cout << "dont";
	std::cin >> temp;
	return nullptr;
}
