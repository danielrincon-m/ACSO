def sqroot(x):
    #x *= 10
    if (x == 0 or x == 1): 
        return x
    i, intResult = 1, 1
    while intResult <= x:
        i += 1
        intResult = i * i
    intRoot = i - 1
      
    return intRoot


def main():
    print(sqroot(18))

main()