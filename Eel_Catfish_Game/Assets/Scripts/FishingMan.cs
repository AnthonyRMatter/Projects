using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class FishingMan : MonoBehaviour
{
    public SpriteRenderer FisherSpriteRenderer;
    public FishingLine FishingLine;
    public Rigidbody rb;
    public Animator _animator;
    public float walkSpeed = 0.0f;
    private bool isFishing = false;
    private bool isRunning = true;
    private Coroutine TimerCoroutine;
    private bool isOkayToStartTimer = true;
    private int secondsUnitlCreation;
    protected int minimumTimeToCreate = 5;
    protected int maximumTimeToCreate = 10;
    
    private Transform hook;
    private void Awake()
    {
        hook = gameObject.transform.GetChild(0);
    }
    void Start()
    {
    
    }

    void Update()
    {
        if (isRunning)
        {
            if (isOkayToStartTimer)
            {
                isOkayToStartTimer = false;
                TimerCoroutine = StartCoroutine(countdownToFish());
      
            }
            if (FisherSpriteRenderer.flipX){
            
                rb.velocity = new Vector3(-GameParameters.FISHERMAN_MOVESPEED,0,0);
            }
            else
            {
                rb.velocity = new Vector3(GameParameters.FISHERMAN_MOVESPEED,0,0);
            }
        }
        
    }

    private bool isPlaying()
    {
        if (Game.IsRunning())
        {
            print("Game is running");
            return true;
        }
        else
        {
            print("Game is not running");
            return false;
        }
    } 

    private void OnCollisionEnter(Collision collision)
    {
        if(!FisherSpriteRenderer.flipX) hook.position
            = new Vector3(hook.position.x - 2.58f, hook.position.y,
                hook.position.z);
        else hook.position = new Vector3(hook.transform.position.x +2.58f, hook.position.y,
            hook.position.z);
        FisherSpriteRenderer.flipX = !FisherSpriteRenderer.flipX;
        
    }
    

    private void FindGameObjects()
    {
        _animator = GetComponent<Animator>();
    }

    private void Fish()
    {
        if (isFishing)
        {
            // _animator.SetTrigger("onFishing");
            _animator.Play("FishingMan Animation");
            isFishing = false;
        }
        
        
    }

    public void stopBoat()
    {
        rb.isKinematic = true;
        
    }

    public void startBoat()
    {
        rb.isKinematic = false;
    }

  

    IEnumerator countdownToFish()
    {
        secondsUnitlCreation = Random.Range(minimumTimeToCreate, maximumTimeToCreate + 1);
        yield return new WaitForSeconds(secondsUnitlCreation);
        isFishing = true;
        Fish();
        isOkayToStartTimer = true;
    }
    
}
