def partition(a,s,e):
    i=s
    j=s-1
    pivot=a[e]
    for i in range(s,e):
        if a[i]<pivot:
            j+=1
            a[i],a[j]=a[j],a[i]
    a[j+1],a[e]=pivot,a[j+1]
    return j+1

def quicksort(a,s,e):
    if s<e:
        m=partition(a,s,e)
        quicksort(a,s,m-1)
        quicksort(a,m+1,e)

if __name__=="__main__":
    a=list(map(int,input("Enter nos").split(" ")))
    n=len(a)
    quicksort(a,0,n-1)
    print(a)
        
    
    
    
        