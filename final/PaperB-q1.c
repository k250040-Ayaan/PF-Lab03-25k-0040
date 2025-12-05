#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MARKS 5
#define NAME_LEN 50

/* -------------------- Student structure -------------------- */
typedef struct
{
    char name[NAME_LEN];
    int marks[MARKS]; // 5 subject marks
} Student;

/* 1. getAverageMark
   Takes a Student, adds 5 marks, finds average and returns it. */
float getAverageMark(Student s)
{
    int sum = 0;
    int i;

    for (i = 0; i < MARKS; i++)
        sum += s.marks[i];

    return (float)sum / MARKS;
}

/* 2. findHighestMark
   Recursive function to find highest of 5 marks. */
int findHighestMarkHelper(int marks[], int index, int total)
{
    if (index == total - 1) // last element
        return marks[index];

    int maxOfRest = findHighestMarkHelper(marks, index + 1, total);

    if (marks[index] > maxOfRest)
        return marks[index];
    else
        return maxOfRest;
}

int findHighestMark(Student s)
{
    return findHighestMarkHelper(s.marks, 0, MARKS);
}

/* 3. applyBonusMarks
   Takes Student pointer and bonus number and adds bonus
   to each of the 5 marks. */
void applyBonusMarks(Student *s, int bonus)
{
    int i;
    for (i = 0; i < MARKS; i++)
        s->marks[i] += bonus;
}

/* 4. compareTwoStudents
   Returns:
     1  if first student's average is higher
    -1  if lower
     0  if equal */
int compareTwoStudents(Student s1, Student s2)
{
    float avg1 = getAverageMark(s1);
    float avg2 = getAverageMark(s2);

    if (avg1 > avg2)
        return 1;
    else if (avg1 < avg2)
        return -1;
    else
        return 0;
}

/* 5. setupClass
   Creates an array of 10 Students in memory and
   returns the address of the first Student. */
Student *setupClass()
{
    // allocate memory for 10 Students
    Student *classPtr = (Student *)malloc(10 * sizeof(Student));

    // (optional) set initial values
    int i, j;
    for (i = 0; i < 10; i++)
    {
        strcpy(classPtr[i].name, "Unknown");
        for (j = 0; j < MARKS; j++)
            classPtr[i].marks[j] = 0;
    }
    return classPtr; // address of first Student
}

/* ---------------- Simple main to test (not required in exam) --------- */
int main()
{
    Student s1 = {"Ali", {80, 75, 90, 85, 70}};
    Student s2 = {"Sara", {60, 65, 70, 75, 80}};

    printf("Average of %s = %.2f\n", s1.name, getAverageMark(s1));
    printf("Highest mark of %s = %d\n", s1.name, findHighestMark(s1));

    applyBonusMarks(&s1, 5);
    printf("After bonus, new average of %s = %.2f\n",
           s1.name, getAverageMark(s1));

    int cmp = compareTwoStudents(s1, s2);
    printf("Compare result = %d\n", cmp);

    Student *class10 = setupClass();
    printf("First student in class10 name = %s\n", class10[0].name);

    free(class10); // free memory
    return 0;
}
