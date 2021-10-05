
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

void test_new_vote_valid(void **state);
void test_init_chain_valid(void **state);
void test_new_block_valid(void **state);
void test_valid_proof_valid(void **state);
void test_proof_of_work(void **state);

int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_new_vote_valid),
      cmocka_unit_test(test_init_chain_valid),
      cmocka_unit_test(test_new_block_valid),
      cmocka_unit_test(test_valid_proof_valid),
      cmocka_unit_test(test_proof_of_work)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_new_vote_valid(void **state)
{
  vote_data_t voteData = {"1990112410089", 1, 1};
  vote_data_t votes[MAX_VOTES];
  int lastVoteIndex = 0;

  int res = new_vote(voteData, votes, &lastVoteIndex);

  assert_int_equal(res, SUCCESS);
  assert_int_equal(lastVoteIndex, 1);
  assert_string_equal(votes[0].voterCnp, "1990112410089");
  assert_int_equal(votes[0].voterSection, 1);
  assert_int_equal(votes[0].votedCandidateIndex, 1);
}

void test_new_block_valid(void **state)
{
  ResultCode result = FAILURE;
  Chain *chain = NULL;

  result = init_chain(&chain);

  assert_int_equal(result, SUCCESS);
  assert_int_equal(chain->block.index, 1);
  assert_null(chain->next);

  vote_data_t voteData = {"1990112410089", 1, 1};
  vote_data_t votes[MAX_VOTES];
  int lastVoteIndex = 0;

  result = new_vote(voteData, votes, &lastVoteIndex);
  assert_int_equal(result, SUCCESS);

  char previousHash[256] = "some";
  int chainLen = 1;

  result = new_block(&chain, votes, &chainLen, previousHash, 100);

  assert_int_equal(result, SUCCESS);
  assert_int_equal(chain->next->block.index, 2);
  assert_null(chain->next->next);
  free(chain);
}

void test_init_chain_valid(void **state)
{
  ResultCode result = FAILURE;
  Chain *chain = NULL;

  result = init_chain(&chain);

  assert_int_equal(result, SUCCESS);
  assert_int_equal(chain->block.index, 1);
  assert_null(chain->next);

  free(chain);
}

void test_valid_proof_valid(void **state)
{
  long last_proof = 3063270;
  long proof = 4;

  Bool res = valid_proof(last_proof, proof);

  assert_int_equal(res, TRUE);
}

void test_proof_of_work(void **state)
{
  long last_proof = 3063270;

  long proof = proof_of_work(last_proof);

  assert_int_equal(proof, 3063274);
}
