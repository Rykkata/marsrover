import cards as c

def run_sim(scores, times):
#---------------------------------------------------
# Data Dictionary
#---------------------------------------------------

    # deck to hold the cards
    deck = c.Deck()
    
    # loop invariant
    busted = False
    
    # Player
    player = c.Player()
    
    # give the player his first to cards
    deck.shuffle()
    player.hit(deck.draw())
    player.hit(deck.draw())
    
    # main loop, hit until busted
    while not busted:
        (score1, score2) = player.calcHand()
        
        if score1 != score2:
            times[score1] = times[score1] + 1
            
            if score2 <= 21:
                times[score2] = times[score2] + 1
        else:
            times[score1] = times[score1] + 1
        
        player.hit(deck.draw())
        (newScore1, newScore2) = player.calcHand()
            
        # special case of an ace
        if newScore1 != newScore2:
            
            # player busted
            if newScore1 > 21:
                scores[score1] = scores[score1] + 1
                busted = True
            if newScore2 > 21:
                if score2 <= 21:
                    scores[score2] = scores[
                                        score2] + 1

        # normal case, no ace
        else:
            if newScore1 > 21:
                scores[score1] = scores[score1] + 1
                busted = True
                
#---------------------------------------------------
# Data Dictionary
#---------------------------------------------------


# Array to hold how many times the player busted by
#   hitting... score[12] is when the player had
#   12 as a score, the value is how many times 
#   he busted, by hitting
scores = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0]
times = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0]

for i in xrange(0, 1000000):
    if ( i % 100000) == 0:
        print "."
    run_sim(scores, times)
        
for i in range(0, len(scores)):
    if (scores[i] != 0) and (i != 21):
        print "%d    %.3f    %d/%d\n" % (
                i, float(scores[i])/float(times[i]), 
                                scores[i], times[i])