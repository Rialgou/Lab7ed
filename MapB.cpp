#include <bits/stdc++.h>
#include "MapB.h"
using namespace std;

MapB::MapB(int N){
	v = vector<pair<string,int>>(N/2);;
	fill =0;
	colisionesAt=0;
	colisionesInsert=0;
}
MapB::~MapB(){
}
void MapB::insert(pair<string,int> p){
	float alpha = (float)fill/(float)v.size();
	if(alpha >=0.5) rehash();
	//cout<<"v.size despues de rehash es: "<<v.size()<<endl;
	int indice = hashf(p.first,v.size());
	//cout<<"v.size es: "<<v.size()<<endl;
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""||v[indice].first=="$"){
			v[indice].first = p.first;
			v[indice].second = p.second;
			fill++;
			return;
		}
		else if(v[indice].first == p.first){
			return;
		}
		else{
			colisionesInsert++;
			indice = (indice+1)%v.size();
		}
	}
	return;
}
void MapB::erase(string s){
	int indice = hashf(s,v.size());
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""){
			return;
		}
		else if(v[indice].first == s){
			v[indice].first = "$";
			v[indice].second = INT_MIN;
			fill--;
			return;
		}
		else{
			indice = (indice+1)%v.size();
		}
	}
	return;
}
int MapB::at(string s){
	int indice = hashf(s,v.size());
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""){
			return INT_MIN;
		}
		else if(v[indice].first == s){
			return v[indice].second;
		}
		else{
			colisionesAt++;
			indice = (indice+1)%v.size();
		}
	}
	return INT_MIN;
}
int MapB::size(){
	return fill;
}
bool MapB::empty(){
	return size()<1;
}
int MapB::hashf(string s,int n){
	int suma=0;
	//cout<<"el entero pasado a hasf es: "<<n<<endl;
	for(int i=0;i<s.size();i++){
		suma=suma+(int)s[i];
		//cout<<s[i]<<": "<<(int)s[i]<<endl;
	}
	//cout<<"siguiente: "<<endl;
	return suma%n;
}
void MapB::rehash(){
	int n = v.size()*2;
	//cout<<"v.size(): "<<v.size();
	fill =0;
	vector<pair<string,int>> aux = vector<pair<string,int>>(n);
	for(int i=0;i<v.size();i++){
		if(v[i].first!=""&&v[i].first!="$"){
			int indice = hashf(v[i].first,n);
			for(int j=0;j<aux.size();j++){
				if(aux[indice].first==""||aux[indice].first=="$"){
					aux[indice].first = v[i].first;
					aux[indice].second = v[i].second;
					fill++;
					break;
				}
				else if(aux[indice].first == v[i].first){
					break;
				}
				else{
					indice = (indice+1)%aux.size();
				}
			}
		}		
	}
	v = aux;
}
void MapB::printList(){
	for(int i=0;i<v.size();i++){
		cout<<"key: "<<v[i].first<<"- value: "<<v[i].second<<endl;
	}
}
int MapB::getColisionesAt(){
	return colisionesAt;
}
int MapB::getColisionesInsert(){
	return colisionesInsert;
}