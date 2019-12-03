/**
    main.cpp
    Purpose: Launch the app, in charge of execute the test
             in the application.

    @author SANTOS Daniel, Quintana Gonzalo, Méry Andy
    @version 1.0 23/11/2019
*/
#include<iostream>
#include<chrono>
#include<memory>
#include<string.h>

#include"test/test.cpp"
static const char* OP1 = "WITH_FLYWEIGHT";
static const char* OP2 = "WITHOUT_FLYWEIGHT";

int main( int argc, char *argv[] )
{
  auto t1 = chrono::high_resolution_clock::now();
  if( argc <= 2)
  {
    printf("You must specify an option to execute the program, \
read the readme for more details.\n");
    return 0;
  }
  Test::MAXS = atol( argv[2] );
  if( Test::MAXS <= 0){
    printf("provide a valid NUM_SOLDIERS, this number should be >= 1 \n");
    return 0;
  }
  if( strcmp (argv[1], OP1) == 0)
  {
    Test::withFlyWeight();
  }else if( strcmp (argv[1], OP2) == 0)
  {
    Test::withoutFlyWeight();
  }else
  {
    printf("Your option %s is not supported,\n\
the only options supported are:\n\
1- %s\n2- %s\n", argv[1], OP1, OP2);
  }
  auto t2 = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> fp_ms = t2 - t1;
  auto int_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
  chrono::duration<long, micro> int_usec = int_ms;
  printf("\t\tTime Consumed: %f ms\n", fp_ms.count());
  return 0;
}
