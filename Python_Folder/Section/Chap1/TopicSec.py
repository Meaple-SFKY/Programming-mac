import math

def main():
    for temp in range(100, 201):
        flag = True
        for i in range(2, temp):
            if temp % i == 0:
                flag = False
                break
        if flag == True:
            print(temp, "\t", end = "")
    print()
if __name__ == '__main__':
    main()