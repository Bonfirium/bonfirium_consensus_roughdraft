#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<ctime>
#include<iostream>
#include <vector>
#include <string>
using namespace std;
void identifyAllNodes(int num, vector<Node*> &allNodes);

int main() {
	setlocale(LC_CTYPE, "rus");
	vector<string> strHash;
	strHash.push_back("0000000000000000000000000000000000000000000000000000000000000000");
	int amountNodes;
	cout << " ол-во нодов: " << endl;
	cin >> amountNodes;
	vector<Node*> allNodes;
	cout << "установленные random id:" << endl;
	identifyAllNodes(amountNodes, allNodes);
	cout << endl << "кол-во уст random св€зей:" << endl;
	allNodes[0]->setRandomSiblings(allNodes);
	allNodes[0]->seeEveryNodeSiblings(allNodes);
	cout << endl;
	allNodes[0]->go(allNodes, strHash);
	//cout << "hash.size() = " << strHash.size() << endl;
	cout << endl << "hash: " << endl;
	for (int i = 0; i < strHash.size(); i++)
		cout << i <<". hash = "<< strHash[i] << endl;
	cout << endl;
	system("pause");
	return 0;
}

void identifyAllNodes(int num, vector<Node*> &allNodes) {
	srand(time(0));
	for (int i = 0; i < num; i++) {
		string str = "0000000000000000000000000000000000000000000000000000000000000000";
		for (int i = 0; i < str.length(); i++) {
			switch (rand() % 16) {
			case 0:
				str[i] = '0';
				break;
			case 1:
				str[i] = '1';
				break;
			case 2:
				str[i] = '2';
				break;
			case 3:
				str[i] = '3';
				break;
			case 4:
				str[i] = '4';
				break;
			case 5:
				str[i] = '5';
				break;
			case 6:
				str[i] = '6';
				break;
			case 7:
				str[i] = '7';
				break;
			case 8:
				str[i] = '8';
				break;
			case 9:
				str[i] = '9';
				break;
			case 10:
				str[i] = 'a';
				break;
			case 11:
				str[i] = 'b';
				break;
			case 12:
				str[i] = 'c';
				break;
			case 13:
				str[i] = 'd';
				break;
			case 14:
				str[i] = 'e';
				break;
			case 15:
				str[i] = 'f';
				break;
			}
		}
		printf("%s", str.c_str());
		cout << endl;
		allNodes.push_back(new Node(i + 1, str));
	}
}
