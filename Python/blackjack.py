import cards as c

def dealerHit(dealer, highScore, deck):
    (score1, score2) = dealer.calcHand()
    if score1 == score2:
        print (
        "Dealer has %s (%d), needs to beat %d." % 
        (dealer, score1, highScore))
    else:
        print (
        "Dealer has %s (%d or %d), needs to beat %d." % 
        (dealer, score1, score2, highScore))
    if score1 >= highScore:
        return score1
    elif score2 >= highScore:
        return score2
    else:
        while (score1 < highScore) and (score2 != highScore):
            if score1 == score2:
                print "Dealer = { %s } %d" % (dealer, score1)
            else:
                print "Dealer = { %s } %d or %d" % (dealer, score1, score2)
            dealer.hit(deck.draw())
            (score1, score2) = dealer.calcHand()
            if (score1 == score2) or (score2 > 21):
                print "Dealer = { %s } %d" % (dealer, score1)
            else:
                print "Dealer = { %s } %d or %d" % (dealer, score1, score2)
            
        if score2 <= 21:
            return score2
        else:
            return score1
    
def playerHit(player, deck):
    (score1, score2) = players[itr].calcHand()
    if score1 == score2:
        print "Player %d = { %s } %d" %  (itr, players[itr], score1 ) 
    else:
        print ( "Player %d = { %s } %d or %d" % 
                                                    (itr, players[itr], score1, score2 ) )
    input = raw_input(
            "Player %d, would you like another card? (Y for yes, N for no)"
            % itr)
    if input == 'Y':
        while input == 'Y':
            players[itr].hit(deck.draw())
            (score1, score2) = players[itr].calcHand()
            if score1 > 21:
                print "Player %d = { %s } %d" %  (itr, players[itr], score1 ) 
                print "BUST!"
                return 0
            if score1 == score2:
                print "Player %d = { %s } %d" %  (itr, players[itr], score1 ) 
            else:
                print ( "Player %d = { %s } %d or %d" % 
                                                        (itr, players[itr], score1, score2 ) )
            input = raw_input(
            "Player %d, would you like another card? (Y for yes, N for no)"
            % itr)
            
    if score2 <= 21:
        return score2
    else:
        return score1

# Set up game
scores = {}
deck = c.Deck()
deck.shuffle()
highScore = 0

dealer = c.Player()
players = []

numPlayers = int(raw_input("How many players are there?"))

for itr in xrange(0, numPlayers):
    players.append(c.Player())
    
    
# Deal cards
dealer.hit(deck.draw())

for itr in xrange(0, numPlayers):
    players[itr].hit(deck.draw())
    
dealer.hit(deck.draw())
(score1, score2) = dealer.calcHand()
if score1 == score2:
    print "Dealer = { %s } %d" % (dealer, score1)
else:
    print "Dealer = { %s } %d or %d" % (dealer, score1, score2)

for itr in xrange(0, numPlayers):
    players[itr].hit(deck.draw())
    (score1, score2) = players[itr].calcHand()
    if score1 == score2:
        print "Player %d = { %s } %d" %  (itr, players[itr], score1 ) 
    else:
        print ( "Player %d = { %s } %d or %d" % 
                                                        (itr, players[itr], score1, score2 ) )

# Let Players play
print "\n\n"
for itr in xrange(0, numPlayers):
    score = playerHit(players[itr], deck)
    print "Player %d, your final score is: %d\n" % (itr, score)
    scores[itr] = score
    if score > highScore:
        highScore = score
    
# Let Dealer play
dealerScore = dealerHit(dealer, highScore, deck)
print "\nDealer's score = %d\n" % dealerScore

if dealerScore > 21:
    print "Dealer busted!\n"
    for itr in xrange(0, numPlayers):
        if scores.get(itr) != 0:
            print "Player %d wins!" % itr
else:
    for itr in xrange(0, numPlayers):
        if scores.get(itr) > dealerScore:
            print "Player %d wins!" % itr