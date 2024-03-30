Used proper Object-Oriented design principles to implement a linked list from scratch. 
Created a design using classes which have appropriate private data members and public services (member functions).
Tested with Valgrind for no memory leaks.

##################################################################
The Game:
The game “what time is it, big-bad wolf?” is a popular game played by children. 
One child, the “wolf”, stands at a fixed location,  (0,0). 
The other children are scattered around the wolf at their own (x,y) locations. 
The children ask “what time is it, big-bad wolf?” and the wolf states a time, for example, “3 o’clock”. 
The children then move 3 steps directly toward the wolf. 
If, instead, the wolf says “lunchtime!”, the wolf grabs the children closest to their location, and they are out of the game.
In this implementation, there is an additional rule: any child in the first quadrant is automatically removed from the game.
##################################################################

##################################################################
Input/Outputs:
1. Command: SPAWN
   Parameters: x y
   Description: Spawn a new child to play the game at coordinates (x,y) if the position (x,y) lies within the first quadrant.
                If so, this child is added to the linked list. Note that the origin and the x or y axes do not belong to 
               the first quadrant. Children may be added at any time until the OVER command is reached.
     Output: "success" if the child’s position lies within the first quadrant
             "failure" otherwise
2. Command: TIME
   Parameter: t
   Description: The children ask the wolf what time it is. If the parameter is non-negative, children move that many units toward the 
                wolf, according to:
                          Δ𝑥 = 𝑡 cos(𝑎𝑡𝑎𝑛2(𝑦, 𝑥))
                          Δ𝑦 = 𝑡 sin (𝑎𝑡𝑎𝑛2(𝑦, 𝑥))
                If any child moves out of the first quadrant after applying the movement, the child is removed from the game (and the linked 
                list). If t is strictly negative, all children within a distance of strictly less than 1m from the wolf are removed from the game.
   Output: The number of children in the game.
4. Command: NUM
   Output: The number of children in the game.
5. Command: PRT
   Parameter: D
   Description: Prints the coordinates of all children with a distance strictly less than D from the wolf.
   Output: "X1 Y1 X2 Y2…" if there are any children within the given distance
           "no children within distance" otherwise
6. Command: OVER
   Description: Indicate the game is over. Ends inputs.
   Output: "the players win" if at least one child is left playing
           "the wolf wins" otherwise
##################################################################

Project for University of Waterloo's ECE 250. Project description and idea by Mike Cooper-Stachowsky.
