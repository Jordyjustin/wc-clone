#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	int opt = 0;
	char cflag=0, lflag = 0, wflag=0, *filename="";
	while((opt=getopt(argc, argv, "clw"))!=-1){
		switch(opt){
			case 'c': cflag = 1; break;
			case 'l': lflag = 1; break;
			case 'w': wflag = 1; break;
			default:
                fprintf(stderr, "Usage: %s [-c] [-l] [-w]\n", argv[0]);
                return 1;
		}
	}
	FILE *fl;
	if(optind >= argc){
		fl = stdin;
	}
	else{
		filename=argv[optind];
		fl = fopen(filename, "r");
		if(fl == NULL){
			fprintf(stderr, "ccwc: %s: %s\n", filename, strerror(errno));
			return 1;
		}
	}
	int c, words = 0, in_word = 0, lines=0;
	long bytes = 0;
    while ((c = fgetc(fl)) != EOF) 
    {
		bytes++;
        if (isspace(c)) 
        {
			if(c=='\n')
				lines+=1;
            if(in_word)
            {
                words++;
                in_word = 0;
            }
        } 
		else 
            in_word = 1;
    }
	if(!(wflag || cflag || lflag)){
		printf("%d %d %ld %s\n", lines, words, bytes, filename);
		return 0;
	}
	if(lflag)
		printf("%d ", lines);
	if(wflag)
		printf("%d ", words); 
	if(cflag)
		printf("%ld ", bytes);
	printf("%s\n", filename);
	fclose(fl);
}
