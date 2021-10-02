
/*

Name:   test_main.c                                                      
                                                                           
Purpose:  Define the UT functions.                                     

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/bbvs.h"


void test_example(void **state);


int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_example)
  };


  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_example(void **state)
{
  int result = example(100, 200);

  assert_int_equal(result, 20000);
}
