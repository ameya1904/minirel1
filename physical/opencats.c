#include "../include/defs.h"
#include "../include/error.h"
#include "../include/globals.h"
#include <stdio.h>

#include<errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

off_t fsize(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}
int max(int a, int b){
  int max;
  if (a>b)
    max= a;
  else
    max= b;
  return max;
}

int readCat(char *path);
char* pathCreate();

int OpenCats()
{
  char path[MAX_PATH_LENGTH],*c;
	c=pathCreate();
  strcpy(path,c);
  readCat(path);
  return 0;
}

char* pathCreate(){
  char path[MAX_PATH_LENGTH],*c;
  strcpy(path,HOME_MINIREL);
  c=strcat(path,"/data/");
  c=strcat(c,CURR_DB);
	c=strcat(c,"/catalog/");
  c=strcat(c,RELCAT);
  return c;
}

int readCat(char *path){
  unsigned int *buffer;
  int slotsize,filesize,size;
  Page pg;
  slotsize=sizeof(pg.slotmap);
  FILE *fp=fopen(path,"rb");
  if(fp!=NULL){
    filesize=fsize(fp);
    size=max(filesize,PAGESIZE);
    fseek(fp,slotsize,SEEK_SET);
    buffer=(unsigned int*)malloc(PAGESIZE/sizeof(unsigned int));
    fread(buffer,sizeof(unsigned int),size/sizeof(unsigned int),fp);
    for(int i=0;i<PAGESIZE/sizeof(unsigned int);i++)
      printf("0x%x\n",buffer[i] );
  }
  else{
    printf("wer\n" );
  }
}
