#include <iostream>
#include <list>
#include <string>
#include "optionAns.h"
using std::string;
using std::list;
class DecisionTreeNode { //הצהרה
public:
	bool isLeaf;
	string value; //leasf with resolte
	list<optionAns*> answersList;
	list<optionAns*>::iterator itplace;
	DecisionTreeNode* father;

	DecisionTreeNode(string x)
	{
		this->isLeaf = true;
		this->value = x;

	}
	DecisionTreeNode* findQ(string x) {
			if (this->value == x) return this;
			if (!isLeaf) { // if Qestion
				list<optionAns*>::iterator it = answersList.begin();
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
	optionAns* addQ() {
		string wherefind;
		std::cin >> wherefind;
		if (findQ(wherefind)) {
			std::cout << "find";
			isLeaf = false;
			itplace = answersList.begin();
			string way, answer;
			std::cin >> way >> answer;
			findQ(wherefind)->answersList.insert(itplace, new optionAns(way, new DecisionTreeNode(answer)));
			print();
		}
		return nullptr;
	}
	void print() {
		list<optionAns*>::iterator it = answersList.begin();
		std::cout << "\n";
		while (it != answersList.end())
		{
			optionAns* temp = *(it);
			DecisionTreeNode* temp2 = temp->son;
			string temp3 = temp2->value;
			std::cout << temp3;
			it++;
		}
	}
};