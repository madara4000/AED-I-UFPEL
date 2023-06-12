
/*70. Climbing Stairs
Easy
17.3K
531
Companies
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

n=4
1.1 step+1step+1step+1step
2.1 step +1 step+2 step
3.
5
n= 1(5 1step
n=4*(1 2 3 de1)
=3 2 2 2 1
*/
#include <stdio.h>

int main()
{ int i,*pdegrau,anterior2,anterior1;
pdegrau=(int*) malloc(45*sizeof(int));
int n=1;
    if (n==1){
        printf("para %d passos tem %d possibilidades\n",n,n) ;
    }
    
     pdegrau[0]=1;
    

      pdegrau[1]=1;
    
    for (i = 2; i < 46; i++)
    { 
     
     anterior1=pdegrau[i-1];
     anterior2=pdegrau[i-2];
      pdegrau[i]=anterior1+anterior2;
       
     printf("para %d passos tem %d possibilidades\n",i,pdegrau[i]);
     
          

     }
    

    return 0;
}
