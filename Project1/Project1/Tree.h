#include <iostream>
#include <list>
#include <string>
#include "DecisionTreeNode.h"
using std::string;
class Tree; //�����

class Tree
{
public:
	DecisionTreeNode* son;
	Tree();
	//~tree()
	void createRoot();
	DecisionTreeNode* findQustion();
	//bool addDecision();
	//void print();
};


