#include <string>

struct Passenger {
    std::string name, surname;
    Passenger * pNext;
};

struct Cruise {
    std::string start_harbour, end_harbour;
    std::string date;
    Passenger * pPassengers;
    Cruise * pPrev, * pNext;
};

Cruise * findCruise(Cruise * pH, const std::string & start_harbour, const std::string & end_harbour, const std::string & date) {
    if(!pH)
        return nullptr;
    
    if(date == pH->date and start_harbour == pH->start_harbour and end_harbour == pH->end_harbour)
        return pH;

    return findCruise(pH->pNext, start_harbour, end_harbour, date);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
