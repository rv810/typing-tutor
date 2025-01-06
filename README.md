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

---

## **Design Constraints**  
1. **No Data Persistence**  
   - Progress is not saved between sessions.  
   - Users must restart from level 0 each time they open the app.  
   - **Impact**: Users cannot track long-term progress.  

2. **No WPM Calculation**  
   - Words-per-minute (WPM) is not currently included.  
   - **Impact**: Users will not receive an accurate measure of typing speed.  
   - Including WPM in future increments would enhance the user experience by providing speed feedback alongside accuracy.

---

## **Increment 1 Functionality**  
The **goal for Increment 1** is to implement the general functionality of the typing tutor. This includes:
1. **Sentence Generation**:
   - Sentences are randomly generated based on the level.
2. **Input Scanning**:
   - User-typed input is captured and checked for accuracy.  
3. **Scoring**:
   - Scores are calculated based on time and accuracy.  
4. **Level Progression**:
   - Users move between levels based on their overall scores.  
5. **Timer Display**:
   - A GUI-based timer shows typing time for each sentence.
6. **Help Flag**:
   - A `--help` flag explains how to use the program.
7. **Build File**:
   - A build file is provided to streamline testing and execution.

---

## **Roles & Responsibilities**
### **Yug Vashisth** - *The GUI Guy*  
- **Responsibilities**:
  2. Implement a progress bar to indicate level completion.
  3. Ensure the timer integrates with other functions to track start and end times.
  4. Write this README file to provide an overview of the project.
- **Deliverables**:
  - Timer and progress bar functionality.
  - Completed README file.
 
---

### **Ronit Patel** - *The Dictionary Dev*  
- **Responsibilities**:
  1. Generate sentences using predefined text files corresponding to each level.
  2. Randomly select and print sentences for each level based on available characters.
  3. Ensure output includes level and sentence number (e.g., *Level 1: Sentence 1: "ha haa ha"*).
- **Deliverables**:
  - Fully implemented sentence generation.

---

### **Prutha Patel** - *Accuracy Assassin*  
- **Responsibilities**:
  1. Implement functionality to capture user input and check sentence accuracy.
  2. Create logic to determine level progression:
     - Pass → Move to the next level.
     - Fail → Retry the current level.
  3. Implement final-level check and display completion message for the user.
- **Deliverables**:
  - Input handling and accuracy checking.
  - Level navigation.

---

### **Resham Vani** - *Calc the Creator*  
- **Responsibilities**:
  1. Write functions to calculate:
     - Individual sentence scores based on time and accuracy.
     - Overall level score and pass/fail determination.
  2. Implement the `--help` flag to display program usage instructions.
  3. Create a build file for compiling and testing the program.
- **Deliverables**:
  - Scoring and pass/fail logic.
  - Help flag and build file.

---

## **Increment 1 Deadline**: **November 20**  
All tasks must be completed and integrated into a working prototype by this date.  

---

## **How to Run the Program**
1. Clone the repository:
   git clone https://github.com/Sam-Scott-McMaster/the-team-assignment-team-16-the-algorithm-avengers.git

2. Build the program using the provided build file:
   
make

3. Run the program:

./type

4. Use the --help flag to view usage instructions:

./type --help

## **Future Enhancements**
- Add data persistence to save user progress between sessions.
- Implement WPM calculation to provide feedback on typing speed.
- Improve sentence difficulty scaling for advanced levels.
- Integrate sound effects or animations for a more engaging experience.
