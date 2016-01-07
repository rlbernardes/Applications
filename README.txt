The program has a options menu
        ====Opções====
        0 - Out
        1 - New rover
        2 - Define place of rover
        3 - Remove rover
        4 - To move rover
        5 - Print the place of the rover
        6 - Read input file
	==================================
you can to create one or more rovers, where each rover has a ID this is necessary for define the commands.
you can create, remove, define the place of the rover, to move the rover and to show the place of the rovers.
the command 6 read one input file with the format:
first line 2 integer separated by space, define one random position for the rover, for example 2 3
second line 2 integer e um characeter, where the integers define the place of the rover e the characeter the coordenate, for example 1 1 S 
third line can have many characters separated by space, this line is resposible by the moves of the rovers, and can has the values L, R an M.

the file can have other lines, the outhers lines has a format one line equals the second line and other line equals the third line.
============================================================================================================================================
Example file patern:

5 5 first line
1 3 W second line
LLMMRMMMRRM third line
2 5 S
MMRMLLMRMMMM
3 3 N
LLMMMRRMMMMM
2 2 E
RRMMMMRMMLMMM
============================================================================================================================================
For the test aplication use the file input.txt, and choose the option 6, this option creates e moves the rovers, and show the result in the finish
