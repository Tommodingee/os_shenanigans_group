#ifndef PR_QUEUE
#define PR_QUEUE
#include <deque>
#include <vector>

#include "Customer.h"

//deque customer processing binary heap implementation
class Priority_queue
{
    std::deque<Customer> queue;
    int customer_time_remaining;
    int queue2_front_index;
    bool new_customer;

    void customer_to_back_q1();

public:
    Priority_queue();

    //return true if queue is empty
    //if front() == queue2_front_index
    bool is_empty_q1();

    //inserts a Customer based on priority - return false on fail
    bool insert_at_priority(Customer*);

    //update Customer object's values and move to new queue position
    //delete customer if they are finished
    void process_q1(); //BIGBOIFUNCTION

    //return index of customer in the queue with id
    int find_customer_with_id(std::string);

    //remove customer and write to output buffer
    void output_completed_customer();

    ~Priority_queue();
};

#endif
