# 14. Write a program to compare three numbers and print the largest one.

def largestNo(num1, num2, num3):
    if num1 > num2 and num1 > num3:
        return num1
    elif num2 > num3:
        return num2
    return num3


num1 = int(input("Input first no.: "))
num2 = int(input("Input second no.: "))
num3 = int(input("Input third no.: "))

print("Largest number(", num1, num2, num3, ")is:", largestNo(num1, num2, num3))
