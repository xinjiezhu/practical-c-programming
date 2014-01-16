/* mshell.c */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define COMMAND_SIZE 256
#define COMMAND_NUM 10

void do_cd(char *argv[]);
void execute_new(char *argv[]);

int main()
{
    char *cmd=(char *)malloc(COMMAND_SIZE*sizeof(char));
    char *cmd_arg[COMMAND_NUM] = {NULL};
    int cmdlen = 0;
    int i = 0;
    int j = 0;
    int tag = 0;

    do
    {
        /*initialize command */
        memset(cmd, 0, COMMAND_SIZE);
        
        printf("-=Mini Shell=-*| ");
        fgets(cmd,COMMAND_SIZE,stdin);
        cmdlen = strlen(cmd);
        cmd[cmdlen-1]='\0';   /*replace '\n' with '\0' */

        /*divide command with cmd_arg */
        for (i = 0; i < COMMAND_NUM; ++ i)
        {
            cmd_arg[i] = NULL;
        }
//        memset(cmd_arg, NULL, COMMAND_NUM);

        /*initialize */
        i=0; 
        j=0; 
        tag=0;
        
        while (i < cmdlen && j < COMMAND_NUM)
        {
            if (cmd[i]==' ')
            {
                cmd[i]='\0';
                tag=0;
            }
            else
            {
                if (tag == 0)
                {
                    cmd_arg[j++] = cmd + i;
                }
                tag=1;
            }
            i++;
        }
        
        /*check input parameter whether less than 10 */
        if (j >= 10 && i < cmdlen)
        {
            printf("TOO MANY ARGUMENTS\n");
            continue;
        }
        
        /*command quit£ºexit Mini Shell */
        if (strcmp(cmd_arg[0],"quit")==0)
        {
            break;
        }
        
        /*command cd */
        if (strcmp(cmd_arg[0],"cd") == 0)
        {
            do_cd(cmd_arg);
            continue;
        }
        
        /*external command and application*/
        execute_new(cmd_arg);
    }while(1);
}
/*implement cd function */
void do_cd(char *argv[])
{
    if(argv[1]!=NULL)
    {
        if(chdir(argv[1])<0)
        switch(errno)
        {
             case ENOENT:
             printf("DIRECTORY NOT FOUND\n");
             break;
             case ENOTDIR:
             printf("NOT A DIRECTORY NAME\n");
             break;
             case EACCES:
             printf("YOU DO NOT HAVE RIGHT TO ACCESS\n");
             break;
             default:
             printf("SOME ERROR HAPPENED IN CHDIR\n");
        }
    }

}

/*execulate external command*/
void execute_new(char *argv[])
{
    pid_t pid;
    
    pid = fork();
    if (pid < 0)
    {
        printf("SOME ERROR HAPPENED IN FORK\n");
        exit(2);
    }
    else if (pid == 0)
    {
        if (execvp(argv[0],argv)<0)
        switch (errno)
        {
            case ENOENT:
            printf("COMMAND OR FILENAME NOT FOUND\n");
            break;
            case EACCES:
            printf("YOU DO NOT HAVE RIGHT TO ACCESS\n");
            break;
            default:
            printf("SOME ERROR HAPPENED IN EXEC\n");
        }
        exit(3);
    }
    else
    {
        wait(NULL);
    }
}
