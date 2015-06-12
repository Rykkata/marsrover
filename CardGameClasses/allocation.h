#ifndef ALLOCATIONHEADER
#define ALLOCATIONHEADER
/*
 * allocating.h
 * wrapper class for allocation functions
 * written by Kristopher Wagner
 */

#include <Windows.h>
#include <stdio.h>

#ifdef _DEBUG
#define  VERBOSE 2                  // controlls debug prints, 0 for none, 1 for errors, > 1 for a lot
#else
#ifdef _RELEASELOGGING
#define  VERBOSE 1                  // controlls debug prints, 0 for none, 1 for errors, > 1 for a lot
#else
#define  VERBOSE 0                  // controlls debug prints, 0 for none, 1 for errors, > 1 for a lot
#endif
#endif

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

