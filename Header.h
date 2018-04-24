#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

class Node {
private:
	int id;
	string str;
	string bestStr;
public:
	vector<Node*> siblings;
	Node(int id, string str);
	int getId();
	string getStr();
	string getBestStr();
	void setBestStr(string str);
	void seeEveryNodeSiblings(vector<Node*> &allNodes);
	void setRandomSiblings(vector<Node*> &allNodes);
	void go(vector<Node*> &allNodes, vector<string> &hash);
	void resetBestId(vector<Node*> &allNodes);
};
string bestOne(string one, string two, vector<string> &hash);
bool checkOnHash(string str, vector<string> &hash);
bool operator >(string one, string two);
string operator -(string main, string hash);
int takeFromOlderRank(string& mainStr, int position, int currentSum);
void takeFromNextRank(string& str, int prev);