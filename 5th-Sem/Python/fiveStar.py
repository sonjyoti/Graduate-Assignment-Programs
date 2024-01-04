# 4. Write a program that takes a positive integer n and then produces n lines of output shown as
# follows. For example enter a size: 5

n = int(input("Input value of n: "))

for i in range(1, n+2, 1):
    for j in range(n+1, i, -1):
        print(" ", end="")
    for k in range(1, i, 1):
        print("* ", end="")
    print("")
