#include <stdio.h>

// Function to convert grade to grade points
float gradeToPoint(char grade) {
    switch(grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int totalCredits = 0;
    float totalPoints = 0.0;
    int credits, i;
    char grade;

    printf("Enter the number of courses: ");
    scanf("%d", &i);

    for (int j = 0; j < i; j++) {
        printf("Enter the grade obtained for course %d (A, B, C, D, F): ", j+1);
        scanf(" %c", &grade); // Notice the space before %c to consume the newline character

        printf("Enter the number of credits for course %d: ", j+1);
        scanf("%d", &credits);

        // Add the credit to total credits
        totalCredits += credits;

        // Add the points to total points
        float points = gradeToPoint(grade);
        if (points == -1.0) {
            printf("Invalid grade entered. Please enter A, B, C, D, or F.\n");
            j--; // Decrement j to re-enter the current course details
            continue;
        }
        totalPoints += points * credits;
    }

    // Calculate and print CGPA
    if (totalCredits != 0) {
        float cgpa = totalPoints / totalCredits;
        printf("Your CGPA is: %.2f\n", cgpa);
    } else {
        printf("No credits entered.\n");
    }

    return 0;
}
