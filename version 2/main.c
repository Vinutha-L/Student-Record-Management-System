#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int usn;
    char name[50];
    int age;
    char branch[50];
    int semester;
};

int studentCount = 0;
int capacity = 2;
struct Student *students;
FILE *fp;

void addStudent();
void displayStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveStudentsToFile();
void readString(char str[], int size);

int main()
{
    int ch;

    students = malloc(capacity * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("----Student Record Management System----\n");

    fp = fopen("students.dat", "rb");

    if (fp != NULL)
    {
        struct Student temp;

        while (fread(&temp, sizeof(struct Student), 1, fp) == 1)
        {
            if (studentCount == capacity)
            {
                capacity *= 2;

                students = realloc(students,
                                   capacity * sizeof(struct Student));

                if (students == NULL)
                {
                    printf("Memory reallocation failed.\n");
                    fclose(fp);
                    return 1;
                }
            }

            students[studentCount] = temp;
            studentCount++;
        }

        fclose(fp);
    }

    do
    {
        printf("\n1.Add student\n");
        printf("2.Display students\n");
        printf("3.Search student\n");
        printf("4.Update student\n");
        printf("5.Delete student\n");
        printf("6.Exit\n");

        printf("Enter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudent();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Select valid choice:\n");
            break;
        }

    } while (ch != 6);

    free(students);

    return 0;
}

void readString(char str[], int size)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    fgets(str, size, stdin);

    str[strcspn(str, "\n")] = '\0';
}

void saveStudentsToFile()
{
    fp = fopen("students.dat", "wb");

    if (fp != NULL)
    {
        fwrite(students, sizeof(struct Student), studentCount, fp);
        fclose(fp);
    }
    else
    {
        printf("Unable to save student records.\n");
    }
}

void addStudent()
{
    int usn;
    int duplicate = 0;

    if (studentCount == capacity)
    {
        capacity *= 2;

        students = realloc(students,
                           capacity * sizeof(struct Student));

        if (students == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }

    printf("Enter student's USN:\n");
    scanf("%d", &usn);

    for (int i = 0; i < studentCount; i++)
    {
        if (usn == students[i].usn)
        {
            duplicate = 1;
            break;
        }
    }

    if (duplicate)
    {
        printf("USN already exists. Student not added.\n");
        return;
    }

    students[studentCount].usn = usn;

    printf("Enter student's NAME:\n");
    readString(students[studentCount].name,
               sizeof(students[studentCount].name));

    printf("Enter student's AGE:\n");
    scanf("%d", &students[studentCount].age);

    printf("Enter student's BRANCH:\n");
    readString(students[studentCount].branch,
               sizeof(students[studentCount].branch));

    printf("Enter student's current SEMESTER:\n");
    scanf("%d", &students[studentCount].semester);

    studentCount++;

    saveStudentsToFile();

    printf("Student added successfully.\n");
}

void displayStudent()
{
    if (studentCount == 0)
    {
        printf("No student records found.\n");
    }
    else
    {
        printf("Number of students=%d\n", studentCount);

        for (int i = 0; i < studentCount; i++)
        {
            printf("\nStudent %d:-\n", i + 1);
            printf("USN:%d\n", students[i].usn);
            printf("NAME:%s\n", students[i].name);
            printf("Age:%d\n", students[i].age);
            printf("BRANCH:%s\n", students[i].branch);
            printf("SEMESTER:%d\n", students[i].semester);
        }
    }
}

void searchStudent()
{
    int usn;
    int found = 0;

    printf("Enter usn to search:");
    scanf("%d", &usn);

    for (int i = 0; i < studentCount; i++)
    {
        if (usn == students[i].usn)
        {
            printf("Student Found.\n");
            printf("Student Name:%s\n", students[i].name);
            printf("Student's Age:%d\n", students[i].age);
            printf("Student's Branch:%s\n", students[i].branch);
            printf("Student's Current semester:%d\n",
                   students[i].semester);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Student not found!!\n");
    }
}

void updateStudent()
{
    int n, ch;
    int found = 0;

    printf("Enter USN:");
    scanf("%d", &n);

    for (int i = 0; i < studentCount; i++)
    {
        if (n == students[i].usn)
        {
            found = 1;

            printf("Student Found.\n");

            do
            {
                printf("\n---Select the detail that needs to be updated---\n");
                printf("1.NAME\n");
                printf("2.USN\n");
                printf("3.AGE\n");
                printf("4.BRANCH\n");
                printf("5.SEMESTER\n");

                printf("Enter your choice:");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("Enter new NAME:");
                    readString(students[i].name,
                               sizeof(students[i].name));
                    printf("Updated successfully.\n");
                    break;

                case 2:
                {
                    int newUSN;
                    int duplicate = 0;

                    printf("Enter new USN:");
                    scanf("%d", &newUSN);

                    for (int j = 0; j < studentCount; j++)
                    {
                        if (j != i && students[j].usn == newUSN)
                        {
                            duplicate = 1;
                            break;
                        }
                    }

                    if (duplicate)
                    {
                        printf("USN already exists. USN not updated.\n");
                    }
                    else
                    {
                        students[i].usn = newUSN;
                        printf("Updated successfully.\n");
                    }

                    break;
                }

                case 3:
                    printf("Enter new AGE:");
                    scanf("%d", &students[i].age);
                    printf("Updated successfully.\n");
                    break;

                case 4:
                    printf("Enter new BRANCH:");
                    readString(students[i].branch,
                               sizeof(students[i].branch));
                    printf("Updated successfully.\n");
                    break;

                case 5:
                    printf("Enter new SEMESTER:");
                    scanf("%d", &students[i].semester);
                    printf("Updated successfully.\n");
                    break;

                default:
                    printf("Enter a valid choice!!\n");
                    break;
                }

            } while (ch < 1 || ch > 5);

            saveStudentsToFile();
            break;
        }
    }

    if (found == 0)
    {
        printf("Student not Found!!\n");
    }
}

void deleteStudent()
{
    int usn;
    int found = 0;

    printf("Enter usn to be deleted:");
    scanf("%d", &usn);

    for (int i = 0; i < studentCount; i++)
    {
        if (usn == students[i].usn)
        {
            found = 1;

            printf("Student Found.\n");

            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;

            saveStudentsToFile();

            printf("Student deleted successfully.\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("Student Not found.\n");
    }
}