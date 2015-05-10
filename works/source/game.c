#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 4700

// the struct of game
struct game{
   char *id;   //player id
   char *sip;  //server ip
   int sport;  //server port
   char *bip;  //bind ip
   int bport;  //bind port
}game_server;

int main(int argc,char* argv[]){
    int    socket_fd,connet_fd;
    struct sockaddr_in   server_addr;
    struct sockaddr_in   client_addr;
    char msg[100];
    if(argc < 5){
         fprintf(stderr,"args not correct!");
	 exit(0);
    }
    
    game_server.bip = argv[1];
    game_server.bport = atoi(argv[2]);
    game_server.sip = argv[3];
    game_server.sport = atoi(argv[4]);
    game_server.id = argv[5];
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        fprintf(stderr,"create scoket error:%s(errno:%d)",strerror(errno),errno);
        exit(0);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(game_server.sport);
    //server_addr.sin_addr.s_addr = inet_addr(game_server.sip);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(socket_fd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0){
       fprintf(stderr,"bind error");
       exit(0);
    }

    memset(&client_addr,0,sizeof(&client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(game_server.bport);
    if(inet_pton(AF_INET,game_server.bip,&client_addr.sin_addr) <= 0){
       fprintf(stderr,"inet_pton error for %s",game_server.sip);
       exit(0);
    }

    if( connect(socket_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))){
        fprintf(stderr,"connect error:%s(errno:%d)",strerror(errno),errno);
        exit(0);
    }

    sprintf(msg,"reg:%s %s",game_server.id,"myphone");
    send(socket_fd,msg,strlen(msg),0);
    //printf("%s %s %s %s %s\n",argv[0],argv[1],argv[2],argv[3],argv[4]);
    return 0;
}
