#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
typedef struct
{
    char course[50];
    char name[50];
} Course;
// Struct definition for student information
typedef struct
{
    int ID;
    char name[MAX_NAME_LENGTH];
    char College[100];
    int Period;
    char Department[100];
    float Credits;
    float GPA;
    char FF;
    int PIN;

} Student;
typedef struct
{
    int ID;
    char name[MAX_NAME_LENGTH];
    int seven;
    int twelve;
    int final;
    int total;
    char Status[100];
} Reg_Student;
Reg_Student student2 = {221008756, "Kareem Mohamed Yousef", 29,28, 36,93,"Passed"};
// Function to store student information in a binary file
// Function to store student information in a binary file
void save_Student_Info(Student student)
{
    FILE *file = fopen("student_data.bin", "ab+");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Student temp;
    int duplicate = 0;

    // Check for duplicate students
    while (fread(&temp, sizeof(Student), 1, file) == 1)
    {
        if (temp.ID == student.ID)
        {
            duplicate = 1;
            break;
        }
    }

    if (duplicate)
    {
        printf("Student with Roll Number %d already exists. Not added.\n", student.ID);
    }
    else
    {
        fwrite(&student, sizeof(Student), 1, file);
        printf("Student added successfully.\n");
    }

    fclose(file);
}
char *Get_Name(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char *name = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            name = strdup(student.name);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return name;
}
char *Get_College(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char *College = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            College = strdup(student.College);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return College;
}
// Function to retrieve GPA by student
int Get_Period(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    int Period = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            Period = student.Period;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return Period;
}
char *Get_Department(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char *Department = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            Department = strdup(student.Department);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return Department;
}
float Get_Credits(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    float Credits = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            Credits = student.Credits;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return Credits;
}
float Get_GPA(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    float GPA = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            GPA = student.GPA;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return GPA;
}
char *Get_FF(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char *FF = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            FF = strdup(student.FF);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return FF;
}
int Get_PIN(int id)
{
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    int PIN = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        if (student.ID == id)
        {
            PIN = student.PIN;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return PIN;
}
void add_Student_To_Course(const char *courseName, Reg_Student student)
{
    char fileName[MAX_NAME_LENGTH];
    sprintf(fileName, "%s.bin", courseName);

    FILE *file = fopen(fileName, "ab");
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    fwrite(&student, sizeof(Reg_Student), 1, file);

    fclose(file);
}
void printStudentInfo(int id)

{
    printf("PIN is correct\n");

    char *name = Get_Name(id);
    if (name != NULL)
    {
        printf("Name: %s\n", name);
    }

    char *College = Get_College(id);
    if (College != NULL)
    {
        printf("College: %s\n", College);
    }

    int Period = Get_Period(id);
    if (Period != -1)
    {
        printf("Period: %d\n", Period);
    }

    char *Department = Get_Department(id);
    if (Department != NULL)
    {
        printf("Department: %s\n", Department);
    }

    float Credits = Get_Credits(id);
    if (Credits != -1)
    {
        printf("Credits: %.2f\n", Credits);
    }

    float gpa = Get_GPA(id);
    if (gpa != -1)
    {
        printf("GPA: %.2f\n", gpa);
    }

    char *FF = Get_FF(id);
    if (FF != NULL)
    {
        printf("FF: %s\n", FF);
    }

    int PIN = Get_PIN(id);
    if (PIN != -1)
    {
        printf("PIN: %d\n", PIN);
    }
}
char *Get_Status_of(const char *courseName, int studentID)
{
    char fileName[MAX_NAME_LENGTH];
    sprintf(fileName, "CS Courses\\%s.bin", courseName);

    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", fileName);
        return NULL;
    }

    Reg_Student student;
    while (fread(&student, sizeof(Reg_Student), 1, file) == 1)
    {
        if (student.ID == studentID)
        {
            fclose(file);
            return strdup(student.Status);
        }
    }

    fclose(file);
    return NULL;
}
void registerCourses(int sem, const int id)
{
    int com;

    if (sem == 2)
    {
        com = strcmp(Get_Status_of("BA101-Calculus-1", id), "Passed");
        if (com == 1)
        {
            printf("1-BA102-Calculus-2\n");
        }
        com = strcmp(Get_Status_of("CS111-Introduction-to-Computers", id), "Passed");
        if (com == 1)
        {
            printf("2-CS143-Introduction to problem solving and programming\n");
        }
        com = strcmp(Get_Status_of("BA113-Physics", id), "Passed");
        if (com == 1)
        {
            printf("3-EC134-Fundamentals of Electronics\n");
        }
        com = strcmp(Get_Status_of("LH135-English-for-Specific-Purposes-I(ESP-I)", id), "Passed");
        if (com == 1)
        {
            printf("4-LH136-English for Specific Purposes II(ESP II)\n");
        }
        com = strcmp(Get_Status_of("BA102-Calculus-2", id), "Passed");
        if (strcmp(Get_Status_of("LH135-English-for-Specific-Purposes-I(ESP-I)", id), "Passed"))
        {
            printf("5-NC133-Communication Skills\n");
        }
    }
    else if (sem == 3)
    {
        com = strcmp(Get_Status_of("BA102-Calculus-2", id), "Passed");
        if (com == 1)
        {
            printf("1-BA201-Calculus-III\n2-BA203-Probability-and-Statistics\n");
        }
        com = strcmp(Get_Status_of("BA113-Physics", id), "Passed");
        if (com == 1)
        {
            printf("3-BA216-Advanced-Physics\n");
        }
        com = strcmp(Get_Status_of("CS111-Introduction-to-Computers", id), "Passed");
        if (com == 1)
        {
            printf("4-CE216-Digital Logic Design\n5-CS202-Discrete Structures\n");
        }
        com = strcmp(Get_Status_of("CS143-Introduction-to-Problem-Solving-and-Programming", id), "Passed");
        if (com == 1)
        {
            printf("6-CS243-Object Oriented Programming\n");
        }
    }
    else if (sem == 4)
    {
        com = strcmp(Get_Status_of("CS143-Introduction-to-Problem-Solving-and-Programming", id), "Passed");
        if (com == 1)
        {
            printf("1-Introduction to Networks\n2-Database Systems\n");
        }
        com = strcmp(Get_Status_of("CE216-Digital-Logic-Design", id), "Passed");
        if (com == 1)
        {
            printf("3-CE243-Intro. to Computer Architecture\n");
        }
        com = strcmp(Get_Status_of("CS243-Object-Oriented-Programming", id), "Passed");
        if (com == 1)
        {
            printf("4-CS212-Data Structures and Algorithms\n5-CS24-Advanced Programming Applications\n");
        }
        com = strcmp(Get_Status_of("IS171-Introduction-to-Information-systems", id), "Passed");
        if (com == 1)
        {
            printf("6-SE291-Introduction to Software Engineering\n");
        }
        printf("7-IT291-Professional Training in Entrepreneurship\n");
    }
    else if (sem == 5)
    {
        com = strcmp(Get_Status_of("BA203-Probability-and-Statistics", id), "Passed");
        if (com == 1)
        {
            printf("1-BA301-Advanced Statistics\n");
        }
        com = strcmp(Get_Status_of("BA102-Calculus-2", id), "Passed");
        if (com == 1)
        {
            printf("2-BA304-Linear Algebra\n");
        }
        com = strcmp(Get_Status_of("CS202-Discrete-Structures", id), "Passed");
        if (com == 1)
        {
            printf("3-CS311-Theory of Computation\n");
        }
        com = strcmp(Get_Status_of("CE243-Intro.-to-Computer-Architecture", id), "Passed");
        com += strcmp(Get_Status_of("CS243-Object-Oriented-Programming", id), "Passed");
        if (com == 2)
        {
            printf("4-CS321-Systems Programming\n");
        }
        com = strcmp(Get_Status_of("IS273-Database-Systems", id), "Passed");
        if (com == 1)
        {
            printf("5-CS333-Web Programming\n");
        }
        com = strcmp(Get_Status_of("CS212-Data-Structures-and-Algorithms", id), "Passed");
        if (com == 1)
        {
            printf("6-CS352-Computer Graphics\n");
        }
        printf("7-IT321-Professional Training in Programming I (.Net 1)\n");
    }

    int num;
    printf("Enter the number of courses you want to register: \n");
    scanf("%d", &num);
    Course *courses = (Course *)malloc(num * sizeof(Course));
    for (int i = 0; i < num; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", courses[i].name);
        printf("Enter the name of course %d: ", i + 1);
        scanf("%s", courses[i].course);
    }
    printf("\nRecorded courses:\n");
    for (int i = 0; i < num; i++)
    {
        printf("Student %d: %s\n", i + 1, courses[i].name);
        printf("Course %d: %s\n\n", i + 1, courses[i].course);
    }

    free(courses); // Free dynamically allocated memory
}

