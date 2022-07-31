#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include <vector>
#include <string>
class Tasklist {
private: 
   //Tasklist* main_task; 
   int priority; 
public: 
   virtual ~Tasklist() {}
/*
   void SetParent(Tasklist* task) { 
	this->main_task = task; 
   }
*/ 
   virtual void set_classif(std::string c) = 0; 
   virtual void set_priority(int i) = 0; 
   virtual void set_descrip(std::string d) = 0;
   virtual void set_title(std::string t) = 0; 
     
   //Each row holds each tasks title, descrip, priority, and classification along that of their subtasks
   //Can be used to print each tasklist 
   virtual std::vector<std::string> get_data() = 0;
   virtual std::string get_title() = 0;
   virtual int get_Priority() = 0;
   virtual std::string get_Classif() = 0; 
   virtual void print() = 0;
}; 
#endif 
