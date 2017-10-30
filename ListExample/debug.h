#ifndef DEBUG_H

#define DEBUG_H

// **** set VERBOSE to true if you want verbose output ****
#define VERBOSE false

#if VERBOSE
#define print1(val1) std::cout << val1 << std::endl
#define print2(val1,val2) std::cout << val1 << val2 << std::endl
#define print3(val1,val2,val3) std::cout << val1 << val2 << val3 << std::endl
#define print4(val1,val2,val3,val4) std::cout << val1 << val2 << val3 << val4 << std::endl
#else
#define print1(val1) 
#define print2(val1,val2) 
#define print3(val1,val2,val3)
#define print4(val1,val2,val3,val4)
#endif

#endif // DEBUG_H
