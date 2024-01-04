# 15. Write a program to print factors of a given number.

def factors(n):
    list = []
    for i in range(1, n//2+1, 1):
        if n % i == 0:
            list.append(i)
    list.append(n)
    return list


n = int(input("Input the value of n: "))
print("Factors of", n, "are:", factors(n))
