#include "unity.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

char *names[]={
  "Ali",
  "David",
  "Zhe Hao",
  "Jane"
};

/*void throwError(char *msg,int errorCode){
  Exception *ex = (excepion malloc());
  ex->errorCode = errorCode;
  ex->errorMs = msg;
  Throw(ex);
}*/

char *getName(int index){
  if(index >= 4)
    Throw("Error : Out of Bound of the array.");
    return names[index];
}

/*char *getName2(int index){
  if(index >= 4)
    throwError("Error : Out of Bound of the array.");
    return names[index];
}*/

void test_Exception_Given_1_Expect_error_code(void)
{
    CEXCEPTION_T  e;
    char *name;

    Try{
      name = getName(5);
      //printf("Name is : %s",name);
      TEST_ASSERT_EQUAL_STRING("David",name);
    }Catch(e){
      printf("Error code : %d",e);
      TEST_FAIL_MESSAGE(e);
    }
}

void test_Exception_Given_1_Expect_Print_error_message(void)
{
    CEXCEPTION_T  e;
    char *name;

    Try{
      name = getName(0);
      printf("Name is : ");
      //TEST_FAIL_MESSAGE("Exceptied ERR_OUT_OF_BOUND to be thrown ,but none");
    }Catch(e){
      //printf("Error code : %d",e);
    }
}
