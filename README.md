# Chess
 
 > Authors: \<[Jackson Hoke](https://github.com/JacksonMHoke)\>
 > \<[Grace Lee](https://github.com/glee139)\>
 > \<[Woovin Youn](https://github.com/groovinwoovin)\>

## Project Description
 > For our project we are making a pvp chess game where you can move your pieces through the terminal(if we have time we will try to add an interface to play through). We all enjoy playing games and chess seemed interesting to make one that seemed feasible and relatable. We will be using C++ as our main coding language. As for external libraries, at this moment we do not plan on using any. The player input will be the chess moves through the terminal(with mouse if we have time), and the output will be the board through terminal using different letters to represent the pieces(board graphics if we have time)
 
 > For one of our design patterns, we plan to use the Composite design pattern. We chose composite pattern because it seemed to fit well with the heirarchy of chess due to the nature of players controlling the board, the board controlling the pieces, and the plethora of seperate pieces that have similar uses. Since we are working with a complex tree structure that contains all the different pieces, the composite pattern allows us to utilize polymorphism to create a common interface that will let us operate on all of the pieces more easily. This will also help us implement the other design pattern we plan to use.
 
 > For the second design pattern we chose to use the Visitor pattern. We will use the visitor class to implement the different ways each piece moves, if a move is valid, if a move puts king into check, etc. This allows us to shift a lot of the burden from each piece to a singular visitor class for each of these operations. Since we anticipated a lot of clutter with having all the functionality inside the each piece class such as moving, checking if a move is valid, etc, this design pattern will allow us to move a lot of the functionality in each piece to a seperate visitor class. This will eliminate a lot of the clutter in each piece class.

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
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
