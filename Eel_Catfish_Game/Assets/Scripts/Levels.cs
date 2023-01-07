using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Levels : MonoBehaviour
{

    public List<GameObject> levels;
    private GameObject levelGameObject;
    private int currentLevel = 0;
    //public PlayerHealth Health;
    
    public GameObject eelPosition;
    public GameObject catfishPosition;
    public GameObject eelStartPosition;
    public GameObject catfishStartPosition;
    public GameObject FisherManStartPosition;
    public GameObject FisherManPosition;



    // Start is called before the first frame update
    
    
    void Start()
    {
        levelGameObject = CreateLevel();
        ResetCharacterPositions();
        print("Created");
        //UpdateLevelReadout();
    }

    public void ResetCharacterPositions()
    {
        eelPosition.transform.position = eelStartPosition.transform.position;
        catfishPosition.transform.position = catfishStartPosition.transform.position;
        FisherManPosition.transform.position = FisherManStartPosition.transform.position;
    }

    public void GoToNextLevel()
    {
        currentLevel++;
        if (currentLevel == levels.Count - 1)
        {
            IsGameOver();
        }

        LoadNextLevel();
    }
    
    public void IsGameOver()
    {
        eelPosition.SetActive(false);
        catfishPosition.SetActive(false);

    }

    // private void OnTriggerEnter(Collider other)
    // {
    //     if (other.gameObject.tag == "Door")
    //     {
    //         print("Hello");
    //         GoToNextLevel();
    //     }
    // }

    private void LoadNextLevel()
    {
        if (levelGameObject != null)
        {
            Destroy(levelGameObject);
        }
        
        levelGameObject = CreateLevel();
        eelPosition.GetComponent<eel>().amountOfDamage += 20;
        catfishPosition.GetComponent<catFish>().amountOfDamage += 20;

        ResetCharacterPositions(); 
        //UpdateLevelReadout();
    }

    // private void UpdateLevelReadout()
    // {
    //     Readouts.ShowLevel(currentLevel + 1);
    // }

    private GameObject CreateLevel()
    {
        return Instantiate(levels[currentLevel],
            levels[currentLevel].transform.position, Quaternion.identity);   
    }
    

}
