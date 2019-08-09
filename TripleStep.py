#Dynamic Programming
#Count no of ways to climb n steps if hop of 1 or 2 or 3 steps allowed
def count(n,memlist):
    if n<0:
        return 0
    elif n==0:
        return 0
    elif n==1:
        return 1
    elif memlist[n]>-1:
        return memlist[n]
    else:
        memlist[n]=count(n-1,memlist)+count(n-2,memlist)+count(n-3,memlist)
        return memlist[n]
n=int(input("Enter no of steps"))
lst=[-1 for i in range(n+1)]
p=count(n,lst)
print("Ways",p)
