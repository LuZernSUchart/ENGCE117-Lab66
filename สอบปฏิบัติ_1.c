#include <stdio.h>

void GetAns( int firstnum[], int Secondnum[], char *Op, int Ans[] );
int main() {
  int A[6], B[6], Answer[7];
  char Operator[1];
  //input
  printf( "\tEnter Number A : \n" );
  printf( "\t A[0] : " );
  scanf( "%d", &A[0] );
  printf( "\t A[1] : " );
  scanf( "%d", &A[1] );
  printf( "\t A[2] : " );
  scanf( "%d", &A[2] );
  printf( "\t A[3] : " );
  scanf( "%d", &A[3] );
  printf( "\t A[4] : " );
  scanf( "%d", &A[4] );
  printf( "\t A[5] : " );
  scanf( "%d", &A[5] );
  printf( "\tEnter Number B : \n" );
  printf( "\t B[0] : " );
  scanf( "%d", &B[0] );
  printf( "\t B[1] : " );
  scanf( "%d", &B[1] );
  printf( "\t B[2] : " );
  scanf( "%d", &B[2] );
  printf( "\t B[3] : " );
  scanf( "%d", &B[3] );
  printf( "\t B[4] : " );
  scanf( "%d", &B[4] );
  printf( "\t B[5] : " );
  scanf( "%d", &B[5] );
  printf( "\tOperator : " );
  scanf( "%s", &Operator );
  GetAns( A, B, Operator, Answer );
  //output
  printf( "\n\n\tIndex\t\t x\t 0\t 1\t 2\t 3\t 4\t 5" );
  printf( "\n\n\tNumber A : \t\t %d\t %d\t %d\t %d\t %d\t %d", A[0], A[1], A[2], A[3], A[4], A[5] );
  printf( "\n\tOperator : \t\t\t\t\t\t\t\t %s", Operator );
  printf( "\n\tNumber B : \t\t %d\t %d\t %d\t %d\t %d\t %d", B[0], B[1], B[2], B[3], B[4], B[5] );
  printf( "\n\t\t\t--------------------------------------------------" );
  printf( "\n\tAnswer :  " );
  for ( int i = 0; i < 7; i++ ) {
{

    printf( "\t %d", Answer[i] );
}
  printf( "\n\t\t\t===================================================" );
  return 0;
}

void GetAns( int firstnum[], int Secondnum[], char *Op, int Ans[] ) {
  
  //decision
  switch ( *Op ) {
    //plus
    case '+' :
      Ans[6] = firstnum[5] + Secondnum[5];
      Ans[5] = firstnum[4] + Secondnum[4];
      Ans[4] = firstnum[3] + Secondnum[3];
      Ans[3] = firstnum[2] + Secondnum[2];
      Ans[2] = firstnum[1] + Secondnum[1];
      Ans[1] = firstnum[0] + Secondnum[0];
      Ans[0] = 0;
      //carry in number
      if ( Ans[6] > 9) {
        Ans[6] = Ans[6] - 10;
        Ans[5] = Ans[5] + 1;
      }

      if ( Ans[5] > 9) {
        Ans[5] = Ans[5] - 10;
        Ans[4] = Ans[4] + 1;
      }
      
      if ( Ans[4] > 9) {
        Ans[4] = Ans[4] - 10;
        Ans[3] = Ans[3] + 1;
      }
      
      if ( Ans[3] > 9) {
        Ans[3] = Ans[3] - 10;
        Ans[2] = Ans[2] + 1;
      }
      
      if ( Ans[2] > 9) {
        Ans[2] = Ans[2] - 10;
        Ans[1] = Ans[1] + 1;
      }
      
      if ( Ans[1] > 9) {
        Ans[1] = Ans[1] - 10;
        Ans[0] = 1;
      }
    break;
    
    //minus
    case '-' :
      Ans[6] = firstnum[5] - Secondnum[5];
      Ans[5] = firstnum[4] - Secondnum[4];
      Ans[4] = firstnum[3] - Secondnum[3];
      Ans[3] = firstnum[2] - Secondnum[2];
      Ans[2] = firstnum[1] - Secondnum[1];
      Ans[1] = firstnum[0] - Secondnum[0];
      Ans[0] = 0;
      //carry out number
      if ( Ans[6] < 0) {
        Ans[6] = Ans[6] + 10;
        Ans[5] = Ans[5] - 1;
      }

      if ( Ans[5] < 0) {
        Ans[5] = Ans[5] + 10;
        Ans[4] = Ans[4] - 1;
      }
      
      if ( Ans[4] < 0) {
        Ans[4] = Ans[4] + 10;
        Ans[3] = Ans[3] - 1;
      }
      
      if ( Ans[3] < 0) {
        Ans[3] = Ans[3] + 10;
        Ans[2] = Ans[2] - 1;
      }
      
      if ( Ans[2] < 0) {
        Ans[2] = Ans[2] + 10;
        Ans[1] = Ans[1] - 1;
      }
    break;
    default : break;
  }
}
