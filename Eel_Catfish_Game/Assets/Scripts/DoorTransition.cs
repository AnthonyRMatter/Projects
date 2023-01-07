using System;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting.FullSerializer;
using UnityEngine;

public class DoorTransition : MonoBehaviour
{
    public Levels Levels;
    public catfishDoor CatfishDoor;
    public eelDoor EelDoor;
    
    private Coroutine TimerCoroutine;
   


    void Update()
    {
        if (CatfishDoor.checkCatfishTrigger() == 1 && EelDoor.checkEelTrigger() == 1)
        {
            Levels.GoToNextLevel();
            setTriggersFalse();
            TimerCoroutine = StartCoroutine(countdownToShowCharacters());

        }
    }

    private void setTriggersFalse()
    {
        CatfishDoor.setCatfishTriggerFalse();
        EelDoor.setEelTriggerFalse();
    }

    IEnumerator countdownToShowCharacters()
    {
        yield return new WaitForSeconds(2);
        EelDoor.showEel();
        CatfishDoor.showCatfish();
    }

    // private void OnTriggerEnter(Collider other)
    // {
    //     if (other.CompareTag("Eel") && other.CompareTag("Catfish"))
    //     {
    //         print("Hello");
    //         Levels.GoToNextLevel();
    //     }
    // }
    
    
    // Start is called before the first frame update


}
