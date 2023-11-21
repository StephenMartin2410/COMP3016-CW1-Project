# **CW1-TypingTestAdventureGame**
### Visual Studio and OS version
- Visual Studio Community 2022 17.8.0
- Windows 11 Pro 23H2 - OS build 22631.2715
---
## How To Play:
1. To begin the game start by pressing the spacebar on the start menu.
2. When prompted to type out a line, type every character displayed under the prompt, including spaces and symbols.
3. Depending on how you perform in this typing test the game will either output a positive or negative story response.
4. Everytime you get a negative response you will lose health.
5. Keep playing the game until you either reach the end or die.
---
## Extra Feature
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
- Loading Start.txt
If the file Start.txt is not opened in the program then the program will flag that this is an issue and exit the program.
![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/48278551-a887-4362-b948-dac6acab0214)
- Loading Story.txt
If the file Story.txt is not opened in the program then the program will flag that this is an issue and exit the program.
![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/ab835174-c8e4-4002-84a1-b0de871875bc)
- Loading Positive.txt and Negative.txt
If the file Positive.txt or Negative.txt are not opened in the program then the program will flag that this is an issue and exit the program.
![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/01938a55-7ead-428d-86af-fb25760d9609)

![image](https://github.com/StephenMartin2410/COMP3016-CW1-Project/assets/91669127/c2955414-87a0-4e2f-adeb-63169beae2b0)




