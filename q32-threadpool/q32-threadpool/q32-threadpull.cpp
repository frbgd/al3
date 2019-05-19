#include <thread>
#include <vector>
#include <iostream>

void report( int i ) 
{
	std::cout<< "Thread" << i << " was here\n";
}

int main() 
{
	unsigned nthreads = std::thread::hardware_concurrency();
	std::vector<std::thread> threads;
	for( unsigned i=0; i<nthreads; ++i )
		threads.push_back( std::thread(report, i) );
	for( auto& t: threads )
		t.join();
	return 0;
}