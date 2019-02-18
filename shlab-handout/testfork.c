#include "csapp.h"
void sigchld_handler(int sig){
	pid_t pid;
	pid = Waitpid(-1, NULL, 0);
	printf("Receive SIGCHLD signal from process %d\n", (int)pid);
	return;	
}
int main(){
	pid_t pid;
	Signal(SIGCHLD, sigchld_handler);

	if((pid = Fork()) == 0){
		printf("Creat a new process %d\n", (int)getpid());
		Sleep(1);
		exit(0);
	}else{
		pid = Waitpid(pid, NULL, 0);
		printf("Reaped the process %d\n", (int)pid);
	}
	return 0;

}
