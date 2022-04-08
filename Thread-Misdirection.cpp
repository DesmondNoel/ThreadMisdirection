
#include <iostream>
#include <windows.h>





/////////////Hiding thread startpoint 
void suba()
{
	std::cout << "I should be called";
}
void subb()
{
	std::cout << "I should not be called";
}

CONTEXT ctx; //CONTEXT structure https://docs.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-context
class customthread
{
public:
	HANDLE thread_handle;


	void create_thread(LPTHREAD_START_ROUTINE routine)
	{
		this->thread_handle = CreateThread(0, 0, routine, 0,  4, 0); //4 signales that we want this thread to be spawned suspended immediately
	}

	customthread(void (*fakedcall)(), void (*realcall)())
	{
		this->create_thread(reinterpret_cast<LPTHREAD_START_ROUTINE>(realcall));


		ctx.ContextFlags = CONTEXT_INTEGER;  

		GetThreadContext(this->thread_handle, &ctx); //Allows us to modify the endpoint of the thread
 
#ifdef _WIN64
		ctx.Rip = (DWORD)fakedcall;
#else
		ctx.Eip = (DWORD)fakedcall;
#endif
		
		ctx.ContextFlags = CONTEXT_INTEGER;

		SetThreadContext(this->thread_handle, &ctx); //The thread now points at our realcall function

		ResumeThread(this->thread_handle);//The thread is now executing


	}
};


int main()
{
	customthread thread(&subb, &suba);
}

