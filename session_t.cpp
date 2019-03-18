/*
 session_t.cpp
 
 Test the class Session
 */

#include <ctime>
#include <cassert>
#include <unistd.h>

class Clock {
public:
    virtual std::time_t start() const = 0;
    virtual std::time_t now() const = 0;
};

class TimeClock : public Clock {
public:
    virtual std::time_t start() const { return now(); }
    virtual std::time_t now() const { return std::time(nullptr); }
};

class Session {
public:
    Session() : start_time(std::time(nullptr)), end_time(0) {}
    void stop() { end_time = std::time(nullptr); }
    std::time_t seconds() { return end_time - start_time; }
private:
    std::time_t start_time;
    std::time_t end_time;
};

int main() {
    
    {
        Session s;
        sleep(2);
        s.stop();
        
        assert(s.seconds() == 2);
    }
    
    return 0;
}
