#include "VecMathListener.h"
#include "antlr4-runtime.h"

#include "VecMathLexer.h"
#include "VecMathParser.h"
#include "VecmathVisualizer.h"
#include <iostream>

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
        listener.OnDisplayVar.Connect([](const std::string& id, float r, float g, float b) {
            app.AddVariableDisplay(id, listener.m_VarMap[id].get(), r, g, b);
        });
        listener.OnClearDisplay.Connect([]() { app.ClearVariableDisplays(); });
        app.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
