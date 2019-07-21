def heapify(a,n,i):
    rt=i
    l=2*i+1
    r=2*i+2
    largest=rt
    if l<n and a[rt]<a[l]:
        largest=l
    if r<n and a[largest]<a[r]:
        largest=r
    if largest!=rt:
        a[largest],a[rt]=a[rt],a[largest]
        heapify(a,n,largest)
    
    
def heapsort(a):
    n=len(a)
    for i in range(n,-1,-1):
        heapify(a,n,i)
    for i in range(n-1,-1,-1):
        a[0],a[i]=a[i],a[0]
        heapify(a,i,0)
    

arr=list(map(int,input("Enter data").split(" ")))
heapsort(arr)
print(arr)