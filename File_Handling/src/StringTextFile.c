/*
 * StringTextFile.c
 *
 *  Created on: 5 Nov 2019
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *fpnt;
char cvar;

  setbuf(stdout, NULL);

  /* ---------------- Create texfile store text --------------------- */
  printf("\n Enter a line of text (end by RETURN): ");

  /* open textfile for write */
  fpnt=fopen("TEXTFILE.TXT","wt");

  /* put character to textfile */
  while( (cvar = getchar())!= '\n'){
		putc(cvar, fpnt);
  }
  putc('\n', fpnt);

  /* close textfile */
  fclose(fpnt);
  /* -------------- Expand the textfile --------------------------- */
  printf("\n Add a second line to the file (end by RETURN): ");

  /* open textfile for append */
  fpnt=fopen("TEXTFILE.TXT","at");

  /* put character to textfile */
  while((cvar = getchar())!= '\n'){
		putc(cvar, fpnt);
  }
  putc('\n', fpnt);

  /* close textfile */
  fclose(fpnt);

  /* ------------- Read entire contents of textfile ---------------- */
  printf("\n Reading all characters from textfile \n");

  /* open textfile for read */
  if((fpnt=fopen("TEXTFILE.TXT","rt"))==NULL){
		printf("\n Cannot find the file!");
		exit(1);
  }

  /* copy all characters from textfile to screen*/
//  while((cvar = getc(fpnt))!=EOF){
//		putchar(cvar);
//  }
  char temp_text[80];
  char *cpnt;
  while(!feof(fpnt))
  {
	  cpnt = fgets(temp_text,80,fpnt);
	  if(cpnt != NULL)
	  {
		  printf("%s",cpnt);
	  }
  }


  /* close textfile */
  fclose(fpnt);

return 0;
}
