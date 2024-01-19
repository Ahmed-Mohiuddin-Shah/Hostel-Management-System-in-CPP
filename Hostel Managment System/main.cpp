#include "ProjectHeader.hpp"

int main(void)
{
    // --------------------- Initialization ---------------------------
    InitWindow(variables::screenWidth, variables::screenHeight, ProjectInfo::appName);
    initializeVariables();
    SetTargetFPS(variables::targetFPS);

    while (!variables::shouldExit && !WindowShouldClose())
    {
        switch (variables::currentLayer)
        {
        case variables::LOADING_SCREEN:
            loadingScreen();
            break;
        case variables::FATAL_ERROR_SCREEN:
            fatalErrorScreen();
            break;
        case variables::CREATE_NEW_HOSTEL_SCREEN:
            createNewHostelScreen();
            break;
        case variables::HOME_SCREEN:
            homeScreen();
            break;
        case variables::HOSTEL_DETAILS_SCREEN:
            hostelDetailsScreen();
            break;
        case variables::EXIT_SCREEN:
            variables::shouldExit = true;
            break;
        default:
            fatalErrorScreen();
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // wrap in closing/exit screen
    unloadResources();
    
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}