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

class TwoSecondClock : public Clock {
public:
    virtual std::time_t start() const { return 0; }
    virtual std::time_t now() const { return 2; }
};

class HourClock : public Clock {
public:
    virtual std::time_t start() const { return 0; }
    virtual std::time_t now() const { return 60 * 60; }
};

class Session {
public:
    Session(const Clock& clock = TimeClock()) : clock(clock), start_time(clock.start()), end_time(0) {}
    void stop() { end_time = clock.now(); }
    std::time_t seconds() { return end_time - start_time; }
private:
    const Clock& clock;
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

    {
        TwoSecondClock c;
        Session s(c);
        s.stop();
        
        assert(s.seconds() == 2);
    }

    {
        HourClock c;
        Session s(c);
        s.stop();
        
        assert(s.seconds() == 60 * 60);
    }

    return 0;
}
