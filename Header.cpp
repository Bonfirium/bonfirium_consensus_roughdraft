#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include"Sha256.h"
#include <vector>
#include <iterator>
#include<ctime>
#include <string>


Node::Node(int id, string str) {
	this->id = id;
	this->str = str;
}

int Node::getId() {
	return this->id;
}

string Node::getStr(){
	return this->str;
}

string Node::getBestStr(){
	return this->bestStr;
}

void Node::setBestStr(string str){
	this->bestStr = str;
}

void Node::seeEveryNodeSiblings(vector<Node*>& allNodes) {
	for (int i = 0; i < allNodes.size(); i++)
		cout << " allNodes[" << i << "]->siblings.size() = " << allNodes[i]->siblings.size() << endl;
}


void Node::resetBestId(vector<Node*>& allNodes) {
	for (int i = 0; i < allNodes.size(); i++) {
		allNodes[i]->setBestStr(allNodes[i]->getStr());
	}
}

void Node::setRandomSiblings(vector<Node*>& allNodes) {
	srand(time(0));
	for (int i = 0; i < allNodes.size(); i++) {
		int countOfSiblingsToCurrentNode;
		do {
			countOfSiblingsToCurrentNode = rand() % allNodes.size();
		} while (countOfSiblingsToCurrentNode < 1);
		for (int f = 0, x = 0; x < countOfSiblingsToCurrentNode; f++, x++) {
			if (f == i)
				f++;
			allNodes[i]->siblings.push_back(allNodes[f]);
			allNodes[f]->siblings.push_back(allNodes[i]);
		}
	}
	for (int i = 0; i < allNodes.size(); i++)		//очистка повторов
		for (int x = 0; x < allNodes[i]->siblings.size()-1; x++)
			for (int u = x + 1; u < allNodes[i]->siblings.size(); u++)
				if (allNodes[i]->siblings[x] == allNodes[i]->siblings[u]) {
					allNodes[i]->siblings.erase(allNodes[i]->siblings.begin() + u);
					u--;
				}
}

void Node::go(vector<Node*>& allNodes, vector<string> &hash) {
	allNodes[0]->resetBestId(allNodes);
	while (hash.size() != allNodes.size() + 1) {
		for (int g = 0; g < allNodes.size(); g++)
			for (int i = 0; i < allNodes.size(); i++)
				for (int x = 0; x < allNodes[i]->siblings.size(); x++)
					allNodes[i]->setBestStr(bestOne(allNodes[i]->getBestStr(), allNodes[i]->siblings[x]->getBestStr(), hash));
		cout << "к - " << hash.back() << endl;
		cout << "лучший - " << allNodes[0]->getBestStr() << endl;
		cout << "лучший после sha256 - " << sha256(allNodes[0]->getBestStr()) << endl << endl;
		hash.push_back(sha256(allNodes[0]->getBestStr()));//кодирование в sha256 лучшего и добавление  в хэш
		allNodes[0]->resetBestId(allNodes);
	}
}

string bestOne(string one, string two, vector<string>& hash){//выборка лучшего
	if (checkOnHash(one, hash) && !checkOnHash(two, hash))
		return two;
	else if (!checkOnHash(one, hash) && checkOnHash(two, hash))
		return one;
	else if ( (one - hash.back())  >  ( two - hash.back() ) )
		return two;
	else return one;
}

bool checkOnHash(string str, vector<string> &hash) {//проверка, встречался ли в хэше елем
	for (int i = 0; i < hash.size(); i++)
		if (sha256(str) == hash[i])
			return true;
	return false;
}

bool operator >(string one, string two) {
	for (int i = 0; i < one.length(); i++) {
		if (one[i] > two[i])
			return true;
		if (one[i] < two[i])
			return false;
	}
	return false;
}

//в перегрузке оператора '-' решал в лоб просто
string operator -(string main, string hash){
	string str = "0000000000000000000000000000000000000000000000000000000000000000";
	if (main > hash);
	else {
		string temp = hash;
		hash = main;
		main = temp;
	}
	for (int i = str.length()-1; i >= 0; i--) {
		int mainInt, hashInt;
		switch (main[i]){
		case '0':
			mainInt = 0;
			break;
		case '1':
			mainInt = 1;
			break;
		case '2':
			mainInt = 2;
			break;
		case '3':
			mainInt = 3;
			break;
		case '4':
			mainInt = 4;
			break;
		case '5':
			mainInt = 5;
			break;
		case '6':
			mainInt = 6;
			break;
		case '7':
			mainInt = 7;
			break;
		case '8':
			mainInt = 8;
			break;
		case '9':
			mainInt = 9;
			break;
		case 'a':
			mainInt = 10;
			break;
		case 'b':
			mainInt = 11;
			break;
		case 'c':
			mainInt = 12;
			break;
		case 'd':
			mainInt = 13;
			break;
		case 'e':
			mainInt = 14;
			break;
		case 'f':
			mainInt = 15;
			break;
		}
		switch (hash[i]) {
		case '0':
			hashInt = 0;
			break;
		case '1':
			hashInt = 1;
			break;
		case '2':
			hashInt = 2;
			break;
		case '3':
			hashInt = 3;
			break;
		case '4':
			hashInt = 4;
			break;
		case '5':
			hashInt = 5;
			break;
		case '6':
			hashInt = 6;
			break;
		case '7':
			hashInt = 7;
			break;
		case '8':
			hashInt = 8;
			break;
		case '9':
			hashInt = 9;
			break;
		case 'a':
			hashInt = 10;
			break;
		case 'b':
			hashInt = 11;
			break;
		case 'c':
			hashInt = 12;
			break;
		case 'd':
			hashInt = 13;
			break;
		case 'e':
			hashInt = 14;
			break;
		case 'f':
			hashInt = 15;
			break;
		}
		mainInt -= hashInt;
		if (mainInt < 0) {
			continue;
			mainInt = takeFromOlderRank(main, i, mainInt);
		}
		switch (mainInt){
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
	return str;
}

//типа если 100-3=97 
int takeFromOlderRank(string& mainStr, int position, int currentSum) {
	int sum = 16 + currentSum;//тк current sum<0
	takeFromNextRank(mainStr, position - 1);
	return sum;
}

//типа если 100-3=97 
void takeFromNextRank(string& str, int prev) {
	if (str[prev] == '0')
		takeFromNextRank(str, prev - 1);
	else {
		if ((str[prev] > 'a' && str[prev] < 'g') || (str[prev] > '0' && str[prev] <= '9'))
			str[prev]--;
		else if (str[prev] == 'a')
			str[prev] = '9';
	}
}