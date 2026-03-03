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
#include <sys/wait.h>
#include <fcntl.h>

int picoshell(char **cmds[])
{
	int	i = 0;
	int	fd[2];
	int	in_fd = 0;
	int	ret = 0;
	pid_t pid;
	int	status;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1) 
			return 1;
		if (!cmds[i + 1])
		{
			fd[0] = -1;
			fd[1] = -1;
		}

		pid = fork();
		if (pid < 0)
		{
			if (fd[0] != -1)
				close(fd[0]);
			if (fd[1] != -1)
				close(fd[1]);
			if (in_fd != 0)
				close(in_fd);
			return 1;
		}

		if (pid == 0)
		{
			if (in_fd != 0)
			{
				if (dup2(in_fd, 0) == -1)
					exit(1);
				close(in_fd);
			}
			if (fd[1] != -1)
			{
				if (dup2(fd[1], 1) == -1)
					exit(1);
				close(fd[1]);
				close(fd[0]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

		if (in_fd != 0) close (in_fd);
		if (fd[1] != -1) close (fd[1]);
		in_fd = fd[0];
		i++;
	}

	while (wait(&status) > 0)
	{
		ret = 1;
	}
	return ret;
}

static int  count_cmds(char **av)
{
    int i = 0;
    int n = 1;

    while (av[i])
    {
        if (av[i][0] == '|' && av[i][1] == '\0')
            n++;
        i++;
    }
    return n;
}

static int  count_args_until_pipe(char **av)
{
    int n = 0;

    while (av[n] && !(av[n][0] == '|' && av[n][1] == '\0'))
        n++;
    return n;
}

int main(int ac, char **av)
{
    char ***cmds;
    int cmd_count;
    int i = 1;
    int c = 0;

    if (ac < 2)
    {
        write(2, "Usage: ./a.out cmd1 args... '|' cmd2 args... ...\n", 50);
        return 1;
    }

    cmd_count = count_cmds(&av[1]);
    cmds = malloc(sizeof(char **) * (cmd_count + 1));
    if (!cmds)
        return 1;

    while (av[i])
    {
        int argc_cmd = count_args_until_pipe(&av[i]);
        cmds[c] = malloc(sizeof(char *) * (argc_cmd + 1));
        if (!cmds[c])
            return 1;

        for (int j = 0; j < argc_cmd; j++)
            cmds[c][j] = av[i + j];
        cmds[c][argc_cmd] = NULL;

        c++;
        i += argc_cmd;

        if (av[i] && av[i][0] == '|' && av[i][1] == '\0')
            i++;
    }
    cmds[c] = NULL;

    int ret = picoshell(cmds);

    // libera só o array de ponteiros (os strings são do av original)
    for (int k = 0; cmds[k]; k++)
        free(cmds[k]);
    free(cmds);

    return ret;
}