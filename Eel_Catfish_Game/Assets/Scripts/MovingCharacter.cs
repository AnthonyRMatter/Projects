using System;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MovingCharacter : MonoBehaviour    
{
    private Rigidbody characterRigid;
    public SpriteRenderer CharSpriteRenderer;
    public float jumpVelocity = 100f;
    private bool canJump = true;
    private bool isJumping;
    private bool isPlaying = false;
    public GameObject PlayButton;
    public GameObject RestartButton;
    
    
    // public void KeepCharOnScreen()
    // {
    //     CharSpriteRenderer.transform.position =
    //         SpriteTools.ConstrainToScreen(CharSpriteRenderer); 
    // }


   
    private void Awake()
    {
        characterRigid = gameObject.GetComponent<Rigidbody>();
    }

    private void Update()
    {

        if (characterRigid.velocity.y == 0){
            canJump = true;
            isJumping = false;
        }
        if(characterRigid.velocity.y < 0) canJump = false;
        if ((Input.GetKeyDown(KeyCode.C)))
        {
            print(gameObject.name + characterRigid.velocity.ToString() );
        }
        if ((Input.GetKeyDown(KeyCode.Z)))
        {
            characterRigid.velocity = Vector3.zero;
        }
       
       // KeepCharOnScreen();
        if (isJumping)
        {
            JumpGravity();
        }
    }
    
    public void StartGame()
    {
        isPlaying = true;
        PlayButton.SetActive(false);
    }

    public void Reset()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }


    private bool HasGameJustEnded()
    {
        if (!Game.IsRunning() && isPlaying)
        {
            return true;
        }

        return false;
    }

    public void PressJump()
    {           
        characterRigid.AddForce(0f, jumpVelocity, 0f);

        // print("PressJump");
        // if (canJump)
        // {
        //     canJump = false;
        //     characterRigid.AddForce(0f, jumpVelocity, 0f);
        //     //characterRigid.velocity = new Vector3(characterRigid.velocity.x,GameParameters.JUMP_VELOCITY,characterRigid.velocity.z);
        //     isJumping = true;
        //     characterRigid.useGravity = false;
        // }
        
    }


    private float CalculateJumpVelocity()
    {
        float vel = characterRigid.velocity.y;
        
        if (vel > 0f && vel < GameParameters.MINIMUM_UPWARDS_VELOCITY)
        {
            ReleaseJump();
            return vel;
        }
        else
        {
            return vel - vel/GameParameters.GRAVITY_DAMPENER;
        }
        
    }
    
    private void OnCollisionEnter(Collision collision)
    {
        characterRigid.useGravity = true;
    }
    private void JumpGravity()
    {
        characterRigid.velocity.Set(characterRigid.velocity.x,CalculateJumpVelocity(),characterRigid.velocity.z);
    }

    public void ReleaseJump()
    {
        isJumping = false;
        characterRigid.useGravity = true;
    }

    public void Walk(bool right)
    {
        int isRight = 0;
        if (right) isRight = 1;
        else isRight = -1;
        characterRigid.velocity = new Vector3( isRight*GameParameters.MAX_SIDE_VELOCITY, characterRigid.velocity.y,
            characterRigid.velocity.z);
        
    }
}
