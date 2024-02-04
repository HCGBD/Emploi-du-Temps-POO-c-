#ifndef TOPOLOGICALSORTER_H
#define TOPOLOGICALSORTER_H

#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"
#include<vector>

class TopologicalSorter{
public:
		
	Activity* bruteForceSort(Activity* activities, PrecedenceConstraint* constraints, int numActivities, int numConstraints);
	Activity auxiliary(Activity* activities, Activity* result, int& resultIndex, PrecedenceConstraint* constraints, int numConstraints, int numActivities);
	void removeActivity(Activity* activities, int& numActivities, Activity activity);
	bool contains(Activity* array, int size, Activity activity);

private:

};


#endif // !TOPOLOGICALSORTER_H


