#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    float salary;
};

void calculate_tax_and_summary() {
    float total_salary_per_month = 0;
    struct Employee employees[100];
    int count = 0;

    while (1) {
        printf("Employee's Name: ");
        scanf("%s", employees[count].name);

        if (strcmp(employees[count].name, "-1") == 0) {
            break;
        }

        printf("Salary (Bath/Month): ");
        scanf("%f", &employees[count].salary);

        total_salary_per_month += employees[count].salary;
        count++;
    }

    float total_salary_per_year = total_salary_per_month * 12;
    float tax_per_year = total_salary_per_year * 0.07;

    printf("All salary per month: %.2f Bath\n", total_salary_per_month);
    printf("All salary per year: %.2f Bath\n", total_salary_per_year);
    printf("Tax (7%% per year): %.2f Bath\n", tax_per_year);

    float max_tax_amount = 0;
    char max_tax_name[50];

    for (int i = 0; i < count; i++) {
        float employee_tax = employees[i].salary * 0.07;
        if (employee_tax > max_tax_amount) {
            max_tax_amount = employee_tax;
            strcpy(max_tax_name, employees[i].name);
        }
    }

    printf("Most tax in company: %s (%.2f Bath per year)\n", max_tax_name, max_tax_amount);
}

int main() {
    // Test case 1
    calculate_tax_and_summary();

    // Test case 2
    calculate_tax_and_summary();

    return 0;
}

