using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sounds : MonoBehaviour
{
    public AudioSource AudioSource;
    public AudioClip waterSplashClip;
    public AudioClip doorEnterClip;
    public AudioClip hitSeaweedClip;
    public AudioClip hitTrashClip;
    
    public void playWaterSplash()
    {
        AudioSource.clip = waterSplashClip;
        AudioSource.Play();
    }

    public void playDoorEnterClip()
    {
        AudioSource.clip = doorEnterClip;
        AudioSource.Play();
    }

    public void playHitSeaweedClip()
    {
        AudioSource.clip = hitSeaweedClip;
        AudioSource.Play();
    }

    public void playHitTrashCLip()
    {
        AudioSource.clip = hitTrashClip;
        AudioSource.Play();
    }
}
