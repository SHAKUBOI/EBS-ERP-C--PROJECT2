#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Define the Student class
class Student {
public:
    string name;
    string first_name;
    string class_name;
    string id;
    string password;

    // Constructor to initialize the Student object
    Student(string name, string first_name, string class_name, string id, string password)
        : name(name), first_name(first_name), class_name(class_name), id(id), password(password) {}

    // Function to check if the provided ID and password match the stored values
    bool login(string input_id, string input_password) const {
        return (input_id == id && input_password == password);
    }
};

// Global vector of students
vector<Student> students;

void initializeStudents() {
    // Initialize the students vector with some data
    students.push_back(Student("Doe", "John", "10th Grade", "12345", "password123"));
    students.push_back(Student("Smith", "Jane", "11th Grade", "67890", "mypassword"));
}

int main() {
    initializeStudents();  // Call this function to initialize students

    string input_id, input_password;
    bool is_logged_in = false;

    cout << "Welcome to the School Login System\n";
    cout << "Please enter your student ID: ";
    cin >> input_id;

    cout << "Please enter your password: ";
    cin >> input_password;

    // Check login credentials for each student
    for (const Student& student : students) {
        if (student.login(input_id, input_password)) {
            is_logged_in = true;
            cout << "Login successful! Welcome, " << student.first_name << " " << student.name << " from " << student.class_name << "!\n";
            break;
        }
    }

    // If login fails
    if (!is_logged_in) {
        cout << "Login failed! Incorrect ID or password.\n";
    }

    return 0;
}
