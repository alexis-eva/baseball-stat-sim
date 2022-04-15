# baseball-stat-sim
C++ program that reads baseball stats from a file, allows the user to update them by simulating baseball innings, and puts the output in a new file.

The program is fixed to read from "stats.txt" and write to "updatedstats.txt".

To use: Create a file "stats.txt" in the same file location as the code executable. "updatedstats.txt" will be created by the program, or overwritten if it exists.

"stats.txt" should contain a list of players, each on their own line, with values seperated by spaces: Number, last name, position, at bats, batting average (decimal), strikeouts, on bases, and homeruns. For example:
```
27 Alexis 2B 300 .489 29 140 22
3 Eva SS 152 .379 74 212 5
