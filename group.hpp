#ifndef __GROUP_HPP__
#define __GROUP_HPP__

#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"


class Group : public Classification{
   private: 
	int school, personal, work;  
   public:
   //user should only have option to choose values 1-3
        Group(int s, int p, int w): school(s), personal(p), work(w) {}
        virtual ~Group(){}

        void display(std::vector<Tasklist*> &subtasks){
            std::cout <<"Subtasks size: "<< subtasks.size()<< "\n\n";

            for(int i = 0; i<subtasks.size()-1; i++){
                int max = i;
                for(int j = i+1; j<subtasks.size(); j++){
                    if(subtasks[j]->get_Priority() > subtasks[max]->get_Priority())
                        max = j;
		        }
                Tasklist* temp = subtasks[max];
                subtasks[max] = subtasks[i];
                subtasks[i] = temp;
            }
            
            if(school == 3)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "School")
                        subtasks[i]->print();
            if(personal==3)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Personal")
                        subtasks[i]->print();
            if(work==3)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Work")
                        subtasks[i]->print();

            if(school==2)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "School")
                        subtasks[i]->print();
            if(personal==2)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Personal")
                        subtasks[i]->print();
            if(work==2)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Work")
                        subtasks[i]->print();
            
            if(school==1)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "School")
                        subtasks[i]->print();
            if(personal==1)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Personal")
                        subtasks[i]->print();
            if(work==1)
                for(int i =0; i<subtasks.size(); i++)
                    if(subtasks[i]->get_Classif() == "Work")
                        subtasks[i]->print();
            std::cout << "\n\n";
	}
 
};

#endif 
