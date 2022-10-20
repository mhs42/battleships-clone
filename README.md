# Battleships Clone

By:
- Muhammad Haris Saad
- Shehryar Sohail

This is a program based off the famous board game "Battleships", which is a game played between two players.

Each player has 5 ships:
- Ship 1 (Dimensions 2x1)
- Ship 2 (Dimensions 3x1)
- Ship 3 (Dimensions 3x1)
- Ship 4 (Dimensions 4x1)
- Ship 5 (Dimensions 5x1)


To begin, both players must place their ships on a 10x10 grid (0,0 to 9,9) on separate turns.
To prevent cheating, one player must look away when it is the other's turn.

Players will be asked to enter the coordinates of a specific element, by being told to enter a row number and a column number.
(Be careful though; enter them as per the instructions given, or you might get an error and have to enter them again!)

When an element is chosen, one end of the ship is placed there. Players must then choose to enter which direction their ship would be placed from
that particular element (Left, Right, Up or Down).
(Be careful though; maintain your ships within the grid, or you might get an error and have to enter them again!)


When all ships have been placed, it is time to battle!

Shehryar and I have decided to spice things up a bit!
Unlike traditional Battleships, instead of getting 5 bombs per turn, you will only get 1 here.
This means you have only one move per turn, so choose wisely!

You will be shown your own ships on a grid above, and the grid which you have to place your bombs at below the other.
Your own ships will be visible by their ship number of the length of their dimensions (i.e. Ship 2, for example, will be displayed as  2 2 2).

On each grid:
- 0: Unbombed
- n: Part of a ship *n* where n = 1, 2, 3, 4, or 5, depending on which ship got hit
- X: Bombed but no ship
- H: Bombed and hit
- S: Bombed and sunken (only happens when all the other elements housing that one ship have been bombed as well)

If one player sinks all the other player's ships when bombing them, then that player will win!
