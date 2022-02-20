import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

p =np.array([])
W =np.array([])
f= open(Path("Dislocation" , "Dislocation", "OUT.txt"), 'r')
file = f.readlines()
trys = int(file[0].rstrip())
y = 0
l = list(map(int, file[1].rstrip().split()))
summ = 0
for j in range(trys):
    x = j
    y = l[j+1]
    summ += y
    p=np.concatenate((p, [x]))
    W=np.concatenate((W, [y]))

plt.ylabel("T, c")
plt.xlabel('N, шт')
plt.plot(p, W, "o")
plt.plot(p, W, "-")
plt.plot(p, [summ / trys]*trys, "-")
plt.title('T(N)')
plt.grid()
plt.show()
print(np.polyfit(W, p, deg=1, cov=True))