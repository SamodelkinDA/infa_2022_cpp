import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

p =np.array([])
W =np.array([])
f= open(Path("Dislocation" , "Dislocation", "OUT.txt"), 'r')
file = f.readlines()
trys = int(file[0].rstrip())
for i in range(1, len(file)):
    y = 0
    l = list(map(int, file[i].rstrip().split()))
    x = l[0]
    for j in range(trys):
        y += l[j+1]
    p=np.concatenate((p, [x]))
    W=np.concatenate((W, [y / trys]))


plt.ylabel("T, c")
plt.xlabel('N, шт')
plt.plot(p, W, "o")
plt.plot(p, W, "-")
plt.title('T(N)')
plt.grid()
plt.show()
print(np.polyfit(W, p, deg=1, cov=True))

