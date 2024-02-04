#ifndef ACTIVITY_H
#define ACTIVITY_H

#include<iostream>

class Activity {

public:

	Activity();
	Activity(std::string, int);
	std::string _getDescription();
	int _getDuration();

	bool isEmpty() const {
		return _description.empty() && (_Duration == 0);
	}

	bool operator==(const Activity& other) const {


		return _description == other._description && _Duration == other._Duration;
	}

private:
	std::string _description;
	int _Duration;

};

#endif // !ACTIVITY_H




