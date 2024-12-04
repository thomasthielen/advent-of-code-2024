import numpy as np

with open('input.txt') as f:
    input = f.readlines()
    
safe = 0

for line in input:
    diff = np.diff(np.array(list(map(int, line.split()))))
    if any(abs(n) not in range(1,4) for n in diff) or (any(n > 0 for n in diff) and any(n < 0 for n in diff)):
        continue
    safe += 1
        
print(safe)