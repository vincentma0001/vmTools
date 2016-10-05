/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTstCaseForTmp.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 23/2/2016 10:17:07
// Modify time 	: 23/2/2016 10:17:07
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "CTstCaseForTmp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CTstCaseForTmp::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const stCmd& stuCmd
// Return    : void
// Notes     : 
// example 2
//void printer( const boost::system::error_code &ex )
//{
//    std::cout << "hello world!" << std::endl;
//}

// example 3
//void printer( const boost::system::error_code &ex, boost::asio::deadline_timer *t,  int* iCount )
//{
//    if (*iCount<5)
//    {
//        std::cout << *iCount << std::endl;
//        ++(*iCount);
//
//        t->expires_at( t->expires_at()+boost::posix_time::seconds(1) );
//        t->async_wait( boost::bind( printer, boost::asio::placeholders::error, t, iCount ) );
//    }
//}

// example 4
//class printer
//{
//private:
//    boost::asio::deadline_timer timer_;
//    int count_;
//public:
//    printer( boost::asio::io_service& io )
//        : timer_( io, boost::posix_time::seconds(1) ),
//        count_(0)
//    {
//        timer_.async_wait(boost::bind(&printer::print, this));
//    }
//    ~printer()
//    {
//        std::cout << "Final count is " << count_ << std::endl;
//    }
//    void print()
//    {
//        if (count_<5)
//        {
//            std::cout << count_ << std::endl;
//            ++count_;
//
//            timer_.expires_at( timer_.expires_at()+boost::posix_time::seconds(1) );
//            timer_.async_wait( boost::bind( &printer::print, this ) );
//        }
//    }
//};

// example 5
class printer
{
private:
    boost::asio::io_service::strand strand_;
    boost::asio::deadline_timer     timer1_;
    boost::asio::deadline_timer     timer2_;
    int count_;
public:
    void print1()
    {
        if ( count_ < 10 )
        {
            std::cout << "TID["<< boost::thread::id()<<"] "" Timer 2 : " << count_ << std::endl;
            ++count_;

            timer1_.expires_at( timer1_.expires_at()+boost::posix_time::seconds(1) );
            timer1_.async_wait( strand_.wrap(boost::bind(&printer::print1,this)) );
        }
    }
    void print2()
    {
        if ( count_ < 20 )
        {
            std::cout << "TID["<< boost::thread::id()<<"] "" Timer 2 : " << count_ << std::endl;
            ++count_;

            timer2_.expires_at( timer2_.expires_at()+boost::posix_time::seconds(2) );
            timer2_.async_wait( strand_.wrap(boost::bind(&printer::print2, this)) );
        }
    }

public:
    printer( boost::asio::io_service& io )
        :strand_(io),
        timer1_(io, boost::posix_time::seconds(1)),
        timer2_(io, boost::posix_time::seconds(2)),
        count_(0)
    {
        timer1_.async_wait( strand_.wrap(boost::bind(&printer::print1, this)) );
        timer2_.async_wait( strand_.wrap(boost::bind(&printer::print2, this)) );
    }
    ~printer()
    {
        std::cout << "Final count is" << count_ << std::endl;
    }
};

void CTstCaseForTmp::OnExcute(const stCmd& stuCmd)
{
    std::cout << "This is a test for test!" << std::endl;

    //using namespace boost::lambda;
    //typedef std::istream_iterator<int> in;

    //std::for_each( in(std::cin), in(), std::cout << (_1 * 3) << " " );

    // example 1
    //boost::asio::io_service io;
    //boost::asio::deadline_timer t( io, boost::posix_time::seconds(5)  );
    //t.wait(  );
    //std::cout << "hello world!" << std::endl;

    // example 2
    //boost::asio::io_service io;
    //boost::asio::deadline_timer t( io, boost::posix_time::seconds(5) );
    //t.async_wait( &printer );
    //io.run();

    // example 3
    //boost::asio::io_service io;
    //int liCount = 0;
    //boost::asio::deadline_timer t( io, boost::posix_time::seconds(1) );
    //t.async_wait( boost::bind(printer, boost::asio::placeholders::error, &t, &liCount ) );
    //io.run();

    // example 4
    //boost::asio::io_service io;
    //printer p(io);
    //io.run();

    // example 5
    boost::asio::io_service io;
    printer p(io);
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
    io.run();
    t.join();


} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTstCaseForTmp.cpp
/////////////////////////////////////////////////////////////////////////////////////////