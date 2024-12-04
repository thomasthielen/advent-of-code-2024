import re

with open('test_1.txt') as f:
    input = f.read()
    
muls = re.findall('mul\(([0-9]{1,3}),([0-9]{1,3})\)', input)
output = 0
for m in muls:
    x, y = map(int, m)
    output += x * y
print(output)