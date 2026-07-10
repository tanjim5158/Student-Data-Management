#include <stdio.h>

struct student {
    int roll;
    int batch;
    char section;
    char name[50];
    double marks[3];

    float cg;
};

int main() {

    FILE *fp;

    struct student students[100];

    int n = 0;
    int choice = 0;
    int batchsearch;
    char sectionsearch;
    int searchRoll;
    int found;
    float cgp;


    fp = fopen("students.txt", "rb");

    if (fp != NULL) {

        while (fread(&students[n], sizeof(struct student), 1, fp)) {
            n++;
        }

        fclose(fp);
    }

    while (choice != 6) {

        printf("\n===== STUDENT PORTAL =====\n");
        printf("1. Enter student details\n");
        printf("2. Show all students\n");
        printf("3. Search by Batch\n");
        printf("4. Search by Section\n");
        printf("5. Search by Roll\n");
        printf("6. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: {

            float sum = 0;

            printf("\nEnter Batch: ");
            scanf("%d", &students[n].batch);

            printf("Enter Section: ");
            scanf(" %c", &students[n].section);

            printf("Enter student name: ");
            scanf(" %[^\n]", students[n].name);

            printf("Enter roll: ");
            scanf("%d", &students[n].roll);

            for (int i = 0; i < 3; i++) {

                printf("Enter mark of subject %d: ", i + 1);
                scanf("%lf", &students[n].marks[i]);
                if (students[n].marks[i] >= 80)
                    cgp = 4.00;
                else if (students[n].marks[i] >= 75 && students[n].marks[i]<80)
                    cgp = 3.75;
                else if (students[n].marks[i] >= 70 && students[n].marks[i]<75)
                    cgp = 3.50;
                else if (students[n].marks[i] >= 65 && students[n].marks[i] < 70)
                    cgp = 3.25;
                else if (students[n].marks[i] >= 60 && students[n].marks[i] < 65)
                    cgp = 3.00;
                else if (students[n].marks[i] >= 50 && students[n].marks[i]< 60)
                    cgp = 2.75;
                else
                    cgp = 0.00;

                sum += cgp;
            }

            students[n].cg= sum / 3;



            fp = fopen("students.txt", "ab");

            if (fp == NULL) {

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

            if (n == 0) {

                printf("\nNo student found\n");
            }
            else {

                for (int i = 0; i < n; i++) {

                    printf("\n===== Student %d =====\n", i + 1);

                    printf("Batch:   %d\n", students[i].batch);
                    printf("Section: %c\n", students[i].section);
                    printf("Name:    %s\n", students[i].name);
                    printf("Roll:    %d\n", students[i].roll);

                    for (int j = 0; j < 3; j++) {

                        printf("Subject %d Mark = %.2lf\n",
                               j + 1,
                               students[i].marks[j]);
                    }


                    printf("CGPA:    %.2f\n", students[i].cg);
                }
            }

            break;

        case 3:

            if (n == 0) {

                printf("\nNo student found\n");
            }
            else {

                printf("\nEnter Batch number: ");
                scanf("%d", &batchsearch);

                found = 0;

                for (int i = 0; i < n; i++) {

                    if (students[i].batch == batchsearch) {

                        printf("\nStudent Found\n");

                        printf("Batch:   %d\n", students[i].batch);
                        printf("Section: %c\n", students[i].section);
                        printf("Name:    %s\n", students[i].name);
                        printf("Roll:    %d\n", students[i].roll);

                        for (int j = 0; j < 3; j++) {

                            printf("Subject %d Mark = %.2lf\n",
                                   j + 1,
                                   students[i].marks[j]);
                        }


                        printf("CGPA:    %.2f\n", students[i].cg);

                        found = 1;
                    }
                }

                if (found == 0) {

                    printf("\nStudent not found\n");
                }
            }

            break;

        case 4:

            if (n == 0) {

                printf("\nNo student found\n");
            }
            else {

                printf("\nEnter Section: ");
                scanf(" %c", &sectionsearch);
                printf("\nEnter Batch: ");
                scanf("%d",&batchsearch);

                found = 0;

                for (int i = 0; i < n; i++) {

                    if (students[i].section == sectionsearch && students[i].batch == batchsearch) {

                        printf("\nBatch: %d\n", students[i].batch);
                        printf("Section: %c\n", students[i].section);
                        printf("Name:    %s\n", students[i].name);
                        printf("Roll:    %d\n", students[i].roll);

                        for (int j = 0; j < 3; j++) {

                            printf("Subject %d Mark = %.2lf\n",
                                   j + 1,
                                   students[i].marks[j]);
                        }


                        printf("CGPA: %.2f\n", students[i].cg);

                        found = 1;
                    }
                }

                if (found == 0) {

                    printf("\nStudent not found\n");
                }
            }

            break;

        case 5:

            if (n == 0) {

                printf("\nNo student found\n");
            }
            else {

                printf("\nEnter Roll Number: ");
                scanf("%d", &searchRoll);
                printf("\nEnter Batch: ");
                scanf("%d",&batchsearch);

                found = 0;

                for (int i = 0; i < n; i++) {

                    if (students[i].roll == searchRoll && students[i].batch == batchsearch) {

                        printf("\nBatch: %d\n", students[i].batch);
                        printf("Section: %c\n", students[i].section);
                        printf("Name:    %s\n", students[i].name);
                        printf("Roll:    %d\n", students[i].roll);

                        for (int j = 0; j < 3; j++) {

                            printf("Subject %d Mark = %.2lf\n",
                                   j + 1,
                                   students[i].marks[j]);
                        }


                        printf("CGPA: %.2f\n", students[i].cg);

                        found = 1;
                    }
                }

                if (found == 0) {

                    printf("\nStudent not found\n");
                }
            }

            break;

        case 6:

            printf("\nProgram End\n");
            break;

        default:

            printf("\nWrong choice\n");
        }
    }

    return 0;
}
