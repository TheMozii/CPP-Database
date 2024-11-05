#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <string>

struct Instructor {
	int id;
	std::string surname;
	std::string name;
	std::string trainingType;
};


struct Session {
	int id;
	std::string name;
	std::string startDateTime;
	std::string endDateTime;
	std::string trainer;
};


struct Client {
	int id;
	std::string surname;
	std::string name;
};


struct ExerciseMachine {
	int id;
	std::string name;
	std::string type;
};


struct Equipment {
	int id;
	std::string name;
	std::string type;
};

#endif // DATASTRUCTURES_H

