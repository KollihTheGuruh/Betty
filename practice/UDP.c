#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define CLIENT_HEADER "UDP Client 1"
#define SERVER_HEADER "UDP Server"

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buf[BUF_SIZE];

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(12345);
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP server listening on port 12345\n");

    // Receive and process messages
    while (1) {
        memset(buf, 0, BUF_SIZE);
        client_addr_len = sizeof(client_addr);

        // Receive message from client
        if (recvfrom(server_sock, buf, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len) < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        // Strip client header
        if (strncmp(buf, CLIENT_HEADER, strlen(CLIENT_HEADER)) == 0) {
            memmove(buf, buf + strlen(CLIENT_HEADER), strlen(buf) - strlen(CLIENT_HEADER));
        }

        // Display message in terminal
        printf("Received message from client: %s\n", buf);

        // Convert message to uppercase
        for (int i = 0; i < strlen(buf); i++) {
            buf[i] = toupper(buf[i]);
        }

        // Attach server header
        char send_buf[BUF_SIZE];
        memset(send_buf, 0, BUF_SIZE);
        sprintf(send_buf, "%s%s", SERVER_HEADER, buf);

        // Send message back to client
        if (sendto(server_sock, send_buf, strlen(send_buf), 0, (struct sockaddr *)&client_addr, client_addr_len) < 0) {
            perror("sendto failed");
            exit(EXIT_FAILURE);
        }

        printf("Sent message back to client: %s\n", buf);
    }

    close(server_sock);
    return 0;
}
