package deck

import "math/rand"

// Suit represents the suits of a card to improve readability
type Suit int

// The list of all suits
const (
	Heart Suit = iota
	Diamond
	Spade
	Club
)

// Value represents the value of the card to improve readability
type Value int

// The list of all values
const (
	Two Value = iota
	Three
	Four
	Five
	Six
	Seven
	Eight
	Nine
	Ten
	Jack
	Queen
	King
	Ace
)

// Card represents a card in a deck
type Card struct {
	s Suit
	v Value
}

// Deck represents a standard 52 card deck
type Deck struct {
	cards []Card
}

// replaces d.cards with a fresh set
func (d *Deck) getNewDeck() {
	d.cards = make([]Card, 52, 52)
	i := 0

	for s := Heart; s < Club; s++ {
		for v := Two; v < Ace; v++ {
			d.cards[i] = Card{s: s, v: v}
			i++
		}
	}
}

func (d *Deck) shuffle() {
	// http://stackoverflow.com/questions/12264789/shuffle-array-in-go
	for i := range d.cards {
		j := rand.Intn(i + 1)
		d.cards[i], d.cards[j] = d.cards[j], d.cards[i]
	}
}
