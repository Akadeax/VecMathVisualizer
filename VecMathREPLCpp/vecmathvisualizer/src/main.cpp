#include "VecMathListener.h"

#include "VecMathLexer.h"
#include "VecmathVisualizer.h"
#include "VecMathParser.h"
#include <iostream>
#include "antlr4-runtime.h"

VecMathListener listener{};
vmv::VecmathVisualizer app{};

void RunConsole()
{
    std::string codeLine;

    listener.promptHeader();

    do
    {
        listener.prompt("vecmath visualizer>");
        std::getline(std::cin, codeLine);
        listener.exec(codeLine);
    } while (!listener.isExit());

    listener.clearVariables();
}

int main()
{
    using namespace VecMath;

    try
    {
        std::jthread{RunConsole}.detach();
        listener.OnDisplayVar.Connect([](const std::string& id){ app.OnDisplayCommand(id); });
        app.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
