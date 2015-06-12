/*
 * allocating.c
 * implementation of "allocation.h"
 * written by Kristopher Wagner
 */

#include "allocation.h"

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
      ZeroMemory(lpRetVal, dwSize);

      if (VERBOSE > 1)
      {
         fprintf(stdout, "w_malloc: Allocated %d bytes. Line: %d\n",
            dwSize, __LINE__);
      }

      return lpRetVal;
   }
}

DWORD w_free(LPVOID pMem)
/* frees the memory and sets it to NULL
 * PRE:  pMem is a valid pointer
 * POST: FCTVAL == ERROR_SUCCESS on success or an errror code otherwise
 *       if the memory is freed NUM_ALLOCATIONS is decremented
 */
{
   DWORD dwRetVal = ERROR_SUCCESS;     // FCTVAL
   
   if (pMem == NULL)
   {
      dwRetVal = ERROR_INVALID_PARAMETER;

      if (VERBOSE > 1)
      {
         fprintf(stderr, "w_free: Error %d, pMem already freed. Line: %d\n", dwRetVal, __LINE__);
      }

      return dwRetVal;
   }

   if (VERBOSE > 1)
   {
      fprintf(stdout, "w_free: About to free memory location %p. Line: %d\n", pMem, __LINE__);
   }

   free(pMem);

   if (VERBOSE > 1)
   {
      fprintf(stdout, "w_free: Freed pMem. Line: %d\n", __LINE__);
   }

   return dwRetVal;
}

DWORD w_memcpy(PBYTE lpSrc, DWORD dwSrcSz, PBYTE lpDest, DWORD dwDestSz)
/* copies source into destination
 * PRE:   lpSrc is a valid pointer of size dwSrcSz
 *        lpDest is a valid pointer of size dwDestSz
 * POST:  FCTVAL == ERROR_SUCCESS on success or an error code otherwise
 *        lpSrc's first dwDestSz bytes are the same as lpDest on success
 */
{
   DWORD dwRetVal = ERROR_SUCCESS;     // FCTVAL
   DWORD dwItr    = 0;                 // iterator variable

   if (dwDestSz < dwSrcSz)
   {
      dwRetVal = ERROR_NOT_ENOUGH_MEMORY;

      if (VERBOSE >= 1)
      {
         fprintf(stderr, "w_memcpy: not enough memory allocated for destination( %d < %d). Line: %d\n",
            dwDestSz, dwSrcSz, __LINE__);
      }

      return dwRetVal;
   }

   if ((lpSrc == NULL) || (lpDest == NULL))
   {
      dwRetVal = ERROR_INVALID_PARAMETER;

      if (VERBOSE >= 1)
      {
         fprintf(stderr, "w-Memcyp: Error %d one of the pointers is NULL. Line: %d\n", dwRetVal, __LINE__);
      }

      return dwRetVal;
   }

   if (VERBOSE > 1)
   {
      fprintf(stdout, "w_memcpy: about to copy %d bytes from %p into %p.\nw_memcpy: Line: %d\n",
         dwDestSz, lpSrc, lpDest, __LINE__);
   }

   memcpy(lpDest, lpSrc, dwDestSz);

   if (VERBOSE > 1)
   {
      fprintf(stdout, "w_memcpy: copied %d bytes from %p into %p.\nw_memcpy: Verifying copy\nLine: %d\n",
         dwDestSz, lpSrc, lpDest, __LINE__);
   }

   for (dwItr = 0; dwItr < dwDestSz; dwItr++)
   {
      if (lpSrc[dwItr] != lpDest[dwItr])
      {
         dwRetVal = ERROR_AUDIT_FAILED;

         if (VERBOSE >= 1)
         {
            fprintf(stderr, "w_memcpy: Destination does not match source. Line: %d\n", __LINE__);
         }

         return dwRetVal;
      }
   }

   return dwRetVal;
}

