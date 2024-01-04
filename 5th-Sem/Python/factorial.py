# 6. Write a function that takes an integer input and calculates the factorial of that number.


def fact(n):
    ans = 1
    for i in range(1, n+1, 1):
        ans = ans * i
    return ans


n = int(input("Input value of n: "))
print("Factorial of :", n, "is", fact(n))
