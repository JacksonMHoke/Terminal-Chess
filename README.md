# Chess
 
 > Authors: \<[Jackson Hoke](https://github.com/JacksonMHoke)\>
 > \<[Grace Lee](https://github.com/glee139)\>
 > \<[Woovin Youn](https://github.com/groovinwoovin)\>

## Project Description
 > For our project we are making a pvp chess game where you can move your pieces through the terminal(if we have time we will try to add an interface to play through). We all enjoy playing games and chess seemed interesting to make one that seemed feasible and relatable. We will be using C++ as our main coding language. As for external libraries, at this moment we do not plan on using any. The player input will be the chess moves through the terminal(with mouse if we have time), and the output will be the board through terminal using different letters to represent the pieces(board graphics if we have time)
## Design Patterns
 > For one of our design patterns we chose to use the Strategy Design Pattern. We picked this design pattern because there are many different behaviors in the game that are shared between the pieces such as checking, moving, and illegal moves. More specifically some pieces share the same functionality as others(for example the queen is a bishop and a rook movement wise) and also when a pawn promotes, it's movement changes to the movement behavior of a different piece. This makes the strategy pattern a good fit as we will be able to swap behaviors and also combine different behaviors as we see fit, which will allow us to implement the features such as the case with the pawn and the queen easier. This will allow us to prevent running across problems when pawns promote and repetitive code with the queen movement.
 
 > For the second design pattern we chose to use the Factory Method pattern. We will use the Factory Method class to create the different pieces at the beginning of the game. After designing the basic chess game, we want to implement different variants of it and anticipated on having to hard code for each variant within the Game class. But with the Factory Method class, we can implement each type of variant as its own class and inherit from a base factory class.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/Chess.png)
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
