/**************************************************/
/* Duy Duong                                      */
/* Date: 04/16/2020                               */
/* CS-241 Section 005                             */
/* Lab 7: Cipher                                  */
/* LCG: Linear Congruential Generator implemented */
/* from header lcg.h                              */
/**************************************************/

#include <stdio.h>
#include "lcg.h"

/* Check whether the number is prime */
int isPrime(unsigned long num)
{
  int i = 2;
  while (i < num / 2)
  {
    if (num % i == 0) return 0;
    else i++;
  }
  return 1;
}

/***************************************************************/
/* Initialize an LCG with modulus m and increment c.           */
/* Calculate multiplier a such that:                           */
/*        a = 1+2p, if 4 is a factor of m, otherwise, a = 1+p. */
/*        p = (product of m’s unique prime factors).           */
/*        a < m                                                */
/* Seed value x is same as increment c.                        */
/* If values are invalid for LCG, set all fields to zero.      */
/***************************************************************/
struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  unsigned long p, td, m_tmp;
  struct LinearCongruentialGenerator lcg;
  lcg.m = 0;
  lcg.c = 0;
  lcg.a = 0;
  lcg.x = 0;
  m_tmp = m;

  /* return initial lcg if m = 0 or c = 0 */
  if (m == 0 || c == 0) return lcg;

  p = 1;
  td = 2;

  /* Find p with test divisor (td) */
  while (td * td <= m)
  { 
    if (m % td == 0)
    { 
      if(isPrime(td)) p *= td;
      do
      {
        m /= td;
      }
      while (m % td == 0);
    }
    else td++;
  }
  if (m > 1) p *= m;

  /* Assign value to a after getting p */
  if (m_tmp % 4 == 0)
  {
    lcg.a = 1 + 2*p;
  }
  else 
  {
    lcg.a = 1 + p;
  }

  /* return empty lcg if a > m */
  if (lcg.a > m_tmp) 
  {
    lcg.a = 0;
    return lcg;
  }

  /* Assign all values if there is no errors */
  lcg.m = m_tmp;
  lcg.c = c;
  lcg.x = c;

  return lcg;
}

/* Update lcg and return next value in the sequence. */
unsigned long getNextRandomValue(struct LinearCongruentialGenerator* lcg)
{
  unsigned long x = lcg->x;

  /* return 0 if lcg is invalid */
  if (lcg->m == 0) return 0;

  lcg->x = ((lcg->a * lcg->x + lcg->c) % lcg->m);
  return x;
}