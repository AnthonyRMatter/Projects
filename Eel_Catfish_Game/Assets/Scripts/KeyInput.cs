
using UnityEngine;

public class KeyInput : MonoBehaviour
{
    public catFish CatFish;
    public eel Eel;
    public SpriteRenderer CatFishRenderer;
    public SpriteRenderer EelRenderer;
    public void Update()
    {
        
        if (Input.GetKeyDown(KeyCode.W))
        {
            CatFish.PressJump();
        }
        else if (Input.GetKeyUp(KeyCode.W))
        {
            CatFish.ReleaseJump();
        }
        // if (!Input.GetKey(KeyCode.W))
        // {
        //     CatFish.ReleaseJump();
        // }
        
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            Eel.PressJump();
        }
        else if (Input.GetKeyUp(KeyCode.UpArrow))
        {
            Eel.ReleaseJump();
        }
        
        if (Input.GetKey(KeyCode.D))
        {
            CatFish.Walk(true);
            CatFishRenderer.flipX = false;

        }
        if (Input.GetKey(KeyCode.A))
        {
            CatFish.Walk(false);
            CatFishRenderer.flipX = true;

        }
        
        if (Input.GetKey(KeyCode.RightArrow))
        {
            Eel.Walk(true);
            EelRenderer.flipX = false;

        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            Eel.Walk(false);
            EelRenderer.flipX = true;

        }
    }
}
