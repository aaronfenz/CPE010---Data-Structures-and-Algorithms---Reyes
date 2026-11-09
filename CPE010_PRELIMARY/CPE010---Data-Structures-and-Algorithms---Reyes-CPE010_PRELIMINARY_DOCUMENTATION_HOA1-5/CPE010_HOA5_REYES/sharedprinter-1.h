#ifndef SHAREDPRINTER_H
#define SHAREDPRINTER_H

#include <iostream>
#include "PrinterJob.h"

// Create the Printer class.
class Printer{
private:

    // Set the maximum number of print jobs.
    static const int MAX = 5;

    // Create the queue using an array.
    Job queue[MAX];

    // Track the first job in the queue.
    int front;

    // Track the last job in the queue.
    int rear;

public:

    // Initialize an empty queue.
    Printer(){
        front = 0;
        rear = -1;
    }

    // Check whether the queue has no jobs.
    bool isEmpty(){
        return rear < front;
    }

    // Check whether the queue is full.
    bool isFull(){
        return rear == MAX - 1;
    }

    // Add a new print job to the rear of the queue.
    void addJob(Job job){
        // Check if the queue is already full.
        if (isFull()){
            std::cout << "Printer queue is full.\n";
            return;
        }

        // Move the rear pointer.
        rear++;

        // Store the new job.
        queue[rear] = job;

        // Display the added user.
        std::cout << "\n===== Added User =====\n";
        std::cout << "Job ID : " << job.getId() << std::endl;
        std::cout << "Name   : " << job.getName() << std::endl;
        std::cout << "Pages  : " << job.getPages() << std::endl;

        // Display the current queue.
        std::cout << "\nCurrent Queue (First Come, First Serve)\n";

        for (int i = front; i <= rear; i++){
            std::cout << queue[i].getId()
                      << " - "
                      << queue[i].getName()
                      << " ("
                      << queue[i].getPages()
                      << " pages)"
                      << std::endl;
        }

        std::cout << std::endl;
    }

    // Process all jobs using FIFO.
    void processJobs(){
        // Check if there are no jobs.
        if (isEmpty()){
            std::cout << "No jobs to process.\n";
            return;
        }

        std::cout << "\n===== Processing Jobs =====\n";

        // Continue until every job has been processed.
        while (!isEmpty()){
            // Print the first job in the queue.
            std::cout << "\nPrinting Job "
                      << queue[front].getId()
                      << " - "
                      << queue[front].getName()
                      << " ("
                      << queue[front].getPages()
                      << " pages)"
                      << std::endl;

            // Remove the processed job.
            front++;

            // Display the queue after processing.
            std::cout << "\nQueue After Processing\n";

            if (isEmpty()){
                std::cout << "Queue is empty.\n";
            }else{
                for (int i = front; i <= rear; i++)
                {
                    std::cout << queue[i].getId()
                              << " - "
                              << queue[i].getName()
                              << " ("
                              << queue[i].getPages()
                              << " pages)"
                              << std::endl;
                }
            }
        }

        // Display the final queue.
        std::cout << "\n===== Final Queue =====\n";
        std::cout << "Queue is empty.\n";

        // Display completion message.
        std::cout << "\nAll jobs completed.\n";
    }
};

#endif