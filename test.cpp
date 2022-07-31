#include "gtest/gtest.h"
#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "unittest.hpp"
#include "classification.hpp"
#include "linear.hpp"

TEST(GetData, GetTaskData){ 
  Tasklist* test = new Tasks("Final Project", "Task Scheduler",1,"School"); 
  std::vector<std::string> v{"Final Project", "Task Scheduler", "1", "School"}; 
  EXPECT_EQ(test->get_data(),v); 
  delete test; 
}

TEST(AddTasks,AddingTasklist) { 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School");  
  test->add_task(task); 
  task->add_task(subtask); 
  std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Scrum Meeting", "Catch up","1","School" };
 EXPECT_EQ(test->get_data(), v); 
  delete test; 
}

TEST(AddTasks,TwoComposites) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Tasks("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Scrum Meeting", "Catch up","1","School" };

 EXPECT_EQ(test->get_data(), v);
  delete test; 
}

TEST(DeleteTask, DeleteComposite) { 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  test->delete_task(task);

   std::vector<std::string> v{"Cs100", "Software Construction", "1", "School"};
   EXPECT_EQ(test->get_data(),v );
   delete test; 
}

TEST(DeleteTask, DeleteLeaf) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Subtask("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  task->delete_task(subtask);

   std::vector<std::string> v{"Final Project", "Task Scheduler", "1", "School"};
EXPECT_EQ(task->get_data(), v);
  delete test; 
}

TEST(SetTask, SetTitle){ 
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  test->set_title("135a"); 
   std::vector<std::string> v{"135a", "Software Construction", "1", "School"};
EXPECT_EQ(test->get_data(), v); 
  delete test; 
}

TEST(EditTask, EditSubTaskTitle) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Tasks("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  task->edit_title(subtask, "Sprint"); 
std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Sprint", "Catch up","1","School" };
EXPECT_EQ(test->get_data(),v);
  delete test; 
}
TEST(EditTask, EditWholeSubTask) {
  Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School");
  Tasks* task = new Tasks("Final Project", "Task Scheduler", 1,"School");
  Tasklist* subtask = new Tasks("Scrum Meeting", "Catch up", 1,"School");
  test->add_task(task);
  task->add_task(subtask);
  task->edit_title(subtask, "Sprint");
  task->edit_descrip(subtask, "Daily meeting"); 
  task->edit_priority(subtask, 3); 
  task->edit_classif(subtask, "Personal"); 
std::vector<std::string> v{"Cs100","Software Construction","1","School","Final Project", "Task Scheduler", "1", "School","Sprint", "Daily meeting","3","Personal" };
EXPECT_EQ(test->get_data(),v);
  delete test; 
}


TEST(Linear, DisplayFunction){

   Tasks* test = new Tasks("Cs100", "Software Construction", 1,"School"); 
    Tasks* task = new Tasks("Final Project", "Task Scheduler", 2,"Work");
    Tasks* subtask1 = new Tasks("Scrum Meeting", "Catch up", 5,"School"); 

    test->add_task(task); 
    test->add_task(subtask1); 

    Classification* sort1 = new Linear(); 
    test->set_strat(sort1); 
    test->printAll();

    std::vector<Tasklist*> compare; 

    compare.push_back(subtask1);
    compare.push_back(task);

    EXPECT_EQ(test->get_Subtasks(), compare);
    delete test;
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
