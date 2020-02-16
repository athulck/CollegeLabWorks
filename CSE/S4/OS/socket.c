#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <process.h>


void main() {

	/* creating a socket
		AF_INET             IPv4
		SOCK_STREAM         TCP                 */ 
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd == -1) {
		printf("\nError creating socket! Exitting ... ");
		exit(0);
	}

	int setsockopt(sockfd, SOL_SOCKET, int optname, const void *optval, socklen_t optlen);

}

connect()

send()
recv()

close()