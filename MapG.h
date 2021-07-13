#ifndef	MAPG_H
#define MAPG_H
#include "ADTMap.h"
#include <vector>
using namespace std;
class MapG : public ADTMap{

private:
	vector<pair<string,int>> v;
	int fill;
	int hashf(string s,int n);
	void rehash();
	int colisionesAt;
	int colisionesInsert;
public:
	MapG(int N);
	~MapG();
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