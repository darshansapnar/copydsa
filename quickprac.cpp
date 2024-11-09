#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int score;

    // Constructor to initialize student with name and score
    Student(string n, int s) {
        name = n;
        score = s;
    }
};

// Partition function for Quick Sort
int partition(Student arr[], int low, int high) {
    Student pivot = arr[low]; // Use the first element as pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Find element from the left greater than the pivot
        while (arr[i].score >= pivot.score && i < high) {
            i++;
        }
        // Find element from the right smaller than the pivot
        while (arr[j].score < pivot.score && j > low) {
            j--;
        }
        // Swap elements if needed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]); // Place pivot in correct position
    return j; // Return pivot index
}

// Quick Sort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

// Function to display the top 10 students
void displayTopTen(Student arr[], int n) {
    for (int i = 0; i < min(10, n); i++) {
        cout << arr[i].name << " - Score: " << arr[i].score << endl;
    }
}


int main() {
    // Sample list of students
    Student students[] = {
        Student("Alice", 95),
        Student("Bob", 85),
        Student("Charlie", 98),
        Student("David", 90),
        Student("Eva", 87),
        Student("Frank", 82),
        Student("Grace", 88),
        Student("Helen", 92),
        Student("Ian", 84),
        Student("Jack", 89),
        Student("Kara", 97)
    };
    int n = sizeof(students) / sizeof(students[0]);

    // Sort the students by score in descending order
    quickSort(students, 0, n - 1);

    // Display the top 10 students
    displayTopTen(students, n);

    return 0;
}
