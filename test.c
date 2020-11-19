#include "header.h"
int main(int argc, char **argv)
{
        shell_loop();
return (0);
}
void shell_loop(void)
{
        int userinput;
        char **argv;
        char *buffer;
        size_t bufsize = 32;
        char *prompt = "& ";
	int status;

        while (!status)
        {
                buffer = malloc(sizeof(char) * bufsize);
                write(STDOUT_FILENO, prompt, stringlength(prompt));
                userinput = getline(&buffer, &bufsize, stdin);
                argv = tokenize(buffer);
		
        }
free(buffer);
free(argv);
}
int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
	}
return (0);
}
int stringlength(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
        {}
return (i);
}
char **tokenize(char *userinput)
{
        int token_inc = 0;
        char *tokenize;
        char **argv;
        int tokencount = 0;
        int i;

        strtok(userinput, "\n");
                for (i = 0; userinput[i] != '\0'; i++)
                {
                        if (userinput[i] == ' ')
                        {
                                tokencount++;
                        }
                }
                argv = malloc(8 * (tokencount + 2));
                if (argv != NULL)
                {
                        token_inc = 0;
                        tokenize = strtok(userinput, " ");
                        while (token_inc < (tokencount + 1))
                        {
                                argv[token_inc] = tokenize;
                                tokenize = strtok(NULL, " ");
                                printf("%s\n", argv[token_inc]);
                                token_inc++;
                        }
                }
return (argv);
}
int forkwaitexec(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failure\n");
	if (child_pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(&status);
	}
return (1);
}
