import bisect
import re
with open('test_2.txt') as f:
    input = f.read()
    
muls = re.findall('mul\(([0-9]{1,3}),([0-9]{1,3})\)', input)
muls_index = re.finditer('mul\([0-9]{1,3},[0-9]{1,3}\)', input)
dos_index = re.finditer('do\(\)', input)
donts_index = re.finditer('don\'t\(\)', input)

muls_pos = []
for m in muls_index:
    muls_pos.append(m.start())
for m in muls:
    first_number, second_number = map(int, m)
    
unsorted_dict = {0: True}
for d in dos_index:
    unsorted_dict[d.start()] = d.group() == 'do()'
for d in donts_index:
    unsorted_dict[d.start()] = d.group() == 'do()'
    
sorted_dict = dict(sorted(unsorted_dict.items())) 
key_list, value_list = list(sorted_dict.keys()), list(sorted_dict.values())

output = 0
for i,m in enumerate(muls):
    if value_list[bisect.bisect_right(key_list, muls_pos[i]) - 1]:
        x, y = map(int, m)
        output += x * y
print(output)