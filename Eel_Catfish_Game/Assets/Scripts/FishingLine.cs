using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FishingLine : MonoBehaviour
{
    public SpriteRenderer fishingLineSprite;
    public GameObject BCGameObject;
   
    
    // Start is called before the first frame update
    void Awake()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnCollisionEnter (Collision collision)
    {
        if (collision.gameObject.tag == "Catfish" )
        {
            print("You have hit catfish");
        }
        else if (collision.gameObject.tag == "Eel")
        {
            print("you hit eel");
        }
    }


   

    public void FlipFishingLine()
    {
        
    }

  
    
    
    
    
}
