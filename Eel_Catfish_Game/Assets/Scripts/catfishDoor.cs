using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class catfishDoor : MonoBehaviour
{
    // Start is called before the first frame update
    public bool isTriggered = false;
    public Animator _animator;
    public GameObject Catfish;
    public Sounds Sounds;
    private Coroutine TimerCoroutine;

    
    // public void Update()
    // {
    //     print("catfishTriggered: " + isTriggered);
    // }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Catfish"))
        {
            isTriggered = true;
            checkCatfishTrigger();
        }

    }

    public void setCatfishTriggerFalse()
    {
        isTriggered = false;
    }

    public int checkCatfishTrigger()
    {
        if (isTriggered == true)
        {
            playCatfishDoorAnimation();
            // TimerCoroutine = StartCoroutine(countdownToHideCatfish());
            return 1;
        }

        return 0;
    }
    public void playCatfishDoorAnimation()
    {
        _animator.Play("CatfishDoor Animation");
        // playDoorEntrySound();
    }
    
    private void FindGameObjects()
    {
        _animator = GetComponent<Animator>();
    }

    //used an animation event to call this method during a specific frame
    public void hideCatfish()
    {
        Catfish.SetActive(false);
    }

    //when animation plays, it sets the characters setActive to false
    //so this sets it back to true and is called when you move to next level
    public void showCatfish()
    {
        Catfish.SetActive(true);
    }

    //used an animation event to call this method during a specific frame
    public void playDoorEntrySound()
    {
        Sounds.playDoorEnterClip();
    }
    
   
    
    // IEnumerator countdownToHideCatfish()
    // {
    //     yield return new WaitForSeconds(1);
    //     hideCatfish();
    // }
}
