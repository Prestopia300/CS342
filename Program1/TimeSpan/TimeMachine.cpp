#include <iostream>
#include "TimeSpan.h";
using namespace std;

void main()
{
    TimeSpan dur1(1, 1, 1);
    TimeSpan dur3 =(dur1);
    TimeSpan dur2(0, 0, 0);
    TimeSpan dur4 = -dur1;
    for (int i = 0; i < 195; i++)
    {
        cout << (dur1 += dur3) << endl;
        cout << (dur2 += dur4) << endl;
    }
  





    //// Professor Dimpsey's Tests

    //int waitVar;
    //
    //TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
    //TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
    //
    //dur7 = dur1 + dur3;
   
    //cout << dur1 << endl;
    //cout << dur2 << endl;
    //cout << dur3 << endl;
    //cout << dur4 << endl;
    //cout << dur5 << endl;
    //cout << dur6 << endl;
    //cout << dur7 << endl;
    //
    //dur7 += dur3;
    //cout << dur3 << endl;
    //cout << dur7 << endl;

    //if (dur3 != dur6) 
    //{ 
    //    cout << "Durations are different" << endl; 
    //}
    //else 
    //{ 
    //    cout << "Durations are the same" << endl; 
    //}
    //
    //
    //// Preston's Operator Tests
    //
    //TimeSpan opDur1(1, 1, 1), opDur2(2, 2, 2), opDur3(3, 3, 3);
    //TimeSpan opDur4(4.4), opDur5(0, 0, 4.4);
    //TimeSpan opDur6(1, 1, 1), opDur7(-1, -1, -1);
    //TimeSpan opDur8(0, 0, 0), opDur9(2, 2, 2);
    //
    //// != test
    //cout << "Testing !=" << endl; 
    //cout << opDur1 << "   !=   " << opDur2 << endl;
    //if (opDur1 != opDur2)
    //{ 
    //    cout << "Durations are different\n\n"; 
    //}
    //else 
    //{ 
    //    cout << "Durations are the same\n\n"; 
    //}
    //
    //// == test
    //cout << "Testing ==" << endl;
    //cout << opDur4 << "   ==   " << opDur5 << endl;
    //if (opDur4 == opDur5)
    //{
    //    cout << "Durations are equal\n\n" << endl;
    //}
    //else
    //{
    //    cout << "Durations are not equal\n\n" << endl;
    //}

    //// + test
    //cout << "Testing +" << endl; 
    //cout << opDur1 << "   +   " << opDur2 << endl;
    //if (opDur1 + opDur2 == opDur3)
    //{
    //    cout << "addition was successful" << "\n\n";
    //}
    //else
    //{
    //    cout << "addition was not successful" << "\n\n";
    //}

    //// - test 
    //cout << "Testing -" << endl; 
    //cout << opDur3 << "   -   " << opDur1 << endl;
    //if (opDur3 - opDur1 == opDur2)
    //{
    //    cout << "subtraction was successful" << "\n\n";
    //}
    //else
    //{
    //    cout << "subtraction was not successful" << "\n\n";
    //}

    //// - (unary negation) test
    //cout << "Testing -(unary negation)" << endl;
    //cout << opDur6 << "   *(-1)   " << opDur7 << endl;
    //if (-opDur6 == opDur7)
    //{
    //    cout << "Unary negation successful\n\n" << endl;
    //}
    //else
    //{
    //    cout << "Unary negation not successful\n\n" << endl;
    //}

    //// += operator test
    //cout << "Testing +=" << endl;
    //cout << opDur6 << "   +=   " << opDur7 << endl;
    //opDur6 += opDur7;
    //if (opDur6 == opDur8)
    //{
    //    cout << "+= was successful\n\n" << endl;
    //}
    //else
    //{
    //    cout << "+= was successful\n\n" << endl;
    //}

    //// -= operator test
    //cout << "Testing -=" << endl;
    //cout << opDur6 << "   -=   " << opDur7 << endl;
    //opDur6 -= opDur7;
    //if (opDur6 == opDur9)
    //{
    //    cout << "-= was successful\n\n" << endl;
    //}
    //else
    //{
    //    cout << "-= was successful\n\n" << endl;
    //}

}