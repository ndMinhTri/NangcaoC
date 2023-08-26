#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[25];
    char gender[10];
    unsigned short yearsofbirth;
} Student;

void DeleteNewLine(char x[]) {
    size_t len = strlen(x);
    if (len > 0 && x[len - 1] == '\n') {
        x[len - 1] = '\0';
    }
}

void enter_student_info(Student *SV) {
    printf("ID: ");
    scanf("%d", &SV->id);
    printf("Years of birth: ");
    scanf("%d", &SV->yearsofbirth);
    printf("Student name: ");
    getchar(); // Clear the newline character left in the buffer
    fgets(SV->name, sizeof(SV->name), stdin);
    DeleteNewLine(SV->name);
    printf("Gender: ");
    fgets(SV->gender, sizeof(SV->gender), stdin);
    DeleteNewLine(SV->gender);
}

void enter_student_list(Student *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Info of student %d:\n", i + 1);
        enter_student_info(a + i);
    }
}

void display_student_info(Student *SV) {
    printf("%10d \t %25s \t %10s \t %10d\n", SV->id, SV->name, SV->gender, SV->yearsofbirth);
}

void display_student_list(Student *a, int n) {
    printf("%10s \t %25s \t %10s \t %10s\n", "ID", "Name", "Gender", "Year of birth");
    for (int i = 0; i < n; i++) {
        display_student_info(a + i);
    }
}

int compare_names(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int main() {
    int n;
    do {
        printf("Enter the number of students: ");
        scanf("%d", &n);
    } while (n <= 0);

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    enter_student_list(students, n);
    display_student_list(students, n);

    FILE *file = fopen("student.csv", "w");
    if (file == NULL) {
        printf("Error opening file to write.\n");
        free(students);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d,%s,%s,%d\n", students[i].id, students[i].name, students[i].gender, students[i].yearsofbirth);
    }
    fclose(file);

    // Sort students by name
    qsort(students, n, sizeof(Student), compare_names);

    printf("\nSorted list by student name:\n");
    display_student_list(students, n);

    // Count and display name statistics
    printf("\nName statistics:\n");
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(students[i].name, students[i -1 ].name) == 0) {
            count++;
        } else {
            printf("%s xuat hien %d lan\n", students[i-1].name, count);
            count = 1;
        }
    }
    printf("%s xuat hien %d lan\n", students[n - 1].name, count);

    // Clean up
    free(students);

    return 0;
}