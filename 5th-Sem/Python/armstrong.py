# 10. Write a program to check a number is Armstrong or not

def digits(n):
    d = 0
    while n != 0:
        n = n // 10
        d = d + 1
    return d


def isArmstrong(n):
    tmp = n
    sum = 0
    d = digits(tmp)
    while tmp != 0:
        sum = sum + (tmp % 10)**d
        tmp = tmp // 10
    if sum == n:
        return True
    return False


n = int(input("Input the value of n: "))

if isArmstrong(n):
    print(n, "is an armstrong number")
else:
    print(n, "is not an armstrong number")
