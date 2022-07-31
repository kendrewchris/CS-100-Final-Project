#ifndef __MAGNITUDE_HPP__
#define __MAGNITUDE_HPP__

#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"


class Magnitude : public Classification{
   private: 
	int school, personal, work;  
   public:
        Magnitude(int s, int p, int w): school(s), personal(p), work(w) {}
        virtual ~Magnitude(){}

//need a  way to check whether tasks in subtask vector 
        void display(std::vector<Tasklist*> &subtasks){
	std::cout <<"Subtasks size: "<< subtasks.size()<< "\n\n";
            std::vector<int> placeholders;
            for(int i=0; i<subtasks.size(); i++){
                if(subtasks[i]->get_Classif() == "School")
                    placeholders.push_back(subtasks[i]->get_Priority()*school);
                else if (subtasks[i]->get_Classif() == "Personal")
                    placeholders.push_back(subtasks[i]->get_Priority()*personal);
                else if(subtasks[i]->get_Classif() == "Work")
                    placeholders.push_back(subtasks[i]->get_Priority()*work);
            }
            for(int i = 0; i<placeholders.size()-1; i++){
                int max = i;
                for(int j = i+1; j<placeholders.size(); j++)
                    if(placeholders[j] > placeholders[max])
                        max = j;
                Tasklist* temp = subtasks[max];
                subtasks[max] = subtasks[i];
                subtasks[i] = temp;
		            int temp2 = placeholders[max];
                placeholders[max] = placeholders[i];
                placeholders[i] = temp2;
            }
            for(int i = 0; i<subtasks.size(); i++)
                subtasks[i]->print();
	}
 
};

#endif 
