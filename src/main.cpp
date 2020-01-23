#include "pch.h"
#include "Core/Application.h"
 
int main(int argc, char** argv)
{
    OGLE::Log::Init();
    OGLE::Application app;
    app.Run();

    return 0;
}
