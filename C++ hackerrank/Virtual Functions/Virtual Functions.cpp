#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
class Person {
  protected:
    char name[256];
    uint32_t age;

  public:
    virtual void putdata() = 0;
    virtual void getdata() = 0;
};

class Student : public Person {
  public:
    Student() {
        id = cur_id++;
        mark = 0;
        age = 1;
    }
    int static cur_id;
    void putdata() {
        std::cout << name << " " << age << " ";
        std::cout << mark << " " << id << '\n';
    };

    void getdata() {
        std::string data;
        std::cin.ignore();
        getline(std::cin, data);
        std::stringstream ss(data);
        ss >> name;
        ss >> age;
        uint32_t m;
        while (ss >> m) {
            mark += m;
        }
    }

  private:
    uint32_t id;
    uint32_t mark;
};

int Student::cur_id = 1;

class Professor : public Person {
  public:
    Professor() {
        id = cur_id++;
        publication = 0;
        age = 1;
    }

    int static cur_id;
    void putdata() {
        std::cout << name << " " << age << " ";
        std::cout << publication << " " << id << '\n';
    };

    void getdata() {
        std::string data;
        std::cin.ignore();
        getline(std::cin, data);
        std::stringstream ss(data);
        ss >> name;
        ss >> age;
        uint32_t pub;
        while (ss >> pub) {
            publication += pub;
        }
    }

  private:
    uint32_t id;
    uint32_t publication;
};
int Professor::cur_id = 1;

int main() {

    int n, val;
    std::cin >> n;     //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++) {
        std::cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        } else
            per[i] = new Student;     // Else the current object is of type Student

        per[i]->getdata();     // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata();     // Print the required output for each object.

    return 0;
}
