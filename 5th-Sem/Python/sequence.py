# 5. Write a function that takes an integer n as input and calculates the value of 1 + 1/1! + 1/2! + 1/3!
# + ... + 1/n

def fact(n):
    ans = 1
    for i in range(1, n+1, 1):
        ans = ans * i
    return ans


def seq(n):
    a = 1
    b = 1
    while fact(a) != n:
        b = b + 1/fact(a)
        a = a + 1
    return b


n = int(input("Input value of n: "))
print("Value of the sequence:", seq(n))
