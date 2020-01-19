#include "pch.h"
#include "Application.h"
 
int main(int argc, char** argv)
{
    OGLE::Log::Init();
    OGLE::Application app;
    app.Run();

    return 0;
}
