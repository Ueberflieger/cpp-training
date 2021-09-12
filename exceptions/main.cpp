#include <iostream>
#include <exception>

using namespace std;

class MyException: exception
{
    private:
        const char *msg;
    
    public:
        MyException(const char *msg)
        {
            this->msg = msg;
        }

        const char* what() const throw()
        {
            return msg;
        }
};

void throw_string_exception()
{
    throw "string exception";
}

void throw_std_exception()
{
    throw exception();
}

void throw_custom_exception()
{
    throw MyException("Hello my exception");
}

int main(void)
{
    // exception handling in cpp is based around three key words:
    // try - start of a block that might throw an exception (protected block)
    // throw - throws the exception
    // catch - block that handles an exception

    // The following function always throws an exeption of type
    // const char*
    try {
        throw_string_exception();
    } catch (const char *msg)
    {
        cout << "caught an error" << endl;
        cerr << msg << endl;
    }

    // The following catch catches all exceptions
    try {
        throw_string_exception();
    } catch (...)
    {
        cout << "Caught an exception" << endl;
    }

    // Cpp provides a set of standard exceptions
    cout << "Throw a standard exception" << endl;
    try {
        throw_std_exception();
    } catch (exception &e)
    {
       cout << "Caught a standard exception: " << e.what() << endl;
    }

    // Throw a custom exception
    cout << "Throw a custom exception" << endl;
    
    try {
        throw_custom_exception();
    } catch (MyException &my_exception)
    {
        cerr << "Caught MyException: " << my_exception.what() << endl;

    }
    

    return 0;
}
