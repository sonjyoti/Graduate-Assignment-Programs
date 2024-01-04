# 2. Using while loop, produce a table of sins, cosines and tangents. Make a variable x in range from
# 0 to 10 in steps of 0.2. For each value of x, print the value of sin(x), cos(x) and tan(x).

import math

x = 0
while x < 10:
    print("\ncos(", x, "): ", math.cos(x), "\nsin(", x, "): ",
          math.sin(x), "\ntan(", x, "): ", math.tan(x))
    x += 0.2
