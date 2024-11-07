#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to swap two students
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Bubble Sort (Sort by Roll No)
void bubbleSortByRollNo(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (students[j].rollNo > students[j + 1].rollNo)
                swap(students[j], students[j + 1]);
}

// Insertion Sort (Sort by Name Alphabetically)
void insertionSortByName(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Partition function for Quick Sort (Sort by SGPA)
int partition(vector<Student>& students, int low, int high) {
    float pivot = students[low].sgpa;
    int i = low, j = high;
    while (i < j) {
        while (students[i].sgpa >= pivot && i < high) i++;
        while (students[j].sgpa < pivot) j--;
        if (i < j) swap(students[i], students[j]);
    }
    swap(students[low], students[j]);
    return j;
}

// Quick Sort (Sort by SGPA - Top 10 Toppers)
void quickSortBySGPA(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pIndex = partition(students, low, high);
        quickSortBySGPA(students, low, pIndex - 1);
        quickSortBySGPA(students, pIndex + 1, high);
    }
}

// Display the list of students
void displayStudents(const vector<Student>& students) {
    for (const auto& student : students)
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
}

// Search students by SGPA
void searchBySGPA(const vector<Student>& students, float sgpa) {
    bool found = false;
    for (const auto& student : students)
        if (student.sgpa == sgpa) {
            cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
            found = true;
        }
    if (!found) cout << "No student found with SGPA: " << sgpa << endl;
}

// Binary Search (Search by Name)
void binarySearchByName(const vector<Student>& students, const string& name) {
    int low = 0, high = students.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].name == name) {
            cout << "Roll No: " << students[mid].rollNo << ", Name: " << students[mid].name << ", SGPA: " << students[mid].sgpa << endl;
            return;
        }
        (students[mid].name < name) ? low = mid + 1 : high = mid - 1;
    }
    cout << "Student not found with name: " << name << endl;
}

int main() {
    vector<Student> students = {
        {101, "Alice", 8.5}, {102, "Bob", 7.4}, {103, "Charlie", 9.2},
        {104, "David", 6.8}, {105, "Eve", 8.0}, {106, "Frank", 9.1},
        {107, "Grace", 7.5}, {108, "Hank", 8.3}, {109, "Ivy", 8.7},
        {110, "Jack", 6.5}, {111, "Karen", 9.3}, {112, "Leo", 7.8},
        {113, "Mona", 8.9}, {114, "Nina", 8.0}, {115, "Oscar", 7.9}
    };

    // Part a: Bubble Sort by Roll No
    bubbleSortByRollNo(students);
    cout << "Sorted by Roll No:" << endl; displayStudents(students);

    // Part b: Insertion Sort by Name
    insertionSortByName(students);
    cout << "\nSorted by Name:" << endl; displayStudents(students);

    // Part c: Quick Sort to find Top 10 Toppers (by SGPA)
    quickSortBySGPA(students, 0, students.size() - 1);
    cout << "\nTop 10 Toppers (Sorted by SGPA):" << endl; displayStudents(students);

    // Part d: Search students by SGPA
    float sgpa; 
    cout << "\nEnter SGPA to search: "; cin >> sgpa;
    searchBySGPA(students, sgpa);

    // Part e: Binary Search by Name
    string name; 
    cout << "\nEnter name to search: "; cin >> name;
    binarySearchByName(students, name);

    return 0;
}
