#ifndef __LINEAR_HPP__
#define __LINEAR_HPP__

#include "tasklist.hpp"
#include "subtask.hpp"
#include "task.hpp"
#include "classification.hpp"
#include <string> 
#include <sstream>

class Linear : public Classification{
    public:
        Linear(){}
        virtual ~Linear(){}

        //need a  way to check whether tasks in subtask vector 
        virtual void display(std::vector<Tasklist*> &subtasks ){
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
	    
            for(int i = 0; i<subtasks.size(); i++){ 
                subtasks[i]->print();
	         }
	  
        }
    
};

#endif 
