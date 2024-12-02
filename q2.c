#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char* name; // Dynamically allocated string
    int salary;
};

void swap(struct employee* x, struct employee* y) {
    struct employee temp = *x;
    *x = *y;
    *y = temp;
}

void sort(struct employee Employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Employees[j].salary > Employees[j + 1].salary) {
                swap(&Employees[j], &Employees[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee* Employees;
    Employees = (struct employee*)malloc(n * sizeof(struct employee));
    if (Employees == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &Employees[i].id);

        getchar(); // Consume leftover newline from the previous input
        printf("Name: ");
        Employees[i].name = (char*)malloc(50 * sizeof(char)); // Allocate memory for name
        if (Employees[i].name == NULL) {
            printf("Memory allocation for name failed\n");
            return 1;
        }
        fgets(Employees[i].name, 50, stdin);
        strtok(Employees[i].name, "\n"); // Remove trailing newline character

        printf("Salary: ");
        scanf("%d", &Employees[i].salary);
    }

    sort(Employees, n);

    printf("Employees details sorted by salary:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %d\n", Employees[i].id, Employees[i].name, Employees[i].salary);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(Employees[i].name); // Free each name
    }
    free(Employees); // Free the array of employees

    return 0;
}
