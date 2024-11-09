#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;

    // Constructor to initialize the Student object
    Student(int roll, string n) {
        rollNo = roll;
        name = n;
    }
};

// Insertion sort function to sort students alphabetically by name
void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > temp.name) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Display function to print roll numbers and names of students
void display(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].rollNo << ": " << arr[i].name << endl;
    }
}

int main() {
    // Array of Student objects
    Student arr[] = {
        Student(2, "Om"),
        Student(5, "Bhaveek"),
        Student(1, "Atharva"),
        Student(9, "Shivam")
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original List:" << endl;
    display(arr, n);  // Display the original list

    insertionSort(arr, n);  // Sort students alphabetically by name

    cout << "\nSorted List (Alphabetically):" << endl;
    display(arr, n);  // Display the sorted list

    return 0;
}
