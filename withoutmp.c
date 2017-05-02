/*objective:
matrix multiplication in dynamic way
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>
int main()
{
int **a,**b,**c;
//int c[3][3];
int a_r,a_c,b_r,b_c;
clock_t start,end; /* variables to store time difference between
start of paralleization and end of parallelization */
double dif; /*variable to calculate the time difference between the parallelization */
int i,j,k;
//clrscr();
again:
printf("\nenter rows and columns for matrix one:");
scanf("%d%d",&a_r,&a_c);
printf("\nenter rows and columns for matrix two:");
scanf("%d%d",&b_r,&b_c);
if(a_c!=b_r )
{
printf("\ncan not multiply");
goto again;
}
/* allocate memory for matrix one */
a=(int **) malloc(10*a_r);
for( i=0;i<a_c; i++)
{
a[i]=(int *) malloc(10*a_c);
}
/* allocate memory for matrix two */
b=(int **) malloc(10*b_r);
for( i=0;i<b_c; i++)

{
b[i]=(int *) malloc(10*b_c);
}
/* allocate memory for sum matrix */
c=(int **) malloc(10*a_r);
for( i=0;i< b_c; i++)
{
c[i]=(int *) malloc(10*b_c);
}
printf("Initializing matrices...\n");
printf("Hello");
start =clock(); //start the timer
//initializing first matrix
for(i=0;i<a_r; i++)
{
for(j=0;j<a_c; j++)
{
a[i][j] = i+j;
}
}
// initializing second matrix
for(i=0;i<b_r; i++)
{
for(j=0;j<b_c; j++)
{
b[i][j] = i*j;
}
}
/*initialize product matrix */
for(i=0;i<a_r; i++)
{
for(j=0;j< b_c; j++)
{
c[i][j]=0;
}
}
/* multiply matrix one and matrix two */
for(i=0;i<a_r; i++)
{
for(j=0;j<a_c; j++)
{
for(k=0;k<b_c; k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}

printf("******************************************************\n");
printf ("Done.\n");
end= clock(); //end the timer
dif = ((double) (end - start)) / CLOCKS_PER_SEC; //store the difference
printf("Parallelization took %f sec. time.\n", dif);
/*free memory*/
for(i=0;i<a_r; i++)
{
free(a[i]);
}
free(a);
for(i=0;i<a_c; i++)
{
free(b[i]);
}
free(b);
for(i=0;i<b_c; i++)
{
free(c[i]);
}
free(c);
}