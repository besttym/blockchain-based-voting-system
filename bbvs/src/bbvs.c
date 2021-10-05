
/*

Name:   bbvs.c                                                       
                                                                           
Purpose:                                      

*/

#include "bbvs.h"

/*
        Simple Proof of Work Algorithm:
         - Find a number p' such that hash(pp') contains leading 4 zeroes, where p is the previous p'
         - p is the previous proof, and p' is the new proof

        param last_proof: <long>
        return: <long>
*/
long proof_of_work(long last_proof)
{
  long proof = 1;

  while (!valid_proof(last_proof, proof))
  {
    ++proof;
  }

  return (last_proof + proof);
}

/*
        Validates the Proof: Does hash(last_proof, proof) contain 4 leading zeroes?
        :param last_proof: <int> Previous Proof
        :param proof: <int> Current Proof
        :return: <bool> True if correct, False if not.
*/

Bool valid_proof(const long last_proof, const long proof)
{
  int i;
  char str[256];
  char hash_buffer[SHA256_LEN + 1];
  long sum = last_proof + proof;
  sprintf(str, "%ld", sum);

  unsigned char *d = SHA256((const unsigned char *)str, strlen(str), 0);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		sprintf(hash_buffer + 2*i,"%02x", d[i]);

  hash_buffer[SHA256_LEN] = '\0';
  return (hash_buffer[SHA256_LEN - 1] == '0' &&
          hash_buffer[SHA256_LEN - 2] == '0' &&
          hash_buffer[SHA256_LEN - 3] == '0' &&
          hash_buffer[SHA256_LEN - 4] == '0');
}
