#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

  int buffer_size, fd, lus, ecrits, i;
  assert( argc>=2 );
  assert( (buffer_size=atoi(argv[1]))>0 );
  char buffer[buffer_size];
  
  if (argc==2) {
    while ((lus=read(STDIN_FILENO,buffer,buffer_size))>0 && lus != EOF){
      if ((ecrits=write(STDOUT_FILENO,buffer,lus))==-1) perror("write");
      assert(ecrits==lus);
    }
  }
  
  else{
    for (i=2;i<argc;i++){
      if ((fd=open(argv[i],O_RDONLY))==-1) perror(argv[i]);
      
      while ((lus=read(fd,buffer,buffer_size))>0){
        if ((ecrits=write(STDOUT_FILENO,buffer,lus))==-1) perror("write");
        assert(ecrits==lus);
      }
      
      if (close(fd)==-1) perror("close");
    }
  }
  return 0;
}
