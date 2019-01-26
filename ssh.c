
#include "ssh.h"

void cd(char*newdir){
    chdir(newdir);
}

void ls(void){

    struct dirent *lecture;
    DIR *rep;
    rep = opendir("." );
    while ((lecture = readdir(rep))) {
        printf("%s\n", lecture->d_name);
    }
    closedir(rep);
}

void makedir (char* dirname){

int status = mkdir(dirname, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

char* pwd (char*path){

    getcwd(path, 500);
    printf("%s\n", path);
    return path;
}

int readfile (char* filename){
    FILE * fd = fopen(filename, "r");
    int countligne=0;
    if(!fd){
        perror("fopen");
        return 1;
    }

    char buff[500];
    char * ret;

    while(1)
    {
        ret = fgets(buff, 500, fd);

        if(!ret)
        {
            if( feof(fd) )
            {
                /* EOF all OK*/
                break;
            }
            else
            {
                /* Error */
                perror("fgets");
                return 1;
            }
        }

        /* USE your buff here */
        fprintf(stdout, "%d  %s",countligne++, ret );//countligne affiche aussi les ligne
    }

    fclose(fd);
}

void nowtime()

{
    struct tm *newtime;
    time_t ltime;

    time(&ltime);

    newtime = localtime(&ltime);

    printf("La Date et l'Heure sont  %s", asctime(newtime));
}

void termtty() {
    char *ret, tty[40];

    if ((ret = ttyname(STDIN_FILENO)) == NULL)
        perror("ttyname() error");
    else {
        strcpy(tty, ret);
        printf("The ttyname associated with my stdin is %s\n", tty);
    }

}

int copy(char* argv2,char*argv3)
{

        FILE * fdin = fopen(argv2, "r");

        if(!fdin){
            perror("fopen");
            return 1;
        }

        FILE * fdout = fopen(argv3, "w");

        if(!fdout){
            perror("fopen");
            return 1;
        }

        char buff[500];
        int cnt;
        while( (cnt = fread(buff, sizeof(char), 500, fdin)) != 0 )
        {
            if(cnt < 0)
            {
                perror("fread");
                return 1;
            }
            int ret = fwrite(buff, sizeof(char), cnt, fdout);
            if(ret < 0)
            {
                perror("fwrite");
                return 1;
            }
        }
        fclose(fdin);
        fclose(fdout);

}

void signal_handler(int signo){

    if (signo==EOF){

        printf("\n you have killed your shell");
       i
    }

}

int newname(char *argv2, char *argv3) {
    return rename(argv2, argv3);
}


