import numpy as np

with open('input.txt') as f:
    input = f.readlines()
    
safe = 0

for line in input:
    diff = np.diff(np.array(list(map(int, line.split()))))
    unsafe = any(abs(n) not in range(1,4) for  n in diff) # checks if any n<-3 or n>3 or n==0
    unsafe = unsafe or any(n > 0 for n in diff) and any(n < 0 for n in diff) # checks if it's both increasing AND decreasing
    if unsafe:
        continue
    safe += 1
        
print(safe)