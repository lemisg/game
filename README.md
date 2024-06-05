Game variables
  -intiall score is 0
  - you get 3 lives
  - the first reponse time is 2 sec
  - the response time chanege over time
  - the game is intially set to not active


there are 3 different sound i will be using the game.
  -correct answer sound 262 hertz
  -incorrect answer sound 131 hertz
  -gameover sound is 65 hertz

  I have 5 different functions declarations 
  1. is for starting game function
  2. is the main game loop
  3. is one the that displays led light
  4. is for incoorect response
  5. is when the game over

set up
initialize the circuit play ground library
set up initial state and button inputs
    -left button is an input
    -right button is an inout
    -game active is not active (gameActive=false


void loop

if statement: if the game is active and the left button reads high, you start the game
if the game is already active go to main loop.

Starting the game:

 - starting score is 0
 - starting live is 3
 - response time is 2 sec
 - the pixels turn off
 - CircuitPlayground.playTone(523, 500);
 - game active is true
 - proceed to main loop

main loop

when lives is greater than 0
and there colors are set to random and 
led is displaying colors
startTime = millis();



                    -when your response time is greater start time -given time 
                            and - you see color red, click right button 
                            and when you get correct response, for 5 sec and go to next round
                            - you see color blue move the led for motion detection
                             and when you get correct response, for 5 sec and go to next round
                            - if you see color green click left
                               and when you get correct response, for 5 sec and go to next round

                       when you response time is less, or you pick wrong answer you get 
                     incorrect response
                it repeat that till you lose all your lives and the game is over


  led display

  when its display color red on all led
   when its display color green on all led
    when its display color blue on all led
write after you display you clear it till it repeat agian


color string set to random( 3 different colors)

when rend index= 0
display red
when its 1 display blue
when neither display green

when you get correct response score increases by 1 and response time decreases by 0.95 and play 500 harts 

when you get incoorrect, you lose one live and play 500 herts

when game is over clear pixel, and set it to red and clear again, play 100 herts and print game over and show score and set game active to false

    
    
     
