#include <stdio.h> 
#include <sys/socket.h>
#include <sys/types.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
 
#define PORT 8080 
   
int main() 
{ 
    //struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client/Mubeen"; 
    char buffer[1024] = {0}; // without this, garbage also sent along string. i don't know purpose of 0
     
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "192.168.1.103", &serv_addr.sin_addr)<=0)  
    { 
    
    	printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    // Creating Connection
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    
    valread = recv(sock , buffer, 1024, 0);
 	if(valread < 0) perror("Message reading error\n");
 	else printf("%s\n",buffer ); 
 	
 	// Closing Socket
 	close(sock);
    
    return 0; 
} 
