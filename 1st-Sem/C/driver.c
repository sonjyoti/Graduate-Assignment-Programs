#include <stdio.h>

int main()
{
    char maritalStatus, gender;
    int age, c;
    printf("Enter the driver's marital status (M(married)/U(unmarried)): ");
    scanf("%c", &maritalStatus);

    if (!(maritalStatus == 'M' || maritalStatus == 'U'))
    {
        printf("Wrong Input, program terminated.\n");
        return 0;
    }
    printf("Enter the driver's age: ");
    scanf("%d", &age);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Enter the driver's gender (m(male)/f(female)): ");
    scanf("%c", &gender);
    if (!(gender == 'm' || gender == 'f'))
    {
        printf("Wrong Input, program terminated.\n");
        return 0;
    }
    if (maritalStatus == 'M' || (maritalStatus == 'U' && ((gender == 'm' && age > 30) || (gender == 'f' && age > 25))))
        printf("Insurance issued\n"); // gender inequality right here :-(
    else
        printf("Insurance declined\n");
    return 0;
}