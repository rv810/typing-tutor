## **Project Title**: Keyboard Warrior 
**Type of App**: C Command Line Utility  

---

## **High-Level Description**  
### **Context**  
Keyboard Warrior is a typing tutor designed for kids who are learning to type. It provides an engaging and structured environment where users improve their typing skills through a series of levels that progressively unlock more keyboard characters.

### **General Outline of the Game**  
1. Each level corresponds to a set of keyboard characters that build upon the last:  
   - **Level 1**: Letters `g`, `h`.  
   - **Level 2**: Adds `f`, `j` to `g`, `h`, and so on.  
2. The user is presented with multiple sentences to type out in each level.  
3. While typing, a **stopwatch** is displayed to track typing time.  
4. Each sentence is scored based on **speed** and **accuracy**.  
5. The **overall score** is calculated as the average of all sentence scores.  
6. The user must achieve a minimum threshold score to "pass" a level:  
   - If the user **fails**, they must redo the level.  
   - If the user **passes**, they proceed to the next level.  
   - If the user completes the last level, a congratulatory message is displayed:  
     - *"Congratulations! You have mastered typing!"*  

## **How to Run the Program**
1. Clone the repository:
   git clone https://github.com/Sam-Scott-McMaster/the-team-assignment-team-16-the-algorithm-avengers.git

2. Build the program using the provided build file:
   
make

3. Run the program:

./type

4. Use the --help flag to view usage instructions:

./type --help
