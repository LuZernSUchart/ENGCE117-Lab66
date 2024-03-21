#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ; //end struct student

void upgrade( struct student child ) ;

int main() {
    struct student aboy ;
    aboy.sex = 'M' ;
    aboy.gpa = 3.00 ;
    upgrade( aboy ) ;
    printf( "Old GPA :%.2f", aboy.gpa ) ;
    return 0 ;
}//end function

void upgrade( struct student child ) {
    if( child.sex = 'M' ) {
        child.gpa = child.gpa * 1.1 ;
        printf( "New GPA Male :%0.2f\n", child.gpa ) ;
    } else {
        child.gpa = child.gpa * 1.2 ;
        printf( "New GPA Female :%0.2f\n", child.gpa ) ;
    }//end if else
}//end function
