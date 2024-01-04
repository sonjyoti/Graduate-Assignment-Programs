# 3. Write a program that reads an integer value and prints ―leap year or ―not a leap year.

year = int(input("Input year: "))

if year % 4 == 0 and year % 100 != 0:
    print(year, "is a leap year")
else:
    print(year, "is not a leap year")
