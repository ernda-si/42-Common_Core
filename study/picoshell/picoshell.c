/* Assignment name:    picoshell
Expected files:        picoshell.c
Allowed functions:    close, fork, wait, exit, execvp, dup2, pipe
___

Write the following function:

int    picoshell(char *cmds[]);

The goal of this function is to execute a pipeline. It must execute each
commands [sic] of cmds and connect the output of one to the input of the
next command (just like a shell).

Cmds contains a null-terminated list of valid commands. Each rows [sic]
of cmds are an argv array directly usable for a call to execvp. The first
arguments [sic] of each command is the command name or path and can be passed
directly as the first argument of execvp.

If any error occur [sic], The function must return 1 (you must of course
close all the open fds before). otherwise the function must wait all child
processes and return 0. You will find in this directory a file main.c which
contain [sic] something to help you test your function.
	

Examples: 
./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb/
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	count_pipes(char **av)
{
	int	count = 0;
	int	i = 0;

	while (av[i])
	{
		if (av[i][0] == '|' && av[i][1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int count_cmds(char **av)
{
	int i;

	i = 0;
	while (av[i] && !(av[i][0] == '|' && av[i][1] == '\0'))
		i++;
	return i;
}

int main(int ac, char **av)
{
	int     i;
	int		args;
	char    ***cmds;

	// av[] = {cmd1, arg1, arg2, NULL};
	i = 1;
	if (ac == 1)
		return 0;
	cmds = (char **)malloc(count_pipes(&av[1]) * sizeof(char **) + 1);
	while (av[i])
	{
		args = count_cmds(&av[1]);
		cmds[i] = (char *)malloc(args * sizeof(char *) + 1);
		for (int j = 0; j < args; j++)
			cmds[i][j] = av[j];
		printf("%d\n", args);
		break;
	}
}