/*
 * deck.h
 * Written by Kristopher Wagner
 * implementation of deck.h
 */

#include "deck.h"


int init_deck(Deck *pDeck)
/* initializes the deck to have one of each card
 * PRE:  pDeck is an unallocated pointer to a Deck
 * POST: FCTVAL == ERROR_SUCCESS on success, or an error code otherwise
 *       pDeck has one of each card and mimics a standard deck
 *       pDeck->iNumCards = DECK_SIZE
 *       pDeck must be freed by the caller on success
 */
{
	// TODO: implement this function
                                                                 
//--------------------------------------------------------------------|
// Data Dictionary                                                    |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "init_deck(): Data Dictionary. Line: %d\n", __LINE__);
#endif

	int iRetVal			   = ERROR_SUCCESS;	// FCTVAL
	DWORD dwItrO		   = 0;				   // iterator variable for outside loop
	DWORD dwItrI		   = 0;				   // iterator variable for inside loop
	DWORD dwTotalCards	= 0;				   // total number of cards put in the deck
	Card curCard		   = { 0 };			   // current card to be added to deck
	Deck *pTempDeck		= NULL;			   // temporary deck for pDeck to point to

//--------------------------------------------------------------------|
// Allocating pointers                                                |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "init_deck(): Allocating pointers. Line: %d\n", __LINE__);
#endif

	if ((pTempDeck = (Deck *)malloc(sizeof(Deck))) == NULL)
	{
		iRetVal = GetLastError();
#if VERBOSE >= 1
		fprintf(stdout, "init_deck(): Allocation error %d. Line: %d\n", iRetVal, __LINE__);
#endif
		return iRetVal;
	}

	if ((pTempDeck->aCards = (Card *)malloc(sizeof(Card)* DECK_SIZE)) == NULL)
	{
		iRetVal = GetLastError();
#if VERBOSE >= 1
		fprintf(stdout, "init_deck(): Allocation error %d. Line: %d\n", iRetVal, __LINE__);
#endif
		free(pTempDeck);
		return iRetVal;
	}

//--------------------------------------------------------------------|
// Put DECK_SIZE cards in the deck                                    |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "init_deck(): Put DECK_SIZE cards in the deck. Line: %d\n", __LINE__);
#endif

	for (dwItrO = 0, dwTotalCards = 0; (dwItrO < 4) && (dwTotalCards < DECK_SIZE); dwItrO++)
	{
		for (dwItrI = 0; (dwItrI < 13) && (dwTotalCards < DECK_SIZE); dwItrI++, dwTotalCards++)
		{
			curCard.cSuit = dwItrO;
			curCard.cValue = dwItrI;
			pTempDeck->aCards[dwTotalCards] = curCard;
		}
	}

	pTempDeck->iNumCards = dwTotalCards;

	if (dwTotalCards != DECK_SIZE)
	{
		iRetVal = ERROR_MORE_DATA;

#if VERBOSE >= 1
		fprintf(stdout, "init_deck(): Created %d cards, should have created %d.. Line: %d\n", dwTotalCards, DECK_SIZE, __LINE__);
#endif

		for (dwItrO = 0; dwItrO < dwTotalCards; dwItrO++)
		{
			free(pTempDeck->aCards);
		}

		free(pTempDeck);

		return iRetVal;
	}

#if VERBOSE > 1
	fprintf(stdout, "init_deck(): Created deck successfully. Line: %d\n", __LINE__);
#endif

	pDeck = pTempDeck;
	return iRetVal;

}
