size = 16
print('Complemento(ah=bh, al=bl, ', end='')
for i in range(size):
    print('sh[' + str(i) + ']=bch' + str(i) + ', ', end='')
for i in range(size):
    if i != size - 1:
        print('sl[' + str(i) + ']=bcl' + str(i) + ', ', end='')
    else:
        print('sl[' + str(i) + ']=bcl' + str(i) + ');')
print()
nCarry = 1
for i in range(size):
    if i == 0:
        print('FullAdder(a=al[' + str(i) + '], b=bcl' + str(i) + ', c=false, sum=sl[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    else:
        print('FullAdder(a=al[' + str(i) + '], b=bcl' + str(i) + ', c=c' + str(nCarry) + ', sum=sl[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    nCarry += 1
print()
for i in range(size):
    print('FullAdder(a=ah[' + str(i) + '], b=bch' + str(i) + ', c=c' + str(nCarry) + ', sum=sh[' + str(i) + '], carry=c' + str(nCarry + 1) + ');')
    nCarry += 1
