# 11. Write a program to check whether the input number is even or odd.

def isOdd(n):
    if n % 2 != 0:
        return True
    else:
        return False


n = int(input("Input the value of n: "))
if isOdd(n):
    print(n, "is an odd number.")
else:
    print(n, "is an even number.")
