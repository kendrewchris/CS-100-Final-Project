# Task Scheduler
 
 > Authors: Viviane Fernando (https://github.com/nwarn003) Ingrid Morales (https://github.com/IngridAMorales) Tracy Vu (https://github.com/uvutracy) Kendrew Christanto(https://github.com/kendrewchris)
 

## Project Description
* As we are all college students, productivity and time management are important skills to have as a student so that we can stay on top of all our tasks. Making an application that keeps track of our assignments along with their priorities, will make sure we succeed in our all our classes.
* We will be using C++, Git and Github to implement our task scheduler. 
* Input would be the task title, description, classifications (school, personal, work), and priority. The user will prioritize each task and classification. Our program sorts our subtasks depending on urgency of the task and the urgency of the classification. 

 
## Class Diagram
![image](https://user-images.githubusercontent.com/68444503/144005199-cd2355f0-9853-4150-a587-ea13e45bec3e.png)


 
 ## Design Patterns
* We will be using the composite pattern to implement our task lists for our task scheduler. We decided to use the composite design pattern because a task list is a hierarchy of tasks that are composed with subtasks. When the user creates a task, they will have the option to extend the task to include subtasks as part of this one task. Subtasks cannot have other subtasks so they are the primitive types of the composite pattern. Implementing the composite design pattern simplified structuring the task lists. 
* We will be using the strategy design pattern to implement the classification for our task scheduler because we want to sort the tasks lists based on priority of each task and the priority of each classification.  Each concrete strategy class displays a different sorted task list.  We decided to use the strategy design pattern because we want the user to be able to change the classification of a task into either "school", "personal", or work" which is defined by numbers 1, 2, and 3.  By ranking the tasks by 1, 2, or 3, it will determine the magnitude of the priority of the classification for each task and rank the tasks for the user.


 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
* Download all files in master onto your local repository
* Run following commands: cmake3 .  make ./main 
 ## Testing
 * We used unit tests to validate the composite and strategy pattern. 
 
