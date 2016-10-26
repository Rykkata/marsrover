package deck

import "Card"

// Deck represents a standard 52 card deck
type Deck struct {
	cards [52]Card
}

func get_new_deck() Deck {
	cards [52]Card
	i := 0

	for s := Heart; s < Club; s++ {
		for v := Two; v < Ace; v++ {
			cards[i] = Card({Suit: s, Value: v})
			i++
		} 
	}

	return cards
}
