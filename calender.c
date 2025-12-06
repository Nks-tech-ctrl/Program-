#include <stdio.h>

int main()
{
    int month, year;
    int daysInMonth, startday;

    printf("Enter month(1-12): ");
    scanf("%d", &month);

    printf("Enter Year: ");
    scanf("%d", &year);

    //leap year
    int isLeap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        isLeap = 1;

    // days in month
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        daysInMonth = 31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;

    else if (month == 2)
    {
        if (isLeap == 1)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else
    {
        printf("invalid month \n");
        return 0;
    }

    // find first day (zeller's formula)
    int m = month;
    int y = year;
    if (m < 3)
    {
        m += 12;
        y--;
    }

    // h Day of week (0 = Saturday, 1 = Sunday, 2 = Monday, ...)
    // q Day of month (we use 1 for the first day)
    // m Month number (March = 3, ..., January = 13, February = 14)
    // K Year within century (year % 100)
    // J Zero-based century

    int K = y % 100;
    int J = y / 100;
    int h = (1 + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    startday = (h + 6) % 7;

    printf("\n\n----------- %d/%d -----------\n", month, year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < startday; i++)
    {
        printf("     "); // keep spacing for empty days
    }

    for (int day = 1; day <= daysInMonth; day++)
    {
        printf("%5d", day); // proper spacing for days
        if ((day + startday) % 7 == 0)
            printf("\n");
    }

    printf("\n----------------------------\n");
    return 0;
}
