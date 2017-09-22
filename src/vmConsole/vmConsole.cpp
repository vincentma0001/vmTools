/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmConsole.cpp
// Version 		: 0.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 4/5/2017 13:46:08
// Modify time 	: 4/5/2017 13:46:08
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <sstream>
#include <iostream>
#include <string>

#include "vmConsole.h"
#include "vmConsoleParams.h"
#include "vmConsoleCaseFactory.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define

static bool gbIsExit=true;						// 是否退出进程

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : vmConsole
// Full name : vmConsole::vmConsole
// Access    : private 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
vmConsole::vmConsole()
{

} // End of function vmConsole(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : vmConsole
// Full name : vmConsole::vmConsole
// Access    : private 
// Brief     : 
// Parameter : const vmConsole& obj
// Return    : 
// Notes     : 
vmConsole::vmConsole(const vmConsole& obj)
{

} // End of function vmConsole(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RegCase
// Full name : vmConsole::RegCase
// Access    : public 
// Brief     : 
// Parameter : const char* szActionName, PACTFUNC pActFunc
// Return    : bool
// Notes     : 
bool vmConsole::RegCase(const char* szCaseName, const char* szCaseNote, PACTFUNC pCaseFunc)
{
	vmConsoleCaseFactory::S_CASE loCase;
	loCase.mstrCaseName = szCaseName;
	loCase.mstrCaseNote = szCaseNote;
	loCase.mpCaseAction = pCaseFunc;

	bool lbRet = gCaseFactory.RegCase(loCase);

	return lbRet;

} // End of function RegCase(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Run
// Full name : vmConsole::Run
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : bool
// Notes     : 
bool vmConsole::Run()
{
	if (!Initialize())
		return false;

	while (gbIsExit == true)
	{
		bool lbRetForBegin = OnBegin();
		if ( lbRetForBegin == false )
		{
			continue;
		}

		// 对用户输入的命令行进行解析
		vmConsoleParams loCP;
		bool bRtForAI = loCP.AnalyzeInput();
		if (bRtForAI == false)
			break;

		
		// 获取测试事件
		PACTFUNC pAction = gCaseFactory.GetCase(loCP.GetCommand());
		if (pAction != NULL)
		{
			// 执行测试事件操作
			pAction(loCP.GetParamsNum(), loCP.GetParams());
		}
		else
		{
			// 对获取测试事件失败情况进行处理
			OnFailedCommandName(loCP.GetCommand());
		} // End of # if( pEvent ... #

		// 后置操作，清理/重置操作环境
		//if (Finish() == false)
		//	break;
		//{   m_bIsExit = false; OnFinishFailed(); break; }
	} // End of ## while( ... ##


	return true;
} // End of function Run(...
/////////////////////////////////////////////////////////////////////////////////////////

bool Help(int argc, char *argv[])
{
	std::cout <<"Show help info : " << std::endl;

	vmConsoleCaseFactory::tItor loItor = gCaseFactory.GetFirstCase();
	for ( int i=0; loItor != gCaseFactory.GetLastCase(); loItor++, i++)
	{
		vmConsoleCaseFactory::S_CASE loCase = loItor->second;
		printf("%15s - %-s\n", loCase.mstrCaseName.c_str(), loCase.mstrCaseNote.c_str());
	}

	return true;
}

bool Exit(int argc, char *argv[])
{
	// Todo: do action 2
	gbIsExit = false;

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Initialize
// Full name : vmConsole::Initialize
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : bool
// Notes     : 
bool vmConsole::Initialize()
{
	// 注册退出函数
	RegCase("Exit", "exit the console program.", (vmConsole::PACTFUNC)Exit);

	// 注册帮助函数
	RegCase("Help", "Show help info.", (vmConsole::PACTFUNC)Help);
	RegCase("help", "Show help info.", (vmConsole::PACTFUNC)Help);
	
	return true;
} // End of function Initialize(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnBegin
// Full name : vmConsole::OnBegin
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : bool
// Notes     : 
bool vmConsole::OnBegin()
{
	std::cout << "[ CMD ]: " << std::ends;
	return true;
} // End of function OnBegin(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnFailedCommandName
// Full name : vmConsole::OnFailedCommandName
// Access    : virtual public 
// Brief     : 
// Parameter : const char* szCommandName
// Return    : bool
// Notes     : 
bool vmConsole::OnFailedCommandName(const char* szCommandName)
{
	std::cout << "Can't find CMD(" << szCommandName << ")" << std::endl;
	return true;
} // End of function OnFailedCommandName(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : vmConsole::operator=
// Access    : private 
// Brief     : 
// Parameter : const vmConsole& obj
// Return    : vm::vmConsole&
// Notes     : 
vm::vmConsole& vmConsole::operator=(const vmConsole& obj)
{
	return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~vmConsole
// Full name : vmConsole::~vmConsole
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
vmConsole::~vmConsole()
{

} // End of function ~vmConsole(...
/////////////////////////////////////////////////////////////////////////////////////////



} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmConsole.cpp
/////////////////////////////////////////////////////////////////////////////////////////