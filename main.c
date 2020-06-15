#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


bool chekEquality(float a,float b)
{    /* 
         This fuction checks about the equality of float variables
         upto five (5) decimal places.

         Args:
         a,b - input to check the equality of float variables upto 
         		five(5) decimal places. 

	*/
     float EPSL = 0.00001;
	 return (abs(a-b)<=EPSL);

}

float* solveBySubstitution(float a, float b,float c,float p,float q,float r)
{

		/*
			This function solves the simultanious equations using
			substitution method.

			Args:
			a,b,c - These are the coefficient of 
					ax + by = c form of equation 1.

			p,q,r - These are the coefficient of 
					px + qy = r form of equation 2.
 

		*/


		printf("----------------------------------------------\v\n");

		printf("Solving by Substitution Method\v\n");

		printf("Substituting y = ((c-ax)/b) in equation 2, we get\n");

		float x2 = ((b*r-q*c)/(b*p-a*q));\
		float y2 = ((c-a*x2)/b);
		printf("x = %f\n",x2);
	 	printf("y = %f\v\n",y2);
		printf("----------------------------------------------\v\n");
	 	float retArray[]={x2,y2};
	 	float *retPoint = retArray; 
	 	return retPoint;

}

void printEquations(float a, float b,float c,float p,float q,float r)
{

		/*
			This function prints two simultanious equations in the linear system.

			Args:
			a,b,c - These are the coefficient of 
					ax + by = c form of equation 1.

			p,q,r - These are the coefficient of 
					px + qy = r form of equation 2.
 

		*/



 printf("----------------------------------------------\n");
 printf("\vThe simultaneous equations are given as:\v\n");
 printf("%.2fx + %.2fy = %.2f\n",a,b,c );
 printf("%.2fx + %.2fy = %.2f\v\n",p,q,r );
 printf("----------------------------------------------\v\n");
 return;	
}


float calculateDet(float a,float b,float p,float q)
{

		/*
			This function calculates the determinant of a 2*2 matrix.

			Args:
			a,b,p,q - these are values of 2*2 matrix given as
					  | a  b |
					  | p  q |

			
		*/

	return (a*q)-(b*p);
}

void printDet(float det)
{
	printf("-------------------------------------------------\n");
	printf("|Determinant of a Matrix M1 is equal to : %.3f|\n",det);
	printf("-------------------------------------------------\v\n");
	return;
}


float* solveByMatrix(float a, float b,float c,float p,float q,float r)
{

		/*
			This function solves the simultanious equations using
			Matrix method.

			Args:
			a,b,c - These are the coefficient of 
					ax + by = c form of equation 1.

			p,q,r - These are the coefficient of 
					px + qy = r form of equation 2.
 

		*/
 printf("----------------------------------------------\v\n");


	 printf("Solving by Matrix Method\v\n");

	 printf("| a  b |    | x |    | b |\n");
	 printf("|      | *  |   | =  |   |\n");
	 printf("| p  q |    | y |    | r |\n\v");
	 printf("   M1         M2       M3\v\n");

    float a1,b1,c1,d1,det;
    det = calculateDet(a,b,p,q);
    //finding the inverse of M1
    a1=(q/det); b1= -(b/det); c1= -(p/det); d1= (a/det);

    printf("The inverse of M1 is given as :\n");
	printf(" %.3f  %.3f    \n\n",a1,b1);
    printf(" %.3f  %.3f   \n\v",c1,d1);

    printf("The result of Inv(M1)*M3 is given as :\n" );
    float x1,y1;
    x1 = a1*c + b1*r;
    y1 = c1*c + d1*r;
	printf(" %f\n\n",x1);
    printf(" %f\n\v",y1);

    printf("The results are x = %f and y = %f\n",x1,y1 );
 	float retArray[]={x1,y1};
 	float *retPoint = retArray; 
 	return retPoint;


}

int roundoff(float a)
{
	return (int)(a>0 ? a+0.5 : a-0.5);
}


void plotGraph(float a, float b,float c,float p,float q,float r,float  x1,float y1)
{
		/*
			This function plots the graph of the simultanious equations.

			Args:
			a,b,c - These are the coefficient of 
					ax + by = c form of equation 1.

			p,q,r - These are the coefficient of 
					px + qy = r form of equation 2.

			x1,y1 - The intersection co-ordinates of lines.			
 

		*/


 printf("----------------------------------------------\v\n");

 printf("NOTE : '*' (if present) shown in graph represents intersection point \n\n");
  
		int i,j;
        printf("The graph can be given as :\n");
        int mat[22][22];
        int x,xs,y,ys;
        for(i=0;i<22;i++)
        {
        	for(j=0;j<22;j++)
        	{   
        		mat[i][j]=0;
        	}
        }
        x1 = roundoff(x1);
        y1 = roundoff(y1);
        y = y1+10;
        ys =y;
        int count =0;
        for(i=0;i<20;i++)
        {
	        x = roundoff((float)((c-b*y)/a));
	        xs = roundoff((float)((r-q*ys)/p));
	        if(abs(x1-x)<=10)
	        {  int xCor = roundoff(10-(x1-x)) ;               
               if(mat[i][xCor]==0)
               mat[i][xCor]=1;
               else
               	mat[i][xCor]=4;
	        }
	        if(abs(x1-xs)<=10)
	        {   int xCor = roundoff(10-(x1-xs));	        	
                if(mat[i][xCor]==0)
	        		mat[i][xCor]=2;
	            else
	            	mat[i][xCor]=4;
	        	count++;
	        }

	        y--;
	        ys--;

        }

        for(i=0;i<20;i++)
        {
        	for(j=0;j<20;j++)
        	{
        		if(j==0||j==19)
        		 	printf("|" );

        	    if(mat[i][j]==1)
        			printf("1");
        		else if(mat[i][j]==2)
        			{printf("2");

        			count--;
        			}
    			else if(mat[i][j]==4)
    				printf("*");
        	    else
        			printf(" ");
        	}

        	printf("\n");
        }

        return;
}



int main()
{
 float a,b,c,p,q,r,x,y;
 printf("Enter a,b and c of ax+by=c\n");
 scanf("%f%f%f",&a,&b,&c);
 printf("Enter p,q and r of px+qy=r\n");
 scanf("%f%f%f",&p,&q,&r);

 printEquations(a,b,c,p,q,r);

 
float det =calculateDet(a,b,p,q) ;

if(det==0)
	{   
		printDet(0);
		printf("The given system of equations is either inconsistent or dependent\n");
		printf("Hence NO UNIQUE SOLUTION EXISTS!\n");
		plotGraph(a,b,c,p,q,r,0,0);

	}
else{
   		printDet(det);
        
   		float *subsResult;
   		float *matrixResult;
   		//call to solve by matrix method
        matrixResult = solveByMatrix(a,b,c,p,q,r);
        float x1 = *matrixResult;
        float y1 = *(matrixResult+1);
        
        //call to solve by substitution method
        subsResult = solveBySubstitution(a,b,c,p,q,r);
        float x2 = *subsResult;
        float y2 = *(subsResult+1);
	 	
	 	if( chekEquality(y1,y2) && chekEquality(x1,x2))
		printf("COMPARISON : We get same values for x and y in both the methods\n");
		else
		printf("COMPARISON : We get different values for x and y in both the methods\n\n");
        


        plotGraph(a,b,c,p,q,r,x1,y1);

   }


 }