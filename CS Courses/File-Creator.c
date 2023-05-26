#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 100
#define MAX_NAME_LENGTH 100

int main() {
    char courseNames[MAX_COURSES][MAX_NAME_LENGTH] = {
        // semester 1
        "BA003-Math-0",
        "BA101-Calculus-1",
        "BA113-Physics",
        "CS111-Introduction-to-Computers",
        "IS171-Introduction-to-Information-systems",
        "LH135-English-for-Specific-Purposes-I(ESP-I)",
        "NC172-Fundamentals-of-Business",
        // semester 2
        "BA102-Calculus-2",
        "CS143-Introduction-to-Problem-Solving-and-Programming",
        "EC134-Fundamentals-of-Electronics",
        "LH136-English-for-Specific-Purposes-II(ESP-II)",
        "NC133-Communication-Skills",
        // semester 3
        "BA201-Calculus-III",
        "BA203-Probability-and-Statistics",
        "BA216-Advanced-Physics",
        "CE216-Digital-Logic-Design",
        "CS202-Discrete-Structures",
        "CS243-Object-Oriented-Programming",
        // semester 4
        "Introduction-to-Networks",
        "CE243-Intro.-to-Computer-Architecture",
        "CS212-Data-Structures-and-Algorithms",
        "CS24-Advanced-Programming-Applications",
        "IS273-Database-Systems",
        "IT291-Professional-Training-in-Entrepreneurship",
        "SE291-Introduction-to-Software-Engineering",
        // semester 5
        "BA301-Advanced-Statistics",
        "BA304-Linear-Algebra",
        "CS311-Theory-of-Computation",
        "CS321-Systems-Programming",
        "CS333-Web-Programming",
        "CS352-Computer-Graphics",
        "IT321-Professional-Training-in-Programming-I(.Net-1)",
        // semester 6
        "CS301-Numerical-Methods",
        "CS305-System-Modeling-and-Simulation",
        "CS312-Computing-Algorithms",
        "CS322-Operating-Systems",
        "CS366Introduction-to-Artificial-Intelligence",
        // minor semester 6
        "IS467-Big-Data-Analytics",
        "IT371-Professional-Training-in-Databases-1",
        // semester 7
        "CS401-Project-1",
        "CS445-Structure-of-Programming-Languages",
        "CS481-Computers-&-Society",
        // minor semester 7
        "CS428-Cloud-Computing",
        "CS441-Compilers",
        "SE496-Software-Engineering-Process",
        "IT411-Professional-Training-in-Software-Testing-2",
        // semester 8
        "CS402-Project-2",
        "CS421-Computer-System-Security",
        "CS451-Human-Computer-Interaction",
        // minor semester 8
        "CS432-Network-Protocols-&-Programming",
        "CS460_Deep-Learning",
        "SE496-Software-Engineering-Process",
        "IT412-Professional-Training-in-Software-Testing-3"
    };

    int i;

    // Create binary files for each course
    for (i = 0; i < MAX_COURSES; i++) {
        char fileName[MAX_NAME_LENGTH];
        sprintf(fileName, "%s.bin", courseNames[i]);
        
        FILE* file = fopen(fileName, "wb");
        if (file == NULL) {
            printf("Failed to create file for course: %s\n", courseNames[i]);
            return 1;
        }
        fclose(file);
    }

    printf("Binary files created successfully!\n");
    return 0;
}
