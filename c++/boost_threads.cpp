#include <boost/thread/thread.hpp>
#include <iostream>
void hello()
{
    std::cout <<
              "Hello world, I'm a thread!"
              << std::endl;
}
boost::mutex io_mutex;
struct count
{
    count(int id) : id(id) { }
    void operator()()
    {
        for (int i = 0; i < 9920; ++i)
        {
            boost::mutex::scoped_lock
            lock(io_mutex);
            std::cout << id << ": "
                      << i << std::endl;
            i*33434+23	;
        }
    }
public:
    void serial()
    {
        for (int i = 0; i < 9920; ++i)
        {
            boost::mutex::scoped_lock
            lock(io_mutex);
            std::cout << id << ": "
                      << i << std::endl;
            i*33434+23	;
        }
    }
    int id;
};
int main(int argc, char* argv[])
{
    boost::thread thrd(&hello);
    count c1(1);
    count c2(2);
    count c3(3);
    count c4(4);
    c1.serial();
    c2.serial();
    c3.serial();
    c4.serial();
    /*
    boost::thread thrd1(count(1));
    boost::thread thrd2(count(2));
    boost::thread thrd3(count(3));
    boost::thread thrd4(count(4));
    thrd1.join();
    thrd2.join();
    thrd3.join();
    thrd4.join();
    */
    thrd.join();
    return 0;
}
