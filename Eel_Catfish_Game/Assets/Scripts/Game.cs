using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public static class Game 
{
    
    public static  UI UI;

    public static Text GameResult;

    private static Levels levels;
    
    private static  bool isRunning = false;
     
    
    public static void Initialize(UI ui) //Pass Game timer later
    {
        UI = ui;
        //GameTimer = gameTimer;
        UI.ShowStartScreen();

    }

    public static void StartGame()
    {
        isRunning = true;
        // hide the start and end screens
        UI.HideStartAndEndScreens();
    }

    public static void EndGame()
    {
        isRunning = false;
        // show game over screen
        //GameResult.text = "Game Over";
    }
    
    public static bool GameJustEnded()
    {
        if (isRunning)
        {
            return true;
        }

        return false;
    }
    
    public static bool IsRunning()
    {
        return isRunning;
    }
}
