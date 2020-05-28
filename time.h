#include <iostream>
#include <time.h>

using namespace std;

class Сalendar {
private:
    int day;
    int month;
    int year;

    Сalendar(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    static Сalendar* singleton_;
public:
    static Сalendar* GetInstance(int d, int m, int y);

    int GetDay(void);
    int GetMonth(void);
    int GetYear(void);
    int DateDifference();
    void Vyvid();

    int operator--()
    {
        int day_ = this->day;
        int month_ = this->month;
        int year_ = this->year;
        day_ = day_ - 1;
        if ((day_ == 0 && month_ == 5) || (day_ == 0 && month_ == 7) || (day_ == 0 && month_ == 10) || (day_ == 0 && month_ == 12))
        {
            month_ = month_ - 1;
            day_ = 30;
        }
        else if (day_ == 0 && month_ == 3)
        {
            day_ = 28;
            month_ = month - 1;
        }
        else if (day_ == 0)
        {
            day_ = 31;
            month_ = month - 1;
        }
        if (month_ == 0)
        {
            month_ = 12;
            year_ = year_ - 1;
        }
        return (this->day = day_, this->month = month_, this->year = year_);
    }

    Сalendar(Сalendar& other) = delete;
    void operator=(const Сalendar&) = delete;

    ~Сalendar() {};
};





int Сalendar::GetDay(void) {
    return day;
}

int Сalendar::GetMonth(void) {
    return month;
}

int Сalendar::GetYear(void) {
    return year;
}

void Сalendar::Vyvid()
{
    cout << "Попередній день:";
    cout << day << "." << month << "." << year << endl;
}


int Сalendar::DateDifference()
{
    int d1, m1, y1;
    d1 = this->day;
    m1 = this->month;
    y1 = this->year;
    int count = 0;
    for (int y_ = 1970; y1 > y_; y1--)
    {
        for (m1; m1 > 0; m1--)
        {
            for (d1; d1 > 0; d1--)
            {
                count++;
            }
            if (m1 == 2)
                d1 = 28;
            else if ((m1 == 4) || (m1 == 6) || (m1 == 9) || (m1 == 11))
                d1 = 30;
            else
                d1 = 31;
        }
        m1 = 12;
    }
    return count;
}

Сalendar* Сalendar::GetInstance(int d, int m, int y)
{

    if (singleton_ == nullptr) {
        singleton_ = new Сalendar(d,m,y);
    }
    return singleton_;
}

Сalendar* Сalendar::singleton_ = nullptr;;


int main() {
    Сalendar* _calendar = Сalendar::GetInstance(2, 4, 1985);
    _calendar->Vyvid();
    Сalendar* _calendar45 = Сalendar::GetInstance(7, 9, 2020);
    _calendar45->Vyvid();
 

}

