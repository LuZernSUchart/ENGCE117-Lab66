#include <stdio.h>
#include <string.h>

void explode( char str1 [ ], char splitter, char out[ ][ 10 ] ) ;

int main() {
    char out[ 20] [ 10 ] ;
    int num ;
    explode( "I/Love/You", '/', out ) ;
    return 0 ;
}//end function

void explode( char str1[ ], char splitter, char out[ ][ 10 ] ) {
    int j = 0 ;
    int k = 0 ;
    for ( int i = 0; str1[i] != '\0'; i++ ) {
        if ( str1[ i ] == splitter ) {
            out[ j ][ k ] = '\0' ;
            j++ ;
            k = 0 ;
        } else {
            printf( "%c", str1[ i ] ) ;
            out[ j ][ k ] = str1[ i ] ;
            k++ ;
        }//end if else
    }//end for loop
    printf( "\n\n" ) ;
    for ( int i = 0; i <= j; i++ ) {
        printf( "Str2[%i] :%s\n", i, out[ i ] ) ;
    }//end for loop
}//end function
