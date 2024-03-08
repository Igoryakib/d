#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string PIB;
    string institute;
    string fatherProfession;
    string motherProfession;
    int siblingsCount;
};

vector<Student> students;

void addStudent(Student s) {
    students.push_back(s);
}

void searchStudent(string PIB) {
    for (const auto& s : students) {
        if (s.PIB == PIB) {
            cout << "��������: " << s.PIB << ", " << s.institute << ", " << s.fatherProfession << ", " << s.motherProfession << ", " << s.siblingsCount << endl;
        }
    }
}

void viewStudents() {
    for (const auto& s : students) {
        cout << s.PIB << ", " << s.institute << ", " << s.fatherProfession << ", " << s.motherProfession << ", " << s.siblingsCount << endl;
    }
}

void modifyStudent(string PIB, string newInstitute, string newFatherProfession, string newMotherProfession, int newSiblingsCount) {
    for (auto& s : students) {
        if (s.PIB == PIB) {
            s.institute = newInstitute;
            s.fatherProfession = newFatherProfession;
            s.motherProfession = newMotherProfession;
            s.siblingsCount = newSiblingsCount;
        }
    }
}

void deleteStudent(string PIB) {
    students.erase(remove_if(students.begin(), students.end(), [PIB](const Student& s) { return s.PIB == PIB; }), students.end());
}

bool compareByPIB(const Student& a, const Student& b) {
    return a.PIB < b.PIB;
}

void sortStudents() {
    sort(students.begin(), students.end(), compareByPIB);
}

void saveToFile() {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& s : students) {
            file << s.PIB << ", " << s.institute << ", " << s.fatherProfession << ", " << s.motherProfession << ", " << s.siblingsCount << endl;
        }
    }
    file.close();
}

int main() {
    // ��������� ����� ��������
    addStudent({ "Ivanov Ivan Ivanovich", "Institute of Information Technology", "Engineer", "Teacher", 2 });
    addStudent({ "Petrov Petro Petrovich", "Institute of Economics and Management", "Accountant", "Doctor", 1 });
    addStudent({ "Sidorov Sidir Sidorovich", "Institute of Mechanics and Machine Building", "Machinist", "Seller", 0 });

    // ����� �������� �� ϲ�
    searchStudent("������ ���� ��������");
    cout << endl;

    // �������� ��� ��������
    viewStudents();
    cout << endl;
    saveToFile();
    addStudent({ "Melnik Mykola Mykolayovych", "Institute of Economics and Management", "Lawyer", "Psychologist", 1 });
    addStudent({ "Kovalenko Kateryna Ivanivna", "Institute of Information Technology", "Programmer", "Designer", 0 });
    addStudent({ "Boyko Bohdan Bohdanovych", "Institute of Mechanics and Machine Building", "Mechanic", "Accountant", 2 });
    addStudent({ "Tkachenko Tetiana Tarasivna", "Institute of Information Technology", "Engineer", "Teacher", 3 });
    addStudent({ "Shevchenko Shevchenko Shevchenkovych", "Institute of Economics and Management", "Economist", "Doctor", 1 });
    addStudent({ "Lysenko Liudmyla Leonidivna", "Institute of Mechanics and Machine Building", "Machinist", "Seller", 0 });
    addStudent({ "Honcharenko Hanna Heorhiivna", "Institute of Information Technology", "Programmer", "Designer", 2 });

    viewStudents();
    cout << endl;
    saveToFile();

    // ���� ����� ��������
    modifyStudent("������ ���� ��������", "�������� ������������� ���������", "�������", "�������", 3);
    viewStudents();
    cout << endl;
    saveToFile();
    // ��������� ��������
    deleteStudent("������� ���� ���������");
    viewStudents();
    cout << endl;
    saveToFile();
    // ���������� �������� �� ϲ�
    sortStudents();
    saveToFile();
    // ���������� ���������� � ����
    //saveToFile();

    return 0;
}
