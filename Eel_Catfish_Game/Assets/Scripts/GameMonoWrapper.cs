using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameMonoWrapper : MonoBehaviour
{
    public UI UI;

    public Text Text;

    //public GameTimer GameTimer;
    
    // Start is called before the first frame update
    void Start()
    {
        Game.Initialize(UI);
    }

    // Update is called once per frame
    void Update()
    {
        if (Game.GameJustEnded())
        {
            Game.EndGame();
        }
    }

    public void StartGame()
    {
        Game.StartGame();
    }
}