Reg_Student student1 = {221008756, "Kareem Mohamed Yousef Ahmed", 29, 28, 36, 93, "Passed"};
int main()
{
    // Student student1 = {221008802, "Abdelrahman Mohammed Hussain","College of Computing and Information Technology", 2, "Computer Science South Valley",15,3.4, 'A',253856};
    // Student student2 = {221008720,"Zeyad hamdy Abdo Hussien","College of Computing and Information Technology",2,"Computer Science South Valley",15,2.5,'C',549784};
    // Student student3 = {221018151,"Mohamed Elhussein Mohamed Gad","College of Computing and Information Technology",2,"Computer Science South Valley",15,2.7,'A',956483};
    // Student student4 = {221008756,"Kareem Mohamed Youssef Ahmed","College of Computing and Information Technology",2,"Computer Science South Valley",15,3.3,'A',214365};
    // Student student5 = {221008565,"Martin Maged Fouad Gerges","College of Computing and Information Technology",2,"Computer Science South Valley",15,3.2,'A',759427};
    // add_Student_To_Course("CS143-Introduction-to-Problem-Solving-and-Programming", student1);
    // saveStudentInfo(student1);
    // saveStudentInfo(student2);
    // saveStudentInfo(student3);
    // saveStudentInfo(student4);
    // saveStudentInfo(student5);

    int id, PIN, sem, num,com;
    float gpa;
    printf("Enter the ID of the student: \n");
    scanf("%d", &id);
    l: printf("Enter PIN: \n");
    scanf("%d", &PIN);
    // int temp_PIN = Get_PIN(id);
    if (Get_PIN(id) == PIN)
    {
        printStudentInfo(id);
    }
    else{
        printf("PIN is incorrect\n");
        goto l;
    }
    sem = Get_Period(id) + 1;
    printf("Current Semester: %d\n", sem);
    gpa = Get_GPA(id);
    printf("GPA: %.2f\n", gpa);
    if (gpa >= 2.00)
    {
        printf("You can register max. 7 courses\n");
    }
    else
    {
        printf("You can register max. 4 courses\n");
    }
    registerCourses(sem, id);
    return 0;
            }
// printf("Enter the number of courses you want to register: \n");
// int num;
// scanf("%d", &num);
// int arr[num];
// for (int i = 0; i < num; i++)
// {
//     printf("Enter the number of the course you want to register: \n");
//     scanf("%d", &arr[i]);
// }