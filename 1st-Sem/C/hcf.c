#include <stdio.h>

int commonFactor(int min, int num1, int num2)
{
    int i, ans;
    for (i = 1; i <= min; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            ans = i;
    }
    return ans;
}

int main()
{
    int num1, num2, min, hcf, lcm;
    printf("Input the two numbers: ");
    scanf("%d %d", &num1, &num2);
    min = num1 < num2 ? num1 : num2;
    hcf = commonFactor(min, num1, num2);
    lcm = (num1 * num2) / hcf;
    printf("LCM and HCF of %d and %d are : %d and %d\n", num1, num2, lcm, hcf);
    return 0;
}