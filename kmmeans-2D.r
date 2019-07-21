getDistance=function(x1,y1,x2,y2){
	d1=(x1-x2)*(x1-x2)
	d2=(y1-y2)*(y1-y2)
	d=sqrt(d1+d2)
	return(d)
}
getMean=function(p){
	m=mean(p)
	return(m)
}
x=function(){
	ax=as.numeric(strsplit(readline("Enter x values for the set:")," ")[[1]])
	ay=as.numeric(strsplit(readline("Enter y values for the set:")," ")[[1]])
	c1x=as.numeric(readline("Enter center 1 x value:"))
	c1y=as.numeric(readline("Enter center 1 y value:"))
	c2x=as.numeric(readline("Enter center 2 x value:"))
	c2y=as.numeric(readline("Enter center 2 y value:"))
	bx=vector(mode="numeric",length=0)
	by=vector(mode="numeric",length=0)
	cx=vector(mode="numeric",length=0)
	cy=vector(mode="numeric",length=0)
	repeat{
		oldc1x=c1x
		oldc1y=c1y
		oldc2x=c2x
		oldc2y=c2y
		j=1
		k=1
		for(i in 1:length(ax)){
			d1=getDistance(ax[i],ay[i],c1x,c1y)
			d2=getDistance(ax[i],ay[i],c2x,c2y)
			if(d1>d2){
				cx[k]=ax[i]
				cy[k]=ay[i]
				k=k+1
			}
			else{
				bx[j]=ax[i]
				by[j]=ay[i]
				j=j+1
			}
		}
		c1x=getMean(bx)
		c1y=getMean(by)
		c2x=getMean(cx)
		c2y=getMean(cy)
		if(abs(c1x-oldc1x)>=0.01 || abs(c1y-oldc1y)>=0.01 || abs(c2x-oldc2x)>=0.01 || abs(c2y-oldc2y)>=0.01)
			break
	}
	cat("Cluster 1","\n")
	for(i in 1:length(bx)){
		cat("x:",bx[i],"\t","y:",by[i],"\n")
	}
	cat("Cluster 1","\n")
	for(i in 1:length(cx)){
		cat("x:",cx[i],"\t","y:",cy[i],"\n")
	}
	cat("Centroid 1","\n")
	cat("x:",c1x,"\t","y:",c1y,"\n")
	cat("Centroid 2","\n")
	cat("x:",c2x,"\t","y:",c2y,"\n")
}
x()