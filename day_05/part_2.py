with open('test.txt') as f:
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
    middle_page_number = 0
    all_satisfied = False
    while(not all_satisfied):
        one_grumpy = False
        for r in rules:
            if r[0] in u and r[1] in u:
                before = u.index(r[0])
                after = u.index(r[1])
                if before > after:
                    u[before], u[after] = u[after], u[before]  
                    middle_page_number = u[int((len(u)-1)/2)] 
                    one_grumpy = True    
        all_satisfied = not(one_grumpy)
    sum += middle_page_number
            
print(sum)