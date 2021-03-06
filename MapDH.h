#ifndef	MAPDH_H
#define MAPDH_H
#include "ADTMap.h"
#include <vector>
using namespace std;
class MapDH : public ADTMap{

private:
	vector<pair<string,int>> v;
	int fill;
	int hashf(string s,int n);
	int dHashf(string s,int n);
	void rehash();
	int colisionesAt;
	int colisionesInsert;
public:
	MapDH(int N);
	~MapDH();
	void insert(pair<string,int> p);
	void erase(string s);
	int at(string s);
	int size();
	bool empty();
	void printList();
	int getColisionesAt();
	int getColisionesInsert();
};
#endif