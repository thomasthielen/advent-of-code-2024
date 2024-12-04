import re
with open('test.txt') as f:
    input = f.read()
    
muls = re.findall('mul\([0-9]{1,3},[0-9]{1,3}\)', input)
num = list(map(int, re.findall('[0-9]{1,3}', ''.join(muls))))
output = 0
for i in range(0, len(num)-1, 2):
    output += num[i] * num[i+1]
print(output)