/*
 * C'est le fichier daemon de Miku ! 
 * J'espère que rien de susper va se produire ici ...
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

static void skeleton_daemon()
{ 
	pid_t pid;
	/* Fork off the parent process */
	pid = fork();

	/* An error occured ! (mon dieu) */ 
	if (pid<0)
		exit(EXIT_FAILURE);
	/* Success : let the parent terminate*/

	if (pid>0)
		exit(EXIT_SUCCESS);

	/* On success : The child process becomes session leader */

	if (setsid()<0)
		exit(EXIT_FAILURE);


	/* Set new file permissions */
	umask(0);

	/*Change the working directory to the root directory */ 
	/* or another appropriate directory*/ 

	chdir("/");

	/* Close all open file descriptors*/ 
	int x;
	for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
	{
		close(x);
	}

	/* Open the log file*/ 
	openlog ("MikuDaemon", LOG_PID, LOG_DAEMON);

}

int main()
{
	skeleton_daemon();
	while (1)
	{
		// Mettre le code du daemon ici !
		syslog (LOG_NOTICE, "Miku Daemon Lancé!");
		sleep(20);
		printf("Hello I'm Hatsune Miku, your virtual Bluetooth controller !\n");
		break;
	}
	syslog (LOG_NOTICE, "Miky Daemon fini!");
	closelog();
	return EXIT_SUCCESS;
}