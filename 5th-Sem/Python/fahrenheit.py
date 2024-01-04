# 1. Using for loop, print a table of Celsius/Fahrenheit equivalences. Let c be the Celsius
# temperatures ranging from 0 to 100, for each value of c, print the corresponding Fahrenheit
# temperature.

for c in range(1, 100, 1):
    fht = (c * (9/5)) + 32
    print("Celcius: ", c, "  Fahrenheit: ", fht)  
