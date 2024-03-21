#include <stdio.h>

char *reverse( char str1[ ] ) ;
char *reverse2( char str2[ ] ) ;

int main() {
    char texta[ 50 ] = "I Love You" ;
    char textb[ 50 ] = "Hello World" ;
    char *out ;
    char *out2 ;    
    out = reverse( texta ) ;
    printf( "\n" ) ;
    out2 = reverse2( textb ) ;

    return 0 ;
}//จบฟังกฺชั่น

char *reverse( char str1[ ] ) {
    int num = 0;
    while ( str1[ num ] != '\0' ) {
        num++ ;
    }//จบลูป

    for ( int i = 0, j = num - 1; i < j; i++, j-- ) {
        char save = str1[ i ] ;
        str1[ i ] = str1[ j ] ;
        str1[ j ] = save ;
    }//จบ for ลูป

    for ( int i = 0; i < num; i++ ) {
        printf( "%c", str1[ i ] ) ;
    }//จบ for ลูป

    return str1 ;
}//จบฟังค์ชั่น

char *reverse2( char str2[ ] ) {
    int num = 0 ;
    while ( str2[ num ] != '\0' ) {
        num++ ;
    }//จบ while ลูป

    for ( int i = 0, j = num - 1; i < j; i++, j-- ) {
        char save = str2[ i ] ;
        str2[ i ] = str2[ j ] ;
        str2[ j ] = save ;
    }//จบ for ลูป

    for ( int i = 0; i < num; i++ ) {
        printf( "%c", str2[ i ] ) ;
    }//จบ for ลูป

    return str2 ;
}//จบฟังก์ชั่น
