#include "TopologicalSorter.h"
#include<iostream>
#include"Activity.h"
#include"PrecedenceConstraint.h"

#include <algorithm>

using namespace std;

Activity* TopologicalSorter::bruteForceSort(Activity* activities, PrecedenceConstraint* constraints, int numActivities, int numConstraints) {
    // Copie des activités dans un nouveau tableau
    Activity* acts = new Activity[numActivities];
    for (int i = 0; i < numActivities; ++i) {
        acts[i] = activities[i];
    }

    Activity* result = new Activity[numActivities];
    int resultIndex = 0;

    while (resultIndex < numActivities) {
        Activity activity = auxiliary(acts, result, resultIndex, constraints, numConstraints,numActivities);

        if (activity.isEmpty()) {
            return {};
        }

        result[resultIndex++] = activity;
        removeActivity(acts, numActivities, activity);
    }

    delete[] acts; // Libérer la mémoire allouée dynamiquement pour la copie
    return (resultIndex == numActivities) ? result : nullptr;
}


Activity TopologicalSorter::auxiliary(Activity* activities, Activity* result, int& resultIndex, PrecedenceConstraint* constraints, int numConstraints, int numActivities) {
   
    for (int i = 0; i < numActivities; ++i) {
        bool ok = true;

        for (int j = 0; j < numConstraints; ++j) {
            if (constraints[j]._getSecond() == activities[i] && !contains(result, resultIndex, constraints[j]._getFirst())) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "Activite "<< ": Description : " << activities[i]._getDescription() << endl;
            return activities[i];
        }
        else
        {
            
        }
    }

  //  return {};
  //  cout << "one Non accepter" << endl;
    //  return {};
}


 void TopologicalSorter::removeActivity(Activity* activities, int& numActivities, Activity activity) {
    int index = -1;
    for (int i = 0; i < numActivities; ++i) {
        if (activities[i] == activity) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < numActivities - 1; ++i) {
            activities[i] = activities[i + 1];
        }
        --numActivities;
    }
}

 bool TopologicalSorter::contains(Activity* array, int size, Activity activity) {
     for (int i = 0; i < size; ++i) {
         if (array[i] == activity) {
             return true;
         }
     }
     return false;
 }