with open('input.txt') as f:
    input = f.readlines()

rules = []
updates = []

for line in input:
    if '|' in line:
        rules.append(list(map(int,line.split('|'))))
    elif ',' in line:
        updates.append(list(map(int,line.split(','))))

sum = 0        

for u in updates:
    middle_page_number = u[int((len(u)-1)/2)]
    for r in rules:
        if r[0] in u and r[1] in u:
            if u.index(r[0]) > u.index(r[1]):
                middle_page_number = 0
                break
    sum += middle_page_number
            
print(sum)