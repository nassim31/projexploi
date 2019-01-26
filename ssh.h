//
// Created by nassim on 17/01/19.
//

#ifndef PROJEXPLOI_SSH_H
#define PROJEXPLOI_SSH_H
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define _XOPEN_SOURCE

int readfile (char* filename);
void ls(void);
void makedir (char* dirname);

char* pwd (char*);
void cd(char*newdir);
void nowtime (void);
void termtty(void);
int copy(char*, char*);
int newname(char*, char*);

void signal_handler(int signo);

#endif PROJEXPLOI_SSH_H
