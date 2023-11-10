#include <iostream>

class Visitor
{
    public:
        virtual void EnterDomain( std::string const & inName ) = 0;
        virtual void ExitDomain( std::string const & inName ) = 0;
};

class VisitorImpl
    : public Visitor
{
    public:
        void EnterDomain( std::string const & inName ) override
        {
            for( int i = 0; i < mIndentationLevel; ++i ) std::cout << "  ";
            std::cout << "Enter: " << inName << std::endl;
            mIndentationLevel++;
        }

        void ExitDomain( std::string const & inName ) override
        {
            mIndentationLevel--;
            for( int i = 0; i < mIndentationLevel; ++i ) std::cout << "  ";
            std::cout << "Exit:  " << inName << std::endl;
        }

    private:
        std::size_t mIndentationLevel{ 0 };
};

class Domain
{
    public:
        Domain( std::string inName, bool inReverse = false )
        : mName( inName ), mReverse( inReverse )
        {
        }

        void AddSubDomain( Domain const & inSubDomain )
        {
            mSubDomains.push_back( inSubDomain );
        }

        void Accept( Visitor & inVisitor )
        {
            inVisitor.EnterDomain( mName );
            if( mReverse )
            {
                for( auto it = mSubDomains.rbegin(); it != mSubDomains.rend(); ++it )
                {
                    it->Accept( inVisitor );
                }
            }
            else
            {
                for( auto it = mSubDomains.begin(); it != mSubDomains.end(); ++it )
                {
                    it->Accept( inVisitor );
                }
            }
            inVisitor.ExitDomain( mName );
        }

    private:
        std::string mName;
        bool mReverse{ false };
        std::vector< Domain > mSubDomains;
};

int main()
{
    Domain theDomain( "root" );
    theDomain.AddSubDomain( Domain( "A" ) );
    theDomain.AddSubDomain( Domain( "B" ) );

    Domain theSubDomain( "C", false );
    theSubDomain.AddSubDomain( Domain( "D" ) );
    theSubDomain.AddSubDomain( Domain( "E" ) );
    theSubDomain.AddSubDomain( Domain( "F" ) );
    theDomain.AddSubDomain( theSubDomain );

    VisitorImpl theVisitor;
    theDomain.Accept( theVisitor );
    std::cout << std::endl;

}