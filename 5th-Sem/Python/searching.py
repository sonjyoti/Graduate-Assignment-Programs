# 19. Write a program to implement linear and binary search on lists.

def binarySearch(list, key):
    start, end = 0, len(list)-1
    while start <= end:
        mid = start + (end - start) // 2
        if list[mid] == key:
            return mid
        elif list[mid] > key:
            end = mid - 1
        else:
            start = mid + 1
    return -1


def linearSearch(list, key):
    for i in range(0, len(list), 1):
        if list[i] == key:
            return i
    return -1


list = [1, 2, 4, 5, 6]
key = int(input("Input the key: "))
n = binarySearch(list, key)
if n != -1:
    print("Binary Search: ")
    print("Key found at index: ", binarySearch(list, key))

if n != -1:
    print("Linear Search: ")
    print("Key found at index: ", linearSearch(list, key))
else:
    print("Key not found")
