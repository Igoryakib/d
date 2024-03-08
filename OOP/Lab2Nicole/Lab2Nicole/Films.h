#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Film.h"

using namespace std;

class Films {
private:
	vector<Film> films;
	int listLength = films.size();
	int maxListLength = 10;
public:
	Films();
	void changeMaxLength(int limit);

	void addNewObj(Film obj);

	void findElement(int id);

	void findChangeElement(int id, string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar);

	void getAllList();

	void deleteFilm(int id);

	void getDirectorFilm(string directorName);

	void sortFilmByName();
};