import os
from pathlib import Path

file = open(Path("Dislocation", "Dislocation", "Data.txt"), 'w')
file.write("10 \n")
for i in range(14, 20):
    file.write(f"{i} \n")
file.write("0 \n")
file.close()
path = Path("Dislocation", "Debug", "Dislocation.exe")
os.startfile(path, 'open')
