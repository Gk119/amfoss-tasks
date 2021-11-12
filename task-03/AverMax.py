t = int(input())

for x in range(t):
    n, k = map(int,input().split())
    #print(n, k)
    lst = map(float,input().split()) 
    #print(*lst)
    maxval = 0.0;
    for i in lst:
        if(i >= 0):
            if(i > maxval):
                maxval = i
        else:
            if(k > 0):
                if((i * (-1)) > maxval):
                    maxval = i * (-1)
    print(maxval)
