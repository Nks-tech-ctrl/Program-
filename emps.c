#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMP 50
#define NAME_SZ 100
#define DEPT_SZ 100
#define LINE_SZ 512
#define DATA_FILE "employees.txt"

struct Employee
{
    int id;
    int age;
    char name[NAME_SZ];
    char department[DEPT_SZ];
    float salary;
};

void read_line(char *buf, size_t n)
{
    if (fgets(buf, (int)n, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
}

void print_table(struct Employee emp[], int count)
{
    if (count == 0)
    {
        printf("\nNo data available.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-5s %-12s %-20s\n", "ID", "Name", "Age", "Salary", "Department");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-5d %-12.2f %-20s\n",
               emp[i].id,
               emp[i].name,
               emp[i].age,
               emp[i].salary,
               emp[i].department);
    }

    printf("------------------------------------------------------------------------------\n");
}

int load_from_file(struct Employee emp[], int max)
{
    FILE *fp = fopen(DATA_FILE, "r");
    if (!fp) return 0;

    char line[LINE_SZ];
    if (!fgets(line, sizeof(line), fp)) { fclose(fp); return 0; }

    int count = atoi(line);
    if (count < 0 || count > max) { fclose(fp); return 0; }

    int i = 0;
    while (i < count && fgets(line, sizeof(line), fp))
    {
        char name_buf[NAME_SZ] = "";
        char dept_buf[DEPT_SZ] = "";
        int id, age;
        float salary;

        if (sscanf(line, "%d|%99[^|]|%d|%f|%99[^\n]",
                   &id, name_buf, &age, &salary, dept_buf) == 5)
        {
            emp[i].id = id;
            strncpy(emp[i].name, name_buf, NAME_SZ - 1);
            emp[i].name[NAME_SZ - 1] = '\0';
            emp[i].age = age;
            emp[i].salary = salary;
            strncpy(emp[i].department, dept_buf, DEPT_SZ - 1);
            emp[i].department[DEPT_SZ - 1] = '\0';
            i++;
        }
        else break;
    }

    fclose(fp);
    return i;
}

int save_to_file(struct Employee emp[], int count)
{
    FILE *fp = fopen(DATA_FILE, "w");
    if (!fp) return 1;

    fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%d|%.2f|%s\n",
                emp[i].id,
                emp[i].name,
                emp[i].age,
                emp[i].salary,
                emp[i].department);
    }

    fclose(fp);
    return 0;
}

void flush_stdin(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main()
{
    struct Employee emp[MAX_EMP];
    int count = 0;
    int choice;
    int mainChoice;

    count = load_from_file(emp, MAX_EMP);

    while (1)
    {
        printf("\n*EMPLOYEE MANAGEMENT SYSTEM*\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &mainChoice) != 1) {
            flush_stdin();
            printf("Invalid input.\n");
            continue;
        }
        flush_stdin();

        if (mainChoice == 1)
        {
            char password[64];
            printf("Enter admin password: ");
            read_line(password, sizeof(password));

            if (strcmp(password, "admin123") != 0)
            {
                printf("Wrong password.\n");
                continue;
            }

            while (1)
            {
                printf("\n--- ADMIN MENU ---\n");
                printf("1-Add Employee details\n");
                printf("2-Display all Employee details\n");
                printf("3-Update Employee Salary\n");
                printf("4-Back to main menu\n");
                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1) {
                    flush_stdin();
                    printf("Invalid input.\n");
                    continue;
                }
                flush_stdin();

                switch (choice)
                {
                case 1:
                    if (count < MAX_EMP)
                    {
                        printf("Enter Employee ID: ");
                        if (scanf("%d", &emp[count].id) != 1) { flush_stdin(); printf("Invalid id.\n"); break; }
                        flush_stdin();

                        printf("Enter Employee Name (can include spaces): ");
                        read_line(emp[count].name, NAME_SZ);

                        printf("Enter Employee Age: ");
                        if (scanf("%d", &emp[count].age) != 1) { flush_stdin(); printf("Invalid age.\n"); break; }
                        flush_stdin();

                        printf("Enter Employee Salary(in Rs): ");
                        if (scanf("%f", &emp[count].salary) != 1) { flush_stdin(); printf("Invalid salary.\n"); break; }
                        flush_stdin();

                        printf("Enter Employee Department (can include spaces): ");
                        read_line(emp[count].department, DEPT_SZ);

                        count++;
                        if (save_to_file(emp, count) == 0)
                            printf("Employee added and saved.\n");
                        else
                            printf("Employee added but failed to save to file.\n");
                    }
                    else
                    {
                        printf("Limit reached\n");
                    }
                    break;

                case 2:
                    print_table(emp, count);
                    break;

                case 3:
                    if (count == 0)
                    {
                        printf("No data available to update\n");
                    }
                    else
                    {
                        int searchId, found = 0;
                        printf("Enter Employee id to update salary: ");
                        if (scanf("%d", &searchId) != 1) { flush_stdin(); printf("Invalid id.\n"); break; }
                        flush_stdin();

                        for (int i = 0; i < count; i++)
                        {
                            if (emp[i].id == searchId)
                            {
                                printf("Enter New Salary: ");
                                if (scanf("%f", &emp[i].salary) != 1) { flush_stdin(); printf("Invalid salary.\n"); break; }
                                flush_stdin();
                                if (save_to_file(emp, count) == 0)
                                    printf("Salary Updated and saved!\n");
                                else
                                    printf("Salary Updated but failed to save to file.\n");
                                found = 1;
                                break;
                            }
                        }
                        if (!found) printf("No data found.\n");
                    }
                    break;

                case 4:
                    goto MAIN_MENU;

                default:
                    printf("Invalid choice!\n");
                    break;
                }
            }
        }
        else if (mainChoice == 2)
        {
            while (1)
            {
                printf("\n--- USER MENU ---\n");
                printf("1. Display all Employee details\n");
                printf("2. Search Employee by ID\n");
                printf("3. Back to main menu\n");
                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1) {
                    flush_stdin();
                    printf("Invalid input.\n");
                    continue;
                }
                flush_stdin();

                if (choice == 1)
                {
                    print_table(emp, count);
                }
                else if (choice == 2)
                {
                    if (count == 0)
                    {
                        printf("No data available.\n");
                    }
                    else
                    {
                        int searchId, found = 0;
                        printf("Enter Employee id to search: ");
                        if (scanf("%d", &searchId) != 1) { flush_stdin(); printf("Invalid id.\n"); continue; }
                        flush_stdin();

                        for (int i = 0; i < count; i++)
                        {
                            if (emp[i].id == searchId)
                            {
                                printf("\n--- Employee Found ---\n");
                                printf("ID: %d\n", emp[i].id);
                                printf("Name: %s\n", emp[i].name);
                                printf("Age: %d\n", emp[i].age);
                                printf("Salary: %.2f\n", emp[i].salary);
                                printf("Department: %s\n", emp[i].department);
                                found = 1;
                                break;
                            }
                        }
                        if (!found) printf("Employee not found.\n");
                    }
                }
                else if (choice == 3)
                {
                    break;
                }
                else
                {
                    printf("Invalid choice!\n");
                }
            }
        }
        else if (mainChoice == 3)
        {
            if (save_to_file(emp, count) == 0)
                printf("Data saved. Exiting...\n");
            else
                printf("Failed to save data. Exiting...\n");
            return 0;
        }
        else
        {
            printf("Invalid choice!\n");
        }

        MAIN_MENU: ;
    }

    return 0;
}