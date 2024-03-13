#include <stdio.h>

// Define the student struct
struct student {
    char name[50];
    int ID;
    int age;
};

int main() {
    // Declare a variable of type struct student
    struct student st1;

    // Input from the user
    printf("Enter name: ");
    scanf(" %[^\n]s", st1.name); // %[^\n]s reads the input until newline is encountered

    printf("Enter ID: ");
    scanf("%d", &st1.ID);

    printf("Enter age: ");
    scanf("%d", &st1.age);

    // Print the values
    printf("\nStudent Details:\n");
    printf("Name: %s\n", st1.name);
    printf("ID: %d\n", st1.ID);
    printf("Age: %d\n", st1.age);

    return 0;
}

