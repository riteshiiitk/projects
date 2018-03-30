 
 
    
      #include <stdio.h>
      #include <stdlib.h>
      #include <math.h>
      #include <string.h>
      
     
       int   row,col;
       int   *image; 
       void  input_image(char *, int, int); 
       void  build_output (int, int, char*); 
       
       #include "myfunction_pgm.c"
       #include "rccount.c"

 
    /* ---------------------------------------------------------- */ 
       
        int main(int argc,char* argv[])
                         {
                          int *x;
                          int i,j;

                          x=(int*)malloc(2*sizeof(int));
                          count_rc(argv[1]);              /* the pgm file is given as input ; returns #row, #col */
                          printf("Row= %d, Col=%d", row,col); 
                          image=(int*)malloc(row*col*sizeof(int));
                           
                           input_image(argv[1],row,col);   
                           /* -------------------------------- */ 
                                for(i=0;i<row;i++)
                                 for(j=0;j<col;j++)
                                  {
                                    *(image+i*col+j) = 255 - *(image+i*col+j);  
                                   }
                           /* -------------------------------- */ 
		           build_output(row, col, argv[1]);  
		           return 0;
		          }
		  
    /* ---------------------------------------------------------------------- */ 



    /* ----------------------------------------------------------------------------------------------- */ 
        void input_image(char *s,int r,int c)
                        {
                          FILE *fp;
                          int line_count=0;
                          int row=0,col=0;
                          unsigned char ch;
                          int i,j;
                         /*---------- open the image file -----------*/
                          fp=fopen(s,"rb");
                          
                          while(fread(&ch,sizeof(ch),1,fp)==1) /* read all values and place in mat */
                             {
                               if(ch=='\n') line_count++;
                                if(line_count==4) break;
                              }
                           while( fread(&ch,sizeof(ch),1,fp)==1)
                                {
                                  *(image+row*c+col)=ch;
                                     col++;
                                    if(col>(c-1)) /* matrix building */
                                      {col=col%c;
                                       row=(row+1)%r;}
                                 }
                             fclose(fp);
                         } /*func. end*/

       /* ------------------------------------------------------------------------------------------------ */ 
        void build_output (int r,int c, char* s) /* construct the image  from bdata */
                     {
                          FILE *fp1,*fp2;
                          int red,green,blue,line_count=0,row=0,col=0;
                          int i,j,mydata;
                          unsigned char ch;
                          char t[200],u[200];
                          int d,m;
                          char *mystring ="-demo.pgm"; 	/* output image name*/
			  
                          build_my_file(r,c);                   /* to make myfile.dat */
                          /* -------------------------------- */
                          for(i=strlen(s)-1;i>=0;i--)
                           {
                            if (s[i]=='.' ) break;  		/* to reflect the input image name to output */
                           }

                          for(j=0;j<i;j++)
                           { t[j]=s[j]; u[j]=s[j]; }

                          t[j]='\0'; u[j]='\0';
                         /* --------------------------------- */
                          strcat(t,mystring);
			  fp2=fopen("myfile.dat","rb"); /* contains the header lines of the image */
                          fp1=fopen(t,"wb+");           /* update t if needed- to change name     */
                          while(fread(&ch,sizeof(ch),1,fp2)==1)
                          fwrite(&ch,sizeof(ch),1,fp1);

                          for(i=0;i<r;i++)
                          for(j=0;j<c;j++)
                           {
                            mydata=*(image+i*c+j);     
                            fwrite(&mydata,sizeof(ch),1,fp1);
                              }
                          
			  fclose(fp2);
                          fclose(fp1);
	                 } /*func. end*/

         /* ------------------------------------------------------------------------------------------------------------- */ 




