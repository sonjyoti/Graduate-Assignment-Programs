# 13. Write a program to print all prime number between a range(for example between 1 and 100).

def prime(n):
    if n == 1:
        return False
    for i in range(2, n//2+1, 1):
        if n % i == 0:
            return False
    return True


low = int(input("Input lower limit: "))
high = int(input("Input upper limit: "))

print("Prime numbers between range(", low, "-", high, "):")
for i in range(low, high, 1):
    if prime(i):
        print(i, end=" ")
print("\n")
