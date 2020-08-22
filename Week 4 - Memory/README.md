# Problem Set 4
* Programming Language: C
* Coding environnment: https://ide.cs50.io/

## Project overview:
This project demonstrates basic understanding and implementation of programming concepts with the programming language C without the use of CS50 library.
- Concepts covered: 
  - Hexadecimal
  - Pointers
  - string
  - Compare and copy
  - valgrind
  - Swap
  - get_int
  - Files
  - JPEG

## Project(s) include:
### Filter (beginner)
- Implements a program that applies filters to BMPs, per the image.
- Background: [Filter]
- Distribution/Starter code: wget [distributionCode](https://cdn.cs50.net/2019/fall/psets/4/filter/less/filter.zip)
- Project file: [filter1.c](filter1.c)
- Run the following commands:
  - make filter1
  - ./filter1
- Snapshot:
  - [Test Cases]

  
### Runoff (beginner)
- Implement a program that runs a runoff election, per the [image.](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCaseExampleForRunoff.JPG)
- Background: [Instant Runoff](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/RunOff.md)
- Project file: [runoff.c](runoff.c)
- Methods I implemented: vote, tabulate, print_winner, find_min, is_tie, eliminate, findTheCandidate and retrieveAndAddItsNextPrefCandidate
- Run the following commands:
  - make runoff
  - ./runoff alice charlie bob
- Distribution/Starter code: wget [distributionCode.c](https://cdn.cs50.net/2019/fall/psets/3/runoff/runoff.c)
- Test cases: [Test Cases](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCasesForRunOff.JPG)

### Tideman (intermediate)
- Implements a program that runs a Tideman election, per the [image.](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCaseExampleForTiderman.JPG)
- Background: [Tideman](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/Tideman.md)
- Project file: [tideman.c](tideman.c)
- Methods I implemented: vote, record_preference, add_pairs,sort_pairs, lock_pairs, and print_winner
- Test cases: [Test Cases](https://github.com/anikaTabassumSardar/HarvardCourse-CS50_IntroductionToComputerScience/blob/master/Week%203%20-%20Algorithm/Snapshots/TestCasesforTideman.JPG)
- Distribution/Starter code: wget [distributionCode.c](https://cdn.cs50.net/2019/fall/psets/3/tideman/tideman.c)
- Run the following commands:
  - make tideman 
  - ./tideman alice charlie bob

## To run the app:
* For this problem set, you’ll use CS50 IDE, a cloud-based programming environment. This environment is similar to CS50 Sandbox and CS50 Lab, the programming environments that David discussed during lecture.
