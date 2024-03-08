#include <iostream>
#include <string>
#include "Film.h"
#include "Films.h"

using namespace std;

int main()
{
    Film film1("Through My Window 3: Looking at You / A través de tu mirada", "Clara Galle", "Marçal Forés", 2024, 10000000, 27000000, false, 1);
    Film film2("Inception", "Leonardo DiCaprio", "Christopher Nolan", 2010, 160000000, 829000000, true, 2);
    Film film3("The Shawshank Redemption", "Tim Robbins", "Frank Darabont", 1994, 25000000, 58900000, false, 3);
    Film film4("The Shawshank Redemption", "Tim Robbins", "Frank Darabont", 1994, 25000000, 58900000, false, 4);;
    Film film5("The Godfather", "Marlon Brando", "Francis Ford Coppola", 1972, 6000000, 245066411, true, 5);
    
    Films listFilms;
    listFilms.addNewObj(film1);
    listFilms.addNewObj(film2);
    listFilms.addNewObj(film3);
    listFilms.addNewObj(film4);
    listFilms.addNewObj(film5);

    listFilms.getAllList();
    cout << endl;
    listFilms.findChangeElement(2, "", "", "", 2020, 0, 0, true);
    cout << endl;
    listFilms.getAllList();
    return 0;
}