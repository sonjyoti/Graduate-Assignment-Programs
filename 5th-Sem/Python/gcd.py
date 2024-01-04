# 16. Write a method to calculate GCD of two numbers.

def gcd(num1, num2):
    if num1 == 0:
        return num2
    if num2 == 0:
        return num1
    if num1 == num2:
        return num2
    if num1 > num2:
        return gcd(num1 - num2, num2)
    else:
        return gcd(num1, num2 - num1)


num1 = int(input("Input the first no.: "))
num2 = int(input("Input the second no.: "))

print("Greatest Common Divisor(", num1, num2, "):", gcd(num1, num2))
