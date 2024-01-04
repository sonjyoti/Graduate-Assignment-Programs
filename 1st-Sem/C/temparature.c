#include <stdio.h>

int main()
{
    float t, f, c;
    // C = (°F - 32) × 5/9
    //[°F] = [°C] × 9/5 + 32
    printf("Enter temperature in fahrenheit: ");
    scanf("%f", &f);
    t = (f - 32) * 5 / 9;
    printf("Centigrade of %.2f°F is %.2f°C\n", f, t);
    printf("Enter temperature in centigrade: ");
    scanf("%f", &c);
    t = ((c * 9 / 5) + 32);
    printf("Fahrenheit of %.2f°C is %.2f°F\n", c, t);
    return 0;
}