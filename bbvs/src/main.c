/*

Name:   main.c                                                       
                                                                           
Purpose:                                         

*/

#include "bbvs.h"


int main(int argc, char **argv)
{
  ResultCode result = FAILURE;
  Chain *chain = NULL;
  vote_data_t votes[MAX_VOTES];

  result = init_chain(&chain);
  if (result == FAILURE)
  {
    // LOG("Failed to init chain");
  }

  free(chain);
  return 0;
} /* main */
