#include "stemmer.h"

int stem(char*p, int i, int j)
{
    b = p; k = j; k0 = i; /* copy the parameters into statics */
   if (k <= k0+1) return k; /*-DEPARTURE-*/

   /* With this line, strings of length 1 or 2 don't go through the
      stemming process, although no mention is made of this in the
      published algorithm. Remove the line to match the published
      algorithm. */

   step1ab();
   if (k > k0) {
       step1c(); step2(); step3(); step4(); step5();
   }
   return k;
}
