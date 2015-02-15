#ifndef ALLOCATIONHEADER
#define ALLOCATIONHEADER
/*
 * allocating.h
 * wrapper class for allocation functions
 * written by Kristopher Wagner
 */

#include <Windows.h>
#include <stdio.h>

#define  VERBOSE 2                  // controlls debug prints, 0 for none, 1 for errors, > 1 for a lot
int NUM_ALLOCATIONS;                // keeps track of the number of allocations to avoid memory leaks

void initNumAllocations();                // use at beginning of main
/* sets the number of allocations to 0    
 * POST: NUM_ALLOCATIONS == 0
 */

int getNumAllocations();               // used to detect memory leaks, use at beginning and end of functions 
/* returns the number of allocations   //    and verify the numbers are equal
 * POST: FCTVAL == NUM_ALLOCATIONS
 */


LPVOID w_malloc(DWORD dwSize);
/* allocates size bytes and returns a pointer to it
 * PRE:   size is > 0
 * POST:  FCTVAL == a pointer to a block of memory on success
 *           or NULL on an error, use GetLastError() to get the error
 *           this memory will need to be freed by the caller
 *        NUM_ALLOCATIONS is incremented on success
 */

DWORD w_free(LPVOID pMem);
/* frees the memory and sets it to NULL 
 * PRE:  pMem is a valid pointer
 * POST: FCTVAL == ERROR_SUCCESS on success or an errror code otherwise
 *       if the memory is freed NUM_ALLOCATIONS is decremented
 */

DWORD w_memcpy(PBYTE lpSrc, DWORD dwSrcSz, PBYTE lpDest, DWORD dwDestSz);
/* copies source into destination
 * PRE:   lpSrc is a valid pointer of size dwSrcSz
 *        lpDest is a valid pointer of size dwDestSz
 * POST:  FCTVAL == ERROR_SUCCESS on success or an error code otherwise
 *        lpSrc's first dwDestSz bytes are the same as lpDest on success
 */

#endif
