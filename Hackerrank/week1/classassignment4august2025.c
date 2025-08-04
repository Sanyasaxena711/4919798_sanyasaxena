#include <stdio.h>

int main()
{
    int day;

    do
    {
        printf("Enter a number (1 to 7): ");
        scanf("%d", &day);
        switch (day)
        {
        case 1:
            printf("The day of the week is: Monday\n");
            printf("To Exit press 0\n");
            break;
        case 2:
            printf("The day of the week is: Tuesday\n");
            printf("To Exit press 0\n");
            break;
        case 3:
            printf("The day of the week is: Wednesday\n");
            printf("To Exit press 0\n");
            break;
        case 4:
            printf("The day of the week is: Thursday\n");
            printf("To Exit press 0\n");
            break;
        case 5:
            printf("The day of the week is: Friday\n");
            printf("To Exit press 0\n");
            break;
        case 6:
            printf("The day of the week is: Saturday\n");
            printf("To Exit press 0\n");
            break;
        case 7:
            printf("The day of the week is: Sunday\n");
            printf("To Exit press 0\n");
            break;
        default:
            printf("Invalid input! Please enter a number from 1 to 7.\n ");
        }
    } while (day != 0);

    return 0;
}
