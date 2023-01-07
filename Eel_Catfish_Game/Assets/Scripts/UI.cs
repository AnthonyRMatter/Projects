using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.UI;

public class UI : MonoBehaviour
{
    // Start is called before the first frame update
    public CanvasGroup StartScreenCanvasGroup;
    public CanvasGroup GameOverScreenCanvasGroup;

    public GameObject PlayerHealth;
    //public TMP_Text Scoretext; // Would use this if text object was a Text Mesh Pro
    //public Text ScoreText;
    //public Text TimeText;
    //public GameTimer GameTimer;


    public void Update()
    {
        //ShowScore(ScoreKeeper.GetScore());
        //ShowTime(GameTimer.GetTimeAsString());
    }
    public void ShowStartScreen()
    {
        CanvasGroupDisplayer.Show(StartScreenCanvasGroup);
        CanvasGroupDisplayer.Hide(GameOverScreenCanvasGroup);
        PlayerHealth.SetActive(false);
        
    }

    public void ShowEndScreen()
    {
        CanvasGroupDisplayer.Show(GameOverScreenCanvasGroup);
        CanvasGroupDisplayer.Hide(StartScreenCanvasGroup);
        PlayerHealth.SetActive(false);
    }

    public void HideStartAndEndScreens()
    {
        CanvasGroupDisplayer.Hide(GameOverScreenCanvasGroup);
        CanvasGroupDisplayer.Hide(StartScreenCanvasGroup);
        PlayerHealth.SetActive(true);
    }

    // public void ShowScore(string score)
    // {
    //     ScoreText.text = "Score: " + score;
    // }
    //
    // public void ShowTime(string time)
    // {
    //     TimeText.text = "Time: " + time;
    // }

}