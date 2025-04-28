#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student
struct Student {
    char name[50];
    int id;
    char department[50];
};

// Function to display available departments
void showDepartments() {
    printf("\nAvailable Departments:\n");
    printf("1. Computer Science\n");
    printf("2. Electronics\n");
    printf("3. Mechanical\n");
    printf("4. Civil\n");
    printf("5. Electrical\n");
}

// Function to save student data to file
void saveToFile(struct Student s) {
    FILE *file = fopen("admission_list.txt", "a"); // "a" to append
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Name: %s | ID: %d | Department: %s\n", s.name, s.id, s.department);
    fclose(file);
    printf("Student details saved successfully.\n");
}

// Function to register a student
void registerStudent() {
    struct Student s;
    int choice;
    
    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", s.name); // Read full line
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    
    showDepartments();
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: strcpy(s.department, "Computer Science"); break;
        case 2: strcpy(s.department, "Electronics"); break;
        case 3: strcpy(s.department, "Mechanical"); break;
        case 4: strcpy(s.department, "Civil"); break;
        case 5: strcpy(s.department, "Electrical"); break;
        default: strcpy(s.department, "Unknown"); break;
    }
    
    saveToFile(s);
}

int main() {
    int option;
    
    do {
        printf("\n--- College Admission System ---\n");
        printf("1. Register Student\n");
        printf("2. Show Available Departments\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerStudent();
                break;
            case 2:
                showDepartments();
                break;
            case 3:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 3);
    
    return 0;
}