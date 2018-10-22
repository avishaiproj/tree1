#include <iostream>
#include <list>
#include <string>
#include "optionAns.h"
using std::string;
class DecisionTreeNode { //הצהרה
public:
	bool isLeaf;
	string value; //leasf with resolte
	std::list<optionAns*> answersList;
	DecisionTreeNode* father;
	DecisionTreeNode(string x)
	{
		this->isLeaf = true;
		this->value = x;
	}
	DecisionTreeNode* findQ(string x) {
			if (this->value == x) return this;
			if (!isLeaf) { // if Qestion
				std::list<optionAns*>::iterator it = answersList.begin();
				while (it != answersList.end())
				{
					optionAns* temp = *(it);
					DecisionTreeNode* temp2 = temp->son;
					DecisionTreeNode* temp3 = temp2->findQ(x);
					if (temp3) { return temp3; };
					it++;
				}
				return nullptr;
			}
		return nullptr;
	}
};