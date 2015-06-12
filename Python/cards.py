import random

class Card(object):
    
    def __init__(self, value, suite):
        super(Card, self).__init__()
        self.Value = value
        self.Suite = suite
        
    def __str__(self):
        return ("%s%c" % (self.Value, self.Suite))
        
class Deck(object):

    def __init__(self):
        super(Deck, self).__init__()
        self.cards = []
        
        self.cards.append(Card('A', chr(3)))
        self.cards.append(Card('A', chr(4)))
        self.cards.append(Card('A', chr(5)))
        self.cards.append(Card('A', chr(6)))
        for val in xrange(50, 57):
            self.cards.append(Card(chr(val), chr(3)))
            self.cards.append(Card(chr(val), chr(4)))
            self.cards.append(Card(chr(val), chr(5)))
            self.cards.append(Card(chr(val), chr(6)))
        self.cards.append(Card('10', chr(3)))
        self.cards.append(Card('10', chr(4)))
        self.cards.append(Card('10', chr(5)))
        self.cards.append(Card('10', chr(6)))
        self.cards.append(Card('J', chr(3)))
        self.cards.append(Card('J', chr(4)))
        self.cards.append(Card('J', chr(5)))
        self.cards.append(Card('J', chr(6)))
        self.cards.append(Card('Q', chr(3)))
        self.cards.append(Card('Q', chr(4)))
        self.cards.append(Card('Q', chr(5)))
        self.cards.append(Card('Q', chr(6)))
        self.cards.append(Card('K', chr(3)))
        self.cards.append(Card('K', chr(4)))
        self.cards.append(Card('K', chr(5)))
        self.cards.append(Card('K', chr(6)))
        
    def __str__(self):
        retval = ""
        for card in self.cards:
            retval = retval + str(card) + "\n"
            
        return retval
        
    def shuffle(self):
        random.shuffle(self.cards)
        
    def draw(self):
        return self.cards.pop()
        
class Player(object):
    
    def __init__(self):
        super(Player, self).__init__()
        self.cards = []
    
    def hit(self, card):
        self.cards.append(card)
        
    def __str__(self):
        retval = ""
        for card in self.cards:
            retval = retval + " " + str(card)
            
        return retval
        
    def calcHand(self):
        retval = [0, 0]
        for card in self.cards:
            if card.Value == 'A':
                retval[0] = retval[0] + 1
                retval[1] = retval[1] + 11
            elif card.Value == '2':
                retval[0] = retval[0] + 2
                retval[1] = retval[1] + 2
            elif card.Value == '3':
                retval[0] = retval[0] + 3
                retval[1] = retval[1] + 3
            elif card.Value == '4':
                retval[0] = retval[0] + 4
                retval[1] = retval[1] + 4
            elif card.Value == '5':
                retval[0] = retval[0] + 5
                retval[1] = retval[1] + 5
            elif card.Value == '6':
                retval[0] = retval[0] + 6
                retval[1] = retval[1] + 6
            elif card.Value == '7':
                retval[0] = retval[0] + 7
                retval[1] = retval[1] + 7
            elif card.Value == '8':
                retval[0] = retval[0] + 8
                retval[1] = retval[1] + 8
            elif card.Value == '9':
                retval[0] = retval[0] + 9
                retval[1] = retval[1] + 9
            elif card.Value == '10':
                retval[0] = retval[0] + 10
                retval[1] = retval[1] + 10
            elif card.Value == 'J':
                retval[0] = retval[0] + 10
                retval[1] = retval[1] + 10
            elif card.Value == 'Q':
                retval[0] = retval[0] + 10
                retval[1] = retval[1] + 10
            elif card.Value == 'K':
                retval[0] = retval[0] + 10
                retval[1] = retval[1] + 10
                
        return (retval[0], retval[1])