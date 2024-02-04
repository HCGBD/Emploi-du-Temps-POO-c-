#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"
#include"MeetConstraint.h"
#include<vector>
#include <algorithm>
#include"TopologicalSorter.h"


using namespace std;

int main(int agrc, char** agrv) {
	/*
	Activity t1("Aller au cours de POO", 10);
	Activity t2("Aller au cours de Probabilite",15);

	//cout << "La liste des taches:" << endl;
	//cout << "Tache une :" << t1._getDescription() << " a " << t1._getDuration() << " min"<<endl;
	//cout << "Tache deux :" << t2._getDescription() << " a " << t2._getDuration() << " min"<<endl;

	PrecedenceConstraint c1(t1, t2);
	
	Activity t3;
	t3 = c1._getSecond();
	//cout << "Tache 3 :" << c1._getFirst()._getDescription() << " a " << c1._getFirst()._getDuration() << " min" << endl;
	//cout << "Tache contraint :" << t3._getDescription() << " a " << t3._getDuration() << " min" << endl;
	
	int tm = c1.isSatisfied(500,5);
	cout << tm << endl;

	if (tm) {
		cout<<"Satisfait !!"<<endl;
	}
	else
	{
		cout<<"Non Satisfait -_- "<<endl;
	}

*/
	Activity atc[6] = {

	// Ajouter des activites 
	 Activity("Se Lever", 1),
	 Activity("Aller au travail", 15),
	 Activity("Prendre une douche", 10),
	 Activity("Se brosser les dents", 3),
	 Activity("S'Habiller", 2),
	 Activity("Prendre un petit dejeuner", 15)

	};


	cout << "Avant le tri topologique " << endl;
	// Affichez les activités ajoutées
	for (int i = 0; i < 6; ++i) {
		cout << "Activite " << i + 1 << ": Description : " << atc[i]._getDescription() << ", Dure : " << atc[i]._getDuration() << " min"<<endl;
	}

	cout << endl;

	// Ajouter des contraintes de precendence

	PrecedenceConstraint cntrt[8] = {
			PrecedenceConstraint(atc[0],atc[5]),
			PrecedenceConstraint(atc[0],atc[4]),
			PrecedenceConstraint(atc[5],atc[3]),
			PrecedenceConstraint(atc[2],atc[4]),
			PrecedenceConstraint(atc[3],atc[1]),
			PrecedenceConstraint(atc[4],atc[1]),
			PrecedenceConstraint(atc[0],atc[2]),
			PrecedenceConstraint(atc[5],atc[1])

	};

	int numAct = 6;
	int numCnt = 8;

	TopologicalSorter ord;

	Activity* ordenan = new Activity[numAct];
		
	ordenan = ord.bruteForceSort(atc, cntrt, numAct, numCnt);

	cout << endl;
	cout << "Apres le tri topologique " << endl;

	for (int i = 0; i < 6; ++i) {
		cout << "Activite " << i + 1 << ": Description : " << ordenan[i]._getDescription()  << endl;
	}

	return 0;
}