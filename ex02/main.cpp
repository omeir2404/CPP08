#include "MutantStack.hpp"
#include <list>
#include <cassert>
void MutantStackTest()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void listTest()
{
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    //[...]
    l.push_back(0);
    std::list<int>::iterator it = l.begin();
    std::list<int>::iterator ite = l.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
void additionalMutantStackTests()
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    // Test top() function
    assert(mstack.top() == 30);

    // Test pop() function
    mstack.pop();
    assert(mstack.top() == 20);

    // Test size() function
    assert(mstack.size() == 2);

    // Test iterator functions
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    // Test dereferencing iterator
    assert(*it == 10);

    // Test incrementing iterator
    it++;
    assert(*it == 20);
    
    // Test decrementing iterator
    it--;
    assert(*it == 10);

    // Test iterator comparison
    assert(it != ite);

    // Test iterator traversal
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "All tests Passed\n";
}

int main()
{
    MutantStackTest();
    std::cout << "--------------------\n";
    listTest();
    std::cout << "--------------------\n";
    additionalMutantStackTests();

    return 0;
}