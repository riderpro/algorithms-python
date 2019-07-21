x=function(){
	a<-as.numeric(strsplit(readline("Enter elements for a:")," ")[[1]])
	c1=as.numeric(readline("Enter initial centre 1:"))
	c2=as.numeric(readline("Enter initial centre 2:"))
	b=vector(mode="numeric",length=0)
	c=vector(mode="numeric",length=0)
	repeat{
		j=1
		k=1
		oldc1=c1
		oldc2=c2
		for(i in 1:length(a)){
			d1=abs(a[i]-c1)
			d2=abs(a[i]-c2)
			if(d1>d2){
				c[k]=a[i]
				i=i+1
				k=k+1
			}
			else{
				b[j]=a[i]
				i=i+1
				j=j+1
			}
		}
		c1=mean(b)
		c2=mean(c)
		if(abs(c1-oldc1)>=0.01 || abs(c2-oldc2)>=0.01 )
			break
	}
	cat("Cluster 1","\n")
	for(i in 1:length(b)){
		cat(b[i],"\t")
	}
	cat("\n")
	cat("Cluster 2","\n")
	for(i in 1:length(c)){
		cat(c[i],"\t")
	}
	cat("\n")
	cat("Centroid 1:",c1,"\t","Centroid 2:",c2,"\n")
}
x()