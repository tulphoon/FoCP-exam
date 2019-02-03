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

Cruise * addCruise(Cruise * & pH, Cruise * & pTail, const std::string & date, const std::string & start_harbour, const std::string & end_harbour) {
    if(!pH) {
        return pTail = pH = new Cruise {start_harbour, end_harbour, date, nullptr, nullptr, nullptr }; // add element to empty list
    } else if(date <= pH->date) {
        pH = new Cruise {start_harbour, end_harbour, date, nullptr, nullptr, pH }; // insert at the beginning of a list
        pH->pNext->pPrev = pH;
        return pH;
    } else if(date >= pTail->date) {
        pTail->pNext = new Cruise {start_harbour, end_harbour, date, nullptr, pTail, nullptr}; // insert at the end of a list
        pTail = pTail->pNext;
        return pTail;
    }

    auto p = pH;
    while(p) {
        if(date <= p->date) {
            p->pPrev->pNext = new Cruise {start_harbour, end_harbour, date, nullptr, p->pPrev, p}; // insert in between two existing elements
            p->pPrev = p->pPrev->pNext;
            return p->pPrev;
        }
        p = p->pNext;
    }

    return nullptr;
}

int main(int argc, char const *argv[])
{
    Cruise * head = nullptr;
    Cruise * tail = nullptr;
    addCruise(head, tail, "2016-05-14", "12:00", "12:30");
    addCruise(head, tail, "2016-04-24", "14:00", "15:30");
    addCruise(head, tail, "2016-08-12", "06:00", "07:30");
    addCruise(head, tail, "2016-07-02", "14:00", "14:30");
    return 0;
}
