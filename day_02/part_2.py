import numpy as np

with open('input.txt') as f: # j3b: 520
    input = f.readlines()
    
def check_diff_accepts(diff):
    return not(any(abs(n) not in range(1,4) for n in diff) or (any(n > 0 for n in diff) and any(n < 0 for n in diff)))

def cycle_removal(numbers):
    for i in range(0,len(numbers)):
        if check_diff_accepts(np.diff(np.delete(numbers, i))):
            return True
    return False

safe = 0

for line in input:
    numbers = np.array(list(map(int, line.split())))
    if check_diff_accepts(np.diff(numbers)):
        safe += 1
        continue
    if cycle_removal(numbers):
        safe += 1
    
print(safe)