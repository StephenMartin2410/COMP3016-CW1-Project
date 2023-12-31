# **CW1-TypingTestAdventureGame**
### Visual Studio and OS version
- Visual Studio Community 2022 17.8.0
- Windows 11 Pro 23H2 - OS build 22631.2715
### Links
- https://github.com/StephenMartin2410/COMP3016-CW1-Project
- https://www.youtube.com/watch?v=_rcp1gl-LBk
---
## How To Play:
1. To begin the game start by pressing the spacebar on the start menu.
2. When prompted to type out a line, type every character displayed under the prompt, including spaces and symbols.
3. Depending on how you perform in this typing test the game will either output a positive or negative story response.
4. Everytime you get a negative response you will lose health.
5. Keep playing the game until you either reach the end or die.
---
## Extra Feature/Further Details
The game is made in a way that means the Start, Story, Positive and Negative files are not fixed.
This means that if a user wants to make their own story all they need to do is ensure that all the files have the same amount of lines and that each of the responses are single lines only.
- The Story.txt file contains the list of lines the player is required to type out.
- The Positive.txt file contains the list of positive responses to all the story lines, so for instance: line 1 of Positive will be outputted if you score well on Story line 1.
- The Negative.txt file contains the list of negative responses to all the story lines, so for instance: line 1 of Negative will be outputted if you score poorly on Story line 1.


- Story.txt - Did the user type this out correctly? <br />
- Positive.txt - Yes <br />
- Negative.txt - No <br />
---
## UML Diagram
![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/0a8f3f2f-f1b9-46f9-b669-187de03d582a)
---
## Exception Handling and Test Cases
- Loading Start.txt exception
If the file Start.txt is not opened in the program then the program will flag that this is an issue and exit the program.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/48278551-a887-4362-b948-dac6acab0214)
- Loading Story.txt exception
If the file Story.txt is not opened in the program then the program will flag that this is an issue and exit the program.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/ab835174-c8e4-4002-84a1-b0de871875bc)
- Loading Positive.txt exception
If the file Positive.txt is not opened in the program then the program will flag that this is an issue and exit the program.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/01938a55-7ead-428d-86af-fb25760d9609)
- Loading Negative.txt exception
If the file Negative.txt is not opened in the program then the program will flag that this is an issue and exit the program.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/c2955414-87a0-4e2f-adeb-63169beae2b0)
- Testing the start menu


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/9d2e7525-6168-47a8-8466-3df88bdd786c)
- Testing output of story line


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/b8baba53-2f2b-43ab-a8d1-cf0a25434fae)
- Testing output of positive outcome


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/4d1c8368-c970-4eb1-8ed7-3edc8223a8e1)
- Testing output of negative outcome


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/14f9fd4b-bf45-4c93-bb97-9892786c342f)
- Testing player death


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/e45227a4-ff5e-4d61-ac12-39f0a1bdd9ed)
- Testing player winning


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/f41c969f-0f99-43c9-9f23-55bbc9f9b4df)


After extensive testing there were a number of things that would break the program. Such as the user pressing enter when typing in the typing test section, this would make the text cursor skip a line and mess up the input loop of getting the chars that the player is inputting. By putting the following code inside a while loop, it prevents the program from progressing unless the user inputs a key that is not enter.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/a52f4316-ae05-4e5e-8276-5b836d2efe68)


Another issue with the program was that it would register an input whenever backspace was pressed instead of going back, this meant that backspace would be considered the next input and would mess up the games flow. The solution to this was making sure whenever the user inputted a backspace, to output a backspace and then override it with a space followed by another backspace, and then to take two iterations off the line iterator. This means that whenever the backspace is entered, it essentially ignores the backspace input and also overrides the input of the previous character.


![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/0e6dcc30-3754-4ae0-90d2-c1250a0398dc)


One remaining issue with the program is that whenever there is a long string of text outputted from a file, it may become split off as it touches the edge of the console application. This makes the text much harder to read and also harder to type. This could be solved by rewriting some of the code to make the output a constant string with line breaks instead of a continuous line or by simply adjusting the size of the console application.





