package deck

import (
	"math/rand"
	"github.com/arcite/marsrover/src/Card"
)

// Deck represents a standard 52 card deck
type Deck struct {
	Cards []card.Card
}

// GetNewDeck replaces d.cards with a fresh set
func (d *Deck) GetNewDeck() {
	d.Cards = make([]card.Card, 52, 52)
	i := 0

	for s := card.Heart; s < card.Club; s++ {
		for v := card.Two; v < card.Ace; v++ {
			d.Cards[i] = card.Card{S: s,V: v}
			i++
		}
	}
}

// Shuffle randomizes the order of the cards
func (d *Deck) Shuffle() {
	// http://stackoverflow.com/questions/12264789/shuffle-array-in-go
	for i := range d.Cards {
		j := rand.Intn(i + 1)
		d.Cards[i], d.Cards[j] = d.Cards[j], d.Cards[i]
	}
}
