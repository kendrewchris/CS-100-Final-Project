#ifndef __CLASSIFICATION_HPP__
#define __CLASSIFICATION_HPP__

#include "task.hpp"
#include "tasklist.hpp"


class Classification{
    private:
        int priority;
        char flair;
        int date;
    public:
        Classification(){}
        virtual ~Classification(){}

        virtual void display(std::vector<Tasklist*> &subtasks) = 0;
    
};


#endif 
