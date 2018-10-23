#include <iostream>
#include <list>
#include <string>
class DecisionTreeNode;
using std::string;
class optionAns {
public:
	string ans;
	DecisionTreeNode* son;
	optionAns(string answer, DecisionTreeNode* leaf) { this->ans = answer; this->son = leaf; }
};