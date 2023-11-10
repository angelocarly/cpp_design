#include <iostream>

class Visitor
{
    public:
        virtual void VisitStep1() = 0;
        virtual void VisitStep2() = 0;
        virtual void VisitStep3() = 0;
};

class VisitorImpl
    : public Visitor
{
    public:
        void VisitStep1() override
        {
            std::cout << "Visited Step 1" << std::endl;
        }

        void VisitStep2() override
        {
            std::cout << "Visited Step 2" << std::endl;
        }

        void VisitStep3() override
        {
            std::cout << "Visited Step 3" << std::endl;
        }
};

class Domain
{
    public:
        void Accept( Visitor & inVisitor, bool inReverse = false )
        {
            if( !inReverse )
            {
                inVisitor.VisitStep1();
                inVisitor.VisitStep2();
                inVisitor.VisitStep3();
            }
            else
            {
                inVisitor.VisitStep3();
                inVisitor.VisitStep2();
                inVisitor.VisitStep1();
            }
        }
};

int main()
{
    Domain theDomain;

    VisitorImpl theVisitor;
    std::cout << "Regular order" << std::endl;
    theDomain.Accept( theVisitor );
    std::cout << std::endl;

    std::cout << "Reversed order" << std::endl;
    theDomain.Accept( theVisitor, true );
}