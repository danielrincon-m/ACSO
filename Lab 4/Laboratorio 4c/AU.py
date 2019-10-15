noth = 1
notl = 1
andh = 1
andl = 1
orh = 1
orl = 1

reps = 16

for i in range(reps):
    print('Not(in=pi1, out=noth' + str(noth) + ');')
    noth += 1
    print('Not(in=pi0, out=noth' + str(noth) + ');')
    noth += 1
    print('Not(in=pi1, out=noth' + str(noth) + ');')
    noth += 1
    print('And(a=noth' + str(noth - 3) + ', b=noth' + str(noth - 2) + ', out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=noth' + str(noth - 1) + ', b=pi0, out=andh' + str(andh) + ');')
    andh += 1
    print('Not(in=pi0, out=noth' + str(noth) + ');')
    noth += 1
    print('Not(in=pi2, out=noth' + str(noth) + ');')
    noth += 1
    print('And(a=andh' + str(andh - 2) + ', b=cih[' + str(i) + '], out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=andh' + str(andh - 2) + ', b=ch[' + str(i) + '], out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=pi1, b=noth' + str(noth - 2) + ', out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=noth' + str(noth - 1) + ', b=pi1, out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=pi0, b=cih[' + str(i) + '], out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=pi2, b=pi1, out=andh' + str(andh) + ');')
    andh += 1
    print('Or(a=andh' + str(andh - 6) + ', b=andh' + str(andh - 5) + ', out=orh' + str(orh) + ');')
    orh += 1
    print('And(a=andh' + str(andh - 4) + ', b=ch[' + str(i) + '], out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=andh' + str(andh - 4) + ', b=andh' + str(andh - 3) + ', out=andh' + str(andh) + ');')
    andh += 1
    print('And(a=andh' + str(andh - 3) + ', b=ch[' + str(i) + '], out=andh' + str(andh) + ');')
    andh += 1
    print('Or(a=orh' + str(orh - 1) + ', b=andh' + str(andh - 3) + ', out=orh' + str(orh) + ');')
    orh += 1
    print('Or(a=andh' + str(andh - 2) + ', b=andh' + str(andh - 1) + ', out=orh' + str(orh) + ');')
    orh += 1
    print('Or(a=orh' + str(orh - 2) + ', b=orh' + str(orh - 1) + ', out=rh[' + str(i) + ']);')
    print()

print()
for i in range(reps):
    print('Not(in=pi1, out=notl' + str(notl) + ');')
    notl += 1
    print('Not(in=pi0, out=notl' + str(notl) + ');')
    notl += 1
    print('Not(in=pi1, out=notl' + str(notl) + ');')
    notl += 1
    print('And(a=notl' + str(notl - 3) + ', b=notl' + str(notl - 2) + ', out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=notl' + str(notl - 1) + ', b=pi0, out=andl' + str(andl) + ');')
    andl += 1
    print('Not(in=pi0, out=notl' + str(notl) + ');')
    notl += 1
    print('Not(in=pi2, out=notl' + str(notl) + ');')
    notl += 1
    print('And(a=andl' + str(andl - 2) + ', b=cil[' + str(i) + '], out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=andl' + str(andl - 2) + ', b=cl[' + str(i) + '], out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=pi1, b=notl' + str(notl - 2) + ', out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=notl' + str(notl - 1) + ', b=pi1, out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=pi0, b=cil[' + str(i) + '], out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=pi2, b=pi1, out=andl' + str(andl) + ');')
    andl += 1
    print('Or(a=andl' + str(andl - 6) + ', b=andl' + str(andl - 5) + ', out=orl' + str(orl) + ');')
    orl += 1
    print('And(a=andl' + str(andl - 4) + ', b=cl[' + str(i) + '], out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=andl' + str(andl - 4) + ', b=andl' + str(andl - 3) + ', out=andl' + str(andl) + ');')
    andl += 1
    print('And(a=andl' + str(andl - 3) + ', b=cl[' + str(i) + '], out=andl' + str(andl) + ');')
    andl += 1
    print('Or(a=orl' + str(orl - 1) + ', b=andl' + str(andl - 3) + ', out=orl' + str(orl) + ');')
    orl += 1
    print('Or(a=andl' + str(andl - 2) + ', b=andl' + str(andl - 1) + ', out=orl' + str(orl) + ');')
    orl += 1
    print('Or(a=orl' + str(orl - 2) + ', b=orl' + str(orl - 1) + ', out=rl[' + str(i) + ']);')
    print()
