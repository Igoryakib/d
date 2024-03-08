#include "Films.h"

Films::Films() {};

void Films::changeMaxLength(int limit) {
	this->maxListLength = limit;
}

void Films::addNewObj(Film obj) {
	if (this->listLength < this->maxListLength) {
		this->films.push_back(obj);
	}
	else {
		cout << "overfilled";
	}
}

void Films::findElement(int id) {
	for (Film& f : this->films) {
		if (f.getId() == id) {
			f.getData();
		}
	}
}

void Films::findChangeElement(int id, string name, string mainRoleActor, string director, int releaseYear, int budget, int boxOfficeFee, bool oscar) {
	for (Film& f : this->films) {
		if (f.getId() == id) {
			f.changeData(name, mainRoleActor, director, releaseYear, budget, boxOfficeFee, oscar);
			f.getData();
		}
	}
}

void Films::getAllList() {
	for (Film& m : this->films) {
		m.getData();
	}
}

void Films::deleteFilm(int id) {
	this->films.erase(remove_if(this->films.begin(), this->films.end(), [id](Film f) { return f.getId() == id; }), this->films.end());
}

void Films::getDirectorFilm(string directorName) {
	for (Film& f : this->films) {
		if (f.getDirector() == directorName) {
			f.getData();
		}
	}
}

void Films::sortFilmByName() {
	sort(this->films.begin(), this->films.end(),
		[](Film a, Film b) { return a.getName() < b.getName(); });
	this->getAllList();
}