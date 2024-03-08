#include "Film.h"

Film::Film(string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar, int id) {
	this->name = name;
	this->mainRoleActor = mainRoleActor;
	this->director = director;
	this->releaseYear = releaseYear;
	this->budget = budget;
	this->boxOfficeFee = boxOfficeFee;
	this->oscar = oscar;
	this->id = id;
};

void Film::changeName(string name) {
	this->name = name;
};

void Film::changeMainRoleActor(string name) {
	this->mainRoleActor = name;
};
void Film::changeDirector(string name) {
	this->director = name;
};
void Film::changeReleaseYear(int year) {
	this->releaseYear = year;
};
void Film::changeBudget(int budget) {
	this->budget = budget;
};
void Film::changeBoxOfficeFee(int boxOfficeFee) {
	this->boxOfficeFee = boxOfficeFee;
};
void Film::changeOscar(bool oscar) {
	this->oscar = oscar;
};

string Film::getName() {
	return this->name;
};
string Film::getMainRoleActor() {
	return this->mainRoleActor;
};
string Film::getDirector() {
	return this->director;
};
int Film::getReleaseYear() {
	return this->releaseYear;
};
int Film::getBudget() {
	return this->budget;
};
int Film::getBoxOfficeFee() {
	return this->boxOfficeFee;
};
bool Film::getOscar() {
	return this->oscar;
};

int Film::getId() {
	return this->id;
}

void Film::getData() {
	cout << "Film name: " << this->getName() << "\t" << "director: " << this->getDirector() << "\t" << "main role actor: " << this->getMainRoleActor() << "budget: " << this->getBudget() << "\t" << "release year: " << this->getReleaseYear() << "\t" << "box office fee: " << this->getBoxOfficeFee() << "\t" << "oscar: " << (this->getOscar() ? "Yes" : "No") << endl;
}

void Film::changeData(string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar) {
	if (!name.empty()) {
		this->changeName(name);
	}
	if (!mainRoleActor.empty()) {
		this->changeMainRoleActor(mainRoleActor);
	}
	if (!director.empty()) {
		this->changeDirector(director);
	}
	if (releaseYear) {
		this->changeReleaseYear(releaseYear);
	}
	if (budget) {
		this->changeBudget(budget);
	}
	if (boxOfficeFee) {
		this->changeBoxOfficeFee(boxOfficeFee);
	}
	this->changeOscar(oscar);
};