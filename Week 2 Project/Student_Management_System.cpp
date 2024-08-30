#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if
#include <iomanip>   // For std::fixed and std::setprecision

// Define the Student struct
struct Student {
    std::string name;
    int age;
    float gpa; 
};

// Function to trim whitespace from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to read student data from a file
void readStudentsFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file '" << filename << "'. Please make sure the file exists in the correct directory." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        Student student;
        std::string ageStr, gpaStr;
        
        // Read name, age, and GPA
        std::getline(ss, student.name, ',');  // Read name until the first comma
        std::getline(ss, ageStr, ',');        // Read age until the next comma
        std::getline(ss, gpaStr, ',');        // Read GPA until the end of the line

        // Trim whitespace from extracted strings
        student.name = trim(student.name);
        ageStr = trim(ageStr);
        gpaStr = trim(gpaStr);

        // Debug: Print the parsed values
        std::cout << "DEBUG: Parsed - Name: " << student.name << ", Age: " << ageStr << ", GPA: " << gpaStr << std::endl;

        // Convert age and GPA to appropriate data types
        try {
            student.age = std::stoi(ageStr);
            student.gpa = std::stof(gpaStr);  // Changed to std::stof for float conversion
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting age or GPA for student: " << student.name << std::endl;
            continue;
        }

        students.push_back(student);
    }

    file.close();
}

// Function to display all students' details
void displayStudents(const std::vector<Student>& students) {
    std::cout << std::fixed << std::setprecision(2); // Set precision for floating-point numbers
    for (const auto& student : students) {
        std::cout << "Name: " << student.name 
                  << ", Age: " << student.age 
                  << ", GPA: " << student.gpa << std::endl;
    }
}

// Function to search for a student by name
void searchStudent(const std::vector<Student>& students, const std::string& name) {
    for (const auto& student : students) {
        if (student.name == name) {
            std::cout << "Found: " << student.name 
                      << ", Age: " << student.age 
                      << ", GPA: " << student.gpa << std::endl;
            return;
        }
    }
    std::cout << "Student not found!" << std::endl;
}

// Main function
int main() {
    std::vector<Student> students;

    // Step 1: Read the data from the file
    readStudentsFromFile("students.txt", students);

    // Step 2: Display all students
    std::cout << "All Students:" << std::endl;
    displayStudents(students);
    std::cout << std::endl;

    // Step 3: Search for a specific student
    std::string searchName;
    std::cout << "Enter the name of the student to search: ";
    std::getline(std::cin, searchName);
    searchStudent(students, searchName);

    return 0;
}
