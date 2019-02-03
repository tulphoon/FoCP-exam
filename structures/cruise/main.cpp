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

// TODO: not sure if works properly, only tested with the function calls defined in the main function below
Passenger * addPassengerToCruise(Passenger * pH, const std::string & name, const std::string & surname) {
    if(!pH) {
        return pH = new Passenger { name, surname, nullptr };
    }

    if(surname <= pH->surname) {
        pH->pNext = addPassengerToCruise(pH->pNext, pH->name, pH->surname);
        pH->name = name;
        pH->surname = surname;
        return pH;
    } else {
        if(pH->pNext)
            addPassengerToCruise(pH->pNext, name, surname);
        else
            pH->pNext = addPassengerToCruise(pH->pNext, name, surname);
    }
}

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

void addPassenger(Cruise * & pH, Cruise * & pT, const std::string & date, const std::string & start_harbour, const std::string & end_harbour, const std::string & name, const std::string & surname) {
    Cruise * foundCruise = findCruise(pH, start_harbour, end_harbour, date);
    if(foundCruise) {
        foundCruise->pPassengers = addPassengerToCruise(foundCruise->pPassengers, name, surname);
    } else {
        Cruise * createdCruise = addCruise(pH, pT, date, start_harbour, end_harbour);
        createdCruise->pPassengers = addPassengerToCruise(createdCruise->pPassengers, name, surname);
    }
}

Cruise * favourite(Cruise * & pH) {
    int currentMax = 0;
    Cruise * favCruise = nullptr;
    
    auto p = pH;
    while(p) { // traversing the Cruise list
        int counter = 0; // counts the number of passengers inside of a given Cruise
        auto pPass = p->pPassengers;
        while(pPass) { // traversing the passengers of a cruise
            counter++;
            pPass = pPass->pNext;
        }
        if(counter > currentMax) { // compare number of passengers in cruise to current maximum number of passengers in another cruise
            currentMax = counter;
            favCruise = p;
        }
        p = p->pNext;
    }
    return favCruise;

}

int main(int argc, char const *argv[])
{
    Cruise * head = nullptr;
    Cruise * tail = nullptr;
    addCruise(head, tail, "2016-05-14", "12:00", "12:30");
    addCruise(head, tail, "2016-04-24", "14:00", "15:30");
    addCruise(head, tail, "2016-08-12", "06:00", "07:30");
    addCruise(head, tail, "2016-07-02", "14:00", "14:30");

    Passenger * passengers = nullptr;
    passengers = addPassengerToCruise(passengers, "Janne", "Xahonen");
    passengers = addPassengerToCruise(passengers, "Adam", "Malysz");
    passengers = addPassengerToCruise(passengers, "Nopeusz", "Nopeusz");
    passengers = addPassengerToCruise(passengers, "Zir", "Zopeusz");

    addPassenger(head, tail, "2016-07-02", "14:00", "14:30", "Karol", "Krawczyk");
    addPassenger(head, tail, "2016-07-02", "14:00", "14:30", "Karol", "Adamczyk");
    addPassenger(head, tail, "2019-01-02", "07:20", "13:25", "Wojciech", "Suchodolski");

    Cruise * fave = favourite(head);
    return 0;
}
