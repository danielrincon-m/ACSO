size = 16
nNot = 1
nCarry = 1
for i in range(size):
    print('Not(in=al[' + str(i) + '], out=not' + str(nNot) +');')
    if i == 0:
        print('HalfAdder(a=not' + str(nNot) + ', b=true, sum=sl[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    else:
        print('HalfAdder(a=not' + str(nNot) + ', b=c' + str(nCarry) + ', sum=sl[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    nNot += 1
    nCarry += 1
print()
for i in range(size):
    print('Not(in=ah[' + str(i) + '], out=not' + str(nNot) +');')
    print('HalfAdder(a=not' + str(nNot) + ', b=c' + str(nCarry) + ', sum=sh[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    nNot += 1
    nCarry += 1
