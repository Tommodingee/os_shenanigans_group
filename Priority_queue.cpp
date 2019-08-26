#include "Priority_queue.h"
#include <iostream>

using namespace std;

void Priority_queue::customer_to_back_q1()
{
    queue.emplace(queue.begin()+queue2_front_index, queue.front());
    queue.pop_front();
}

void Priority_queue::process_q1()
{
    //if new customer, initilaise new customer_time_remaining
    if(new_customer)
    {
        customer_time_remaining = (8 - queue.front()->get_priority()) * 10;
        new_customer = false;
    }

    //if customer has tickets remaining - reduce time remaining by 1 clock cycle
    customer_time_remaining -= 5;


/*****     CASE ONE : Finished customer order     *****/

    //update customer's ticket value
    //if customer has all tickets processed (if true)
    if( queue.front()->update_tix() )
    {
        //print customer's details to output buffer
        output_completed_customer();
        //delete customer
        queue.pop_front();
        new_customer = true;
        queue2_front_index--;
        return;
    }


/*****     CASE TWO : Not finished customer order. Place customer in correct queue pos     *****/

    //if customer has reached end of their allotted clock time
    if(customer_time_remaining <= 0)
    {
        //if true, priority of customer needs to be incremented
        if ( queue.front()->update_rds_q1() )
        {
            //if true, customer needs to be demoted to queue 2
            if ( queue.front()->update_pri_q1() )
            {
                //puts customer at "back of queue 2"
                queue.push_back(queue.front());
                queue.pop_front();
                new_customer = true;
                queue2_front_index--;
                return;
            }
            else
            {
                customer_to_back_q1();
                new_customer = true;
                return;
            }
        }
        //if false, customer needs to be put to "back of queue 1"
        else
        {
            customer_to_back_q1();
            new_customer = true;
            return;
        }
    }
    cout << "REACHED END OF process_q1()" << endl;
}
