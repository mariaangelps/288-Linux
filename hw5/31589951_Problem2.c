#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  int opt;
  while((opt=getopt(argc,argv,"cduf:s:"))!=-1){
    switch(opt) {
      case 'c':
        //printf("Option c: %c\n", opt); break;
      case 'd':
        //printf("Option d: %c\n", opt); break;
      case 'u':
        printf("Option: %c\n", opt); break;
      case 'f':
      case 's':
        printf("Option: %c\n", opt);
	printf("Type - Parameters:  %s\n",optarg);break;
      case ':':
        printf("missing option argument %c ",optopt); break;
      case '?':
        printf("unknown option: %c\n", optopt); break;
    }
  }
  for(; optind < argc; optind++)
    printf("Additional Arguments: %s\n", argv[optind]);
  exit(0);
}
