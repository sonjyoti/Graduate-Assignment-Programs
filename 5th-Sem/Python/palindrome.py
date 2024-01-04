# 7. Write a function that takes a string input and checks if it is a palindrome or not.

def palindrome(str):
    return str == str[::-1]


str = input("Input the string: ")
if palindrome(str):
    print("String is a palindrome")
else:
    print("String is not a palindrome")
