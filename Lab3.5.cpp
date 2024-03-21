#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;//end struct student

struct student ( *GetStudent( int *room ) )[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;
    children = GetStudent( &group ) ;
    return 0 ;
}//end function

struct student ( *GetStudent( int *room ) )[ 10 ] {
    struct student child[ 20 ][ 10 ] ;
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
