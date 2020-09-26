import csv
import matplotlib.pyplot as plt
import numpy as np
fast = []
normal = []
with open('result.csv', newline='') as csvfile:
    rows = csv.reader(csvfile)
    first = True
    for row in rows:
        if first:
            first = False
            continue
        fast.append(int(row[0]))
        normal.append(int(row[1]))
divisor = list(range(2, 5001))
plt.figure(figsize=(10, 5))
plt.plot(divisor, fast, color = 'r', label="fast")
plt.plot(divisor, normal, color = 'g', label="normal")
plt.title("Fast division v.s. Normal division")
plt.xlabel("divisor")
plt.ylabel("time (ns)")
plt.ylim(0, 150)
plt.legend(loc = "upper right", fontsize=10)
plt.savefig("Result.png")
