#include <stdio.h>

#define MAX 50

// Global variables
int rollNo[MAX];
char name[MAX][30];
int marks[MAX][5];
int total[MAX];
float percentage[MAX];
char grade[MAX];
int count = 0;

// Function to calculate grade
char calculateGrade(float per) {
    if (per >= 80)
        return 'A';
    else if (per >= 60)
        return 'B';
    else if (per >= 40)
        return 'C';
    else
        return 'F';
}

// Function to add student
void addStudent() {
    int i;

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNo[count]);

    getchar();  //  clears leftover newline

    printf("Enter Student Name: ");
    fgets(name[count], 30, stdin);

    total[count] = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter marks of subject %d: ", i + 1);
        scanf("%d", &marks[count][i]);
        total[count] += marks[count][i];
    }

    percentage[count] = total[count] / 5.0;
    grade[count] = calculateGrade(percentage[count]);

    count++;

    printf("\nStudent record added successfully!\n");
}

// Function to display all students
void displayStudents() {
    int i, j;

    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\n-----------------------------");
        printf("\nRoll No: %d", rollNo[i]);
        printf("\nName: %s", name[i]);
        printf("\nMarks: ");

        for (j = 0; j < 5; j++) {
            printf("%d ", marks[i][j]);
        }

        printf("\nTotal Marks: %d", total[i]);
        printf("\nPercentage: %.2f%%", percentage[i]);
        printf("\nGrade: %c", grade[i]);
        printf("\nStatus: %s",
               (grade[i] == 'F') ? "Fail" : "Pass");
        printf("\n-----------------------------\n");
    }
}

// Function to search student
void searchStudent() {
    int r, i, j;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &r);

    for (i = 0; i < count; i++) {
        if (rollNo[i] == r) {
            printf("\nStudent Found!");
            printf("\nName: %s", name[i]);
            printf("\nMarks: ");

            for (j = 0; j < 5; j++) {
                printf("%d ", marks[i][j]);
            }

            printf("\nTotal: %d", total[i]);
            printf("\nPercentage: %.2f%%", percentage[i]);
            printf("\nGrade: %c", grade[i]);
            return;
        }
    }

    printf("\nStudent record not found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== Student Result Management System ==========");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Results");
        printf("\n3. Search Student by Roll No");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("\nThank you for using the system!");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 4);

    return 0;
}

