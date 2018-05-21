# nqueens_bitwise
A bitwise implementation in C for the n queens problem.

This was something of a milestone project. In the gruelling entry exams for my computer science school (school 42), on the fourth day (going from no coding experience!) we were asked to attempt to sovle the n queens problem in C without the help of any library functions.

I managed to do it then, but by Jove the code was ugly.

Later as a student, I learnt of bitwise operators. They immediately appealed to me due to their inception-like qualities (it's happening inside a number??). I produced an AI able to pack tetris shapes together as a first project with bitwsie operators (see <a href="https://github.com/SamLynnEvans/Fillit">here</a>), and finally now had some time to go back and address the n queens problem with this much more elegant solution.

The positions of the queens are not recorded, but instead we make use of three integers to see if it is possible to place a queen in a given row. One integer represents the column conflicts (whether a queen is in that column), another represents the major diagonal conflicts (how the queen's left to right diagonal attacks land on that row), and finally the third represents the minor diagonal conflicts (how the other queens' left diagonal attacks land on that row).

Each integer is updated every time a queen can be placed, and every time we move down a row, the major and minor diagonal conflict integers are shifted to the left and right respectively.

A full explanation of the logic in JS can be seen <a href="http://jgpettibone.github.io/bitwise-n-queens/">here</a>.
