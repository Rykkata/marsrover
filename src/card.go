package card

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
