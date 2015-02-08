/*
 * allocating.c
 * implementation of "allocation.h"
 * written by Kristopher Wagner
 */

#include "allocation.h"

void setVerbose(DWORD verbose)
/* sets the verbose output
 * PRE:  verbose >= 0
 * POST:  VERBOSE == verbose
 */
{
   VERBOSE = verbose;
}

int getNumAllocations()
/* returns the number of allocations
 * POST: FCTVAL == NUM_ALLOCATIONS
 */
{
   return NUM_ALLOCATIONS;
}


LPVOID w_malloc(DWORD dwSize)
/* allocates size bytes and returns a pointer to it
 * PRE:   size is > 0
 * POST:  FCTVAL == a pointer to a block of memory on success
 *           or NULL on an error, use GetLastError() to get the error
 *           this memory will need to be freed by the caller
 *        NUM_ALLOCATIONS is incremented on success
 */
{

   LPVOID lpRetVal   = NULL;           // return value pointer
   int dwErr         = ERROR_SUCCESS;  // error code for SetLastError()


   if (dwSize <= 0)
   {
      if (VERBOSE >= 1)
      {
         fprintf(stderr, "w_malloc: dwSize must be greater than 0. Line: %d\n", __LINE__);
      }

      dwErr = ERROR_INVALID_PARAMETER;
      SetLastError(dwErr);
      return NULL;
   }

   if (VERBOSE > 1)
   {
      fprintf(stdout, "w_malloc: Allocating %u bytes. Line: %\n", dwSize, __LINE__);
   }

   if ((lpRetVal = malloc(dwSize)) == NULL)
   {
      if (VERBOSE >= 1)
      {
         dwErr = GetLastError();
         fprintf(stderr, "w_malloc: Error %d in malloc. Line %d\n", dwErr, __LINE__);
         SetLastError(dwErr);
      }

      return NULL;
   }
   else
   {
      NUM_ALLOCATIONS++;

      if (VERBOSE > 1)
      {
         fprintf(stdout, "w_malloc: Allocated %d bytes.\nw_malloc: Total allocations: %d.\nw_malloc: Line: %d\n",
            dwSize, NUM_ALLOCATIONS, __LINE__);
      }

      return lpRetVal;
   }
}

int w_free(LPVOID pMem);
/* frees the memory and sets it to NULL 
 * PRE:  pMem is a valid pointer
 * POST: FCTVAL == ERROR_SUCCESS on success or an errror code otherwise
 *       if the memory is freed NUM_ALLOCATIONS is decremented
 */


