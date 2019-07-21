#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
struct sockaddr_in serv;
int sock,con,r,w;
unsigned short serv_port = 5601;
char serv_ip[] = "10.0.2.15";
char rbuff[128],sbuff[128];
int main()
{
	serv.sin_family = AF_INET;
	serv.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv.sin_addr));
	printf("\n client ready \n");
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		printf("socket error \n");
		exit(1);
	}
	con = connect(sock,(struct sockaddr *)&serv,sizeof(serv));
	if(con<0)
	{
		printf("cannot connect \n");
		close(sock);
		exit(1);
	}
	while(1){
	printf("your message\n");
	gets(&sbuff);
	w = write(sock,sbuff,128);
	if(w<0)
	{
		printf("cannot send \n");
		close(sock);
		exit(1);
	}
	r = read(sock,rbuff,128);
	if(r<0)
		printf("error \n");
	else
		{
			rbuff[r] = '\0';
			if(!strcmp(rbuff,"bye"))
			{
				close(sock);
				exit(1);
			}
			else{
			printf("server message:\n");
			puts(rbuff);}

		}
	}


	close(sock);

}
