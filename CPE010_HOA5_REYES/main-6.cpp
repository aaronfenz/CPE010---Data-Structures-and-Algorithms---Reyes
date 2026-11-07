#include "SharedPrinter.h"

int main()
{
    // Create the shared printer.
    Printer printer;

    // Add the first print job.
    printer.addJob(Job(101, "Joma", 10));

    // Add the second print job.
    printer.addJob(Job(102, "Carlo", 6));

    // Add the third print job.
    printer.addJob(Job(103, "Rodney", 8));

    // Process the print jobs in FIFO order.
    printer.processJobs();

    // End the program.
    return 0;
}