#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;//end struct student

void GetStudent( struct student child[][10], int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    GetStudent( children, &group ) ;
    return 0 ;
}//end function

void GetStudent( struct student child[ ][ 10 ], int *room ) {
    printf( "Enter Room: " ) ;
    scanf( "%i", room ) ;

    for ( int i = 0; i < *room; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            printf( "Enter Name Student [%i][%i]: ", i + 1, j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
        }//end for loop
    }//end for loop
    
    for ( int k = 0; k < *room; k++ ) {
        for ( int l = 0; l < 10; l++ ) {
            printf( "Name Student [%i][%i]: %s \n", k + 1, l + 1, child[ k ][ l ] ) ;
        }//end for loop
    }//end for loop
}//end function
