#pragma once
#include <iostream>
#include <string>

using namespace std;

class Film {
private:
	string name;
	string mainRoleActor;
	string director;
	int releaseYear;
	int budget;
	int boxOfficeFee;
	bool oscar;
	int id;

public:
	Film(string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar, int id);

	void changeName(string name);
	void changeMainRoleActor(string name);
	void changeDirector(string name);
	void changeReleaseYear(int year);
	void changeBudget(int budget);
	void changeBoxOfficeFee(int boxOfficeFee);
	void changeOscar(bool oscar);
	void changeData(string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar);

	string getName();
	string getMainRoleActor();
	string getDirector();
	int getReleaseYear();
	int getBudget();
	int getBoxOfficeFee();
	bool getOscar();
	int getId();
	void getData();
};