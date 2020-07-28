# Mario Beginner
## Pseudocode for how to approach this Mario Beginner project:
- Prompt the user for height
- Check if the user input is valid (inclusive range 1-8) [Note: this can be achieved by do-while]
    - If the value is valid, start building the pyramid (print '#' in a loop)
    - If the value if invalid, keep prompting the user
    
## Tactics for building the pyramid right aligned:
- It is easier to build the pyramid left-aligned than right aligned so, first build it left-aligned
- Use the height - 1 to print visible dots to make it right aligned
- Now replace the dots with spaces
