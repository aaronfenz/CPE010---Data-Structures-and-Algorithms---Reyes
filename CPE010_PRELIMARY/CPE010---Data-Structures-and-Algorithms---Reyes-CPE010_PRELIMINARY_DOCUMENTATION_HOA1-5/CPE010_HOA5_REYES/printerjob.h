#ifndef PRINTERJOB_H
#define PRINTERJOB_H

#include <string>

// Create the Job class to store a print request.
class Job{
private:
    // Store the job ID.
    int id;

    // Store the user's name.
    std::string name;

    // Store the number of pages.
    int pages;

public:

    // Initialize default values.
    Job(){
        id = 0;
        name = "";
        pages = 0;
    }

    // Initialize the job with user-provided values.
    Job(int jobId, std::string user, int numPages){
        id = jobId;
        name = user;
        pages = numPages;
    }

    // Return the job ID.
    int getId() const{
        return id;
    }

    // Return the user's name.
    std::string getName() const{
        return name;
    }

    // Return the number of pages.
    int getPages() const{
        return pages;
    }
    
};

#endif