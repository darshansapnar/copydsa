#include <iostream>
#include <string>
using namespace std;

// Define a Student class to hold the roll number and name
class Student {
public:
    int rollNumber;
    string name;

    // Constructor to initialize student with roll number and name
    Student(int roll, string studentName) {
        rollNumber = roll;
        name = studentName;
    }
};

// Function to swap two Student objects based on roll number
void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Function to perform Bubble Sort on the student list based on roll number
void bubbleSort(Student arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j].rollNumber > arr[j + 1].rollNumber) {
                // Swap students if their roll numbers are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to display the list of students
void displayStudents(Student arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "Roll Number: " << arr[i].rollNumber << ", Name: " << arr[i].name << endl;
    }
}

int main() {
    // Create an array of students
    Student students[] = {
        Student(3, "John"),
        Student(1, "Alice"),
        Student(4, "Bob"),
        Student(2, "Charlie")
    };
    int length = sizeof(students) / sizeof(students[0]);

    cout << "Original Roll Call List: " << endl;
    displayStudents(students, length);  // Display the original list

    // Sort the students by their roll number using Bubble Sort
    bubbleSort(students, length);

    cout << "\nSorted Roll Call List (by Roll Number): " << endl;
    displayStudents(students, length);  // Display the sorted list

    return 0;
}
