# 12. Write a program to print all even number between a range(for example between 1 and 100).

low = int(input("Input lower limit: "))
high = int(input("Input upper limit: "))

print("Even numbers between range(", low, "-", high, "):")
for i in range(low, high, 1):
    if i % 2 == 0:
        print(i, end=" ")
print("\n")
