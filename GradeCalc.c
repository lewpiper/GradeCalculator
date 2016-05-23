//Midterm Grade Calculator
//Lew Piper III | Palomar ID 011263249

#include <stdio.h>
#include <stdlib.h>
void calculateAverage();

FILE *fpOut;

int main(int argc, const char * argv[]) {
    //Opening file for writing output to
    if (!(fpOut = fopen("csis.txt", "w"))) {
        printf("csis.text could not be opened for output");
        exit(1);
    }
    calculateAverage();
    fclose(fpOut);
    return 0;
}

void calculateAverage(void) {
    //Init all variables needed
    char firstName[15], lastName[15];
    char grade, nextStudent;
    double Score1, Score2, Score3;
    double average;
    nextStudent = 'Y';
    Score1 = 0;
    Score2 = 0;
    Score3 = 0;
    average = 0;
    grade = 'A';
    
    while (nextStudent == 'Y' || nextStudent == 'y') {
        //Prompt for student name information
        printf("What is the student's first name? ");
        scanf("%s", &*firstName);
        fprintf(fpOut,"What is the student's first name? %s \n", firstName);
        printf("What is the student's last name? ");
        scanf("%s", &*lastName);
        fprintf(fpOut,"What is the student's last name? %s \n", lastName);
        
        //Ask for first test score and check validity of input
        printf("What was the first test score? ");
        scanf("%lf", &Score1);
        fprintf(fpOut,"What was the first test score? %.2lf\n", Score1);
        while (Score1 > 100 || Score1 < 0) {
            printf("Invalid score, the valid range is 0 – 100\n");
            fprintf(fpOut,"Invalid score, the valid range is 0 – 100\n");
            printf("What was the first test score? ");
            scanf("%lf", &Score1);
            fprintf(fpOut,"What was the first test score? %.2lf\n", Score1);
        }
        
        //Ask for second test score and check validity of input
        printf("What was the second test score? ");
        scanf("%lf", &Score2);
        fprintf(fpOut,"What was the second test score? %.2lf\n", Score2);
        while (Score2 > 100 || Score2 < 0) {
            printf("Invalid score, the valid range is 0 – 100\n");
            fprintf(fpOut,"Invalid score, the valid range is 0 – 100\n");
            printf("What was the second test score? ");
            scanf("%lf", &Score2);
            fprintf(fpOut,"What was the second test score? %.2lf\n", Score2);
        }
        
        //Ask for third test score and check validity of input
        printf("What was the third test score? ");
        scanf("%lf", &Score3);
        fprintf(fpOut,"What was the third test score? %.2lf\n", Score3);
        while (Score3 > 100 || Score3 < 0) {
            printf("Invalid score, the valid range is 0 – 100\n");
            fprintf(fpOut,"Invalid score, the valid range is 0 – 100\n");
            printf("What was the third test score? ");
            scanf("%lf", &Score3);
            fprintf(fpOut,"What was the third test score? %.2lf\n", Score3);
        }
        
        //Output for each student of name, average and letter grade
        printf("\n");
        fprintf(fpOut,"\n");
        printf("Name: %s %s\n", firstName, lastName);
        fprintf(fpOut,"Name: %s %s\n", firstName, lastName);
        average = (Score1 + Score2 + Score3)/3;
        printf("Average: %.2lf\n", average);
        fprintf(fpOut,"Average: %.2lf\n", average);
        
        //Logic for letter grade and printing grade
        if (average >= 90.00) {
            grade = 'A';
        } else if (average >= 80.00 && average <= 89.99) {
            grade = 'B';
        } else if (average >= 70.00 && average <= 79.99) {
            grade = 'C';
        } else if (average >= 60.00 && average <= 69.99) {
            grade = 'D';
        } else if (average < 60) {
            grade = 'F';
        }
        printf("Letter Grade: %c\n", grade);
        fprintf(fpOut,"Letter Grade: %c\n", grade);
        printf("\n");
        fprintf(fpOut,"\n");
        average = 0;
        
        //Asking if there is another student to calculate
        printf("Calculate another student grade: (press Y for Yes, press N for No)");
        scanf("%s", &nextStudent);
        fprintf(fpOut,"Calculate another student grade: (press Y for Yes, press N for No) %c \n", nextStudent);
        
        //If the user responses with anything out of the input range ask again
        while (nextStudent != 'Y' && nextStudent != 'y' && nextStudent != 'N' && nextStudent != 'n') {
            printf("The command entered was an invalid letter entry.\n");
            fprintf(fpOut,"The command entered was an invalid letter entry.\n");
            printf("Calculate another student grade: (press Y for Yes, press N for No) ");
            scanf("%s", &nextStudent);
            fprintf(fpOut,"Calculate another student grade: (press Y for Yes, press N for No) %c \n", nextStudent);
        }
        
        //Break the loop if there is no more students
        if (nextStudent == 'N' || nextStudent == 'n') {
            break;
        }
    }
}