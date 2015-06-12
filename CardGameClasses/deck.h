#ifndef DECKHEADER
#define DECKHEADER
/*
 * deck.h
 * wrapper class for card classes
 * written by Kristopher Wagner
 */

#include <stdlib.h>
#include <time.h>
#include "allocation.h"

#define HAND_SIZE 5
#define DECK_SIZE 52

typedef enum
{
   High_card,
   One_pair,
   Two_pair,
   Three_of_a_kind,
   Straight,
   Flush,
   Full_house,
   Four_of_a_kind,
   Straight_flush,
   Royal_flush
}Hand_Type;

typedef enum
{
   Two,
   Three,
   Four,
   Five,
   Six,
   Seven,
   Eight,
   Nine,
   Ten,
   Jack,
   Queen,
   King,
   Ace
}Value;

typedef enum
{
   Heart,
   Diamond,
   Spade,
   Club
}Suit;

typedef struct
{
   Suit cSuit;    // Suit of the card
                  // suit can be one of the following { 'H' = heart, 'D' = diamond, 'S' = spade, 'C' = club }
   Value cValue;  // Value of the card
                  // value can be one of the following { [2, 10], 'J' = Jack, 'Q' = Queen, 'K' = King, 'A' = Ace }
}Card;

typedef struct
{
   Card aCards[HAND_SIZE];		// Array of HAND_SIZE cards to represent a hand of cards
}Hand;

typedef struct
{
   Card *aCards;			// an array of cards in the deck
   DWORD dwNumCards;	   // number of cards currently in the deck
}Deck;

DWORD init_deck(Deck *pDeck);
/* initializes the deck to have one of each card 
 * PRE:  pDeck is a  valid pointer to a Deck
 * POST: FCTVAL == ERROR_SUCCESS on success, or an error code otherwise
 *       pDeck has one of each card and mimics a standard deck
 *       pDeck->dwNumCards = DECK_SIZE
 */

DWORD shuffle_deck(Deck *pDeck);
/* shuffles the deck
 * PRE:  pDeck is a valid pointer to a Deck
 * POST: FCTVAL == ERROR_SUCCESS on success, or an error code otherwise
 *       pDeck->aCards is in a random order
 */

Card draw_card(Deck *pDeck, int *errorCode);
/* removes the 'Top" card [index 0] off the deck and returns it 
 * PRE:  pDeck is a valid pointer to a Deck and has at least one card in it
 * POST: errorCode == ERROR_SUCCESS on success, or an error code otherwise
 *       retVal = the "top" card of the deck
 *       pDeck->aCards has one less card
 *       pDeck->dwNumCards is decremented by 1
 */

Hand_Type getHandType(Hand curHand);         // Designed for 5 card hand types of games                       
/* calculates the current type of the hand
 * PRE:  curHand is an intialized hand with HAND_SIZE number of cards
 * POST: FCTVAL == the highest value Hand_Type in the curHand  
 */

#endif