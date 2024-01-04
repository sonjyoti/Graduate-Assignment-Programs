# 20. Write a program to sort a list using insertion sort and bubble sort and selection sort.

def insertionSort(list):
    print("\nInsertion Sort")
    for i in range(1, len(list), 1):
        for j in range(i, 0, -1):
            if list[j] < list[j-1]:
                list[j], list[j-1] = list[j-1], list[j]
    return list


def bubbleSort(list):
    print("\nBubble sort")
    for i in range(0, len(list), 1):
        for j in range(0, len(list)-1-i, 1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
    return list


def selectionSort(list):
    print("\nSelection sort")
    for i in range(0, len(list)-1, 1):
        for j in range(i+1, len(list), 1):
            if list[i] > list[j]:
                list[i], list[j] = list[j], list[i]
    return list


list = [12, 11, 13, 5, 6]

print("Before sorting: ", list)
print("After sorting:  ", insertionSort(list))
print("After sorting:  ", bubbleSort(list))
print("After sorting:  ", selectionSort(list))
