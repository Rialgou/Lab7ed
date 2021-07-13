#include <bits/stdc++.h>
#include "MapB.h"
#include "MapG.h"
#include "MapDH.h"
using namespace std;
string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] = "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}
int main()
{
	int n;
	cout<<"ingrese la cantidad de claves para la tabla hash: ";
	cin >>n;
	int rep =100;
	srand(time(NULL));
	int lv; 
	int ccab=0;
	int ccib=0;
	int ccag=0;
	int ccig=0;
	int ccadh=0;
	int ccidh=0;
	MapB * b;
	MapG *g;
	MapDH * dh;
	for(int i=0;i<rep;i++){
		b = new MapB(n);
		g = new MapG(n);
		dh = new MapDH(n);
		string str[n];
		for(int j=0;j<n;j++){
			str[j]=random_string(rand()%10+1);
			b->insert(make_pair(str[j],rand()%100));
			g->insert(make_pair(str[j],rand()%100));
			dh->insert(make_pair(str[j],rand()%100));
		}
		for(int j=0;j<n;j++){
			b->at(str[j]);
			g->at(str[j]);
			dh->at(str[j]);
		}

		ccib+=b->getColisionesInsert();
		ccig+=g->getColisionesInsert();
		ccidh+=dh->getColisionesInsert();

		ccab+=b->getColisionesAt();
		ccag+=g->getColisionesAt();
		ccadh+=dh->getColisionesAt();
	}
	cout<<"colision insert b: "<<ccib/rep<<endl;
	cout<<"colision at b: "<<ccab/rep<<endl;
	cout<<"colision insert g : "<<ccig/rep<<endl;
	cout<<"colision at g: "<<ccag/rep<<endl;
	cout<<"colisioninsert dh: "<<ccidh/rep<<endl;
	cout<<"colision at dh: "<<ccadh/rep<<endl;
	/*for(int i=0;i<rep;i++){
		MapB *b = new MapB(n);
		MapG *g = new MapG(n);
		MapDH *dh = new MapDH(n);
		string s[n];
		for(int j=0;j<n;j++){
			//s[j]= random_string(rand()%15+1);
			b->insert(make_pair("a"+(char)j,rand()%100));
			g->insert(make_pair("a"+(char)j,rand()%100));
			dh->insert(make_pair("a"+(char)j,rand()%100));
		}
		for(int j=0;j<n;j++){
			b->at(s[j]);
			g->at(s[j]);
			dh->at(s[j]);
		}
		ccab+= b->getColisionesAt();
		ccib+= b->getColisionesInsert();

		ccag+= g->getColisionesAt();
		ccig+= g->getColisionesInsert();

		ccadh+= dh->getColisionesAt();
		ccidh+= dh->getColisionesInsert();
	}
	printf("MapB insert : %d\n\n",ccib/rep);
	printf("MapG insert : %d\n\n",ccig/rep );
	printf("MapDH insert : %d\n\n",ccidh/rep );
	printf("MapB at : %d\n\n",ccab/rep );
	printf("MapG at : %d\n\n",ccag/rep );
	printf("MapDH at : %d\n\n",ccadh/rep );*/
	/*MapB * b = new MapB(50);
	MapG * g = new MapG(50);
	MapDH * dh = new MapDH(50);
	if(b->empty())cout<<"vacio xd"<<endl;
	cout<<b->size()<<endl;
	b->insert(make_pair("hola",15));
	b->insert(make_pair("adios",10));
	cout<<b->at("adios")<<endl;;
	cout<<b->at("hola")<<endl;;
	cout<<b->size()<<endl;
	if(!b->empty())cout<<"no vacio"<<endl;
	b->erase("adios");
	b->insert(make_pair("adios",15));
	b->insert(make_pair("lmao",4));
	b->insert(make_pair("proxd",33));
	b->erase("proxd");
	b->insert(make_pair("proxd",30));
	b->printList();
	cout<<endl<<endl;
	b->insert(make_pair("ola",32));
	b->insert(make_pair("ala",22));
	b->insert(make_pair("ela",356));
	b->erase("ela");
	b->insert(make_pair("ale",3123));

	b->printList();
	cout<<b->at("ale")<<endl;
	g->insert(make_pair("hola",15));
	g->insert(make_pair("adios",10));
	cout<<g->at("adios")<<endl;;
	cout<<g->at("hola")<<endl;;
	cout<<g->size()<<endl;
	if(!g->empty())cout<<"no vacio"<<endl;
	g->erase("adios");
	g->insert(make_pair("adios",15));
	g->insert(make_pair("lmao",4));
	g->insert(make_pair("proxd",33));
	g->erase("proxd");
	g->insert(make_pair("proxd",30));
	g->printList();
	cout<<endl<<endl;
	g->insert(make_pair("ola",32));
	g->insert(make_pair("ala",22));
	g->insert(make_pair("ela",356));
	g->erase("ela");
	g->insert(make_pair("ale",3123));

	g->printList();
	dh->insert(make_pair("hola",15));
	dh->insert(make_pair("adios",10));
	cout<<dh->at("adios")<<endl;;
	cout<<dh->at("hola")<<endl;;
	cout<<dh->size()<<endl;
	if(!dh->empty())cout<<"no vacio"<<endl;
	dh->erase("adios");
	dh->insert(make_pair("adios",15));
	dh->insert(make_pair("lmao",4));
	dh->insert(make_pair("proxd",33));
	dh->erase("proxd");
	dh->insert(make_pair("proxd",30));
	dh->printList();
	cout<<endl<<endl;
	dh->insert(make_pair("ola",32));
	dh->insert(make_pair("ala",22));
	dh->insert(make_pair("ela",356));
	dh->erase("ela");
	dh->insert(make_pair("ale",3123));

	dh->printList();*/
	//string s = "hola";
	//int su = (int)s[0]+(int)s[1]+(int)s[2]+(int)s[3];
	//cout<<su<<endl;
	//cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<endl;
	//int h = (int)s[0];
	//cout<<h<<endl;
	//vector<pair<string,int>> v(17);
	//make_pair {}
	//int indice = hashf(s,17);
	//cout<<indice<<endl;
	//v[indice]= make_pair("hola",3);
	//v[hashf("helo", 17)] = make_pair("helo",5);
	//for(int i =0;i<v.size();i++){
	//	cout<<v[i].first<<" - "<<v[i].second<<endl;
	//}
	/*vector<pair<string,int>> v(16);
	cout<<v.size()<<endl;
	cout<<v[0].second<<endl;
	cout<<v[1].second<<endl;
	if(v[0].first=="")cout<<"es nulo"<<endl;
	else cout<<"no es nulo"<<endl;
	v[0].first = "hola mundo";
	if(v[0].first=="")cout<<"es nulo"<<endl;
	else cout<<v[0].first<<endl;*/
	return 0;
}
