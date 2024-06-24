#include <iostream>
#include <iomanip>
using namespace std;

class Student {
    string surname;
    double averageGrade;
    bool scholarship;
public:
    Student() : surname(""), averageGrade(0.0), scholarship(false) {}

    void setStudentData(string s, double avg) {
        surname = s;
        averageGrade = avg;
        scholarship = (avg >= 8.0);
    }

    void print() const {
        cout << "Surname: " << surname << ", Average Grade: "
            << fixed << setprecision(2) << averageGrade
            << ", Scholarship: " << boolalpha << scholarship << endl;
    }
};

int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    if (n > MAX_STUDENTS) {
        cout << "The number of students exceeds the maximum limit of " << MAX_STUDENTS << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string surname;
        double averageGrade;
        cout << "Enter surname of student " << i + 1 << ": ";
        cin >> surname;
        cout << "Enter average grade of student " << i + 1 << ": ";
        cin >> averageGrade;
        students[i].setStudentData(surname, averageGrade);
    }

    cout << "\nStudent data:\n";
    for (int i = 0; i < n; i++) {
        students[i].print();
    }

    return 0;
}