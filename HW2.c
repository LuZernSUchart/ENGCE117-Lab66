#include <stdio.h>

int main() {
	int n = 0, i = 0;
	char runagian, mode, sort;
	
	printf ("\tInput max number : ");
	scanf ("%d", &n);
	printf ("\t[%d] : ", n);
	for (i = 1; i <= n; i++) {
	    printf ("%d ",i);
	}
//1'st state
	printf ("\n\tOdd/Even/Normal number (o/e/n) : ");
	while (1) {
    scanf ("%c", &mode);
  	if (mode == 'e') {
  	  printf ("\tEven Series :");
  	    for (i = 1; i <= n; i++) {
  	        if (i % 2 == 0) {
  	            printf (" %d", i);
  	            }
  	    }
  	    break;
  	} else if (mode == 'o') {
  	       printf ("\tOdd Series :");
  	        for (i = 1; i <= n; i++) {
  	            if (i % 2 != 0) {
  	                printf ( " %d", i);
  	            }
  	        }
  	        break;
  	}else if (mode == 'n') {
  	        printf ("\tNormal Series :");
  	        for (i = 1; i <= n; i++) {
  	            printf (" %d", i);
  	        }   
  	        break;
  	}
  }
  //2'rd state
  	printf ("\n\tDo you want ASC or DESC (a/z) : ");
  	while (1) {
      scanf ("%c", &sort);
    	if (sort == 'a') {
          if (mode == 'e') {
            printf ("\tEven Series :");
            for (i = 1; i <= n; i++) {
            	if (i % 2 == 0) {
            	  printf (" %d", i);
            	}
            }
            
          } else if (mode == 'o') {
            printf ("\tOdd Series :");
            for (i = 1; i <= n; i++) {
            	if (i % 2 != 0) {
            	  printf (" %d", i);
            	}
            }
            
          }else if (mode == 'n') {
            printf ("\tNormal Series :");
            for (i = 1; i <= n; i++) {
            	printf (" %d", i);
            }   
            
          }
    	    printf("\n\tASC mode.\n");
    	    break;
    	  } else if (sort == 'z') {
            if (mode == 'e') {
              printf ("\tEven Series :");
              for (i = n; i >= 1; i--) {
                if (i % 2 == 0) {
              	  printf(" %d", i);
              	}
              }
            } else if (mode == 'o') {
              printf ("\tOdd Series :");
              for (i = n; i >= 1; i--) {
              	if (i % 2 != 0) {
              	  printf (" %d", i);
              	}
              }
            }else if (mode == 'n') {
              printf ("\tNormal Series :");
              for (i = n; i >= 1; i--) {
              	printf (" %d", i);
              }   
            }
            printf ("\n\tDESC mode.\n");
      	  }
    	}
  	return 0 ;
	}


