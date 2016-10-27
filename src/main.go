package main

import (deck "github.com/arcite/marsrover/src/Deck")

func main() {
	sampleDeck := deck.Deck{}

	sampleDeck.GetNewDeck()
	sampleDeck.Shuffle()
}
