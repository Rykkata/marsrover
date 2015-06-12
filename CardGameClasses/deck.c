/*
 * deck.h
 * Written by Kristopher Wagner
 * implementation of deck.h
 */

#include "deck.h"


DWORD init_deck(Deck *pDeck)
/* initializes the deck to have one of each card
 * PRE:  pDeck is an unallocated pointer to a Deck
 * POST: FCTVAL == ERROR_SUCCESS on success, or an error code otherwise
 *       pDeck has one of each card and mimics a standard deck
 *       pDeck->dwNumCards = DECK_SIZE
 *       pDeck must be freed by the caller on success
 */
{
	// TODO: test this function
                                                                 
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

   if ((pTempDeck = (Deck *)w_malloc(sizeof(Deck))) == NULL)
	{
		iRetVal = GetLastError();
#if VERBOSE >= 1
		fprintf(stdout, "init_deck(): Allocation error %d. Line: %d\n", iRetVal, __LINE__);
#endif
		return iRetVal;
	}

   if ((pTempDeck->aCards = (Card *)w_malloc(sizeof(Card)* DECK_SIZE)) == NULL)
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

	pTempDeck->dwNumCards = dwTotalCards;

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

DWORD shuffle_deck(Deck *pDeck)
/* shuffles the deck
 * PRE:  pDeck is a valid pointer to a Deck
 * POST: FCTVAL == ERROR_SUCCESS on success, or an error code otherwise
 *       pDeck->aCards is in a random order
 */
{
//--------------------------------------------------------------------|
// Data Dictionary                                                    |
//--------------------------------------------------------------------|

   Deck tempDeck = { 0 };

//--------------------------------------------------------------------|
// Allocate pointers                                                |
//--------------------------------------------------------------------|
   
   // this would be so much easier in Python...

   // TODO implement and test this function

   return 0;
}

Card draw_card(Deck *pDeck, int *errorCode)
/* removes the 'Top" card [index 0] off the deck and returns it 
 * PRE:  pDeck is a valid pointer to a Deck and has at least one card in it
 * POST: errorCode == ERROR_SUCCESS on success, or an error code otherwise
 *       retVal = the "top" card of the deck
 *       pDeck->aCards has one less card
 *       pDeck->dwNumCards is decremented by 1
 */
{
   // TODO test this function
   // TODO improve pre and post to match error conditions

   if ((pDeck == NULL) || (errorCode == NULL))
   {
#if VERBOSE >= 1
      fprintf(stdout, "draw_card(): Error NULL params. Line: %d\n", __LINE__);
#endif
      SetLastError(ERROR_INVALID_PARAMETER);

      Card retCard = { 0 };
      return retCard;
   }

//--------------------------------------------------------------------|
// Data Dictionary                                                    |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "draw_card(): Data Dictionary. Line: %d\n", __LINE__);
#endif

   Card retCard   = { 0 };             // Card to return
   Deck tempDeck  = { 0 };             // there is prolly a better way of doing this
   DWORD dwItr    = 0;                 // iterator for copy

   *errorCode     = ERROR_SUCCESS;     // let's be optimistic, WOOO

//--------------------------------------------------------------------|
// Pop the top card                                                   |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "draw_card(): Pop the top card. Line: %d\n", __LINE__);
#endif

   if (pDeck->aCards == NULL)
   {
#if VERBOSE >= 1
      fprintf(stdout, "draw_card(): Error NULL params. Line: %d\n", __LINE__);
#endif

      *errorCode = ERROR_INVALID_PARAMETER;
      return retCard;
   }

   retCard.cSuit = pDeck->aCards[0].cSuit;      // retCard is the top card
   retCard.cValue = pDeck->aCards[0].cValue;

//--------------------------------------------------------------------|
// Update the deck                                                    |
//--------------------------------------------------------------------|

#if VERBOSE > 1
	fprintf(stdout, "draw_card(): Update the deck . Line: %d\n", __LINE__);
#endif

   tempDeck.dwNumCards = pDeck->dwNumCards - 1;

   if ((tempDeck.aCards = (Card *)w_malloc(sizeof(Card)* tempDeck.dwNumCards)) == NULL)
   {
      *errorCode = GetLastError();

#if VERBOSE >= 1
      fprintf(stdout, "draw_card(): Error %d allocating deck. Line: %d\n", 
         *errorCode, __LINE__);
#endif

      return retCard;
   }

   // copying each card to a new deck
   for (dwItr = 0; dwItr < tempDeck.dwNumCards; dwItr++)
   {
      tempDeck.aCards[dwItr].cSuit = pDeck->aCards[dwItr + 1].cSuit;
      tempDeck.aCards[dwItr].cValue = pDeck->aCards[dwItr + 1].cValue;
   }

   w_free(pDeck->aCards);                    // free the old deck

   pDeck->aCards = tempDeck.aCards;          // update the deck
   pDeck->dwNumCards = tempDeck.dwNumCards;

#if VERBOSE > 1
   fprintf(stdout, "draw_card(): Drew card succesfully. Line: %d\n", __LINE__);
#endif

   return retCard;
}
