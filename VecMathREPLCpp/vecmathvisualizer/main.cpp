#include "ANTLRInputStream.h"
#include "VecMathLexer.h"
#include "VecMathListener.h"
#include "VecMathParser.h"
#include "Vocabulary.h"
#include "Scalar.h"
#include "Vector3D.h"
#include <iostream>
#include <algorithm>

#ifdef _WIN32
#ifndef NDEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#endif
#endif
void printTokens(antlr4::CommonTokenStream& stream, const antlr4::dfa::Vocabulary& symbols);

void OnDisplayVar(const std::string& name, IMatrix* var);

int main()
{
#ifdef _WIN32
#ifndef NDEBUG
    _CrtSetDbgFlag(_CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_ALLOC_MEM_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
#endif
#endif
    std::string codeLine;
    size_t tokenType = -1;
    using namespace antlr4;
    using namespace VecMath;
    {
        try
        {
            VecMathListener listener{};
            listener.OnDisplayVar.Connect(OnDisplayVar);

            listener.promptHeader();
            do
            {
                listener.prompt("woo vecmath >");
                std::getline(std::cin, codeLine);
                listener.exec(codeLine);
            } while (!listener.isExit());
            listener.clearVariables();
        }
        catch (std::system_error const& e)
        {
            std::cerr << e.what() << std::endl;
            std::cerr << e.code() << std::endl;
        }
    }
#ifdef _WIN32
#ifndef NDEBUG
    _CrtDumpMemoryLeaks();
#endif
#endif
}

void printTokens(antlr4::CommonTokenStream& stream, const antlr4::dfa::Vocabulary& symbols)
{
    using namespace std;
    for (auto token : stream.getTokens())
    {
        cout << token->getText();
        cout << " [";
        cout << symbols.getSymbolicName(token->getType());
        cout << "] ";
    }
    cout << endl;
}


void OnDisplayVar(const std::string& val, IMatrix* matrix)
{
	std::cout << "DISPLAY RECEIVED\n";
}
