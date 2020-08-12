# Problem Set 3
* Programming Language: C
* Coding environnment: https://ide.cs50.io/

## Project overview:
This project demonstrates basic understanding and implementation of programming concepts with the programming language C.
- Concepts covered: 
  - Linear Search
  - Binary Search
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Recursion
  - Merge Sort
  - Big O
  - Structs

## Project(s) include:
### Plurality
**Background**: Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, 
who generally chooses the leader of the political party that wins the most seats in the House of Commons. 
The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). 
In the plurality vote, every voter gets to vote for one candidate.
At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

- Completes the implementation of plurality.c in such a way that the program simulates a plurality vote election.
- Distribution/Starter code: wget [distributionCode.c](https://cdn.cs50.net/2019/fall/psets/3/plurality/plurality.c)
- Project file: [plurality.c](plurality.c)
- Methods I implemented: vote and print_winner
- Run the following commands:
  - make plurality
  - ./plurality
- Snapshot:
  - [Test Cases](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCasesForPlurality.JPG)

  
### Runoff (beginner)
- Implement a program that runs a runoff election, per the [image.](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCaseExampleForRunoff.JPG)
- Background: [Instant Runoff](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/RunOff.md)
- Project file: [runoff.c](runoff.c)
- Methods I implemented: vote, tabulate, print_winner, find_min, is_tie, and eliminate.
- Run the following commands:
  - make runoff
  - ./runoff
- Distribution/Starter code: wget [distributionCode.c](https://cdn.cs50.net/2019/fall/psets/3/runoff/runoff.c)
- Test cases: [Test Cases]

### Substitution (intermediate)
- Implements a program that implements a substitution cipher.
- Project file: [substitutionCiper.c](substitutionCiper.c)
- Test cases: [Test Cases](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%202%20-%20Arrays/Snapshots/TestCasesForSubstitutionCipher.JPG)
- Run the following commands:
  - make substitutionCiper
  - ./substitutionCiper

## To run the app:
* For this problem set, you’ll use CS50 IDE, a cloud-based programming environment. This environment is similar to CS50 Sandbox and CS50 Lab, the programming environments that David discussed during lecture.
