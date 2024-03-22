#include <stdio.h>
#include <string.h>

struct Human {
  char Name[50];
  int Age;
};

void PrintHuman(struct Human Arr[], int N);
void PrintHumanAboveAvg(struct Human Arr[], int N, float Avg ) ;
void Sort( struct Human Arr[] , int N, int Mode = 1 ) ;
float AverageAge(struct Human Arr[], int N) ;

int main() {
  int N = 8;
  
  struct Human Person[8];
  strcpy(Person[0].Name, "Tuu");
  strcpy(Person[1].Name, "Tum");
  strcpy(Person[2].Name, "Too");
  strcpy(Person[3].Name, "Toy");
  strcpy(Person[4].Name, "Tai");
  strcpy(Person[5].Name, "Tim");
  strcpy(Person[6].Name, "Tom");
  strcpy(Person[7].Name, "Tang");
  
  Person[0].Age = 18;
  Person[1].Age = 16;
  Person[2].Age = 17;
  Person[3].Age = 17;
  Person[4].Age = 21;
  Person[5].Age = 20;
  Person[6].Age = 20;
  Person[7].Age = 16;

  PrintHuman(Person, N); //!Sort
  Sort(Person, N, 1);
  PrintHuman(Person, N); //Sort 0-9 ASC
  Sort(Person, N, 2);
  PrintHuman(Person, N); //Sort 9-0 DESC
  
  
  float AVG = AverageAge(Person, N) ;
  printf("\nAverage Age = %.2f", AVG ) ;
  PrintHumanAboveAvg(Person, N , AVG ) ;
  
  return 0 ;
}

void PrintHuman(struct Human Arr[], int N) {
  int i = 0;
  printf("\tHuman : \n ");
  for (int i = 0; i < N; i++) {
    printf("%s (%d) ",Arr[i].Name, Arr[i].Age);
  }
  printf("\n");
}

void PrintHumanAboveAvg(struct Human Arr[], int N, float Avg) {
  int i = 0;
  printf("\n\tHuman : \n ");
  for (int i = 0; i < N; i++) if (Arr[i].Age > Avg) printf("%s (%d) ",Arr[i].Name, Arr[i].Age);
    
  printf("\n");
}

void Sort(struct Human Arr[], int N, int Mode) {
  int i = 0, j = 0;
  struct Human hold;
  
  
  for(i = 0; i < N; i++){
    for(j = i + 1; j < N; j++){
      if(Mode == 1) {
        if(Arr[i].Age < Arr[j].Age) {
          hold    = Arr[i];
          Arr[i]  = Arr[j];
          Arr[j]  = hold;
        }
      }else if(Mode == 2){
        if(Arr[i].Age > Arr[j].Age) {
          hold    = Arr[i];
          Arr[i]  = Arr[j];
          Arr[j]  = hold;
        }
      }
    }
  }
  
}

float AverageAge(struct Human Arr[], int N) {
  float Output = 0,Sum = 0;
  for(int i = 0 ; i < N; i++) {
    Sum += Arr[i].Age ;
  }
  Output = Sum / N ;
  return Output ;
}

