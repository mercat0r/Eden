# Project Eden (2001)


![alt text](http://www.core-design.com/images/goodies/Project-eden-logo.png)

## Quick description

Project Eden is a 2001 action-adventure video game developed by Core Design, the authors of Tomb Raider.
The plot sees a squad of four law enforcement agents investigating disappearances by working their way downwards through layers of a towering mega-city. Gameplay emphasises puzzle-solving, requiring the player(s) to control each of the four characters and use their individual abilities to progress. A single player can control any of the characters and jump between them at will; up to four players can play simultaneously, taking control of team members.
(Wikipedia)

## Internal info

The game uses DirectX 8 and was compiled with VC++ 6.0.

## What is already done ?

Not much, but it's something...

- (Wnd.cpp)         Main game window (CreateWindowEx, WndProc, etc.)
- (main.cpp)        Error return codes
- (cdcheck.cpp)     Checks if the game CD is in the drive :) (disabled by default, add CDCHECK to the preprocessor to enable it)
- (DXInit.cpp)      Partial DirectX 9 initialisation
- (DirectInput.cpp) Very partial DirectInput 8 initialisation
- (Time.cpp)        Some QueryFrequency thing... is it needed for sound sync?

## Screenshots

Here is a screenshot of the level editor used back in 2001 (unfortunately never released).

![alt text](http://www.core-design.com/images/goodies/othergames/roomeditorscreensprojecteden/screen17.jpg)

## What is the main goal ?

The main goal at this moment is to play the recompiled game, converted to DirectX 9, at least to the main menu, as it will be a big step forward. Then, I hope it will be possible to make our own levels...

## Notes

My coding is not perfect...
Feel free rewriting some of my code if you want to.

## Contact

Feel free to contact me/join the discussion here: https://discord.gg/N3kbFAW
