using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class eelDoor : MonoBehaviour
{
    public bool isTriggered = false;
    public Animator _animator;
    public Sounds Sounds;

    public GameObject Eel;
    private Coroutine TimerCoroutine;
    // Start is called before the first frame update
    
    // public void Update()
    // {
    //     print("eelTriggered: " + isTriggered);
    // }
    
    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Eel"))
        {
            isTriggered = true;
            checkEelTrigger();
        }
    }

    public void setEelTriggerFalse()
    {
        isTriggered = false;
    }

    public int checkEelTrigger()
    {
        if (isTriggered == true)
        {
            playEelDoorAnimation();
            // TimerCoroutine = StartCoroutine(countdownToHideEel());
            return 1;
        }
        // showEel();
        return 0;
    }
    

    public void playEelDoorAnimation()
    {
        _animator.Play("Eel Door Animation");
    }
    
    private void FindGameObjects()
    {
        _animator = GetComponent<Animator>();
    }

    public void hideEel()
    {
        Eel.SetActive(false);
    }

    public void showEel()
    {
        Eel.SetActive(true);
    }

    public void playDoorEntrySound()
    {
        Sounds.playDoorEnterClip();
    }
    
    IEnumerator countdownToHideEel()
    {
        yield return new WaitForSeconds(1);
        hideEel();
    }
}
