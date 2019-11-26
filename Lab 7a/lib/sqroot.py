def sqroot(x):
    if x == 0:
        return x
    i, intResult = 1, 1
    while intResult <= x:
        i += 1
        intResult = i * i
    intResult = i - 1
    intResult *= 10

    return intResult


def main():
    print(sqroot(180019))


main()
