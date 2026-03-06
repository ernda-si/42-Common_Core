// //This file is given at the exam

// #include <stdio.h>
// #include <malloc.h>
// #include <stdlib.h>
// #include <ctype.h>

// typedef struct node {
//     enum {
//         ADD,
//         MULTI,
//         VAL
//     }   type;
//     int val;
//     struct node *l;
//     struct node *r;
// }   node;

// node    *new_node(node n)
// {
//     node *ret = calloc(1, sizeof(n));
//     if (!ret)
//         return (NULL);
//     *ret = n;
//     return (ret);
// }

// void    destroy_tree(node *n)
// {
//     if (!n)
//         return ;
//     if (n->type != VAL)
//     {
//         destroy_tree(n->l);
//         destroy_tree(n->r);
//     }
//     free(n);
// }

// void    unexpected(char c)
// {
//     if (c)
//         printf("Unexpected token '%c'\n", c);
//     else
//         printf("Unexpected end of file\n");
// }

// int accept(char **s, char c)
// {
//     if (**s == c)
//     {
//         (*s)++;
//         return (1);
//     }
//     return (0);
// }

// int expect(char **s, char c)
// {
//     if (accept(s, c))
//         return (1);
//     unexpected(**s);
//     return (0);
// }

// static node *parse_val(char **s);
// static node *parse_multi(char **s);
// static node *parse_plus(char **s);

// node    *parse_expr(char *s)
// {
//     char *p = s;
//     node *ret = parse_plus(&p);
//     if (!ret)
//         return NULL;
//     if (*p) 
//     {
//         unexpected(*p);
//         destroy_tree(ret);
//         return (NULL);
//     }
//     return (ret);
// }

// static node *parse_val(char **s)
// {
//     if (isdigit((unsigned char)**s))
//     {
//         node n = { .type = VAL, .val = **s - '0', .l = NULL, .r = NULL };
//         (*s)++;
//         return new_node(n);
//     }
//     if (accept(s, '('))
//     {
//         node *res = parse_plus(s);
//         if (!res)
//             return NULL;
//         if (!expect(s, ')'))
//         {
//             destroy_tree(res);
//             return NULL;
//         }
//         return res;
//     }
//     unexpected(**s);
//     return NULL;
// }

// static node *parse_multi(char **s)
// {
//     node *left = parse_val(s);
//     if (!left)
//         return NULL;
//     while (accept(s, '*'))
//     {
//         node *right = parse_val(s);
//         if (!right)
//         {
//             destroy_tree(left);
//             return NULL;
//         }
//         node n = { .type = MULTI, .l = left, .r = right };
//         left = new_node(n);
//         if (!left)
//             return NULL;
//     }
//     return left;
// }

// static node *parse_plus(char **s)
// {
//     node *left = parse_multi(s);
//     if (!left)
//         return NULL;
//     while (accept(s, '+'))
//     {
//         node *right = parse_multi(s);
//         if (!right)
//         {
//             destroy_tree(left);
//             return NULL;
//         }
//         node n = { .type = ADD, .l = left, .r = right };
//         left = new_node(n);
//         if (!left)
//             return NULL;
//     }
//     return left;
// }

// int eval_tree(node *tree)
// {
//     switch (tree->type)
//     {
//         case ADD:
//             return (eval_tree(tree->l) + eval_tree(tree->r));
//         case MULTI:
//             return (eval_tree(tree->l) * eval_tree(tree->r));
//         case VAL:
//             return (tree->val);
//     }
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//         return (1);
//     node *tree = parse_expr(argv[1]);
//     if (!tree)
//         return (1);
//     printf("%d\n", eval_tree(tree));
//     destroy_tree(tree);
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdlib.h>

// int ft_popen(const char *file, char *const argv[], char type)
// {
//     if (!file || !argv || (type != 'r' && type != 'w'))
//         return (-1);
//     int fd[2];
//     if (pipe(fd) < 0)
//         return (-1);
//     pid_t pid = fork();
//     if (pid < 0)
//     {
//         close (fd[0]);
//         close (fd[1]);
//         return (-1);
//     }
//     if (pid == 0)
//     {
//         if (type == 'r')
//         {
//             close(fd[0]);
//             if (dup2(fd[1], STDOUT_FILENO) < 0)
//                 exit(-1);
//         }
//         else
//         {
//             close (fd[1]);
//             if (dup2(fd[0], STDIN_FILENO) < 0)
//                 exit(-1);
//         }
//         close(fd[0]);
//         close(fd[1]);
//         execvp(file, argv);
//         exit(-1);
//     }
//     if (type == 'r')
//     {
//         close(fd[1]);
//         return (fd[0]);
//     }
//     else
//     {
//         close(fd[0]);
//         return (fd[1]);
//     }
// }

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// int picoshell(char **cmds[])
// {
//     int i = 0;
//     int fd[2];
//     int in_fd = 0;
//     int ret = 0;
//     pid_t pid;
//     int status;

//     while (cmds[i])
//     {
//         if (cmds[i + 1] && pipe(fd) == -1) return 1;
//         if (!cmds[i + 1]) fd[0] = fd[1] = -1;

//         pid = fork();
//         if (pid < 0)
//         {
//             if (fd[0] != -1) close(fd[0]);
//             if (fd[1] != -1) close(fd[1]);
//             if (in_fd != 0) close(in_fd);
//         }

//         if (pid == 0)
//         {
//             if (in_fd != 0)
//             {
//                 if (dup2(in_fd, 0) == -1) 
//                     exit(1);
//                 close(in_fd);
//             }
//             if (fd[1] != -1)
//             {
//                 if (dup2(fd[1], 1) == -1)
//                     exit(1);
//                 close(fd[1]);
//                 close(fd[0]);
//             }
//             execvp(cmds[i][0], cmds[i]);
//             exit(1);
//         }
        
//         if (in_fd != 0) close(in_fd);
//         if (fd[1] != 0) close(fd[1]);
//         in_fd = fd[0];
//         i++;
//     }

//     while (wait(&status) > 0)
//     {
//         if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
//             ret = 1;
//     }
//     return ret;
// }

int picoshell(char **cmds[])
{
    int status;
    int fd[2];
    int ret = 0;
    int i = 0;
    int in_fd = 0;

    while (cmds[i])
    {
        if (cmds[i + 1] && pipe(fd) == -1)
            return 1;
        if (!cmds[i + 1])
            fd[0] = fd[1] = -1;
        
        pid_t pid = fork();
        if (pid < 0 )
        {
            if (fd[0] != -1)
                close(fd[0]);
            if (fd[1] != -1)
                close(fd[1]);
            if (in_fd != -1)
                close(in_fd);
        }
        if (pid == 0)
        {
            if (in_fd != -1)
            {
                if (dup2(in_fd, 0) < 0)
                    exit(-1);
                close(in_fd);
            }
            if (fd[1] != -1)
            {
                if (dup2(fd[1], 1) < 0)
                    exit(-1);
                close(fd[0]);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(-1);
        }
        if (fd[1] != -1)
            close(fd[1]);
        if (in_fd != -1)
            close(in_fd);
        in_fd = fd[0];
        i++;

    }
    while (wait(&status) > 0)
    {
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
