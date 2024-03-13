// Nestor Garcia
// 12/12/2022
// Hash Table of Employees

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

struct Employee {
    string name, department;
    int ID;

    Employee(string argName = "Jane", string argDept = "retail", int argID = 0) {
        name = argName;
        department = argDept;
        ID = argID;
    }
};

int hashIndex(int buckets, Employee argEmployee, vector<string> argDepts);

bool compare(Employee argEmployee1, Employee argEmployee2);
void printTable(list<Employee> arg[], const int size);


int main(void) {
    srand(time(NULL));

    const int size = 5;

    list<Employee> hashTable[size];
    vector<string> employeeNames = { "Aaron", "John", "Joe", "Zac", "Isaiah", "Hykeem", "Ann", "Timothy", "James", "Jeremy", "Christina", "Maria", "Earl"};
    vector<string> employeeDepts = { "Retail", "Online", "Shipping", "Warehouse", "Delivery" };


    for (int i = 0; i < 50; i++) {

        string randName = employeeNames[rand() % employeeNames.size()];
        string randDept = employeeDepts[rand() % employeeDepts.size()];

        Employee newHire = Employee(randName, randDept, (rand() % 99999));

        int key = hashIndex(size, newHire, employeeDepts);
        hashTable[key].push_back(newHire);

    }
    
    for (int i = 0; i < size; i++) {
        hashTable[i].sort(compare);

    }

    printTable(hashTable, size);


    return 0;
}



int hashIndex(int buckets, Employee argEmployee, vector<string> argDepts) {
    int index = -1;

    for (int j = 0; j < buckets; j++) {
        if (argEmployee.department == argDepts[j]) { // if the employees dept matches the dept in the vector of depts then place them in said number bucket

            index = j;
            
            return index;
        }
    }

    return index;
}

bool compare(Employee argEmployee1, Employee argEmployee2) {

    return(argEmployee1.ID < argEmployee2.ID);

}


void printTable(list<Employee> arg[], const int size) {
    list<Employee>::iterator itr;

    for (int i = 0; i < size; i++) {
        cout << "\nBucket " << i << ": " << endl;

        for (itr = arg[i].begin(); itr != arg[i].end(); itr++) {
            cout << itr->name << ", " << itr->department << ", " << itr->ID << endl;

        }
        

        cout << endl;

    }
}