#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
struct sockaddr_in serv,cli;
int sock,bin,lis,conn,r,w;
unsigned short serv_port = 5601;
char serv_ip[] = "10.0.2.15";
char rbuff[128],sbuff[128];
int main()
{
	serv.sin_family = AF_INET;
	serv.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv.sin_addr));
	sock = socket(AF_INET,SOCK_STREAM,0);
	printf("\n server ready \n");
		if(sock<0)
		{
			printf("socket error \n ");
		}
	bin = bind(sock,(struct sockaddr *)&serv,sizeof(serv));
	if(bin<0)
	{
		printf("binderror\n");
		close(sock);
		exit(1);

	}
	lis = listen(sock,5);
	if(lis<0)
	{
		printf("cannot listen \n");
		close(sock);
		exit(1);
	}
	printf("ctrl +c to stop \n");
	int cli_len = sizeof(cli);
	while(1){
		conn = accept(sock,(struct sockaddr *)&cli, &cli_len);
		if(conn<0)
		{
			printf("cannot connect \n");
			close(sock);
			exit(1);
		}
	
		printf("conection from %s\n",inet_ntoa(cli.sin_addr));
		while(1)
		{
		
		
			r = read(conn,rbuff,128);
			if(r<0)
			{
				printf("cannot receive \n");
			}
			else
			{
				rbuff[r] = '\0';
				printf("message from client:\n");
				puts(rbuff);
				printf("\nyour message:\n");
				gets(&sbuff);
		
				w = write(conn,sbuff,128);
				if(w<0)
				{
					printf("cannot send \n");
				}
				if(!strcmp(sbuff,"bye"))
				break;
			}
		}
	
 }
	close(sock);
}
