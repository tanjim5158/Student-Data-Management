#include <stdio.h>

struct student {
    int roll;
    char name[50];
    double marks[3];
    float average;
};

int main() {

    FILE *fp;

    struct student students[100];

    int n = 0;
    int choice;
    int searchRoll;
    int found;

   

    fp = fopen("students.txt", "rb");

    if(fp != NULL) {

        while(fread(&students[n], sizeof(struct student), 1, fp)) {
            n++;
        }

        fclose(fp);
    }

    while(choice != 4) {

        printf("\n===== STUDENT PORTAL =====\n");
        printf("1. Enter student details\n");
        printf("2. Show all students\n");
        printf("3. Search by roll\n");
        printf("4. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        getchar();

        switch(choice) {

           

            case 1: {

                float sum = 0;

                printf("\nEnter student name: ");
                scanf("%[^\n]", students[n].name);

                getchar();

                printf("Enter roll: ");
                scanf("%d", &students[n].roll);

                for(int i = 0; i < 3; i++) {

                    printf("Enter mark of subject %d: ", i + 1);

                    scanf("%lf", &students[n].marks[i]);

                    sum = sum + students[n].marks[i];
                }

                students[n].average = sum / 3;

                

                fp = fopen("students.txt", "ab");

                if(fp == NULL) {

                    printf("File cannot be opened\n");
                }

                else {

                    fwrite(&students[n], sizeof(struct student), 1, fp);

                    fclose(fp);

                    printf("\nStudent data saved successfully\n");
                }

                n++;

                break;
            }

            

            case 2:

                if(n == 0) {

                    printf("\nNo student found\n");
                }

                else {

                    for(int i = 0; i < n; i++) {

                        printf("\n===== Student %d =====\n", i + 1);

                        printf("Name: %s\n", students[i].name);

                        printf("Roll: %d\n", students[i].roll);

                        for(int j = 0; j < 3; j++) {

                            printf("Subject %d Mark = %.2lf\n",
                                   j + 1,
                                   students[i].marks[j]);
                        }

                        printf("Average = %.2f\n",
                               students[i].average);
                    }
                }

                break;

            

            case 3:

                printf("\nEnter roll number: ");

                scanf("%d", &searchRoll);

                found = 0;

                for(int i = 0; i < n; i++) {

                    if(students[i].roll == searchRoll) {

                        printf("\nStudent Found\n");

                        printf("Name: %s\n", students[i].name);

                        printf("Roll: %d\n", students[i].roll);

                        for(int j = 0; j < 3; j++) {

                            printf("Subject %d Mark = %.2lf\n",
                                   j + 1,
                                   students[i].marks[j]);
                        }

                        printf("Average = %.2f\n",
                               students[i].average);

                        found = 1;

                        break;
                    }
                }

                if(found == 0) {

                    printf("\nStudent not found\n");
                }

                break;

           

            case 4:

                printf("\nProgram closed\n");

                break;

            default:

                printf("\nWrong choice\n");
        }
    }

    return 0;
}