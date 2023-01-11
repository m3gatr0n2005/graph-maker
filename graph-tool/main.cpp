#include "Core/application.h"


int main()
{
    ApplicationDescription desc;
    desc.name = "graph-tool";
    desc.FPS = 60;
    desc.windowWidth = 1600;
    desc.windowHeight = 900;
    desc.clearColor = { 215, 255, 255 };

    Application* app = new Application(desc);;
    app->run();
    delete app;

    return EXIT_SUCCESS;
}
