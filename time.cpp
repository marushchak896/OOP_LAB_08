#include <iostream>
#include <string>

using namespace std;




class Printed
{
protected:
    string name1;
    int amount_of_pages;
public:
    virtual ~Printed() {};
    virtual double DoAlgorithm(double x, double y, int amount)const = 0;
};

class Context
{
private:
    Printed* strategy_;
public:
    Context(Printed* strategy = nullptr) : strategy_(strategy)
    {}
    ~Context()
    {
        delete this->strategy_;
    }
    void set_strategy(Printed* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    void DoSomeBusinessLogic(double x, double y, int amount) const
    {
        double result = this->strategy_->DoAlgorithm(x,y,amount);
        std::cout << result << "\n";

    }
};



class Magazine :public Printed
{
private:
    double PageSizeX;
    double PageSizeY;
    int Amount_of_Books;
    int Period;
    float Paper;
public:
    Magazine() {};
    Magazine(double p_x, double p_y, int am, int per, string n, int pg);
    int GetPageSizeX(void);
    int GetPageSizeY(void);
    int GetAmount_of_Books(void);
    int GetPeriod(void);
    string GetName(void);
    int GetPages(void);
    double Amount_of_Paper(void);
    double Amount_of_Paper1(void);
    double DoAlgorithm(double x, double y, int amount) const override
    {
        return (x * y - amount) * 10000;
    }
};




Magazine::Magazine(double p_x, double p_y, int am, int per, string n, int pg)
{
    PageSizeX = p_x;
    PageSizeY = p_y;
    Amount_of_Books = am;
    Period = per;
}

int Magazine::GetPageSizeX(void)
{
    return PageSizeX;
}

int Magazine::GetPageSizeY(void)
{
    return PageSizeY;
}

int Magazine::GetAmount_of_Books(void)
{
    return Amount_of_Books;
}

int Magazine::GetPeriod(void)
{
    return Period;
}

string Magazine::GetName(void)
{
    return name1;
}

int Magazine::GetPages(void)
{
    return amount_of_pages;
}

double Magazine::Amount_of_Paper()
{
    double count;
    count = PageSizeX * PageSizeY * amount_of_pages / 10000;
    return count;
}

double Magazine::Amount_of_Paper1()
{
    double count1;
    count1 = PageSizeX * PageSizeY * Amount_of_Books * amount_of_pages / 10000;
    return count1;
}

class Booklet : public Printed
{
private:
    double PageSizeX;
    double PageSizeY;
    int Amount_of_Books;
public:
    Booklet() {};
    Booklet(double p_x, double p_y, int am);
    int GetPageSizeX(void);
    int GetPageSizeY(void);
    int GetAmount_of_Books(void);
    double Amount_of_Paper(void);
    double Amount_of_Paper1(void);
    double DoAlgorithm(double x, double y, int amount) const override
    {
        return x / y * 10000 + amount;
    }
};




Booklet::Booklet(double p_x, double p_y, int am)
{
    PageSizeX = p_x;
    PageSizeY = p_y;
    Amount_of_Books = am;
}

int Booklet::GetPageSizeX(void)
{
    return PageSizeX;
}

int Booklet::GetPageSizeY(void)
{
    return PageSizeY;
}

int Booklet::GetAmount_of_Books(void)
{
    return Amount_of_Books;
}

double Booklet::Amount_of_Paper()
{
    double count;
    count = PageSizeX * PageSizeY / 10000;
    return count;
}

double Booklet::Amount_of_Paper1()
{
    double count1;
    count1 = PageSizeX * PageSizeY * Amount_of_Books / 10000;
    return count1;
}


int main()
{
    Context* context = new Context(new Magazine);
    context->DoSomeBusinessLogic(12, 5, 9);
    context->set_strategy(new Booklet);
    context->DoSomeBusinessLogic(12, 5, 9);
    return 0;
}

