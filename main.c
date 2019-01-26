#include "ssh.h"

int main(int argc, char ** argv){
char path[500];
char tmp [200];
char *commande[2];


while(1) {
    printf("\n> %s @: ",getenv("PWD"));
    int comdcounter=0;
    int commd_nbr=1;
    for (int k = 0; k < commd_nbr; ++k)
     {//pour recevvoire les donnés maintant probléme pour les traiter + condition d arret
        signal(EOF, signal_handler);
        scanf("%s", tmp);
        signal(EOF, signal_handler);
        signal(EOF, signal_handler);
        if (strcmp(tmp, "\\n") == 0)break;
        commande[k] = (char *) malloc(strlen(tmp) + 1);
        strcpy(commande[k], tmp);
        comdcounter++;
        
			if (k==0 && strcmp(commande[k], "readf") == 0 )//	ICI AJOUTE TOUTES LES FONCTION ET CHAQUE FOIX CHANGE LE NOBRE DES ARS A
			//AJOUTER A commd_nbr
			{
				commd_nbr++;	
			}
			
    }


    for (int j = 0; j < comdcounter; ++j) {


        if (strcmp(commande[j], "readf") == 0) {
            int g;
            g = readfile(commande[j + 1]);
            j++;
            continue;
        }
        if (strcmp(commande[j], "^D") == 0) {
            pid_t n= getppid();
            kill(n, SIGINT);
                }

        if (strcmp(commande[j], "makedir") == 0) {
            makedir(commande[j + 1]);
            j++;
            continue;
        }

        if (strcmp(commande[j], "ls") == 0) {
            ls();
            continue;
        }

        if (strcmp(commande[j], "pwd") == 0) {
            pwd(path);
            continue;
        }
        if (strcmp(commande[j], "cd") == 0) {
            cd(commande[j + 1]);
            continue;
        }

        if (strcmp(commande[j], "time") == 0) {
            nowtime();
            continue;
        }

        if (strcmp(commande[j], "whoami") == 0) {
            termtty();
            continue;
        }

        if (strcmp(commande[j], "newname") == 0) {
            if (newname(commande[j + 1], commande[j + 2]) != 0)
                printf("renaming failed \n");
            j += 2;
            continue;
        }

        if (strcmp(commande[j], "copy") == 0) {
            int b = copy(commande[j + 1], commande[j + 2]);
            if (b) { printf("copy error\n"); }
            j += 2;
            continue;
        }

        free(commande[j]);
    }

    signal(EOF, signal_handler);
}

// pid_t n= getppid();
//printf("page size %d\n",getpagesize());
//while (1){}


    return 0;
}
