# 9. Write a program to generate Fibonacci series.

def fibonacci(n):
    if(n == 0):
        return n
    elif(n == 1):
        return n
    return fibonacci(n-1)+fibonacci(n-2)


n = int(input("Input the value of n: "))
for i in range(0, n, 1):
    print(fibonacci(i), end=' ')
print("\n")
