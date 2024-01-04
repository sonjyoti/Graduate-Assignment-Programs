# 8. Write a list function to convert a string into a list, as in list (‘abc’) gives [a, b, c].

def toList(str):
    list = []
    for i in str:
        list.append(i)
    return list


str = "abc"
print(toList(str))
